#pragma once

#include <QLabel>

class ScaledPixmap : public QWidget {
public:
	ScaledPixmap(QWidget* parent = 0);
	void setScaledPixmap(const QPixmap& pixmap);
protected:
	void paintEvent(QPaintEvent* event);
private:
	QPixmap m_pixmap;
};

