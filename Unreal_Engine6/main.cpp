#include "windowpart1.h".h"
#include "tests\testVector.h"
#include "tests\testMatrix.h"
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

    WindowPart1 w;
    w.show();
    return a.exec();
}
