#ifndef QTImageMANAGER_H
#define QTImageMANAGER_H

//#include <Qt/qgl.h>
//#include <Qt/Qstring.h>
//#include <QtGui/QMouseEvent>
//#include <QFile>
//#include <QApplication>
//#include <QtGui>
//#include <QtCore> 
//#include <QCoreApplication>
//#include <QApplication>
//#include <QtGui>
#include <QApplication>
#include <QtGui>
#include <QtCore> 

#include <opencv2\opencv.hpp>
#include <QtOpenGL/QGLWidget>
//#include "cv.h"
//#include "highgui.h"
//#include "imgproc.hpp"
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#ifndef GL_BGR_EXT
#define GL_BGR_EXT 0x80e0
#endif

#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80e1
#endif

typedef std::vector<IplImage*> vectorIplImages;

class CQtImageManager : public QGLWidget
{
	
	Q_OBJECT
	
public:

	//***********************METODOS****************************/
	CQtImageManager(QWidget* parent = 0, const QGLWidget* sharedWidget = 0, Qt::WindowFlags f = 0 );
	~CQtImageManager(void);
	
	// Set image parameters
	bool setImage(
		unsigned char* imgP, 
		const int width, 
		const int height, 
		const int pixeldepth,
		const bool flipped = false);
		
signals:
	void updateViewGL(void);
	
public slots:
	
	// Hace un Set de la imagen a visualizar
	void setVisualicedImage(cv::Mat img);


	// Para resetear la matriz de GL_PROJECTION
	void resetGL_PROJECTIONMatrix(void);
	
	// Bucle para capturar y visualizar Image en tiempo real en la gui
	void videoLoop(void);

protected:

	// standard qt methods
	void paintGL();
	void resizeGL(int w, int h);
	void initializeGL();

	// internal draw method
	void drawTexture(float ul, float ur, float ll, float lr);

	// helper method
	unsigned int NextLargerPowerOfTwo(unsigned int n);

	//*********************ATRIBUTOS****************************/
protected:

	// Mutex para proteger accesos desde multiples threads
	QMutex m_mutex;

	// Imagen RGB mostrada
	cv::Mat m_imgRGB;

	//Imagen a mostrar
	cv::Mat m_imgToShow;


	// pointer to the data of the displayed image
	unsigned char* m_imgP;
	// image parameters
	unsigned int m_width, m_height, m_pixeldepth;
	// if set to true image will be flipped horizontally
	bool m_flipped;
	// width of the texture buffer
	unsigned int m_texWidth;
	// height of the texture buffer
	unsigned int m_texHeight;
	// texture identifier
	unsigned int m_texNameGL;
	// clipping rectangle for texture
	float m_texUpperLeftX, m_texUpperLeftY, m_texLowerRightX, m_texLowerRightY;

};


#endif // _QTImageMANAGER_H