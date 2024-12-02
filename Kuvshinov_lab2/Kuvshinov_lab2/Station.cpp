#include "Station.h"

Station::Station() : name(""), total_workshops(0), working_workshops(0), efficiency(0) {}

void Station::input() {
    cout << "������� �������� ��: ";
    cin.ignore();
    getline(cin, name);

    cout << "������� ����� ���������� �����: ";
    while (!(cin >> total_workshops) || total_workshops <= 0) {
        cout << "������! ������� ������������� ����� �����: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "������� ���������� ���������� �����: ";
    while (!(cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        cout << "������! ������� ����� �� 0 �� " << total_workshops << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "������� ������������� (0.0 - 100.0): ";
    while (!(cin >> efficiency) || efficiency < 0.0 || efficiency > 100.0) {
        cout << "������! ������� ����� �� 0.0 �� 100.0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void Station::output() const {
    cout << "��: " << name
        << "\n����� ���������� �����: " << total_workshops
        << "\n���������� ����: " << working_workshops
        << "\n�������������: " << efficiency << "%\n";
}

void Station::editWorkshops() {
    cout << "������� ����� ���������� ���������� ����� (�� 0 �� " << total_workshops << "): ";
    while (!(cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        cout << "������! ������� ����� �� 0 �� " << total_workshops << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void Station::saveToFile(ofstream& out) const {
    out << name << '\n'
        << total_workshops << '\n'
        << working_workshops << '\n'
        << efficiency << '\n';
}

void Station::loadFromFile(ifstream& in) {
    in.ignore();
    getline(in, name);
    in >> total_workshops >> working_workshops >> efficiency;
}
