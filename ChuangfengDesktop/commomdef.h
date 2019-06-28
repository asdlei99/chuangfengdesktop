#pragma once
#define  ICONSIZE   26
#define  ICONFONTSIZE   15
#define  PIXMAPSIZE   30
#define  ICOSPACE   15

struct DetailItemStruct
{
	DetailItemStruct() {
		id = 0;
		strTime = "";
		strRemake = "";
		strTaskName = "";
		strIncome = "";
		strPay = "";
		strSurpls = "";
		strCostArea = "";
	}
	int id;
	QString  strTime;
	QString  strRemake;
	QString  strTaskName;
	QString	 strIncome;
	QString  strPay;
	QString  strSurpls;
	QString	 strCostArea;

};