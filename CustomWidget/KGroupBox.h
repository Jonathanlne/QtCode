#pragma once

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>

class KVGroupBox;
class KGroupBox : public QWidget
{
public:
    KGroupBox(const QString &title, QWidget *parent = nullptr);
    void AddWidget(int colomn, QWidget *pWidget);

private:
    QVBoxLayout *m_pLayout;
    QVBoxLayout *m_pBaseContentLayout;
    QVBoxLayout *m_pAdditionalContentLayout;
    KVGroupBox *m_pCentralWidget;
};

