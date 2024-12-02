#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Pipe.h"
#include "Station.h"

using namespace std;


int getValidMenuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "\nВведите номер действия: ";
        cin >> input;

        try {
            choice = stoi(input);
            if (choice >= 0 && choice <= 9) {
                return choice;
            }
            else {
                cout << "Ошибка: Введите число от 0 до 9.\n";
            }
        }
        catch (exception& e) {
            cout << "Ошибка: Введите корректное целое число.\n";
        }
    }
}


void deletePipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для удаления.\n";
        return;
    }
    cout << "Введите номер трубы для удаления: ";
    size_t index;
    cin >> index;
    if (index > 0 && index <= pipes.size()) {
        pipes.erase(pipes.begin() + index - 1);
        cout << "Труба удалена.\n";
    }
    else {
        cout << "Ошибка: Неверный номер трубы.\n";
    }
}

void deleteStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для удаления.\n";
        return;
    }
    cout << "Введите номер КС для удаления: ";
    size_t index;
    cin >> index;
    if (index > 0 && index <= stations.size()) {
        stations.erase(stations.begin() + index - 1);
        cout << "КС удалена.\n";
    }
    else {
        cout << "Ошибка: Неверный номер КС.\n";
    }
}

void showAllObjects(const vector<Pipe>& pipes, const vector<Station>& stations) {
    cout << "\nСписок труб:\n";
    for (size_t i = 0; i < pipes.size(); ++i) {
        cout << i + 1 << ". ";
        pipes[i].output();
    }
    cout << "\nСписок КС:\n";
    for (size_t i = 0; i < stations.size(); ++i) {
        cout << i + 1 << ". ";
        stations[i].output();
    }
}

void editPipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        return;
    }
    cout << "Введите номер трубы для редактирования: ";
    size_t index;
    cin >> index;
    if (index > 0 && index <= pipes.size()) {
        pipes[index - 1].editRepairStatus();
    }
    else {
        cout << "Ошибка: Неверный номер трубы.\n";
    }
}

void editStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для редактирования.\n";
        return;
    }
    cout << "Введите номер КС для редактирования: ";
    size_t index;
    cin >> index;
    if (index > 0 && index <= stations.size()) {
        stations[index - 1].editWorkshops();
    }
    else {
        cout << "Ошибка: Неверный номер КС.\n";
    }
}

void showMenu() {
    cout << "\nМеню:\n"
        << "1. Добавить трубу\n"
        << "2. Добавить КС\n"
        << "3. Просмотреть все объекты\n"
        << "4. Редактировать статус ремонта трубы\n"
        << "5. Редактировать цехи КС\n"
        << "6. Удалить трубу\n"
        << "7. Удалить КС\n"
        << "8. Сохранить данные в файл\n"
        << "9. Загрузить данные из файла\n"
        << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Pipe> pipes;
    vector<Station> stations;

    while (true) {
        showMenu();

        
        int choice = getValidMenuChoice();

        switch (choice) {
        case 1: {
            Pipe p;
            p.input();
            pipes.push_back(p);
            break;
        }
        case 2: {
            Station s;
            s.input();
            stations.push_back(s);
            break;
        }
        case 3:
            showAllObjects(pipes, stations);
            break;
        case 4:
            editPipe(pipes);
            break;
        case 5:
            editStation(stations);
            break;
        case 6:
            deletePipe(pipes);
            break;
        case 7:
            deleteStation(stations);
            break;
        case 8: {
            ofstream file("data.txt");
            if (file.is_open()) {
                file << pipes.size() << '\n';
                for (const auto& pipe : pipes) {
                    pipe.saveToFile(file);
                }
                file << stations.size() << '\n';
                for (const auto& station : stations) {
                    station.saveToFile(file);
                }
                file.close();
                cout << "Данные сохранены.\n";
            }
            else {
                cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 9: {
            ifstream file("data.txt");
            if (file.is_open()) {
                size_t count;
                file >> count;
                pipes.clear();
                for (size_t i = 0; i < count; ++i) {
                    Pipe p;
                    p.loadFromFile(file);
                    pipes.push_back(p);
                }
                file >> count;
                stations.clear();
                for (size_t i = 0; i < count; ++i) {
                    Station s;
                    s.loadFromFile(file);
                    stations.push_back(s);
                }
                file.close();
                cout << "Данные загружены.\n";
            }
            else {
                cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 0:
            return 0;
        default:
            break;
        }
    }
}
