#include "QtStereoCamProject.h"

QtStereoCamProject::QtStereoCamProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	left_cam = new cv::VideoCapture(1);
	right_cam = new cv::VideoCapture(2);

	left_cam->set(cv::CAP_PROP_FRAME_WIDTH, 1920);
	left_cam->set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
	left_cam->set(cv::CAP_PROP_AUTOFOCUS, 0);
	/*left_cam->set(cv::CAP_PROP_FOCUS, 25);
	left_cam->set(cv::CAP_PROP_BRIGHTNESS, 125);*/

	right_cam->set(cv::CAP_PROP_FRAME_WIDTH, 1920);
	right_cam->set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
	right_cam->set(cv::CAP_PROP_AUTOFOCUS, 0);
	/*right_cam->set(cv::CAP_PROP_FOCUS, 25);
	right_cam->set(cv::CAP_PROP_BRIGHTNESS, 125);*/
	m_capturing = false;
	m_take_a_pic = false;
	m_image_counter = 0;

	connect(ui.startCapture_pushButton, SIGNAL(toggled(bool)), this, SLOT(startStopCapture(bool)));
	connect(ui.calibrateCameras_pushButton, SIGNAL(clicked()), this, SLOT(cameraCalibration()));
	connect(ui.computeDisparityMap_pushButton, SIGNAL(clicked()), this, SLOT(computeDisparityMap()));
	connect(ui.takePic_pushButton, SIGNAL(clicked()), this, SLOT(takeAPhoto()));
	connect(ui.brightness_verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(setBrightness(int)));
	connect(ui.focus_verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(setFocus(int)));
}

void QtStereoCamProject::takeAPhoto() {
	m_take_a_pic = true;
}

void QtStereoCamProject::setBrightness(int value) {
	
	left_cam->set(cv::CAP_PROP_BRIGHTNESS, value);
	right_cam->set(cv::CAP_PROP_BRIGHTNESS, value);
}

void QtStereoCamProject::setFocus(int value) {

	left_cam->set(cv::CAP_PROP_FOCUS, value);
	right_cam->set(cv::CAP_PROP_BRIGHTNESS, value);
}

int QtStereoCamProject::imageCapture()
{
	cv::Mat img1, img2, img1g, img2g;
	std::vector< cv::Point2f > corners1, corners2;

	cv::Size board_size = cv::Size(ui.width_spinBox->value(), ui.height_spinBox->value());
	int board_n = ui.width_spinBox->value() * ui.height_spinBox->value();

	left_cam->read(img1);
	right_cam->read(img2);

	img1.copyTo(img1);
	img2.copyTo(img2);

	cv::cvtColor(img1, img1g, CV_BGR2GRAY);
	cv::cvtColor(img2, img2g, CV_BGR2GRAY);


	bool founD1 = false, founD2 = false;

	founD1 = cv::findChessboardCorners(img1, board_size, corners1, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
	founD2 = cv::findChessboardCorners(img2, board_size, corners2, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);

	if (founD1)
	{
		cv::cornerSubPix(img1g, corners1, cv::Size(5, 5), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
		cv::drawChessboardCorners(img1g, board_size, corners1, founD1);
	}

	if (founD2)
	{
		cv::cornerSubPix(img2g, corners2, cv::Size(5, 5), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
		cv::drawChessboardCorners(img2g, board_size, corners2, founD2);
	}

	ui.camLeft_openGLWidget->setVisualicedImage(img1g);
	ui.camRight_openGLWidget->setVisualicedImage(img2g);

	if (m_take_a_pic)
	{
		m_image_counter++;
		std::string full_path_left = QString("%1/left%2.bmp").arg(m_images_dir).arg(m_image_counter).toStdString();
		std::string full_path_right = QString("%1/right%2.bmp").arg(m_images_dir).arg(m_image_counter).toStdString();

		std::cout << "Saving img pair " << m_image_counter << endl;

		cv::imwrite(full_path_left, img1);
		cv::imwrite(full_path_right, img2);

		m_take_a_pic = false;
	}

	if (m_capturing)
	{
		QTimer::singleShot(1, this, SLOT(imageCapture()));
	}


	return 0;
}

void QtStereoCamProject::cameraCalibration() {

	std::vector< std::vector< cv::Point3f > > object_points;
	std::vector< std::vector< cv::Point2f > > image_points_1, image_points_2;
	std::vector< cv::Point2f > corners1, corners2;
	Rect validRoi[2];
	cv::Mat img1, img2, img1g, img2g;

	std::string out_file_left = "cam_left.yml";
	std::string out_file_right = "cam_right.yml";
	std::string out_file_stereo = "cam_stereo.yml";

	int board_width = ui.width_spinBox->value();
	int board_height = ui.height_spinBox->value();
	double square_size = ui.size_doubleSpinBox->value();

	cv::Size board_size = cv::Size(board_width, board_height);
	int board_n = board_width * board_height;

	m_images_dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	QDir directory_images(m_images_dir);
	QStringList images_left = directory_images.entryList(QStringList() << "left*.jpg");
	QStringList images_right = directory_images.entryList(QStringList() << "right*.jpg");

	for (size_t i = 0; i < images_left.size(); i++)
	{
		std::string full_path_left = QString("%1/%2").arg(m_images_dir).arg(images_left[i]).toStdString();
		std::string full_path_right = QString("%1/%2").arg(m_images_dir).arg(images_right[i]).toStdString();

		img1 = cv::imread(full_path_left, CV_LOAD_IMAGE_COLOR);
		img2 = cv::imread(full_path_right, CV_LOAD_IMAGE_COLOR);

		cv::cvtColor(img1, img1g, CV_BGR2GRAY);
		cv::cvtColor(img2, img2g, CV_BGR2GRAY);

		bool found1 = false, found2 = false;

		found1 = cv::findChessboardCorners(img1, board_size, corners1, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FILTER_QUADS);
		found2 = cv::findChessboardCorners(img2, board_size, corners2, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FILTER_QUADS);

		if (!found1 || !found2) {
			printf("Chessboard find error!\n");
			printf("leftImg: %s and rightImg: %s\n", images_left[i].toStdString(), images_right[i].toStdString());
			continue;
		}

		if (found1)
		{
			cv::cornerSubPix(img1g, corners1, cv::Size(5, 5), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			cv::drawChessboardCorners(img1g, board_size, corners1, found1);
		}

		if (found2)
		{
			cv::cornerSubPix(img2g, corners2, cv::Size(5, 5), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
			cv::drawChessboardCorners(img2g, board_size, corners2, found2);
		}

		std::vector< cv::Point3f > obj;
		for (int i = 0; i < board_height; i++)
			for (int j = 0; j < board_width; j++)
				obj.push_back(cv::Point3f((float)j * square_size, (float)i * square_size, 0));

		if (found1 && found2) {
			printf("%d. Found corners!\n", i);
			image_points_1.push_back(corners1);
			image_points_2.push_back(corners2);
			object_points.push_back(obj);
		}

		ui.camLeft_openGLWidget->setVisualicedImage(img1g);
		ui.camRight_openGLWidget->setVisualicedImage(img2g);

		cv::waitKey(10);
	}

	cv::Mat K1, K2;
	cv::Mat D1, D2;
	std::vector< cv::Mat > rvecs_left, rvecs_right, tvecs_left, tvecs_right;

	int flag = 0;
	flag |= CALIB_FIX_K4;
	flag |= CALIB_FIX_K5;

	cv::calibrateCamera(object_points, image_points_1, img1.size(), K1, D1, rvecs_left, tvecs_left, flag);
	cv::calibrateCamera(object_points, image_points_2, img2.size(), K2, D2, rvecs_right, tvecs_right, flag);

	printf("Calibration error left camera: %f\n", computeReprojectionErrors(object_points, image_points_1, rvecs_left, tvecs_left, K1, D1));
	printf("Calibration error right camera: %f\n", computeReprojectionErrors(object_points, image_points_2, rvecs_right, tvecs_right, K2, D2));

	cv::FileStorage fs_left(out_file_left, cv::FileStorage::WRITE);
	fs_left << "K" << K1;
	fs_left << "D" << D1;

	cv::FileStorage fs_right(out_file_right, cv::FileStorage::WRITE);
	fs_right << "K" << K2;
	fs_right << "D" << D2;

	printf("Starting Calibration...\n");
	cv::Mat R, F, E, T;

	flag = 0;
	flag |= CALIB_FIX_INTRINSIC;

	cv::stereoCalibrate(object_points, image_points_1, image_points_2, K1, D1, K2, D2, img1.size(), R, T, E, F, flag);

	cv::FileStorage fs_stereo(out_file_stereo, cv::FileStorage::WRITE);
	fs_stereo << "K1" << K1;
	fs_stereo << "K2" << K2;
	fs_stereo << "D1" << D1;
	fs_stereo << "D2" << D2;
	fs_stereo << "R" << R;
	fs_stereo << "T" << T;
	fs_stereo << "E" << E;
	fs_stereo << "F" << F;

	printf("Done Calibration.\n");

	printf("Starting Rectification...\n");

	cv::Mat R1, R2, P1, P2, Q;
	cv::stereoRectify(K1, D1, K2, D2, img1.size(), R, T, R1, R2, P1, P2, Q, CV_CALIB_ZERO_DISPARITY, 0, img1.size(), &validRoi[0], &validRoi[1]);

	fs_stereo << "R1" << R1;
	fs_stereo << "R2" << R2;
	fs_stereo << "P1" << P1;
	fs_stereo << "P2" << P2;
	fs_stereo << "Q" << Q;

	printf("Done Rectification.\n");

	
}

void QtStereoCamProject::startStopCapture(bool start) {

	if (start)
	{
		m_capturing = true;
		m_image_counter = 0;
		m_images_dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
		//cv::String path = dir.toStdString();
		imageCapture();
	}
	else
	{
		m_capturing = false;
	}
}

double QtStereoCamProject::computeReprojectionErrors(const std::vector< std::vector< cv::Point3f > >& objectPoints, const std::vector< std::vector< cv::Point2f > >& imagePoints, const std::vector< cv::Mat >& rvecs, const std::vector< cv::Mat >& tvecs, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs) {
	std::vector< cv::Point2f > imagePoints2;
	int i, totalPoints = 0;
	double totalErr = 0, err;
	std::vector< float > perViewErrors;
	perViewErrors.resize(objectPoints.size());

	for (i = 0; i < (int)objectPoints.size(); ++i) {

		projectPoints(cv::Mat(objectPoints[i]), rvecs[i], tvecs[i], cameraMatrix,
			distCoeffs, imagePoints2);
		err = cv::norm(cv::Mat(imagePoints[i]), cv::Mat(imagePoints2), CV_L2);
		int n = (int)objectPoints[i].size();
		perViewErrors[i] = (float)std::sqrt(err*err / n);
		totalErr += err * err;
		totalPoints += n;
	}

	return std::sqrt(totalErr / totalPoints);
}


void QtStereoCamProject::computeDisparityMap() {

	cv::Mat R1, R2, P1, P2, Q;
	cv::Mat K1, K2, R;
	cv::Mat T;
	cv::Mat D1, D2;

	Ptr<StereoSGBM> sgbm = StereoSGBM::create(0, 16, 3);

	QString filenameL = QFileDialog::getOpenFileName(this, tr("Open Image"), "./", tr("Image Files (*left.png *left.jpg *left.bmp)"));

	QString filenameR = filenameL.left(filenameL.lastIndexOf("left.jpg"));
	filenameR = filenameR + "right.jpg";

	cv::Mat img1, img2, img1_gray, img2_gray;

	img1 = cv::imread(filenameL.toStdString(), CV_LOAD_IMAGE_COLOR);
	img2 = cv::imread(filenameR.toStdString(), CV_LOAD_IMAGE_COLOR);

	cv::FileStorage fs1("cam_stereo.yml", cv::FileStorage::READ);

	fs1["K1"] >> K1;
	fs1["K2"] >> K2;
	fs1["D1"] >> D1;
	fs1["D2"] >> D2;
	fs1["R"] >> R;
	fs1["T"] >> T;

	fs1["R1"] >> R1;
	fs1["R2"] >> R2;
	fs1["P1"] >> P1;
	fs1["P2"] >> P2;
	fs1["Q"] >> Q;

	Mat map11, map12, map21, map22;
	cv::Mat img1r, img2r;

	cv::initUndistortRectifyMap(K1, D1, R1, P1, img1.size(), CV_16SC2, map11, map12);
	cv::initUndistortRectifyMap(K2, D2, R2, P2, img2.size(), CV_16SC2, map21, map22);

	cv::remap(img1, img1r, map11, map12, cv::INTER_LINEAR);
	cv::remap(img2, img2r, map21, map22, cv::INTER_LINEAR);
	
	img1 = img1r;
	img2 = img2r;


	//METODO SGBM!!!///
	Mat disp, disp8;

	sgbm->setPreFilterCap(4);
	sgbm->setBlockSize(5);

	int cn = img1.channels();
	sgbm->setP1(600);
	sgbm->setP2(2400);
	sgbm->setMinDisparity(0);
	sgbm->setNumDisparities(192);
	sgbm->setUniquenessRatio(10);
	sgbm->setSpeckleWindowSize(100);
	sgbm->setSpeckleRange(32);
	sgbm->setDisp12MaxDiff(1);
	sgbm->compute(img1, img2, disp);

	normalize(disp, disp8, 0, 255, CV_MINMAX, CV_8U);
	ui.camLeft_openGLWidget->setVisualicedImage(disp8);


	////METODO ELAS!!!//
	/*cv::cvtColor(img1r, img1_gray, CV_BGR2GRAY);
	cv::cvtColor(img2r, img2_gray, CV_BGR2GRAY);

	const cv::Size imsize = img1_gray.size();
	const int32_t dims[3] = { imsize.width,imsize.height,imsize.width };

	cv::Mat leftdpf = cv::Mat::zeros(imsize, CV_32F);
	cv::Mat rightdpf = cv::Mat::zeros(imsize, CV_32F);

	Elas::parameters param(Elas::MIDDLEBURY);
	param.postprocess_only_left = true;
	Elas elas(param);
	elas.process(img1_gray.data, img2_gray.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims);

	cv::Mat disp = cv::Mat(imsize, CV_8UC1, cv::Scalar(0));
	leftdpf.convertTo(disp, CV_8U, 1.);
	ui.camLeft_openGLWidget->setVisualicedImage(disp);*/

	imwrite("disparity.bmp", disp8);
	Mat xyz;
	reprojectImageTo3D(disp8, xyz, Q, true);
	saveXYZ("xyz.txt", xyz);

}

void QtStereoCamProject::saveXYZ(const char* filename, const Mat& mat)
{
	const double max_z = 1.0e4;
	FILE* fp = fopen(filename, "wt");
	for (int y = 0; y < mat.rows; y++)
	{
		for (int x = 0; x < mat.cols; x++)
		{
			Vec3f point = mat.at<Vec3f>(y, x);
			if (fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z) continue;
			fprintf(fp, "%f %f %f\n", point[0], point[1], point[2]);
		}
	}
	fclose(fp);
}
