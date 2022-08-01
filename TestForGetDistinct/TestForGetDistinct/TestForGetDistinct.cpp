// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

int SolveLinearEquation(double b, double c) {
	if (b != 0) {
		double x = -c / b;
		return 1; 
	}
	else {
		return 0;
	}
}
int SolveQuadraticEquation(double a, double b, double c) {
	double D = (b * b) - (4 * a * c);
	if (D == 0) {
		double x = -b / (2 * a);
		return 1;
	} 
	else if (D > 0){
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		return 2;
	}
	else {
		return 0;
	}
}

int GetDistinctRealRootCount(double a, double b, double c) {
	if (a == 0) {
		return SolveLinearEquation(b, c);
	}
	else {
		return SolveQuadraticEquation(a, b, c);
	}
}

void TestNoRoot()
{
	AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "x^2+1 = 0 has 0 root");
	AssertEqual(GetDistinctRealRootCount(6, 2, 1), 2, "6x^2+2x+1 = 0 has 2 root");
	AssertEqual(GetDistinctRealRootCount(1, -5, 10), 0, "x^2-5x+10 = 0 has 0 root");
}
void TestOneRoot()
{
	AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "x^2 = 0 has 1 root");
	AssertEqual(GetDistinctRealRootCount(2, -4, 2), 1, "2x^2-4x+2 = 0 has 1 root");
	AssertEqual(GetDistinctRealRootCount(9, 6, 1), 1, "9x^2+6x+1 = 0 has 1 root");
}
void TestTwoRoot()
{
	AssertEqual(GetDistinctRealRootCount(1, 6, 8), 2, "x^2+6x+8 = 0 has 2 root");
	AssertEqual(GetDistinctRealRootCount(1, 0, -25), 2, "x^2-25 = 0 has 2 root");
	AssertEqual(GetDistinctRealRootCount(1, -10, 0), 2, "x^2-10x = 0 has 2 root");
}
void TestLinearEquation()
{
	AssertEqual(GetDistinctRealRootCount(0, 5, -20), 1, "5x-20 = 0 has 1 root");
	AssertEqual(GetDistinctRealRootCount(0, 0, 25), 1, "25 = 0 has 1 root");
	AssertEqual(GetDistinctRealRootCount(0, 4, 0), 1, "4x = 0 has 1 root");
}

int main() {
	TestRunner runner;
	runner.RunTest(TestNoRoot, "Test with no root ");
	runner.RunTest(TestOneRoot, "Test with one root ");
	runner.RunTest(TestTwoRoot, "Test with two root ");
	runner.RunTest(TestLinearEquation, "Test for linear equation ");
	return 0;
}
