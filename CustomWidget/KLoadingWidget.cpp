#include "KLoadingWidget.h"
#include <QPushButton>
#include <QPainter>
#include <QColor>
#include <QtMath>

#define NUMBER_OF_POINT  (10)

KLoadingWidget::KLoadingWidget(QWidget *parent):
    QDialog(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setMinimumSize(300, 300);
    m_pCancelButton = new QPushButton("取消",this);
    connect(m_pCancelButton, &QPushButton::pressed, [=](){
        this->close();
        emit CancelSignal();
    });
    for(int i = 1;  i <= NUMBER_OF_POINT; i++)
    {
        double R = width() * 0.3;
        double radian = 360.0 / NUMBER_OF_POINT * i;
        double dx = R * qCos(qDegreesToRadians(radian));
        double dy = R * qSin(qDegreesToRadians(radian));
        m_Points.append(QPointF(width() / 2 + dx, height() / 2 + dy));
        m_PointSizes.append(i + 2);
    }
    connect(&m_Timer, &QTimer::timeout, [=](){
        repaint();
    });
    m_Timer.start(300);
}

void KLoadingWidget::showEvent(QShowEvent *event)
{

    int iPosX = 0;
    int iPosY = 0;
    QWidget *pWidget = parentWidget();

    if(pWidget != nullptr)
    {
        iPosX += pWidget->width() / 2 - width();
        iPosY += pWidget->height() / 2 - width();

    }

    while(pWidget != nullptr)
    {
        iPosX += pWidget->x();
        iPosY += pWidget->y();
        pWidget = pWidget->parentWidget();
    }
    m_pCancelButton->move(width() / 2 - m_pCancelButton->width() / 2 ,
                          height() - m_pCancelButton->height() - 10);

    QDialog::showEvent(event);
}

void KLoadingWidget::paintEvent(QPaintEvent *event)
{
    static int offset = 0;
    QPainter painter(this);
    painter.setPen(QColor(49, 177, 190));
    painter.setBrush(QColor(49, 177, 190));
    painter.setRenderHint(QPainter::Antialiasing);
    for(int i = 0; i < m_Points.size(); i++)
    {
        painter.drawEllipse(m_Points[(i + offset) % NUMBER_OF_POINT], m_PointSizes[i], m_PointSizes[i]);
    }
    offset = (offset + 1) % NUMBER_OF_POINT;
    QDialog::paintEvent(event);
}
