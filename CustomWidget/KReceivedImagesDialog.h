#pragma once

#include <QWidget>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QList>
#include <QTimer>
#include <QSet>

class KReceivedImagesDialog : public QDialog
{
    Q_OBJECT
public:
    KReceivedImagesDialog(QWidget *parent = nullptr);
    void SetRow(int row);

public slots:
    void UpdateData();
    void CheckNewData();
private:
    QTableWidget *m_pTableWidget;
    QList<QCheckBox *> m_pCheckBoxList;
    QList<QString>     m_FilePathList;
    QTimer             m_Timer;
    QSet<QString>      m_FileNameSet;
    QString m_Path ;
};
