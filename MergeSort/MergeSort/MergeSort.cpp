// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSortTwo(RandomIt range_begin, RandomIt range_end) {
    //так как для RandomIt определены операции сложения и вычитания (например, begin + 1 = next), то операция end-begin даст кол-во итератор между ними
    if ( (range_end - range_begin) < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto half_it = begin(elements) + elements.size()/2;
    
    MergeSortTwo(begin(elements), half_it);
    MergeSortTwo(half_it, end(elements));

    merge(begin(elements), half_it, half_it, end(elements), range_begin);
}

template <typename RandomIt>
void MergeSortThree(RandomIt range_begin, RandomIt range_end) {
    if ((range_end - range_begin) < 2) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    size_t border = elements.size() / 3;

    MergeSortThree(begin(elements), begin(elements) + border);
    MergeSortThree(begin(elements) + border, begin(elements) + 2*border);
    MergeSortThree(begin(elements) + 2*border, end(elements));

    vector<typename RandomIt::value_type> new_elements;
    merge(begin(elements), begin(elements) + border, begin(elements) + border, begin(elements) + 2 * border, back_inserter(new_elements));

    merge(begin(new_elements), end(new_elements), begin(elements) + 2 * border, end(elements), range_begin);
}

int main() {
    vector<int> v = { 0, -2, 4, -6 };
    MergeSortTwo(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;


    vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSortTwo(begin(v1), end(v1));
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> v2 = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
    MergeSortThree(begin(v2), end(v2));
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
