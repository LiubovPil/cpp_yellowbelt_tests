#include "Query.h"

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