#pragma once
#ifndef NAVBUTTON_H
#define NAVBUTTON_H

/**
 * ������ť�ؼ� ����:feiyangqingyun(QQ:517216493) 2017-12-19
 * 1:���������ֵ����+�Ҳ�+����+�ײ����
 * 2:���������ֶ��뷽ʽ
 * 3:��������ʾ������/�����Ǳ߳�/������λ��/��������ɫ
 * 4:��������ʾͼ��/ͼ����/ͼ��ߴ�/����״̬ͼ��/��ͣ״̬ͼ��/ѡ��״̬ͼ��
 * 5:��������ʾ�߿�����/�������/�������/����λ��/������ɫ
 * 6:����������������ɫ/��ͣ������ɫ/ѡ�б�����ɫ
 * 7:����������������ɫ/��ͣ������ɫ/ѡ��������ɫ
 * 8:�����ñ�����ɫΪ��ˢ��ɫ
 * 9:������ͼ���λ�����+�Ҳ�+����+�ײ�
 */

#include <QPushButton>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT NavButton : public QPushButton
#else
class NavButton : public QPushButton
#endif

{
	Q_OBJECT
		Q_ENUMS(TextAlign)
		Q_ENUMS(TrianglePosition)
		Q_ENUMS(LinePosition)
		Q_ENUMS(IconPosition)

		Q_PROPERTY(int paddingLeft READ getPaddingLeft WRITE setPaddingLeft)
		Q_PROPERTY(int paddingRight READ getPaddingRight WRITE setPaddingRight)
		Q_PROPERTY(int paddingTop READ getPaddingTop WRITE setPaddingTop)
		Q_PROPERTY(int paddingBottom READ getPaddingBottom WRITE setPaddingBottom)
		Q_PROPERTY(TextAlign textAlign READ getTextAlign WRITE setTextAlign)


		Q_PROPERTY(int iconPaddingLeft READ getIconPaddingLeft WRITE setIconLeftPadding)
		Q_PROPERTY(int iconPaddingRight READ getIconPaddingRight WRITE setIconRightPadding)
		Q_PROPERTY(int iconPaddingTop READ getIconPaddingTop WRITE setIconTopPadding)
		Q_PROPERTY(int iconPaddingBottom READ getIconPaddingBottom WRITE setIconBottomPadding)
		Q_PROPERTY(IconPosition iconPosition READ getIconPos WRITE setIconPosition)

		Q_PROPERTY(bool showTriangle READ getShowTriangle WRITE setShowTriangle)
		Q_PROPERTY(int triangleLen READ getTriangleLen WRITE setTriangleLen)
		Q_PROPERTY(TrianglePosition trianglePosition READ getTrianglePosition WRITE setTrianglePosition)
		Q_PROPERTY(QColor triangleColor READ getTriangleColor WRITE setTriangleColor)

		Q_PROPERTY(bool showIcon READ getShowIcon WRITE setShowIcon)
		Q_PROPERTY(int iconSpace READ getIconSpace WRITE setIconSpace)
		Q_PROPERTY(QSize iconSize READ getIconSize WRITE setIconSize)
		Q_PROPERTY(QPixmap iconNormal READ getIconNormal WRITE setIconNormal)
		Q_PROPERTY(QPixmap iconHover READ getIconHover WRITE setIconHover)
		Q_PROPERTY(QPixmap iconCheck READ getIconCheck WRITE setIconCheck)

		Q_PROPERTY(bool showLine READ getShowLine WRITE setShowLine)
		Q_PROPERTY(int lineSpace READ getLineSpace WRITE setLineSpace)
		Q_PROPERTY(int lineWidth READ getLineWidth WRITE setLineWidth)
		Q_PROPERTY(LinePosition linePosition READ getLinePosition WRITE setLinePosition)
		Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor)

		Q_PROPERTY(QColor normalBgColor READ getNormalBgColor WRITE setNormalBgColor)
		Q_PROPERTY(QColor hoverBgColor READ getHoverBgColor WRITE setHoverBgColor)
		Q_PROPERTY(QColor checkBgColor READ getCheckBgColor WRITE setCheckBgColor)
		Q_PROPERTY(QColor normalTextColor READ getNormalTextColor WRITE setNormalTextColor)
		Q_PROPERTY(QColor hoverTextColor READ getHoverTextColor WRITE setHoverTextColor)
		Q_PROPERTY(QColor checkTextColor READ getCheckTextColor WRITE setCheckTextColor)

public:
	enum TextAlign {
		TextAlign_Left = 0x0001,    //������
		TextAlign_Right = 0x0002,   //�Ҳ����
		TextAlign_Top = 0x0020,     //��������
		TextAlign_Bottom = 0x0040,  //�ײ�����
		TextAlign_Center = 0x0004   //���ж���
	};

	enum TrianglePosition {
		TrianglePosition_Left = 0,  //���
		TrianglePosition_Right = 1, //�Ҳ�
		TrianglePosition_Top = 2,   //����
		TrianglePosition_Bottom = 3 //�ײ�
	};

	enum IconPosition {
		IconPosition_Left = 0,      //���
		IconPosition_Right = 1,     //�Ҳ�
		IconPosition_Top = 2,       //����
		IconPosition_Bottom = 3     //�ײ�
	};

	enum LinePosition {
		LinePosition_Left = 0,      //���
		LinePosition_Right = 1,     //�Ҳ�
		LinePosition_Top = 2,       //����
		LinePosition_Bottom = 3     //�ײ�
	};

	explicit NavButton(QWidget *parent = 0);

protected:
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void paintEvent(QPaintEvent *);
	void drawBg(QPainter *painter);
	void drawText(QPainter *painter);
	void drawIcon(QPainter *painter);
	void drawLine(QPainter *painter);
	void drawTriangle(QPainter *painter);

private:
	int paddingLeft;                    //���������
	int paddingRight;                   //�����Ҳ���
	int paddingTop;                     //���ֶ������
	int paddingBottom;                  //���ֵײ����
	TextAlign textAlign;                //���ֶ���

	bool showTriangle;                  //��ʾ������
	int triangleLen;                    //�����Ǳ߳�
	TrianglePosition trianglePosition;  //������λ��
	QColor triangleColor;               //��������ɫ

	bool showIcon;                      //��ʾͼ��
	int iconSpace;                      //ͼ����
	QSize iconSize;                     //ͼ��ߴ�
	QPixmap iconNormal;                 //����ͼ��
	QPixmap iconHover;                  //��ͣͼ��
	QPixmap iconCheck;                  //ѡ��ͼ��
	int iconPaddingLeft;                //ͼ�������
	int iconPaddingRight;               //ͼ���Ҳ���
	int iconPaddingTop;                 //ͼ�궥�����
	int iconPaddingBottom;              //ͼ��ײ����
	IconPosition iconPosition;          //ͼ��λ��

	bool showLine;                      //��ʾ����
	int lineSpace;                      //�������
	int lineWidth;                      //�������
	LinePosition linePosition;          //����λ��
	QColor lineColor;                   //������ɫ

	QColor normalBgColor;               //����������ɫ
	QColor hoverBgColor;                //��ͣ������ɫ
	QColor checkBgColor;                //ѡ�б�����ɫ
	QColor normalTextColor;             //����������ɫ
	QColor hoverTextColor;              //��ͣ������ɫ
	QColor checkTextColor;              //ѡ��������ɫ

	QBrush normalBgBrush;               //����������ˢ
	QBrush hoverBgBrush;                //��ͣ������ˢ
	QBrush checkBgBrush;                //ѡ�б�����ˢ

	bool hover;                         //��ͣ��־λ

public:
	int getPaddingLeft()                const;
	int getPaddingRight()               const;
	int getPaddingTop()                 const;
	int getPaddingBottom()              const;
	TextAlign getTextAlign()            const;

	bool getShowTriangle()              const;
	int getTriangleLen()                const;
	TrianglePosition getTrianglePosition()const;
	QColor getTriangleColor()           const;

	bool getShowIcon()                  const;
	int getIconSpace()                  const;
	QSize getIconSize()                 const;
	QPixmap getIconNormal()             const;
	QPixmap getIconHover()              const;
	QPixmap getIconCheck()              const;
	int getIconPaddingLeft()            const;
	int getIconPaddingRight()           const;
	int getIconPaddingTop()             const;
	int getIconPaddingBottom()          const;
	IconPosition getIconPos()           const;

	bool getShowLine()                  const;
	int getLineSpace()                  const;
	int getLineWidth()                  const;
	LinePosition getLinePosition()      const;
	QColor getLineColor()               const;

	QColor getNormalBgColor()           const;
	QColor getHoverBgColor()            const;
	QColor getCheckBgColor()            const;
	QColor getNormalTextColor()         const;
	QColor getHoverTextColor()          const;
	QColor getCheckTextColor()          const;

	QSize sizeHint()                    const;
	QSize minimumSizeHint()             const;

public Q_SLOTS:
	//�������ּ��
	void setPaddingLeft(int paddingLeft);
	void setPaddingRight(int paddingRight);
	void setPaddingTop(int paddingTop);
	void setPaddingBottom(int paddingBottom);
	void setPadding(int padding);
	void setPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom);

	//����ͼƬ���
	void setIconLeftPadding(int paddingLeft);
	void setIconRightPadding(int paddingRight);
	void setIconTopPadding(int paddingTop);
	void setIconBottomPadding(int paddingBottom);
	void setIconPadding(int padding);
	void setIconPadding(int paddingLeft, int paddingRight, int paddingTop, int paddingBottom);

	//�������ֶ���
	void setTextAlign(const TextAlign &textAlign);

	//������ʾ������
	void setShowTriangle(bool showTriangle);
	//���õ����Ǳ߳�
	void setTriangleLen(int triangleLen);
	//���õ�����λ��
	void setTrianglePosition(const TrianglePosition &trianglePosition);
	//���õ�������ɫ
	void setTriangleColor(const QColor &triangleColor);

	//������ʾͼ��
	void setShowIcon(bool showIcon);
	//����ͼ����
	void setIconSpace(int iconSpace);
	//����ͼ��ߴ�
	void setIconSize(const QSize &iconSize);
	//��������ͼ��
	void setIconNormal(const QPixmap &iconNormal);
	//������ͣͼ��
	void setIconHover(const QPixmap &iconHover);
	//���ð���ͼ��
	void setIconCheck(const QPixmap &iconCheck);
	//����ͼ��λ��
	void setIconPosition(const IconPosition &iconPos);

	//������ʾ����
	void setShowLine(bool showLine);
	//�����������
	void setLineSpace(int lineSpace);
	//�����������
	void setLineWidth(int lineWidth);
	//��������λ��
	void setLinePosition(const LinePosition &linePosition);
	//����������ɫ
	void setLineColor(const QColor &lineColor);

	//��������������ɫ
	void setNormalBgColor(const QColor &normalBgColor);
	//������ͣ������ɫ
	void setHoverBgColor(const QColor &hoverBgColor);
	//����ѡ�б�����ɫ
	void setCheckBgColor(const QColor &checkBgColor);

	//��������������ɫ
	void setNormalTextColor(const QColor &normalTextColor);
	//������ͣ������ɫ
	void setHoverTextColor(const QColor &hoverTextColor);
	//����ѡ��������ɫ
	void setCheckTextColor(const QColor &checkTextColor);

	//��������������ˢ
	void setNormalBgBrush(const QBrush &normalBgBrush);
	//������ͣ������ˢ
	void setHoverBgBrush(const QBrush &hoverBgBrush);
	//����ѡ�б�����ˢ
	void setCheckBgBrush(const QBrush &checkBgBrush);

};

#endif // NAVBUTTON_H


