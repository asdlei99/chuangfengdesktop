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
	QString type = "À«¡œ";
	int number = 0;
};

#define LONGINURL					"http://%1:%2/zerg/public/index.php/login"
#define INCOMEFEEDSTORE				"http://%1:%2/zerg/public/index.php/InComFeedStore"
#define INSERTMATERIAL				"http://%1:%2/zerg/public/index.php/InsertMaterial"
#define SEARCHFEEDINGTOREPORT		"http://%1:%2/zerg/public/index.php/SerachFeedingToReport"
#define GETUSERLIST					"http://%1:%2/zerg/public/index.php/getUserList"
#define SearchOutFeedStoreByReport	"http://%1:%2/zerg/public/index.php/SearchOutFeedStoreByReport"

#define addAquaculture				"http://%1:%2/zerg/public/index.php/addAquaculture"
#define getFixedUsetoReport			 "http://%1:%2/zerg/public/index.php/getFixedUsetoReport"
#define SearchOutMaterialByReport	 "http://%1:%2/zerg/public/index.php/SearchOutMaterialByReport"
#define getFixedUsetoReport			"http://%1:%2/zerg/public/index.php/getFixedUsetoReport"
#define SearchFixedAsset			"http://%1:%2/zerg/public/index.php/SearchFixedAsset"
#define getDuesList					"http://%1:%2/zerg/public/index.php/getDuesList"
#define getDuesDetail			  "http://%1:%2/zerg/public/index.php/getDuesDetail"
#define getBakDetail			 "http://%1:%2/zerg/public/index.php/getBakDetail"

#define SearchFeedStore				"http://%1:%2/zerg/public/index.php/SearchFeedStore"
#define SearchBackFeedStore			 "http://%1:%2/zerg/public/index.php/SearchBackFeedStore"
#define SearchInComFeedStore		"http://%1:%2/zerg/public/index.php/SearchInComFeedStore"
#define SearchReturnfeedstoreToReport	"http://%1:%2/zerg/public/index.php/SearchReturnfeedstoreToReport"
#define SerachFeedingAll				"http://%1:%2/zerg/public/index.php/SerachFeedingAll"
#define addbak							"http://%1:%2/zerg/public/index.php/addbak"
#define insertTaskItem					"http://%1:%2/zerg/public/index.php/insertTaskItem"
#define getTaskItem						"http://%1:%2/zerg/public/index.php/getTaskItem"
#define getAquaculturearea				"http://%1:%2/zerg/public/index.php/getAquaculturearea"
#define addAquacultureareaDetail		"http://%1:%2/zerg/public/index.php/addAquacultureareaDetail"
#define addFeeding						"http://%1:%2/zerg/public/index.php/addFeeding"
#define SerachFeeding					"http://%1:%2/zerg/public/index.php/SerachFeeding"
#define SearchAreaFeedStore				"http://%1:%2/zerg/public/index.php/SearchAreaFeedStore"
#define OutComFeedStore					"http://%1:%2/zerg/public/index.php/OutComFeedStore"
#define BackFeedStore					"http://%1:%2/zerg/public/index.php/BackFeedStore"
#define ReturnFeedStore					"http://%1:%2/zerg/public/index.php/ReturnFeedStore"
#define SearchOutFeedStore				"http://%1:%2/zerg/public/index.php/SearchOutFeedStore"
#define SearchReturnFeedStore			 "http://%1:%2/zerg/public/index.php/SearchReturnFeedStore"
#define InComFeedStore					"http://%1:%2/zerg/public/index.php/InComFeedStore"
#define getGeneralDetail				"http://%1:%2/zerg/public/index.php/getGeneralDetail"
#define addGeneral						"http://%1:%2/zerg/public/index.php/addGeneral"
#define SearchInMaterialDetail			"http://%1:%2/zerg/public/index.php/SearchInMaterialDetail"
#define SearchOutMaterialDetail			"http://%1:%2/zerg/public/index.php/SearchOutMaterialDetail"
#define OutMaterial							"http://%1:%2/zerg/public/index.php/OutMaterial"
#define SerachMaterial					"http://%1:%2/zerg/public/index.php/SerachMaterial"
#define InsertMaterial					"http://%1:%2/zerg/public/index.php/InsertMaterial"
#define addDue							"http://%1:%2/zerg/public/index.php/addDue"
#define getDuesDetail					"http://%1:%2/zerg/public/index.php/getDuesDetail"
#define addCostareas					"http://%1:%2/zerg/public/index.php/addCostareas"
#define getCostareas					"http://%1:%2/zerg/public/index.php/getCostareas"
#define addSupplier						"http://%1:%2/zerg/public/index.php/addSupplier"
#define getSupplier						"http://%1:%2/zerg/public/index.php/getSupplier"
#define adduser							"http://%1:%2/zerg/public/index.php/adduser"

