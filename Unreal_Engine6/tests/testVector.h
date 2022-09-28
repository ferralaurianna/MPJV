#include <QTest>

class TestVector: public QObject
{
    Q_OBJECT
private:
    int nbTest = 1000;

private slots:

    void operationByScalar(); 

    void operationBetweenVector();

    void constructor(); 

    void norm(); 

    void normalization(); 

    void scalarProduct(); 

};
