#include "mainwindow.h"
#include <QApplication>
#include "KDictionaryDialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.showMaximized();
    KDictionaryDialog dialog;
    dialog.exec();

    return a.exec();
}
