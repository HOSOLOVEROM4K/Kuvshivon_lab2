#ifndef PIPE_H
#define PIPE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Pipe {
private:
    string name;
    double length;
    double diameter;
    bool in_repair;

public:
    Pipe();
    void input();
    void output() const;
    void editRepairStatus();
    void saveToFile(ofstream& out) const;
    void loadFromFile(ifstream& in);
};

#endif
