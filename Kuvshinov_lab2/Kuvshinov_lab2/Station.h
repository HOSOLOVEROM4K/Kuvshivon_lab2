#ifndef STATION_H
#define STATION_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Station {
private:
    string name;
    int total_workshops;
    int working_workshops;
    double efficiency;

public:
    Station();
    void input();
    void output() const;
    void editWorkshops();
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
};

#endif
