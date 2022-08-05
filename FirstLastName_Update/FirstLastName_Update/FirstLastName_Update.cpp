// Tasks from the course "Fundamentals of C++: Yellow Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        firstname_changes[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        lastname_changes[year] = last_name;
    }
    string GetFullName(int year) {
        const auto it_firstname = firstname_changes.upper_bound(year);  // может быть заменена на функцию возращающую string (string FindNameByYear) (см белый пояс)
        const auto it_lastname = lastname_changes.upper_bound(year);  // может быть заменена на функцию возращающую string (string FindNameByYear) (см белый пояс)
        
        if (it_firstname == begin(firstname_changes) && it_lastname == begin(lastname_changes)) {
            return "Incognito";
        }
        else if (it_firstname == begin(firstname_changes))
            return (*prev(it_lastname)).second + " with unknown first name";
        else if (it_lastname == begin(lastname_changes)) {
            return (*prev(it_firstname)).second + " with unknown last name";
        }
        else
            return (*prev(it_firstname)).second + " " + (*prev(it_lastname)).second;
    }
private:
    map<int, string> firstname_changes;
    map<int, string> lastname_changes;
};

int main(){
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
