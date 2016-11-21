#ifndef COMPONENT_1_H
#define COMPONENT_1_H

#include <QDialog>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

#define CM_TITLE_HEIGHT 30					//ԭ���������߶�

#define DEFAULT_BORDER_WIDTH 5				//�߽���
#define DEFAULT_MAGNETIC_OFFSET 20			//����Ч����Χ
#define DEFAULT_ERROR_RANGE 6				//���������Χ
#define DEFAULT_TOOLBAR_WIDTH 80			//��������ToolBar���
#define DEFAULT_STATUS_HEIGHT 29			//��������StatusBar�߶�
enum MousePosition
{
    mpCenter, mpLeft, mpTop, mpRight, mpBottom,
    mpLeftTop, mpLeftBottom, mpRightTop, mpRightBottom
};

namespace Ui {
class Component;
}

class Component : public QWidget
{
    Q_OBJECT

public:
    explicit Component(const int nComponentId, QWidget *parent = 0);
    ~Component();

	/* ����ԭ���ı߽��� */
	void setBorderWidth(int nBorderWidth);

	/* ���ô���ЧӦӰ�췶Χ  */
	void setMagneticOffset(int nMagneticOffset);

	/* ���ô���ЧӦ����������Χ  */
	void setErrorRange(int nErrorRange);

	/* ������������ToolBar���  */
	void setToolBarWidth(int nToolBarWidth);

	/* ������������StatusBar���  */
	void setStatusBarHeight(int nStatusBarHeight);

signals:
	/* ԭ���ر��ź� */
	void onComponentClose(int nMyComponentId);

protected:
	bool event(QEvent* evt);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void paintEvent(QPaintEvent *event);

	/* �������resizeʱ����ʽ */
	void setMouseResizeCursor(const QPoint& pt);

private:
	/* ��ʼ������ */
	inline void initComponent();
	/* ������갴�������������� */
	inline void updateMousePressedData(QMouseEvent *event);
	/* ��������-���ڱ߿� */
	inline void updateDataOnBorder(QMouseEvent *event);
	/* ��������-���ڱ����� */
	inline void updateDataOnTitleBar(QMouseEvent *event);
	/* ������������ƶ������� */
	inline void updateMouseLeftLimit();
	/* ��������ƶ����� */
	inline void limitMouseArea();
	/* ������ק��� */
	inline void resetDragData(QMouseEvent *event);
	/* ��С�߽���ж��봦��---ԭ�� */
	inline void minBoundaryToComponent(const QRect &parentRect, const QRect &bechmarkRect, const QRect &targetRect, QMouseEvent *event);
	/* ��С�߽���ж��봦��---���� */
	inline void minBoundaryToVessel(const QRect &bechmarkRect, const QRect &targetRect, QMouseEvent *event);
	/* �ж���갴��ʱ�����Ƿ��ڱ߿� */
	inline bool mouseOnWinBorder(const QPoint& pt);
	/* �ı�ԭ����С */
	inline void changeSize(QMouseEvent* evt);

	/* ����ı����С��͸� */
	inline QSize calcMinSize(const QSize &sizeHint, const QSize &minSizeHint,
		const QSize &minSize, const QSize &maxSize,
		const QSizePolicy &sizePolicy);

	inline QRect leftBorder() const;
	inline QRect rightBorder() const;
	inline QRect topBorder() const;
	inline QRect bottomBorder() const;

private slots:
	/* �ر�ԭ����ť�� */
	void on_btnClose_clicked();

private:
    Ui::Component *ui;

    int m_nMyComponentId 			;
    int m_nTitleHeight 				;
	int m_nBorderWidth 				;
	int m_nMagneticOffset 			;
	int m_nErrorRange 				;
	int m_nToolBarWidth 			;
	int m_nStatusBarHeight 			;
	int m_nMoveCount 				;
	bool m_bMousePressedInTitle 	;
	bool m_bMousePressedInBorder 	;
	bool m_bHorRelatived 			;
	bool m_bVerRelatived 			;
	bool m_bHorStick_s 				;
	bool m_bVerStick_s 				;
	bool m_bHorStick_c 				;
	bool m_bVerStick_c 				;

	QPoint m_pDragPosition;					// �ڴ��ڱ�����갴��ʱ����Ļ����λ��
	QPoint m_pDragMoveOffset;				// ��¼��갴��ʱ�봰�����½ǵ�ƫ������
	QPoint m_qpMousePressPoint;				// ��갴��ʱ��λ��
	QPoint m_qpDiffPos;						// ����ƶ�ʱ������ƫ������

	QRect m_rParentRect;					// ��������geometry
	QRect m_rMouseLimitRect;				// �����קʱ�����ƶ�������

	QList<Component*> m_lComponent;			// ��ȡ���������е�ԭ����ͼ�б�


    MousePosition m_eMousePos;
};

#endif // COMPONENT_1_H
