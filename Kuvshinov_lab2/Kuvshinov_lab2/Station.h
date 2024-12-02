#pragma once
#ifndef STATION_H
#define STATION_H

#include <string>
#include <iostream>
#include <fstream>

class Station {
private:
    std::string name;
    int total_workshops;
    int working_workshops;
    double efficiency;

public:
    Station();
    void input();
    void output() const;
    void editWorkshops();
    void saveToFile(std::ofstream& out) const;
    void loadFromFile(std::ifstream& in);
};

#endif
