#ifndef NULLHYPOTHESISTEST_H
#define NULLHYPOTHESISTEST_H

#include <QtTest>

class NullHypothesisTest : public QObject
{
    Q_OBJECT
private slots:
    void test_two_sided_hypothesis();
    void test_one_sided_hypothesis();
    void test_student_t_distribution();
    void test_nullHypothesisParameterClass();
    void test_hypothesis_invalidParameter();
};

#endif // NULLHYPOTHESISTEST_H
