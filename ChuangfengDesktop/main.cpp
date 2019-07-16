#include "yaolog.h"
#include "ChuangfengDesktop.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QMessageBox>
#include "LoginQWidget.h"
#include "commomdef.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::string logConfig = "./logconfig.ini";

	YAOLOG_INIT;
	YAOLOG_CREATE(APP, true, YaoUtil::LOG_TYPE_TEXT);
	YAOLOG_CREATE(NET, true, YaoUtil::LOG_TYPE_TEXT);
	YAOLOG_CREATE(DEBG, true, YaoUtil::LOG_TYPE_TEXT);
	YAOLOG_CREATE(ERR, true, YaoUtil::LOG_TYPE_TEXT);
	YAOLOG_CREATE(SOCK, true, YaoUtil::LOG_TYPE_FORMATTED_BIN);

	YAOLOG_SET_ATTR_FROM_CONFIG_FILE(APP, logConfig.c_str());
	YAOLOG_SET_ATTR_FROM_CONFIG_FILE(NET, logConfig.c_str());
	YAOLOG_SET_ATTR_FROM_CONFIG_FILE(DEBG, logConfig.c_str());
	YAOLOG_SET_ATTR_FROM_CONFIG_FILE(ERR, logConfig.c_str());
	YAOLOG_SET_ATTR_FROM_CONFIG_FILE(SOCK, logConfig.c_str());
	

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
