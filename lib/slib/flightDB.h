#ifndef __FLIGHT_DB_H
#define __FLIGHT_DB_H

#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include "airport.h"
#include "flight.h"

class FlightDatabase {
public:
    enum class DataParameters { icao24, callsign, origin, destination, departure_time, arrival_time, totalParm };
    FlightDatabase() : loaded(false) {}
    bool load_db(const std::string& dataBasePath,const std::string& airportCode);
    const std::list<Flight>& get_flights_by_airport_name(std::string airport_name, bool from) const; // from == true, to == false
    const std::list<Flight>& get_flights_by_callsign(std::string callsign) const;
    void rerun_script() const;
    const std::list<const std::string&> get_airports_names() const;
private:
    std::list<Flight>&& getFlightsFromFiles(ifstream& inFile);
    bool load_flights_to_DB(const string& filePath, const string& postfix, const string& airportCode);

    std::list<Airport> Airports;
    bool loaded;
};

#endif