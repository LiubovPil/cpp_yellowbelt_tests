// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& name)
        : Name(name) {
    }

    const string Name;
};


class Dog : public Animal{
public:
    Dog(const string& name) : Animal(name) {
    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

