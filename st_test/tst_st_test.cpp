#include <QtTest>

// add necessary includes here

class st_test : public QObject
{
    Q_OBJECT

public:
    st_test();
    ~st_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

st_test::st_test()
{

}

st_test::~st_test()
{

}

void st_test::initTestCase()
{

}

void st_test::cleanupTestCase()
{

}

void st_test::test_case1()
{

}

QTEST_APPLESS_MAIN(st_test)

#include "tst_st_test.moc"
