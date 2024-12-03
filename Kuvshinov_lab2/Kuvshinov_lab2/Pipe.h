#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <fstream>

class Pipe {
private:
    int id;
    std::string name;
    double length;
    double diameter;
    bool inRepair;

public:
    Pipe() : id(0), name(""), length(0), diameter(0), inRepair(false) {}
    Pipe(int id) : id(id), name(""), length(0), diameter(0), inRepair(false) {}
    int getId() const { return id; }
    std::string getName() const { return name; } // Добавить, если используется в поиске
    bool getRepairStatus() const { return inRepair; } // Добавлен метод для исправления ошибки
    void input();
    void output() const;
    void editRepairStatus();
    void saveToFile(std::ofstream& out) const;
    void loadFromFile(std::ifstream& in);
};

#endif
