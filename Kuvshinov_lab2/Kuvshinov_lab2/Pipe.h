#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <fstream>

class Pipe {
private:
    int id;                     // ���������� �������������
    std::string name;           // ��������
    double length;              // �����
    double diameter;            // �������
    bool inRepair;              // ������� "� �������"

public:
    // ����������� �� ���������
    Pipe() : id(0), name(""), length(0), diameter(0), inRepair(false) {}

    // ����������� � ID
    Pipe(int id) : id(id), name(""), length(0), diameter(0), inRepair(false) {}

    // ������ ��� ID
    int getId() const { return id; }

    // ���� ������
    void input();

    // ����� ������
    void output() const;

    // �������������� ������� �������
    void editRepairStatus();

    // ���������� � ����
    void saveToFile(std::ofstream& out) const;

    // �������� �� �����
    void loadFromFile(std::ifstream& in);
};

#endif
