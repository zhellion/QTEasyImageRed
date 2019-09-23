#pragma once


#include "ui_Pff.h"
#include <QFileDialog>
#include <QPicture>
#include <QImage>
#include <QPainter>
#include <QOffscreenSurface>

#include <qopengl.h>
#include <qsurfaceformat.h>
#include <qsurface.h>
#include <qopenglcontext.h>
#include <qopenglshaderprogram.h>
#include <qopenglframebufferobject.h>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>

#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core_c.h>
#include <qtimer.h>
#include "mat_and_qimage.hpp"



class Pff : public QMainWindow
{
	Q_OBJECT

public:
	Pff(QWidget *parent = Q_NULLPTR);

private:
	Ui::PffClass ui;
	
	QImage gimg;
	QImage oimg;
	int h;
	int w;
	float BrightnessModG =0;
	float contrastModG = 1;


	void imageToForm(QImage qimg);
	//QImage* IplImage2QImage(IplImage* iplImg);
	//IplImage* QImage2IplImage(QImage* qimg);
	void writeLog(QString what);
	double timer(std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime);
	QImage ImageNewSettings(QImage qimg, float BrightnessMod, float contrastMod);
	QString filename = "";
	bool fileLoaded = false;


public slots:
	void LoadImg();
	void slider1change(int value);
	void slider2change(int value);
	void changeImage();
	void SaveImage();
	void OGLProcess();

};
