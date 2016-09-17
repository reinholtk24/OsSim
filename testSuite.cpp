#include <iostream>
#include "testSuite.h"


TestMaster::TestMaster()
{
    std::cout << "Test Class Created Dawg." << std::endl;
    passed = 0;
    failed = 0;
}

void TestMaster::checkVersion(std::string version)
{
    if(version.empty())
    {
        failed++;
    }
    else
    {
        passed++;
    }
}

void TestMaster::checkDate(std::string date)
{
    if(date.empty())
    {
        failed++;
    }
    else
    {
        passed++;
    }
}

void TestMaster::testSummary()
{
    std::cout << "Tests passed: " << passed << std::endl;
    std::cout << "Tests failed: " << failed << std::endl;
}

TestMaster::~TestMaster()
{
    std::cout << "Completely destroying the object!" << std::endl;
}
