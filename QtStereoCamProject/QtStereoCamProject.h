#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include "ui_QtStereoCamProject.h"
#include "elas/elas.h"
#include <opencv2/features2d/features2d.hpp>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"

#include <stdio.h>

using namespace cv;
using namespace std;

class QtStereoCamProject : public QMainWindow
{
	Q_OBJECT

public:
	QtStereoCamProject(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtStereoCamProjectClass ui;
	cv::VideoCapture *left_cam, *right_cam;
	QString m_images_dir;
	bool m_capturing, m_take_a_pic;
	Rect m_roi1, m_roi2;
	int m_image_counter;
	double computeReprojectionErrors(const std::vector< std::vector< cv::Point3f > >& objectPoints, const std::vector< std::vector< cv::Point2f > >& imagePoints, const std::vector< cv::Mat >& rvecs, const std::vector< cv::Mat >& tvecs, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs);

private slots:
	void startStopCapture(bool start);
	int imageCapture();
	void cameraCalibration();
	void computeDisparityMap();
	void takeAPhoto();
	void setBrightness(int value);
	void setFocus(int value);
	void saveXYZ(const char* filename, const Mat& mat);
};
