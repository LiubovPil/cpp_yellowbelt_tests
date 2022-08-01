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

bool IsPalindrom(const string& str) {
	size_t size = str.size();
	for (size_t i = 0; i < size / 2; i++) {
		if (str[i] != str[(size - 1) - i]) {
			return false;
		}
	}
	return true;
}

void TestForPalindrom() {
	Assert(IsPalindrom("deed"), "Deed is palindrom");
	Assert(IsPalindrom("tenet"), "Tenet is palindrom");
	Assert(IsPalindrom("racecar"), "Racecar is palindrom");
	Assert(IsPalindrom("1 a 2 b b 2 a 1"), "1 a 2 b b 2 a 1 is palindrom");
	Assert(IsPalindrom("redivider"), "Redivider is palindrom");
}
void TestForNotPalindrom() {
	Assert(!IsPalindrom("eveN"), "Even isn't palindrom");
	Assert(!IsPalindrom("arraY"), "Array isn't palindrom");
	Assert(!IsPalindrom("garagE"), "Garage isn't palindrom");
	Assert(!IsPalindrom("  rotator"), " rotator(space first) isn't palindrom");
	Assert(!IsPalindrom("repaper  "), "Repaper (space last) isn't palindrom");
	Assert(!IsPalindrom("testSset"), "Testsset isn't palindrom");
}
int main() {
	TestRunner runner;
	runner.RunTest(TestForPalindrom, "Test for palindrom");
	runner.RunTest(TestForNotPalindrom, "Test for not palindrom");

	string word;
	cin >> word;
	cout << IsPalindrom(word);
	return 0;
}