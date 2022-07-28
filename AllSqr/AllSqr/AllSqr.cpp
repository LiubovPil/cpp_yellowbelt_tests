// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <utility>
#include <map>
#include <vector>

using namespace std;

template<typename First, typename Second> pair<First, Second> operator * (pair<First, Second>& p1, pair<First, Second>& p2) {
    return { p1.first * p2.first, p1.second * p2.second };
}
/*template<typename T> T Sqr(T t) {
    return t * t;
}*/
template<typename T> vector<T> Sqr(vector<T>& v) {
    for (T& item : v) {
        T sqr = item * item;
        item = sqr;
    }
    return v;
}
template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second>& p) {
    First sqr_first = p.first * p.first;
    p.first = sqr_first;
    Second sqr_second = p.second * p.second;
    p.second = sqr_second;
    return p;
}
template<typename T1, typename T2> map<T1, T2> Sqr(map<T1, T2>& m) {
    for (auto& item : m) {
        T2 sqr = item.second * item.second;
        item.second = sqr;
    }
    return m;
}

int main()
{
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}