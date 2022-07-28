// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};
int FindMaxRepetitionCount(const vector<Region>& regions) {
    int max_repeat = 0;
    size_t r_size = regions.size();
    //can be used map<region, int> instead - region = key, int = value (how many this region meets) (used ++map[key] for changing value when region meets)
    for (size_t i = 0; i < r_size; ++i) {
        int repeat = 0;
        for (size_t j = 0; i < r_size; ++i) {
            if (tie(regions[i].std_name, regions[i].parent_std_name, regions[i].names, regions[i].population) == 
                tie(regions[j].std_name, regions[j].parent_std_name, regions[j].names, regions[j].population))
                ++repeat;
        }
        if (repeat > max_repeat)
            max_repeat = repeat;
    }
    return max_repeat;
}
/*
bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
        tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetition_count;
    for (const Region& region : regions) {
        result = max(result, ++repetition_count[region]);
    }
    return result;
}*/

int main()
{
    cout << FindMaxRepetitionCount({
    {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    },
    }) << endl;

    cout << FindMaxRepetitionCount({
    {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Toulouse",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        31
    },
    }) << endl;

    return 0;
}

