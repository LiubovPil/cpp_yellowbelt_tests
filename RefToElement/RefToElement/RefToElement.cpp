// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename K, typename V> V& GetRefStrict(map<K, V>& m, const K k) {
    if (m.count(k) == 0) {
        throw runtime_error("There is no such key");
    }
    return m.at(k);
}

int main()
{
    map<int, string> m = { {0, "value"} };
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl;
    return 0;
}