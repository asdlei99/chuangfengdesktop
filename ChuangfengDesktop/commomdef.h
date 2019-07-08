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
struct noPayDetailItem
{
	noPayDetailItem() {
		 id = 0;
		 strTime = "";
		 strSuplier = "";
		 strAdd = "0";
		 strReturn = "0";
		 strAdjust = "0";
		 strPayment = "0";
		 strMake = "";
		 strInitValue = "0";
		 strSurplus = "0";
	}
	int id;
	QString strTime;
	QString strSuplier;
	QString strAdd;
	QString strReturn;
	QString strAdjust;
	QString strPayment;
	QString strMake;
	QString strInitValue;
	QString strSurplus;
};

enum FeedTypeEnum
{
	_enIncomStore = 1,
	_enOutStore,
	_enRenturnStore,
	_enBack
};


struct FeedStoreStruct
{
	int id = 0;
	QString supplier = "";
	QString subject_name = "";
	QString specs = "";
	QString unit = "";
	QString price = "0";
	int number = 0;
};


struct FeedStoreIn_out_return_Struct
{
	int id = 0;
	QString time = "";
	QString subject_name = "";
	int number = 0;
	QString price = "0";
	int surplus = 0;
	QString total = "0";
	QString area = "";

};
struct AreaFeedStoreStruct
{
	int id = 0;
	QString area = "";
	QString specs = "";
	QString unit = "";
	QString supplier = "";
	QString subject_name = "";
	QString price = "0";
	int number = 0;
};

struct AreaFeedFeedingDetailStruct
{
	int id = 0;
	QString time;
	QString area = "";
	QString areaitem = "";
	QString specs = "";
	QString unit = "";
	QString supplier = "";
	QString subject_name = "";
	QString price = "0";
	int number = 0;
};