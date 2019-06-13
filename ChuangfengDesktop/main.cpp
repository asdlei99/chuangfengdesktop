#include "ChuangfengDesktop.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QMessageBox>
#include "LoginQWidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile file("style.css");// 导入UI qss样式
	if (file.open(QFile::ReadOnly))
	{
		QString styleSheet = QLatin1String(file.readAll());
		a.setStyleSheet(styleSheet);
		file.close();
	}
	else  // 引入出错
	{
		QMessageBox::warning(NULL, "warning", "Open failed", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
	LoginQWidget Wnd ;
	Wnd.show();
	
	
	return a.exec();
}
