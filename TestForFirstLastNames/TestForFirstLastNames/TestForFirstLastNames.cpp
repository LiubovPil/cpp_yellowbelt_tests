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

string FindNameByYear(int year, const map<int, string>& name_changes) {
	string name;
	for (const auto& item : name_changes)
	{
		if (item.first > year) {
			break;
		}
		name = item.second;
	}
	return name;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firstname_changes[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		lastname_changes[year] = last_name;
	}
	string GetFullName(int year) {
		const string first_name = FindNameByYear(year, firstname_changes);
		const string last_name = FindNameByYear(year, lastname_changes);
		
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";
		}
		else {
			return first_name + " " + last_name;
		}
	}
private:
	map<int, string> firstname_changes;
	map<int, string> lastname_changes;
};

void TestIncognito() {
	Person person;
	AssertEqual(person.GetFullName(1900), "Incognito", "No information about the person in 1900");

	person.ChangeLastName(1950, "Ivanova");
	AssertEqual(person.GetFullName(1910), "Incognito", "No information about the person in 1910");
	
	person.ChangeFirstName(1955, "Anna");
	AssertEqual(person.GetFullName(1910), "Incognito", "No information about the person in 1930");

	person.ChangeFirstName(1960, "Anna-Victoria");
	AssertEqual(person.GetFullName(1949), "Incognito", "No information about the person in 1949");
}
void TestLastName(){
	Person person;
	AssertEqual(person.GetFullName(1900), "Incognito", "No information about the person in 1900");

	person.ChangeLastName(1950, "Ivanova");
	AssertEqual(person.GetFullName(1955), "Ivanova with unknown first name", "1955: Person with last name Ivanova");

	person.ChangeLastName(1970, "Petrova");
	AssertEqual(person.GetFullName(1960), "Ivanova with unknown first name", "1960: Person with last name Ivanova");
	AssertEqual(person.GetFullName(1975), "Petrova with unknown first name", "1975: Person with last name Petrova");

	person.ChangeLastName(1980, "Ivanova");
	AssertEqual(person.GetFullName(1930), "Incognito", "No information about the person in 1930");
	AssertEqual(person.GetFullName(1957), "Ivanova with unknown first name", "1960: Person with last name Ivanova");
	AssertEqual(person.GetFullName(1977), "Petrova with unknown first name", "1975: Person with last name Petrova");
	AssertEqual(person.GetFullName(1985), "Ivanova with unknown first name", "1975: Person with last name Ivanova");
}
void TestFirstName() {
	Person person;
	AssertEqual(person.GetFullName(1900), "Incognito", "No information about the person in 1900");

	person.ChangeFirstName(1955, "Anna");
	person.ChangeLastName(1950, "Ivanova");
	AssertEqual(person.GetFullName(1960), "Anna Ivanova", "1960: Person with first name Anna and last name Ivanova");

	person.ChangeFirstName(1960, "Anna-Victoria");
	AssertEqual(person.GetFullName(1957), "Anna Ivanova", "1957: Person with first name Anna and last name Ivanova");
	AssertEqual(person.GetFullName(1965), "Anna-Victoria Ivanova", "1965: Person with first name Anna-Victoria and last name Ivanova");

	person.ChangeFirstName(1950, "Polina");
	person.ChangeLastName(1970, "Petrova");
	AssertEqual(person.GetFullName(1952), "Polina Ivanova", "1952: Person with first name Polina and last name Ivanova");
	AssertEqual(person.GetFullName(1957), "Anna Ivanova", "1957: Person with first name Anna and last name Ivanova");
	AssertEqual(person.GetFullName(1975), "Anna-Victoria Petrova", "1975: Person with first name Anna-Victoria and last name Petrova");

	person.ChangeLastName(1980, "Ivanova");
	AssertEqual(person.GetFullName(1930), "Incognito", "No information about the person in 1930");
	AssertEqual(person.GetFullName(1952), "Polina Ivanova", "1952: Person with first name Polina and last name Ivanova");
	AssertEqual(person.GetFullName(1975), "Anna-Victoria Petrova", "1975: Person with first name Anna and last name Petrova");
	AssertEqual(person.GetFullName(1985), "Anna-Victoria Ivanova", "1985: Person with first name Anna-Victoria and last name Ivanova");
}
void TestFullName() {
	Person person;
	AssertEqual(person.GetFullName(1900), "Incognito", "No information about the person in 1900");

	person.ChangeFirstName(1955, "Anna");
	AssertEqual(person.GetFullName(1960), "Anna with unknown last name", "1960: Person with first name Anna");

	person.ChangeFirstName(1960, "Anna-Victoria");
	AssertEqual(person.GetFullName(1957), "Anna with unknown last name", "1960: Person with first name Anna");
	AssertEqual(person.GetFullName(1965), "Anna-Victoria with unknown last name", "1965: Person with first name Anna-Victoria");

	person.ChangeFirstName(1950, "Polina");
	AssertEqual(person.GetFullName(1930), "Incognito", "No information about the person in 1930");
	AssertEqual(person.GetFullName(1952), "Polina with unknown last name", "1952: Person with first name Polina");
	AssertEqual(person.GetFullName(1957), "Anna with unknown last name", "1960: Person with first name Anna");
	AssertEqual(person.GetFullName(1960), "Anna-Victoria with unknown last name", "1960: Person with first name Anna-Victoria");
}
int main() {
	TestRunner runner;
	runner.RunTest(TestIncognito, "Incognito test");
	runner.RunTest(TestLastName, "Last name test");
	runner.RunTest(TestFirstName, "First name test");
	runner.RunTest(TestFullName, "Full name test");
	return 0;
}
