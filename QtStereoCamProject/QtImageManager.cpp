
#include "QtImageManager.h"

CQtImageManager::CQtImageManager(QWidget* parent, const QGLWidget* sharedWidget, Qt::WindowFlags f) : QGLWidget(parent, sharedWidget, f), m_imgP(0)
{
	//crearImagen(&m_imgRGB,1,1,IPL_DEPTH_8U,3);
	m_imgRGB = cv::Mat(1,1,CV_8UC3);
	QObject::connect(this, SIGNAL(updateViewGL(void)), this, SLOT(updateGL(void)));

}

CQtImageManager::~CQtImageManager()
{
	glDeleteTextures(1, &m_texNameGL);
	m_imgRGB.release();
}

void CQtImageManager::initializeGL()
{
	// INIT
	// Let OpenGL clear to black
	glColor3f(0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the shading model
	glShadeModel(GL_FLAT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glGenTextures(1, &m_texNameGL);
}

void CQtImageManager::paintGL()
 {
	// PAINT
	glColor3f(1.0,1.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	if (!m_imgP)	return;
	glDisable(GL_DEPTH_TEST);
	drawTexture(m_texUpperLeftX, m_texUpperLeftY, m_texLowerRightX, m_texLowerRightY);
	glEnable(GL_DEPTH_TEST);	
}

 /** 
draws the texture sub image on the screen
@param upper left x coordinate
@param upper left y coordinate
@param lower right x coordinate
@param lower right y coordinate
*/
void CQtImageManager::drawTexture(float ulX, float ulY, float lrX, float lrY)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texNameGL);
	switch (m_pixeldepth) 
	{
	case 8: glTexSubImage2D ( GL_TEXTURE_2D, 0, m_texWidth-m_width, m_texHeight-m_height, 
				m_width, m_height, GL_LUMINANCE, 
				GL_UNSIGNED_BYTE, m_imgP);
		break;
	case 24:
		glTexSubImage2D ( GL_TEXTURE_2D, 0, m_texWidth-m_width, m_texHeight-m_height,  
			m_width, m_height, GL_BGR_EXT,  
			GL_UNSIGNED_BYTE, m_imgP);
		break;
	case 32:
		glTexSubImage2D ( GL_TEXTURE_2D, 0, m_texWidth-m_width, m_texHeight-m_height,  
			m_width, m_height, GL_BGRA_EXT,  
			GL_UNSIGNED_BYTE, m_imgP);
		break;		
	}

	glLoadIdentity();					// Reset The Modelview Matrix

	glBegin(GL_QUADS);
	if (m_flipped)
	{	
    //flipped
		glTexCoord2f(ulX, ulY);    glVertex2f( -1, -1 );
		glTexCoord2f(ulX, lrY);    glVertex2f( -1, 1 );
		glTexCoord2f(lrX, lrY);    glVertex2f(  1, 1 );
		glTexCoord2f(lrX, ulY);    glVertex2f(  1, -1 );
	}
	else
	{
		glTexCoord2f(ulX, ulY);    glVertex2f( -1, 1 );
		glTexCoord2f(ulX, lrY);    glVertex2f( -1, -1 );
		glTexCoord2f(lrX, lrY);    glVertex2f(  1, -1 );
		glTexCoord2f(lrX, ulY);    glVertex2f(  1, 1 );
	}
  glEnd();
	glDisable(GL_TEXTURE_2D);

	glTranslatef(-1.0,1.0,0);
	glScalef(2.0/m_width, 2.0/m_height, 0.0);
}

unsigned int CQtImageManager::NextLargerPowerOfTwo(unsigned int n) {
	unsigned int candidate = n;

	while((candidate & (candidate - 1)) != 0) {
		++candidate;
	}
	return candidate;
}

void CQtImageManager::resetGL_PROJECTIONMatrix(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

void CQtImageManager::resizeGL(int w, int h)
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	// RESIZE
	int delta;
	float aspectRatio = (float) h/w;
	float aspectRatioIm = (float) m_height/m_width; 
	if (aspectRatio > aspectRatioIm)
	{
		// Sobra por arriba/abajo
		delta = 0.5*(h-w*aspectRatioIm);
		glViewport(0, delta, (GLsizei) w, (GLsizei) h-2*delta);
	}
	else if (aspectRatio < aspectRatioIm)
	{
		// Sobra por izda/dcha
		delta = 0.5*(w-h/aspectRatioIm);
		glViewport(delta, 0, (GLsizei) w-2*delta, (GLsizei) h);
	}
	else
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

bool CQtImageManager::setImage(
	unsigned char* imgP, 
	const int width, 
	const int height, 
	const int pixeldepth, 
	const bool flipped /*=false*/)
{
	m_imgP = imgP; m_width = width; m_height = height; m_pixeldepth = pixeldepth;
    m_flipped = flipped;
	emit updateViewGL();	

	// only 8, 24 and 32 bit images are supported
	if (!imgP || (pixeldepth!=8 && pixeldepth!=24 && pixeldepth!=32))
		return false;
	glEnable(GL_TEXTURE_2D);					// Enable Texture Mapping
	// calculate texture size
	m_texWidth  = NextLargerPowerOfTwo(m_width);
	m_texHeight = NextLargerPowerOfTwo(m_height);
	// create texture memory
	unsigned char* textureGL = new GLubyte[m_texHeight*m_texWidth* (pixeldepth>>3)];
	// calculate texture coordinates for image
	m_texUpperLeftX = float (m_texWidth-m_width) / (float) (m_texWidth);
	m_texUpperLeftY = float (m_texHeight-m_height) / (float) (m_texHeight);
	m_texLowerRightX = 1.0; // (float) (_texWidth) / (float) _height;
	m_texLowerRightY = 1.0; // (float) (_texHeight) / (float) _width;

	// tell OpenGL which texture "id" we will be working with.:
	glBindTexture(GL_TEXTURE_2D, m_texNameGL);
	// tell OpenGL that the pixel data which is going to be passed to it is aligned in byte order:
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// set the various parameters for the current OpenGL texture:
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// tell OpenGL how the texture will act when it is rendered into a scene:
	// The GL_MODULATE attribute allows you to apply effects such as lighting 
	// and coloring to your texture. If you do not want lighting and coloring to effect 
	// your texture and you would like to display the texture unchanged when coloring 
	// is applied replace GL_MODULATE with GL_DECAL
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, _texWidth, _texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, img->data());
	switch(m_pixeldepth) {
	case 8:
		glTexImage2D(GL_TEXTURE_2D, 0,  GL_LUMINANCE, m_texWidth, m_texHeight, 0,  GL_LUMINANCE, GL_UNSIGNED_BYTE,textureGL); 
		break;
	case 24:
		glTexImage2D(GL_TEXTURE_2D, 0,  GL_RGB, m_texWidth,m_texHeight, 0,  GL_RGB, GL_UNSIGNED_BYTE, textureGL); 
		break;
	case 32:
		glTexImage2D(GL_TEXTURE_2D, 0,  GL_RGBA, m_texWidth,m_texHeight, 0,  GL_RGBA, GL_UNSIGNED_BYTE, textureGL); 
		break;	
	default:
		glDisable(GL_TEXTURE_2D);
		delete[] textureGL;
		return false;
	}    
    
	glDisable(GL_TEXTURE_2D);
	//glFlush();
	delete[] textureGL;
    
 	return true;
}

void CQtImageManager::setVisualicedImage(cv::Mat img)
{
	img.copyTo(m_imgToShow);
	QSize sizeWidget = this->size();
	this->resizeGL(sizeWidget.width(), sizeWidget.height());
	videoLoop();
}

void CQtImageManager::videoLoop()
{

	m_mutex.lock();

	if ((m_imgRGB.cols != m_imgToShow.cols) || (m_imgRGB.rows != m_imgToShow.rows))
	{
		// Para que la visualizacion sea correcta relleno con marco negro para que IplImage.widthStep == 3*IplImage.width
		int validWidth;
		int faltanBytesPorRellenar = 8-((m_imgToShow.cols*3) % 8);
		switch (faltanBytesPorRellenar)
		{
		case 8:
			validWidth = m_imgToShow.cols;
			break;
		case 1:
			validWidth = m_imgToShow.cols+3;
			break;
		case 2:
			validWidth = m_imgToShow.cols+6;
			break;
		case 3:
			validWidth = m_imgToShow.cols+9;
			break;
		case 4:
			validWidth = m_imgToShow.cols+4;
			break;
		case 5:
			validWidth = m_imgToShow.cols+7;
			break;
		case 6:
			validWidth = m_imgToShow.cols+10;
			break;
		case 7:
			validWidth = m_imgToShow.cols+5;
			break;
		}
		m_imgRGB =cv::Mat(m_imgToShow.rows,validWidth,CV_8UC3);
	}
	m_imgRGB.setTo(0);
	if (m_imgToShow.total() > 0)
	{
		cv::Mat imgRGBroi = m_imgRGB.colRange(0,m_imgToShow.cols).rowRange(0,m_imgToShow.rows);
		//if(m_imgToShow.depth() != 8)
		//{
		//	cv::Mat auxI;
		//	cv::convertScaleAbs(m_imgToShow,auxI,255.0/1024);
		//	cv::cvtColor(auxI,imgRGBroi,CV_GRAY2RGB);
		//	auxI.release();
		//}
		//else
		//{
			if(m_imgToShow.type() == CV_8U)//todo: hacer que esto mire si tiene un canal no si es CV_8U
				cv::cvtColor(m_imgToShow, imgRGBroi, CV_GRAY2RGB);
			else
				m_imgToShow.copyTo(imgRGBroi);
		//}
	}

	// Pinto marco blanco para distinguir dónde termina la imagen y ver si el láser se sale de la misma
	cv::rectangle(m_imgRGB, cv::Rect(0,0,m_imgRGB.cols-1,m_imgRGB.rows-1), CV_RGB(255, 255, 255), 3);

	this->setImage((unsigned char*) m_imgRGB.data, m_imgRGB.cols, m_imgRGB.rows, 24, false);

	m_mutex.unlock();

}