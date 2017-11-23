#include "test-nullhypothesis.h"
#include "nullhypothesis.h"

void NullHypothesisTest::test_two_sided_hypothesis()
{
    double mu_0 = 2.6;
    NullHypothesisSign sign = NullHypothesisSign::NOT_EQUAL;
    int n = 40;
    double alpha = 0.05;
    double mean = 4.525, std = 5.17;

    int ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, alpha, sign);

    QCOMPARE(ret, NULL_HYPOTHESIS_REJECT_SECCESS);
}

void NullHypothesisTest::test_one_sided_hypothesis()
{
    double mu_0 = 22.0;
    NullHypothesisSign sign = NullHypothesisSign::LESS_THEN;
    int n = 56;
    double alpha = 0.05;
    double mean = 23.5, std = 10.2;

    int ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, alpha, sign);

    QCOMPARE(ret, NULL_HYPOTHESIS_REJECT_FAIL);
}

void NullHypothesisTest::test_student_t_distribution()
{
    double mu_0 = 200.0;
    NullHypothesisSign sign = NullHypothesisSign::GREATER_THEN;
    int n = 10;
    double alpha = 0.05;
    double mean = 192.7, std = 10.81;

    int ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, alpha, sign);

    QCOMPARE(ret, NULL_HYPOTHESIS_REJECT_SECCESS);
}

void NullHypothesisTest::test_nullHypothesisParameterClass()
{
    double mu_0 = 200.0;
    NullHypothesisSign sign = NullHypothesisSign::GREATER_THEN;
    int n = 10;
    double alpha = 0.05;
    double mean = 192.7, std = 10.81;

    NullHypothesisParameter p(mean, std, n, mu_0, alpha, sign);
    p.print();
    int ret = NullHypothesis::hyphothesis(p);

    QCOMPARE(ret, NULL_HYPOTHESIS_REJECT_SECCESS);
}

void NullHypothesisTest::test_hypothesis_invalidParameter()
{
    double mu_0 = 200.0;
    NullHypothesisSign sign = NullHypothesisSign::GREATER_THEN;
    int n = 10;
    double alpha = 0.05;
    double mean = 192.7, std = 10.81;

    int ret = NullHypothesis::hyphothesis(mean, std, 0, mu_0, alpha, sign);
    QCOMPARE(ret, -1);

    ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, 1.000000000000001, sign);
    QCOMPARE(ret, -1);

    ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, -0.000000000000001, sign);
    QCOMPARE(ret, -1);

    ret = NullHypothesis::hyphothesis(mean, std, n, mu_0, alpha, NullHypothesisSign::NONE);
    QCOMPARE(ret, -1);
}
