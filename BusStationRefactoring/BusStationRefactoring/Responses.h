#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct BusesForStopResponse {
	vector<string> ListBuses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	// в задании остановки не отсортированы по ключам, поэтому здесь вектор пар
	vector<pair<string, vector<string>>> ListsStops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	map <string, vector<string>> ListAllBuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);


