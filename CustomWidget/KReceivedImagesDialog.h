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
    Q_OBJECT
public:
    KReceivedImagesDialog(QWidget *parent = nullptr);
    void SetRow(int row, const QString &path);

public slots:
    void UpdateData();

private:
    QTableWidget *m_pTableWidget;
    QList<QCheckBox *> m_pCheckBoxList;
    QList<QString>     m_FilePathList;
};
