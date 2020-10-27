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

class KReceivedImagesDialog : public QDialog
{
public:
    KReceivedImagesDialog(QWidget *parent = nullptr);
    void UpdateData();
    void SetRow(int row, const QString &path);
private:
    QTableWidget *m_pTableWidget;
    QList<QCheckBox *> m_pCheckBoxList;
    QList<QString>     m_FilePathList;
};
