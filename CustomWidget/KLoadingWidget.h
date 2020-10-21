#pragma once

#include <QDialog>
#include <QWidget>
#include <QPointF>
#include <QList>
#include <QTimer>
class QPushButton;

class KLoadingWidget : public QDialog
{
    Q_OBJECT
public:
    KLoadingWidget(QWidget *parent = nullptr);
public slots:
signals:
    void CancelSignal();
protected:
    void showEvent(QShowEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    QPushButton *m_pCancelButton;
    QList<QPointF> m_Points;
    QList<int>     m_PointSizes;
    QTimer         m_Timer;
};
