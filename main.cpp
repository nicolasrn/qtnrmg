#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QLibraryInfo>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //pour que toutes les fenêtres soient en français
    QTranslator trans;
    trans.load("qt_"+ QLocale::system().name(),QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&trans);

    QTranslator myappTransletor;
    myappTransletor.load("myapp_"+QLocale::system().name());
    a.installTranslator((&myappTransletor));


    MainWindow w;
    w.show();

    return a.exec();
}
