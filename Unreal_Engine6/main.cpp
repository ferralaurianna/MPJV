#include "mainwindow.h"
#include "testVector.h"
#include "testMatrix.h"
#include <QApplication>
#include <QTest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTEST_SET_MAIN_SOURCE_PATH;

    TestVector t1;
    QTest::qExec(&t1, argc, argv);

    TestMatrix t2;
    QTest::qExec(&t2, argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
