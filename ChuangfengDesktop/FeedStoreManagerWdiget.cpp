#include "FeedStoreManagerWdiget.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>
#include <QPainter>
#include <QPen>
#include <QtMath>
#include "iconhelper.h"
#include "commomdef.h"



FeedStoreManagerWdiget::FeedStoreManagerWdiget(QWidget *parent)
	:MoveableFramelessWindow(parent)
	, ui(new Ui::FeedStore)
{
	ui->setupUi(this);
	connect(ui->feedstore_cose_btn, &QPushButton::clicked, this, &QWidget::close);
	connect(ui->feedstore_max_restore_btn, &QPushButton::clicked, this, &FeedStoreManagerWdiget::updateMaximize);
	connect(ui->feedstore_min_btn, &QPushButton::clicked, this, &QWidget::showMinimized);
	ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
	//���ð�ť��������Ϊ"maximizeProperty"
	ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
	ui->feedstore_max_restore_btn->setStyle(QApplication::style());

	m_NavButtonList << ui->feedstore_detail_opt << ui->feedstore_in_out_opt  
		<<ui->area_detail_opt<< ui->area_in_out_opt;
	QList<QChar> pixChar;
	pixChar << 0xf509 << 0xf1fe << 0xf2a3 << 0xf1fe ;
	QColor normalBgColor = QColor("#364E6F");
	QColor hoverBgColor = QColor("#478CB6");
	QColor checkBgColor = QColor("#478CB6");
	QColor normalTextColor = QColor("#FFFFFF");
	QColor hoverTextColor = QColor("#FFFFFF");
	QColor checkTextColor = QColor("#FFFFFF");

	for (int i = 0; i < m_NavButtonList.count(); i++) {

		m_NavButtonList.at(i)->setLineColor(QColor("#029FEA"));
		///mNavButtonList.at(i)->setShowLine(true);
		m_NavButtonList.at(i)->setTextAlign(NavButton::TextAlign_Left);
		m_NavButtonList.at(i)->setTrianglePosition(NavButton::TrianglePosition_Right);
		//mNavButtonList.at(i)->setLinePosition(NavButton::LinePosition_Top);

		m_NavButtonList.at(i)->setPaddingLeft(5);
		m_NavButtonList.at(i)->setLineSpace(1);
		m_NavButtonList.at(i)->setLineWidth(5);
		m_NavButtonList.at(i)->setLineColor(QColor(255, 107, 107));
		m_NavButtonList.at(i)->setShowTriangle(true);

		m_NavButtonList.at(i)->setShowIcon(true);
		m_NavButtonList.at(i)->setIconSpace(ICOSPACE);
		m_NavButtonList.at(i)->setIconSize(QSize(ICONSIZE, ICONSIZE));

		//�ֿ�����ͼ��
		QChar icon = pixChar.at(i);
		QPixmap iconNormal = IconHelper::Instance()->getPixmap(normalTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconHover = IconHelper::Instance()->getPixmap(hoverTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);
		QPixmap iconCheck = IconHelper::Instance()->getPixmap(checkTextColor.name(), icon, ICONFONTSIZE, PIXMAPSIZE, PIXMAPSIZE);

		m_NavButtonList.at(i)->setIconNormal(iconNormal);
		m_NavButtonList.at(i)->setIconHover(iconHover);
		m_NavButtonList.at(i)->setIconCheck(iconCheck);

		m_NavButtonList.at(i)->setNormalBgColor(normalBgColor);
		m_NavButtonList.at(i)->setHoverBgColor(hoverBgColor);
		m_NavButtonList.at(i)->setCheckBgColor(checkBgColor);
		m_NavButtonList.at(i)->setNormalTextColor(normalTextColor);
		m_NavButtonList.at(i)->setHoverTextColor(hoverTextColor);
		m_NavButtonList.at(i)->setCheckTextColor(checkTextColor);

		connect(m_NavButtonList.at(i), &QPushButton::clicked, this, &FeedStoreManagerWdiget::SlotOptionClick);
	}
	m_NavButtonList.at(0)->setChecked(true);
}


FeedStoreManagerWdiget::~FeedStoreManagerWdiget()
{
}

void FeedStoreManagerWdiget::updateMaximize()
{
	QWidget *pWindow = this->window(); //��ñ��������ڵĴ���
	pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();  //�������/��ԭ��ʾ
	if (pWindow->isTopLevel())
	{
		bool bMaximize = pWindow->isMaximized(); //�жϴ����ǲ������״̬�����򷵻�true�����򷵻�false
		if (bMaximize)
		{
			//Ŀǰ���������״̬�������/��ԭ��toolTip����Ϊ"Restore"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("��ԭ"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "restore");
		}
		else
		{
			//Ŀǰ�����ǻ�ԭ״̬�������/��ԭ��toolTip����Ϊ"Maximize"
			ui->feedstore_max_restore_btn->setToolTip(QString::fromLocal8Bit("���"));
			//���ð�ť��������Ϊ"maximizeProperty"
			ui->feedstore_max_restore_btn->setProperty("maximizeProperty", "maximize");
		}

		ui->feedstore_max_restore_btn->setStyle(QApplication::style());
	}
}

void FeedStoreManagerWdiget::SlotOptionClick()
{
	NavButton *btn = (NavButton *)sender();
	for (int i = 0; i < m_NavButtonList.count(); i++) {
		if (m_NavButtonList.at(i) == btn)
		{
			ui->feedstore_stackedWidget->setCurrentIndex(i);
			m_NavButtonList.at(i)->setChecked(true);
		}
		else {
			m_NavButtonList.at(i)->setChecked(false);
		}
	}
}

void FeedStoreManagerWdiget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event); //û��ʵ���Ե����ã�ֻ����������event���Բ�ʹ�ã������������������
	emit ui->feedstore_max_restore_btn->clicked();
}

void FeedStoreManagerWdiget::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(0, 0, this->width(), 40);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(QColor(41, 57, 85)));
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(0, 40, this->width(), this->height());
		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);
		//painter.fillPath(path, QBrush(QColor(68, 71, 77)));
		painter.fillPath(path, QBrush(QColor(54, 78, 111)));
	}
}

QWidget* FeedStoreManagerWdiget::getDragnWidget()
{
	return ui->child_widget_title;
}
