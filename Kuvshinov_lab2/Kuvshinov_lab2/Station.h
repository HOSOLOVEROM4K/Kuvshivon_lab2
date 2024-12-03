#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <fstream>

class Station {
private:
    int id;
    std::string name;
    int totalWorkshops;
    int workingWorkshops;
    double efficiency;

public:
    Station() : id(0), name(""), totalWorkshops(0), workingWorkshops(0), efficiency(0) {}
    Station(int id) : id(id), name(""), totalWorkshops(0), workingWorkshops(0), efficiency(0) {}
    int getId() const { return id; }
    std::string getName() const { return name; }  // ������� ��� ��������� �������� ��
    int getTotalWorkshops() const { return totalWorkshops; }  // ������� ��� ��������� ������ ����� �����
    int getWorkingWorkshops() const { return workingWorkshops; }  // ������� ��� ��������� ����� ���������� �����
    void input();
    void output() const;
    void editWorkshops();
    void saveToFile(std::ofstream& out) const;
    void loadFromFile(std::ifstream& in);
};

#endif
