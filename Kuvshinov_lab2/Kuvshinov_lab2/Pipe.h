#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <string>
#include <iostream>
#include <fstream>

class Pipe {
private:
    std::string name;
    double length;
    double diameter;
    bool in_repair;

public:
    Pipe();
    void input();
    void output() const;
    void editRepairStatus();
    void saveToFile(std::ofstream& out) const;
    void loadFromFile(std::ifstream& in);
};

#endif
