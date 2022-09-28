#include <QTest>

class TestMatrix : public QObject
{
    Q_OBJECT
private:
    int nbTest = 1000;

private slots:

    void operatorGetTest();

    void operatorScalarTest();

    void operatorMatrixTest();

};
