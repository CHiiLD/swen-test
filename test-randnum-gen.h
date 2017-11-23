#ifndef RANDGEN_H
#define RANDGEN_H

#include <QtTest>

class RandNumGenTest : public QObject
{
    Q_OBJECT

private slots:
    void test_call();
    void test_gen();
    void test_invaildParameter();
};

#endif // RANDGEN_H
