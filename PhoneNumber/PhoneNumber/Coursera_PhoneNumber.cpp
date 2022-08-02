// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>

#include "Test_runner.h"
#include "PhoneNumber.h"

void Tests() {
    PhoneNumber ph1("+7-495-111-22-33");
    AssertEqual(ph1.GetCountryCode(), "7", "Country code for +7-495-111-22-33 is 7");
    AssertEqual(ph1.GetCityCode(), "495", "City code for +7-495-111-22-33 is 495");
    AssertEqual(ph1.GetLocalNumber(), "111-22-33", "Local number for +7-495-111-22-33 is 111-22-33");
    AssertEqual(ph1.GetInternationalNumber(), "+7-495-111-22-33", "International number for +7-495-111-22-33 is +7-495-111-22-33");
    
    PhoneNumber ph2("+323-22-460002");
    AssertEqual(ph2.GetCountryCode(), "323", "Country code for +323-22-460002 is 323");
    AssertEqual(ph2.GetCityCode(), "22", "City code for +323-22-460002 is 22");
    AssertEqual(ph2.GetLocalNumber(), "460002", "Local number for +323-22-460002 is 460002");
    AssertEqual(ph2.GetInternationalNumber(), "+323-22-460002", "International number for +323-22-460002 is +323-22-460002");

    PhoneNumber ph3("+1-2-coursera-cpp");
    AssertEqual(ph3.GetCountryCode(), "1", "Country code for +1-2-coursera-cpp is 1");
    AssertEqual(ph3.GetCityCode(), "2", "City code for +1-2-coursera-cpp is 2");
    AssertEqual(ph3.GetLocalNumber(), "coursera-cpp", "Local number for +1-2-coursera-cpp is coursera-cpp");
    AssertEqual(ph3.GetInternationalNumber(), "+1-2-coursera-cpp", "International number for +1-2-coursera-cpp is +1-2-coursera-cpp");
}

int main()
{
    TestRunner testrunner;
    testrunner.RunTest(Tests, "Tests for +7-495-111-22-33, +323-22-460002 and +1-2-coursera-cpp");
}

