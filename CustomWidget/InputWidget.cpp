#include "InputWidget.h"

#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QList>
const int DEFAULT_WIDTH     = 300;
const int DEFAULT_HEIGHT    = 30;
const int DEFAULT_FONT_SIZE = 12;

InputWidget::InputWidget(const QString &tItemName, const InputType &type,
                         QWidget *parent):
    QWidget(parent),
    m_pLineEdit(nullptr),
    m_pDateEdit(nullptr),
    m_FontSize(DEFAULT_FONT_SIZE)
{
    m_pLayout = new QHBoxLayout(this);


    m_pItemName = new QLabel(tItemName);
    m_pItemName->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

    const int ITEM_NAME_WEIGHT = 1;
    m_pLayout->addWidget(m_pItemName, ITEM_NAME_WEIGHT);
    if(type == Text)
    {
        m_pLineEdit = new QLineEdit();
        m_pLineEdit->setMinimumWidth(DEFAULT_WIDTH);
        m_pLayout->addWidget(m_pLineEdit);
        m_InputList.append(m_pLineEdit);
    }
    else
    {
        m_pDateEdit = new QDateEdit();
        m_pDateEdit->setDate(QDate::currentDate());
        m_pDateEdit->setCalendarPopup(true);
        m_pDateEdit->setAlignment(Qt::AlignCenter);
        m_pDateEdit->setCalendarWidget(new QCalendarWidget());
        m_pDateEdit->setMinimumWidth(DEFAULT_WIDTH);
        m_pLayout->addWidget(m_pDateEdit);
    }

    //SetInputWidth(DEFAULT_WIDTH);
    SetHeight(DEFAULT_HEIGHT);
    SetFontSize(m_FontSize);
    setLayout(m_pLayout);
}

std::string InputWidget::GetInput()
{
    if(m_pLineEdit)
        return m_pLineEdit->text().toStdString();
    return "";
}

QDate InputWidget::GetDate()
{
    if(m_pDateEdit == nullptr)
        return QDate();
    return m_pDateEdit->date();
}

void InputWidget::SetInput(const std::string &text)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString(text.c_str()));
}

void InputWidget::SetInput(int number)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString::number(number));
}

void InputWidget::SetInput(const QList<QString> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        m_InputList[i]->setText(list[i]);
    }
}

void InputWidget::SetInput(const QList<int> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        SetInput(list[i]);
    }
}

void InputWidget::SetInput(const QList<double> &list)
{
    for(int i = 0; i < m_InputList.size(); i++)
    {
        if(i >= list.size())
            return;
        SetInput(list[i]);
    }
}

void InputWidget::SetInput(double number)
{
    if(m_pLineEdit)
        m_pLineEdit->setText(QString::number(number));
}

void InputWidget::SetEditable(bool editable)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setEnabled(editable);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setEnabled(editable);
    }
}

void InputWidget::SetDate(const QDate &date)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(date);
}

void InputWidget::SetDate(const QString &tDateString, const QString &format)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(QDate::fromString(tDateString, format));
}

void InputWidget::SetDate(int y, int m, int d)
{
    if(m_pDateEdit)
        m_pDateEdit->setDate(QDate(y, m, d));
}

void InputWidget::SetHeight(int tHeight)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setMinimumHeight(tHeight);
        m_pLineEdit->setMaximumHeight(tHeight);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setMinimumHeight(tHeight);
        m_pDateEdit->setMaximumHeight(tHeight);
    }
}

void InputWidget::SetInputWidth(int tWidth)
{
    if(m_pLineEdit != nullptr)
    {
        m_pLineEdit->setMinimumWidth(tWidth);
        m_pLineEdit->setMaximumWidth(tWidth);
    }
    else if(m_pDateEdit != nullptr)
    {
        m_pDateEdit->setMinimumWidth(tWidth);
        m_pDateEdit->setMaximumWidth(tWidth);
    }
}

void InputWidget::SetLabelWidth(int tWidth)
{
    m_pItemName->setMinimumWidth(tWidth);
    m_pItemName->setMaximumWidth(tWidth);
}

void InputWidget::SetWidth(int tWidth)
{
    resize(tWidth, height());
}

void InputWidget::SetFontSize(int tSize)
{
    m_FontSize = tSize;
    m_pItemName->setFont(QFont((m_pItemName->font()).family(), tSize));
    if(m_pLineEdit)
    {
        m_pLineEdit->setFont(QFont((m_pLineEdit->font()).family(), tSize));
    }
    else if(m_pDateEdit)
    {
        m_pDateEdit->setFont(QFont((m_pDateEdit->font()).family(), tSize));
    }
}

void InputWidget::AppendWidget(QLineEdit *pWidget, int width,  int weight)
{
    if(weight)
    {
        m_pLayout->addWidget(pWidget, weight);
    }
    else
    {
        m_pLayout->addWidget(pWidget);
    }
    if(width)
    {
        pWidget->setMinimumWidth(width);
        pWidget->setMaximumWidth(width);
    }
    pWidget->setFont(QFont(pWidget->font().family(), m_FontSize));
    m_InputList.append(pWidget);
}

void InputWidget::AppendWidget(QWidget *pWidget, int width, int weight)
{
    if(weight)
    {
        m_pLayout->addWidget(pWidget, weight);
    }
    else
    {
        m_pLayout->addWidget(pWidget);
    }
    if(width)
    {
        pWidget->setMinimumWidth(width);
        pWidget->setMaximumWidth(width);
    }
    pWidget->setFont(QFont(pWidget->font().family(), m_FontSize));
}

void InputWidget::AppendText(const QString &text, int width,  int weight)
{
    QLabel *tLabel = new QLabel(text);
    if(width)
    {
        tLabel->setMinimumWidth(width);
        tLabel->setMaximumWidth(width);
    }
    tLabel->setFont(QFont(tLabel->font().family(), m_FontSize));
    if(weight)
    {
        m_pLayout->addWidget(tLabel, weight);
    }
    else
    {
        m_pLayout->addWidget(tLabel);
    }
}

void InputWidget::InsertWidget(int index, QWidget *pWidget, int width, int weight)
{
    pWidget->setMinimumWidth(width);
    pWidget->setMaximumWidth(width);
    m_pLayout->insertWidget(index, pWidget, weight);
}
