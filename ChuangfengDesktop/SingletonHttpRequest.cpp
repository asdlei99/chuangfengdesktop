#include "SingletonHttpRequest.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QTextCodec>


//外部初始化 before invoke main

 SingletonHttpRequest* SingletonHttpRequest::m_instance = new SingletonHttpRequest;

void SingletonHttpRequest::RequestGet(const QString&strUrl, const QString&strToken, QByteArray&retBuf)
{
	QNetworkRequest request;
	QNetworkAccessManager* pNetManager = new QNetworkAccessManager(this);

	request.setUrl(QUrl(strUrl));
	request.setRawHeader("token", strToken.toLocal8Bit());

	QNetworkReply *reply = pNetManager->get(request);

	QEventLoop eventLoop;
	connect(pNetManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	retBuf = reply->readAll();
	delete pNetManager;
	pNetManager = nullptr;
}

void SingletonHttpRequest::RequestPost(const QString&strUrl, const QString&strToken, const QString&strParam, QByteArray&retBuf)
{
	QNetworkRequest request;
	QNetworkAccessManager* pNetManager = new QNetworkAccessManager(this);

	request.setUrl(QUrl(strUrl));
	request.setRawHeader("token", strToken.toLocal8Bit());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	QByteArray encodedString = QTextCodec::codecForName("UTF-8")->fromUnicode(strParam);
	QNetworkReply *reply = pNetManager->post(request, encodedString);
	QEventLoop eventLoop;
	connect(pNetManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();       //block until finish
	retBuf = reply->readAll();
	delete pNetManager;
	pNetManager = nullptr;
}
