// Final assignment for the course "Fundamentals of C++: White Belt"
// Done by Liubov Piliagina

#include <iostream>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {

    set<int>::const_iterator upper = numbers.upper_bound(border);
    if (upper == begin(numbers))
        return upper;
    //end = begin в пустом множестве
    set<int>::const_iterator lower = prev(upper);
    if (upper == end(numbers))
        return lower;

    if ((border - *lower) > (*upper - border))
        return upper;
    else
        return lower;

    //последний цикл можно заменить на:
    //const bool is_left = (border - *last_less <= *first_not_less - border);
    //return is_left ? last_less : first_not_less;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;

    set<int> numbers = { 1, 4, 6 };
    cout <<
        * FindNearestElement(numbers, 0) << " " <<
        * FindNearestElement(numbers, 3) << " " <<
        * FindNearestElement(numbers, 5) << " " <<
        * FindNearestElement(numbers, 6) << " " <<
        * FindNearestElement(numbers, 100) << endl;

    return 0;
}
