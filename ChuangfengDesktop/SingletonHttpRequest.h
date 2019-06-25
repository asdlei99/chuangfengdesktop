#pragma once
#include <QObject>


class SingletonHttpRequest:public QObject
{
	Q_OBJECT
private:
	static  SingletonHttpRequest* m_instance;
	SingletonHttpRequest() {}
public:
	static  SingletonHttpRequest* getInstance()
	{
		return m_instance;
	}
public:
	void RequestGet(const QString&strUrl,const QString&strToken, QByteArray&retBuf);
	void RequestPost(const QString&strUrl, const QString&strToken, const QString&strParam, QByteArray&retBuf);
};



