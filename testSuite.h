#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>

class TestMaster
{
    public:
        TestMaster();
        ~TestMaster();
        void checkVersion(std::string version);
        void checkDate(std::string date);
        void testSummary();

    private:
        int passed;
        int failed;
};
#endif //TestSuite_H
