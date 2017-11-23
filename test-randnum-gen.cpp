#include "test-randnum-gen.h"
#include <string>
#include "randnumgen.h"

void RandNumGenTest::test_call()
{
    std::list<int> values;
    RandNumber::generate(0, 1000, 10, values);
}

void RandNumGenTest::test_gen()
{
    unsigned long size = 15;
    int min = 0, max = 1000;
    std::list<int> values;
    int ret = RandNumber::generate(min, max, size, values);
    QCOMPARE(ret, 0);
    QCOMPARE(values.size(), size);

    for(auto iter = values.begin(); iter != values.end(); ++iter)
    {
        int number = *iter;
        QVERIFY(min <= ret && ret <= max);
        qDebug(std::to_string(number).c_str());
    }
}

void RandNumGenTest::test_invaildParameter()
{
    std::list<int> values;
    int ret = RandNumber::generate(1001, 1000, 10, values);
    QCOMPARE(ret, -1);

    ret = RandNumber::generate(1000, 1000, 10, values);
    QCOMPARE(ret, 0);

    ret = RandNumber::generate(0, 1000, -1, values);
    QCOMPARE(ret, -1);

    ret = RandNumber::generate(0, 1000, 0, values);
    QCOMPARE(ret, 0);
}
