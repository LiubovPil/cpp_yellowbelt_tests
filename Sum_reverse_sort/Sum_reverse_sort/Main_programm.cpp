// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>

#include "Test_runner.h"
#include "Sum_reverse_sort.h"

void TestForSum() {
    AssertEqual(Sum(0, 0), 0, " 0 + 0 = 0");
    AssertEqual(Sum(2, 3), 5, " 2 + 3 = 5");
    AssertEqual(Sum(-20, 10), -10, " -20 + 10 = -10");
}
void TestForReverse() {
    AssertEqual(Reverse("deed"), "deed", "Reverse deed is deed");
    AssertEqual(Reverse("omomom"), "momomo", "Reverse omomom is momomo");
    AssertEqual(Reverse("programm"), "mmargorp", "Reverse programm is mmargorp");
}
void TestForSort() {
    vector<int> nums{ 5, 4, 3, 2, 1 };
    Sort(nums);

    AssertEqual(nums, vector<int>{ 1, 2, 3, 4, 5 }, "Sorted vector for { 5, 4, 3, 2, 1 } is { 1, 2, 3, 4, 5 }");

    nums = { 10, -10, 0, 5, -5 };
    Sort(nums);

    AssertEqual(nums, vector<int>{ -10, -5, 0, 5, 10 }, "Sorted vector for { 10, -10, 0, 5, -5 } is { -10, -5, 0, 5, 10 }");
}
int main()
{
    TestRunner runner;
    runner.RunTest(TestForSum, "Test for sum");
    runner.RunTest(TestForReverse, "Test for reverse");
    runner.RunTest(TestForSort, "Test for sort");
}

