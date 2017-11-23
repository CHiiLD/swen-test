#ifndef MULTIVARIATEANAL_H
#define MULTIVARIATEANAL_H

#include <QtTest>

class FoundationStatTest : public QObject
{
    Q_OBJECT

private slots:
    void test_mean();
    void test_mean_invalidParameter();
    void test_variance();
    void test_variance_invalidParameter();
    void test_standardDeviation();
    void test_standardDeviation_invalidParameter();
    void test_pecentile();
    void test_pecentile_invalidParameter();
    void test_correlationCoefficient();
    void test_correlationCoefficient_invalidParameter();
};

#endif // MULTIVARIATEANAL_H
