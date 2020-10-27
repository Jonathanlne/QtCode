#include "mainwindow.h"
#include <QApplication>
#include "KReceivedImagesDialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.showMaximized();
    KReceivedImagesDialog dialog;
    dialog.exec();

    return a.exec();
}
