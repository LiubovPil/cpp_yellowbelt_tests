#include "Responses.h"

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

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.ListAllBuses.empty()) {
		os << "No buses" << "\n";
	}
	else {
		for (const auto& item : r.ListAllBuses) {
			os << "Bus " << item.first << ":";
			for (const auto& item : item.second) {
				os << " " << item;
			}
			os << "\n";
		}
	}
	return os;
}
