#include "Pff.h"

using std::chrono::time_point;
using std::chrono::high_resolution_clock;

Pff::Pff(QWidget *parent)
	: QMainWindow(parent)
{

	
	ui.setupUi(this);
	connect(ui.pushButton, &QAbstractButton::clicked, this, &Pff::LoadImg);
	connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), SLOT(slider1change(int)));
	connect(ui.horizontalSlider_2, SIGNAL(valueChanged(int)), SLOT(slider2change(int)));
	connect(ui.changeImage, &QAbstractButton::clicked, this, &Pff::changeImage);
	connect(ui.saveButton, &QAbstractButton::clicked, this, &Pff::SaveImage);
	connect(ui.pushButton_2, &QAbstractButton::clicked, this, &Pff::OGLProcess);

}

void Pff::LoadImg()
{
	time_point<high_resolution_clock> lastTime = high_resolution_clock::now();
	this->filename = QFileDialog::getOpenFileName(this, "*JPG", "C:\\", "*JPG");
	this->filename.replace("/", "\\");
	ui.lineEdit->setText(filename);
	
	if (filename != "")
	{
		this->fileLoaded = true;
		this->gimg = QImage(filename);
		this->fileLoaded = true;
		this->oimg = this->gimg;

		imageToForm(this->gimg);
		this->h = this->gimg.height();
		this->w = this->gimg.width();
		ui.label->setText(QString::number(this->h));
		ui.label_2->setText(QString::number(this->w));
		ui.label_3->setText("x");
		writeLog("Image loaded (" + QString::number(timer(lastTime)) + " ms)");
	}
	else
	{
		writeLog("Image not loaded (wrong fileName)");
	}
	
	
}
/*IplImage* Pff::QImage2IplImage(QImage* qimg)
{

	IplImage* imgHeader = cvCreateImageHeader(cvSize(qimg->width(), qimg->height()), IPL_DEPTH_8U, 4);
	imgHeader->imageData = (char*)qimg->bits();

	uchar* newdata = (uchar*)malloc(sizeof(uchar) * qimg->byteCount());
	memcpy(&newdata, qimg->bits(), qimg->byteCount());
	
	imgHeader->imageData = (char*)newdata;
	return imgHeader;
}
*/
void Pff::writeLog(QString what)
{
	ui.normalLog->append(what);
}

double Pff::timer(time_point<high_resolution_clock> lastFrameTime)
{
	
	time_point<high_resolution_clock> currentFrameTime = high_resolution_clock::now();
	int64_t delta = std::chrono::duration_cast<std::chrono::microseconds>(currentFrameTime - lastFrameTime).count();

	return (double)delta / 1000;
}

QImage Pff::ImageNewSettings(QImage qimg, float BrightnessMod, float contrastMod)
{
	if (BrightnessMod != 0 || contrastMod!=1)
	{
		time_point<high_resolution_clock> lastTime = high_resolution_clock::now();
		cv::Mat m = ocv::qt::qimage_to_mat_ref(qimg);
	
		
			

			m.convertTo(m, -1, contrastMod, BrightnessMod);//image.convertTo(new_image, -1, alpha, beta); 
		
		
		writeLog("Image change (" + QString::number(timer(lastTime)) + " ms)");
		return ocv::qt::mat_to_qimage_cpy(m);
	}
	else 
	{
		writeLog("image not change");
		return qimg;
	}
}


/*QImage* Pff::IplImage2QImage(IplImage* iplImg)
{
	int h = iplImg->height;
	int w = iplImg->width;
	int channels = iplImg->nChannels;
	QImage* qimg = new QImage(w, h, QImage::Format_ARGB32);
	char* data = iplImg->imageData;

	for (int y = 0; y < h; y++, data += iplImg->widthStep)
	{
		for (int x = 0; x < w; x++)
		{
			char r, g, b, a = 0;
			if (channels == 1)
			{
				r = data[x * channels];
				g = data[x * channels];
				b = data[x * channels];
			}
			else if (channels == 3 || channels == 4)
			{
				r = data[x * channels + 2];
				g = data[x * channels + 1];
				b = data[x * channels];
			}

			if (channels == 4)
			{
				a = data[x * channels + 3];
				qimg->setPixel(x, y, qRgba(r, g, b, a));
			}
			else
			{
				qimg->setPixel(x, y, qRgb(r, g, b));
			}
		}
	}
	return qimg;

}*/


void Pff::imageToForm(QImage qimg)
{
	QPixmap a;
	a.convertFromImage(qimg);
	ui.widget->setScaledPixmap(a);
}

void Pff::slider1change(int value)
{
	ui.SiderCount1->setText(QString::number(value));
	this->BrightnessModG = value;
}

void Pff::slider2change(int value)
{
	float formValue = 0;
	if (value >= 0)
	{
		formValue = 1+ value / 10;
	}
	else
	{
		formValue = 1 + (float)value / 100;
	}

	ui.SiderCount2->setText(QString::number(formValue));
	this->contrastModG = formValue;

}

void Pff::changeImage()
{
	if (this->fileLoaded)
	{
		this->gimg = ImageNewSettings(this->oimg, this->BrightnessModG, this->contrastModG);
		imageToForm(this->gimg);
	}
	else
	{
		writeLog("Not find Image");
	}
		//this->gimg.save("C:\\Users\\1\\Desktop\\img.jpg");

}

void Pff::SaveImage()
{
	if (this->fileLoaded)
	{
		int pointPos = this->filename.indexOf(".");
		QString buffer = filename.mid(pointPos, filename.length() - 1);
		QString saveFileName = filename;
		saveFileName.remove(pointPos, filename.length() - pointPos);
		saveFileName = saveFileName + "_changed" + buffer;

		saveFileName = QFileDialog::getSaveFileName(this, "Save file", saveFileName, "*JPG");
		saveFileName.replace("/", "\\");
		this->gimg.save(saveFileName);
		this->oimg = this->gimg;
		ui.lineEdit->setText(saveFileName);
	}
	else
	{
		writeLog("Not find Image");
	}
}

void Pff::OGLProcess()
{
	
	if (this->fileLoaded)
	{
		if (this->contrastModG != 0 || this->BrightnessModG != 1)
		{

			time_point<high_resolution_clock> lastTime = high_resolution_clock::now();
			QSurfaceFormat format;
			format.setMajorVersion(2);
			format.setMinorVersion(1);
			format.setProfile(QSurfaceFormat::CoreProfile);
			format.setRenderableType(QSurfaceFormat::OpenGL);

			QOpenGLContext context;
			context.setFormat(format);
			if (!context.create())
				qFatal("Cannot create the requested OpenGL context!");

			QOffscreenSurface surface;
			surface.setFormat(format);
			surface.create();
			context.makeCurrent(&surface);


			const QRect drawRect(0, 0, this->oimg.width(), this->oimg.height());
			const QSize drawRectSize = drawRect.size();

			QOpenGLFramebufferObjectFormat fboFormat;
			fboFormat.setSamples(16);
			fboFormat.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);

			QOpenGLFramebufferObject fbo(drawRectSize, fboFormat);
			fbo.bind();

			QOpenGLFunctions* OGLR = new QOpenGLFunctions(&context);

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			GLfloat vertices[] = {
				 1.0f,  1.0f, 0.0f, 1.0, 0.0,
				 1.0f, -1.0f, 0.0f, 1.0, 1.0,
				-1.0f, -1.0f, 0.0f, 0.0, 1.0,
				-1.0f,  1.0f, 0.0f, 0.0, 0.0
			};
			GLuint indices[] = {
				0, 1, 3,
				1, 2, 3
			};

			GLuint VBO;
			OGLR->glGenBuffers(1, &VBO);

			OGLR->glBindBuffer(GL_ARRAY_BUFFER, VBO);
			OGLR->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			GLuint EBO;
			OGLR->glGenBuffers(1, &EBO);


			const char* vertexShaderSource =
				"#version 330 core\n"
				"layout(location = 0) in vec3 position;\n"
				"layout(location = 1) in vec2 texCoord;\n"

				"out vec2 TexCoord;\n"

				"void main()\n"
				"{\n"
				"gl_Position = vec4(position, 1.0f);\n"
				"TexCoord = texCoord;\n"
				"}\n";

			const char* fragmentShaderSource =
				"#version 330 core\n"
				"in vec2 TexCoord;\n"

				"uniform float alpfa;\n"
				"uniform float beta;\n"

				"out vec4 color;\n"

				"uniform sampler2D ourTexture;\n"

				"void main()\n"
				"{\n"
				"vec4 texturev4 = vec4(alpfa * texture(ourTexture, TexCoord).x + beta, alpfa * texture(ourTexture, TexCoord).y + beta, alpfa * texture(ourTexture, TexCoord).z + beta, 1.0);\n"
				"color = texturev4;\n"
				"}\n";

			GLuint vertexShader;
			vertexShader = OGLR->glCreateShader(GL_VERTEX_SHADER);
			OGLR->glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			OGLR->glCompileShader(vertexShader);

			GLuint fragmentShader;
			fragmentShader = OGLR->glCreateShader(GL_FRAGMENT_SHADER);
			OGLR->glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			OGLR->glCompileShader(fragmentShader);

			GLuint shaderProgram;
			shaderProgram = OGLR->glCreateProgram();

			OGLR->glAttachShader(shaderProgram, vertexShader);
			OGLR->glAttachShader(shaderProgram, fragmentShader);
			OGLR->glLinkProgram(shaderProgram);

			OGLR->glUseProgram(shaderProgram);

			OGLR->glDeleteShader(vertexShader);
			OGLR->glDeleteShader(fragmentShader);

			QOpenGLVertexArrayObject* VAO = new QOpenGLVertexArrayObject(&context);
			VAO->create();
			VAO->bind();

			OGLR->glBindBuffer(GL_ARRAY_BUFFER, VBO);
			OGLR->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			OGLR->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			OGLR->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			OGLR->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
			OGLR->glEnableVertexAttribArray(0);
			OGLR->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
			OGLR->glEnableVertexAttribArray(1);


			VAO->release();

			/*GLuint texture;
			OGLR->glGenTextures(1, &texture);
			OGLR->glBindTexture(GL_TEXTURE_2D, texture);
			OGLR->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			OGLR->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);*/





			/*OGLR->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->oimg.width(), this->oimg.height(), 0, GL_RGB, GL_UNSIGNED_BYTE,);
			OGLR->glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);*/




			OGLR->glUniform1f(OGLR->glGetUniformLocation(shaderProgram, "alpfa"), this->contrastModG);

			OGLR->glUniform1f(OGLR->glGetUniformLocation(shaderProgram, "beta"), this->BrightnessModG / 255);

			//---------------------------
			//OGLR->glBindTexture(GL_TEXTURE_2D, texture);
			QOpenGLTexture* texture = new QOpenGLTexture(this->oimg);
			texture->bind();
			VAO->bind();



			OGLR->glViewport(0, 0, this->oimg.width(), this->oimg.height());

			OGLR->glUseProgram(shaderProgram);

			OGLR->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			VAO->release();


			this->gimg = fbo.toImage();
			imageToForm(this->gimg);
			writeLog("Image change (" + QString::number(timer(lastTime)) + " ms)");
		}
		else
		{
			writeLog("image not change");
		}
	}
	else
	{
	writeLog("Not find Image");
	}
	
}
