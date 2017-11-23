#include "test-basicstat.h"
#include "basicstat.h"

void FoundationStatTest::test_mean()
{
    std::list<double> data;
    double data1 = 2.0, data2 = 1.0;
    data.push_back(data1);
    data.push_back(data2);
    double mean;
    int ret = FoundationStat::mean(data, mean);
    QCOMPARE(ret, 0);
    QCOMPARE(mean, (data1 + data2) /2);
}

void FoundationStatTest::test_mean_invalidParameter()
{
    std::list<double> data;
    double mean;
    int ret = FoundationStat::mean(data, mean);
    QCOMPARE(ret, -1);
}

void FoundationStatTest::test_variance()
{
    std::list<double> data;
    data.push_back(3.0);
    data.push_back(5.0);
    data.push_back(7.0);
    data.push_back(7.0);
    data.push_back(8.0);
    double variance;
    int ret = FoundationStat::variance(data, variance);
    QCOMPARE(ret, 0);
    QCOMPARE(variance, 4.0);
}

void FoundationStatTest::test_variance_invalidParameter()
{
    std::list<double> data;
    double variance;
    int ret = FoundationStat::variance(data, variance);
    QCOMPARE(ret, -1);
}

void FoundationStatTest::test_standardDeviation()
{
    std::list<double> data;
    data.push_back(3.0);
    data.push_back(5.0);
    data.push_back(7.0);
    data.push_back(7.0);
    data.push_back(8.0);
    double variance;
    int ret = FoundationStat::standardDeviation(data, variance);
    QCOMPARE(ret, 0);
    QCOMPARE(variance, 2.0);
}

void FoundationStatTest::test_standardDeviation_invalidParameter()
{
    std::list<double> data;
    double variance;
    int ret = FoundationStat::variance(data, variance);
    QCOMPARE(ret, -1);
}

void FoundationStatTest::test_pecentile()
{
    std::list<double> data;
    double value;
    double d[] = {1.6, 1.7, 1.8, 1.8, 1.9, 2.1, 2.5, 3.0, 3.0, 4.4,
                  12.7, 15.3, 15.5, 15.9, 15.9, 16.1, 16.5, 17.5, 18.3, 19.0,
                  4.5, 4.5, 5.9, 7.1, 7.4, 7.5, 7.7, 8.6, 9.3, 9.5,
                  19.4, 22.5, 23.5, 24.0, 31.7, 32.8, 43.5, 53.3};
    for(int i = 0; i < sizeof(d) / sizeof(double); ++i)
        data.push_back(d[i]);

    int ret = FoundationStat::pecentile(data, 0.25, value);
    QCOMPARE(ret, 0);
    QCOMPARE(value, 4.4);

    ret = FoundationStat::pecentile(data, 0.5, value);
    QCOMPARE(ret, 0);
    QCOMPARE(value, 9.4);

    ret = FoundationStat::pecentile(data, 0.75, value);
    QCOMPARE(ret, 0);
    QCOMPARE(value, 18.3);

    ret = FoundationStat::pecentile(data, 0.90, value);
    QCOMPARE(ret, 0);
    QCOMPARE(value, 31.7);
}

void FoundationStatTest::test_pecentile_invalidParameter()
{
    std::list<double> data;
    double value;
    int ret = FoundationStat::pecentile(data, 0, value);
    QCOMPARE(ret, -1);

    data.push_back(3.0);
    data.push_back(5.0);
    data.push_back(7.0);

    ret = FoundationStat::pecentile(data, -0.0000000000001, value);
    QCOMPARE(ret, -1);

    ret = FoundationStat::pecentile(data, 1.0000000000001, value);
    QCOMPARE(ret, -1);
}

#define banollim(x,dig) (floor((x)*pow(10,dig)+0.5)/pow(10,dig))

void FoundationStatTest::test_correlationCoefficient()
{
    std::list<double> datax, datay;
    double value;
    datax.push_back(2.0);
    datax.push_back(1.0);
    datax.push_back(5.0);
    datax.push_back(0.0);
    datay.push_back(5.0);
    datay.push_back(3.0);
    datay.push_back(6.0);
    datay.push_back(2.0);

    int ret = FoundationStat::correlationCoefficient(datax, datay, value);
    QCOMPARE(ret, 0);
    double roundVlaue = banollim(value, 2); //실수를 실수로 반올림
    QCOMPARE(roundVlaue, 0.93);
}

void FoundationStatTest::test_correlationCoefficient_invalidParameter()
{
    std::list<double> datax, datay;
    double value;

    int ret = FoundationStat::correlationCoefficient(datax, datay, value);
    QCOMPARE(ret, -1);

    datax.push_back(1.0);
    datax.push_back(5.0);
    datax.push_back(0.0);
    datay.push_back(5.0);
    datay.push_back(3.0);
    datay.push_back(6.0);
    datay.push_back(2.0);

    ret = FoundationStat::correlationCoefficient(datax, datay, value); //데이터 셋 사이즈 검사
    QCOMPARE(ret, -1);
}
