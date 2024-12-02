#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Pipe.h"
#include "Station.h"

using namespace std;

// Проверка уникальности ID
bool isUniqueId(int id, const vector<Pipe>& pipes, const vector<Station>& stations) {
    // Проверяем ID среди труб
    for (const auto& pipe : pipes) {
        if (pipe.getId() == id) {
            return false;
        }
    }

    // Проверяем ID среди станций
    for (const auto& station : stations) {
        if (station.getId() == id) {
            return false;
        }
    }

    return true;
}

// Получение уникального ID от пользователя
int getUniqueId(const vector<Pipe>& pipes, const vector<Station>& stations) {
    int id;
    while (true) {
        cout << "Введите уникальный ID: ";
        cin >> id;

        if (isUniqueId(id, pipes, stations)) {
            return id; // ID уникален
        }
        else {
            cout << "Ошибка: ID уже используется. Попробуйте снова.\n";
        }
    }
}

// Функция для проверки корректности выбора действия
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

// Остальные функции работы с объектами остаются прежними
void showAllObjects(const vector<Pipe>& pipes, const vector<Station>& stations) {
    cout << "\nСписок труб:\n";
    for (const auto& pipe : pipes) {
        pipe.output();
    }
    cout << "\nСписок КС:\n";
    for (const auto& station : stations) {
        station.output();
    }
}

void deletePipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для удаления.\n";
        return;
    }

    cout << "Введите ID трубы для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
    if (it != pipes.end()) {
        pipes.erase(it);
        cout << "Труба удалена.\n";
    }
    else {
        cout << "Ошибка: Труба с таким ID не найдена.\n";
    }
}

void deleteStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для удаления.\n";
        return;
    }

    cout << "Введите ID КС для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
    if (it != stations.end()) {
        stations.erase(it);
        cout << "КС удалена.\n";
    }
    else {
        cout << "Ошибка: КС с таким ID не найдена.\n";
    }
}

void editPipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        return;
    }
    cout << "Введите ID трубы для редактирования: ";
    int id;
    cin >> id;

    auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
    if (it != pipes.end()) {
        it->editRepairStatus();
    }
    else {
        cout << "Ошибка: Труба с таким ID не найдена.\n";
    }
}

void editStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для редактирования.\n";
        return;
    }
    cout << "Введите ID КС для редактирования: ";
    int id;
    cin >> id;

    auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
    if (it != stations.end()) {
        it->editWorkshops();
    }
    else {
        cout << "Ошибка: КС с таким ID не найдена.\n";
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
            int id = getUniqueId(pipes, stations); // Получение уникального ID
            Pipe p(id); // Конструктор принимает ID
            p.input();
            pipes.push_back(p);
            break;
        }
        case 2: {
            int id = getUniqueId(pipes, stations); // Получение уникального ID
            Station s(id); // Конструктор принимает ID
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
