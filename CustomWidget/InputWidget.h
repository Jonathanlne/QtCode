#pragma once

#include <QWidget>
#include <QDate>
#include <QList>
class QLineEdit;
class QLabel;
class QDateEdit;
class QHBoxLayout;
class QComboBox;
class InputWidget : public QWidget
{
    Q_OBJECT
public:
    enum InputType
    {
        Text,
        Date,
        ComboBox
    };
    InputWidget(const QString &tItemName, const InputType &type = Text,
                QWidget *parent = nullptr);

    std::string GetInput();
    QDate GetDate();
    void AddInputWidget(int num,const QList<int> &widths = QList<int>(), const QList<int> &weights = QList<int>());
    void AddComboItem(const QString &item);
    void AddComboItem(const QList<QString> &list);
    void SetInput(const std::string &text);
    void SetInput(int number);
    void SetInput(const QList<QString> &list);
    void SetInput(const QList<int>  &list);
    void SetInput(const QList<double> &list);
    void SetInput(double number);
    void SetEditable(bool editable);
    void SetDate(const QDate &date);
    void SetDate(const QString &tDateString, const QString &format = "yyyy-MM-d");
    void SetDate(int y, int m, int d);
    void SetHeight(int tHeight);
    void SetInputWidth(int tWidth);
    void SetLabelWidth(int tWidth);
    void SetWidth(int tWidth);
    void SetFontSize(int tSize);
    void AppendWidget(QLineEdit *pWidget, int width = 0,  int weight = 0);
    void AppendWidget(QWidget *pWidget, int width = 0,  int weight = 0);
    void AppendText(const QString& text, int width = 0, int weight = 0);
    void InsertWidget(int index, QWidget *pWidget, int width = 0, int weight = 0);

private:
    QLineEdit          *m_pLineEdit;
    QLabel             *m_pItemName;
    QDateEdit          *m_pDateEdit;
    QHBoxLayout        *m_pLayout;
    int                 m_FontSize;
    QList<QLineEdit *>  m_InputList;
    QList<QWidget *>    m_WidgetList;
    QComboBox          *m_pComboBox;
};

