// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

ostream& operator <<(ostream& os, const vector<int>& v) {
    for (auto item : v) {
        os << item << " ";
    }
    os << endl;
    return os;
}

int main()
{
    int num;
    cin >> num;

    vector<int> numbers;

    //vector<int> numbers(num);
    //iota(numbers.begin(), numbers.end(), 1); // заполняет вектор + reverse (для обратного порядка)

    for (int i = 0; i < num; ++i) {
        numbers.push_back(num-i);
    }
    do {
        cout << numbers;
    } while (prev_permutation(begin(numbers), end(numbers)));
    //rotate(begin(numbers), begin(numbers), end(numbers)); //вращает, как будто все элементы расположены на рулетке
}
