#include "Station.h"
#include <iostream>
#include <string>

using namespace std;

void Station::input() {
    cout << "������� �������� ��: ";
    cin.ignore();
    getline(cin, name);

    // ���� ������ ���������� ����� � ��������� �� ������������
    while (true) {
        cout << "������� ����� ���������� �����: ";
        cin >> totalWorkshops;

        if (cin.fail()) {  // �������� �� ������ �����
            cin.clear();  // ����� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� ������ �����
            cout << "������: ������� ���������� ����� ��� ������ ���������� �����.\n";
        }
        else {
            break;  // ���������� �����, ���� ���� ���������
        }
    }

    // ���� ���������� ���������� ����� � ��������� �� ������������
    while (true) {
        cout << "������� ���������� ���������� �����: ";
        cin >> workingWorkshops;

        if (cin.fail()) {  // �������� �� ������ �����
            cin.clear();  // ����� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� ������ �����
            cout << "������: ������� ���������� ����� ��� ���������� ���������� �����.\n";
        }
        else if (workingWorkshops > totalWorkshops) {
            cout << "������: ������� ����� �� ����� ���� ������ ������ ����������.\n";
        }
        else {
            break;  // ���������� �����, ���� ���� ���������
        }
    }

    cout << "������� ������������� ��: ";
    cin >> efficiency;
}


void Station::output() const {
    cout << "�� ID: " << id << "\n"
        << "��������: " << name << "\n"
        << "����� ���������� �����: " << totalWorkshops << "\n"
        << "���������� �����: " << workingWorkshops << "\n"
        << "�������������: " << efficiency << "\n";
}

void Station::editWorkshops() {
    cout << "������� ���������� ���������� �����: " << workingWorkshops << "\n";
    cout << "������� ����� ���������� ���������� �����: ";

    int newWorkingWorkshops;
    do {
        cin >> newWorkingWorkshops;
        if (newWorkingWorkshops > totalWorkshops) {
            cout << "������: ������� ����� �� ����� ���� ������ ������ ����������.\n";
        }
    } while (newWorkingWorkshops > totalWorkshops);

    workingWorkshops = newWorkingWorkshops;
}

void Station::saveToFile(ofstream& out) const {
    out << id << "\n"
        << name << "\n"
        << totalWorkshops << "\n"
        << workingWorkshops << "\n"
        << efficiency << "\n";
}

void Station::loadFromFile(ifstream& in) {
    in >> id;
    in.ignore(); // ������� ������� ����� ������ ����� ������� ������
    getline(in, name);
    in >> totalWorkshops >> workingWorkshops >> efficiency;
}
