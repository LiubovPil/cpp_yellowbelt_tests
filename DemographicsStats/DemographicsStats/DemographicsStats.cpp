// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

enum class Gender {
	FEMALE,
	MALE
};
struct Person {
	int age; // возраст
	Gender gender; // пол
	bool is_employed; // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
			return lhs.age < rhs.age;
		}
	);
	return middle->age;
}

void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
	auto it1 = partition(begin(persons), end(persons), [](const auto& item) {
		return item.gender == Gender::FEMALE;
		}); //переставляет элементы так, чтобы элементы, выполняющие условию стояли в начале
	cout << "Median age for females = " << ComputeMedianAge(begin(persons), it1) << endl;
	cout << "Median age for males = " << ComputeMedianAge(it1, end(persons)) << endl;
	auto it2 = partition(begin(persons), it1, [](const auto& item) {
		return item.is_employed == true;
		});
	cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it2) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(it2, it1) << endl;
	auto it3 = partition(it1, end(persons), [](const auto& item) {
		return item.is_employed == true;
		});
	cout << "Median age for employed males = " << ComputeMedianAge(it1, it3) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(it3, end(persons)) << endl;
}

int main() {
	vector<Person> persons = {
	{31, Gender::MALE, false},
	{40, Gender::FEMALE, true},
	{24, Gender::MALE, true},
	{20, Gender::FEMALE, true},
	{80, Gender::FEMALE, false},
	{78, Gender::MALE, false},
	{10, Gender::FEMALE, false},
	{55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;
}