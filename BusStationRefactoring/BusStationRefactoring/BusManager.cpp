#include "BusManager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	BusesToStops.insert(make_pair(bus, stops));
	for (const string& stop : stops) {
		StopsToBuses[stop].push_back(bus);
	}
}
BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	if (StopsToBuses.count(stop) == 0) {
		return BusesForStopResponse{ vector<string>() };
	}
	else {
		return BusesForStopResponse{ vector<string>{StopsToBuses.at(stop)} };
	}
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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

AllBusesResponse BusManager::GetAllBuses() const {
	return AllBusesResponse{ BusesToStops };
}
