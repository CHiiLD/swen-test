#include <QtTest>
#include "test-randnum-gen.h"
#include "test-basicstat.h"
#include "test-nullhypothesis.h"

int main(int argc, char *argv[])
{
    int status = 0;

    RandNumGenTest t1;
    status |= QTest::qExec(&t1, argc, argv);

    FoundationStatTest t2;
    status |=QTest::qExec(&t2, argc, argv);

    NullHypothesisTest t3;
    status |=QTest::qExec(&t3, argc, argv);

    return status;
}
