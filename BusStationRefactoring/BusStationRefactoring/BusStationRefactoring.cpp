// Tasks from the course "Fundamentals of C++: Yellow Belt
// Done by Liubov Piliagina

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string request;
	is >> request;
	if (request == "NEW_BUS")
	{
		q.type = QueryType::NewBus;

		is >> q.bus;

		int stop_count = 0;
		is >> stop_count;
		vector<string>& stops = q.stops;
		stops.resize(stop_count);

		for (string& item : stops) {
			is >> item;
		}
	}
	else if (request == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (request == "STOPS_FOR_BUS")
	{
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	vector<string> ListBuses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.ListBuses.empty()) {
		os << "No stop" << "\n";
	}
	else {
		bool first = true;
		for (const auto& item : r.ListBuses) {
			if (!first) {
				os << " ";
			}
			os << item;
			if (first) {
				first = false;
			}
		}
		os << "\n";
	}
	return os;
}

struct StopsForBusResponse {
	// в задании остановки не отсортированы по ключам, поэтому здесь ветор пар
	vector<pair<string, vector<string>>> ListsStops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.ListsStops.empty()) {
		os << "No bus" << "\n";
	}
	else {
		for (const auto& item : r.ListsStops) {
			os << "Stop " << item.first << ":";
			bool first = true;
			for (const auto& item : item.second) {
				os << " " << item;
			}
			os << "\n";
		}
	}
	return os;
}

struct AllBusesResponse {
	map <string, vector<string>> ListAllBuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.ListAllBuses.empty()) {
		os << "No buses" << "\n";
	}
	else {
		for (const auto& item : r.ListAllBuses) {
			os << "Bus " << item.first << ":";
			for (const auto& item : item.second) {
				os << " " <<item;
			}
			os << "\n";
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		BusesToStops.insert(make_pair(bus, stops));
		for (const string& stop : stops) {
			StopsToBuses[stop].push_back(bus);
		}
	}
	BusesForStopResponse GetBusesForStop(const string& stop) const {
		if (StopsToBuses.count(stop) == 0) {
			return BusesForStopResponse{vector<string>()};
		}
		else {
			return BusesForStopResponse{vector<string>{StopsToBuses.at(stop)}};
		}
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		vector<pair<string, vector<string>>> result;
		if (BusesToStops.count(bus) == 0) {
			return StopsForBusResponse{ result };
		}
		else {
			for (const string& stop : BusesToStops.at(bus)) {
				vector<string> buses;
				if (StopsToBuses.at(stop).size() == 1) {
					buses.push_back("no interchange");
				}
				else {
					for (const string& other_bus : StopsToBuses.at(stop)) {
						if (bus != other_bus) {
							buses.push_back(other_bus);
						}
					}
				}
				result.push_back(make_pair(stop, buses));
			}
			return StopsForBusResponse{ result };
		}
	}

	AllBusesResponse GetAllBuses() const {
		return AllBusesResponse{ BusesToStops };
	}

private:
	map<string, vector<string>> BusesToStops, StopsToBuses;
};

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}