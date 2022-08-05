// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {

    string s_prefix_first = { prefix };
    auto it_first = lower_bound(range_begin, range_end, s_prefix_first);
    
    string s_prefix_second {static_cast<char>(prefix + 1)};
    auto it_second = lower_bound(range_begin, range_end, s_prefix_second);
    //auto it_second = lower_bound(it_first, range_end, s_prefix_second);

    return make_pair(it_first, it_second);
}
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWithSecond(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {

    auto itr = std::equal_range(range_begin, range_end, prefix,
        [&prefix](const std::string& x, const std::string& y)
        {
            return x.compare(0, prefix.length(), y.substr(0, prefix.length())) < 0;;
        });
    return std::make_pair(itr.first, itr.second);
}

int main()
{
    /*const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
    (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
    (z_result.second - begin(sorted_strings)) << endl;*/

    const vector<string> sorted_strings_second = { "moscow", "motovilikha", "murmansk" };

    const auto mo_result =
        FindStartsWithSecond(begin(sorted_strings_second), end(sorted_strings_second), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
        FindStartsWithSecond(begin(sorted_strings_second), end(sorted_strings_second), "mt");
    cout << (mt_result.first - begin(sorted_strings_second)) << " " <<
    (mt_result.second - begin(sorted_strings_second)) << endl;

    const auto na_result =
        FindStartsWithSecond(begin(sorted_strings_second), end(sorted_strings_second), "na");
    cout << (na_result.first - begin(sorted_strings_second)) << " " <<
    (na_result.second - begin(sorted_strings_second)) << endl;

    return 0;
}