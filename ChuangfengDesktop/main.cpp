#include "ChuangfengDesktop.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QMessageBox>
#include "LoginQWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile file("style.css");// ����UI qss��ʽ
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());
		a.setStyleSheet(styleSheet);
		file.close();
	}
	else  // �������
	{
		QMessageBox::warning(NULL, "warning", "Open failed", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	LoginQWidget Wnd ;
	Wnd.show();
	
	
	return a.exec();
}
