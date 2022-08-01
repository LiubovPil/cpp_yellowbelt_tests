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

int GreatesCommonDivisor(int a, int b) {
	if (b == 0)
		return a;
	else
		return GreatesCommonDivisor(b, a % b);
};

class Rational {
public:
	Rational() {
		numerator_value = 0;
		denominator_value = 1;
	};
	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw invalid_argument("Invalid argument");
		}
		int divisor = GreatesCommonDivisor(numerator, denominator);

		numerator_value = numerator / divisor;
		denominator_value = denominator / divisor;

		if (denominator_value < 0) {
			numerator_value = -numerator_value;
			denominator_value = -denominator_value;
		}
	}
	int Numerator() const {
		return numerator_value;
	}
	int Denominator() const {
		return denominator_value;
	}
private:
	int numerator_value = 0;
	int denominator_value = 1;
};
 
void TestDefaultConstructor()
{
	Rational r1;
	AssertEqual(r1.Numerator(), 0, "The numerator of default rational r1 is 0");
	AssertEqual(r1.Denominator(), 1, "The denominator of default rational r1 is 1");
}
void TestConstructorWithParametrs() {
	Rational r2{ 1, 2 };
	AssertEqual(r2.Numerator(), 1, "The numerator of default rational r2 is 1");
	AssertEqual(r2.Denominator(), 2, "The denominator of default rational r2 is 2");

	Rational r3 = { 0, 15 };
	AssertEqual(r3.Numerator(), 0, "The numerator of default rational r3 is 0");
	AssertEqual(r3.Denominator(), 1, "The denominator of default rational r3 is 1");
}

void TestConstructorWithReducation() {
	Rational r4{ 4, 6 };
	AssertEqual(r4.Numerator(), 2, "The numerator of default rational r4 is 2");
	AssertEqual(r4.Denominator(), 3, "The denominator of default rational r4 is 3");

	Rational r5( 8, 96 );
	AssertEqual(r5.Numerator(), 1, "The numerator of default rational r5 is 1");
	AssertEqual(r5.Denominator(), 12, "The denominator of default rational r5 is 12");
}
void TestConstructorForNegative() {
	Rational r6{ -1, -3 };
	AssertEqual(r6.Numerator(), 1, "The numerator of default rational r6 is 1");
	AssertEqual(r6.Denominator(), 3, "The denominator of default rational r6 is 3");

	Rational r7(4, -36);
	AssertEqual(r7.Numerator(), -1, "The numerator of default rational r7 is -1");
	AssertEqual(r7.Denominator(), 9, "The denominator of default rational r7 is 9");

	Rational r8(-7, 12);
	AssertEqual(r8.Numerator(), -7, "The numerator of default rational r8 is -7");
	AssertEqual(r8.Denominator(), 12, "The denominator of default rational r8 is 12");
}
int main() {
	TestRunner runner;
	runner.RunTest(TestDefaultConstructor, "Test default constructor ");
	runner.RunTest(TestConstructorWithParametrs, "Test constructor with parametrs ");
	runner.RunTest(TestConstructorWithReducation, "Test reducation of rational ");
	runner.RunTest(TestConstructorForNegative, "Test negative rational ");
	return 0;
}
