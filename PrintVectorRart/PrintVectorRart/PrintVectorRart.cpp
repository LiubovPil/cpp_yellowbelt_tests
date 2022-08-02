// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto it = find_if(begin(numbers), end(numbers), [](const int& number) {
        return number < 0;
        });
    while (it != begin(numbers)) {
        --it;
        cout << *it << " ";
    }
    /*  //из лекции
        for (auto iter = it; iter != numbers.begin(); ) {
        cout << *(--iter) << " ";
    }*/
}

int main()
{
    PrintVectorPart({ 6, 1, 8, -5, 4 });
    cout << endl;
    PrintVectorPart({ -6, 1, 8, -5, 4 }); // ничего не выведется
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, 4 });
    cout << endl;
    return 0;
}

