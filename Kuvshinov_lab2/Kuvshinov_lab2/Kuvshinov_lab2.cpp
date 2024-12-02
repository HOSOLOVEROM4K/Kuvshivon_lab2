#include <iostream>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "Station.h"

void showMenu() {
    std::cout 
        << "1. Добавить трубу\n"
        << "2. Добавить КС\n"
        << "3. Просмотреть все объекты\n"
        << "4. Редактировать статус ремонта трубы\n"
        << "5. Редактировать цехи КС\n"
        << "6. Сохранить данные в файл\n"
        << "7. Загрузить данные из файла\n"
        << "0. Выход\n"
        << "Введите номер действия: ";
}

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<Pipe> pipes;
    std::vector<Station> stations;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

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
        case 3: {
            std::cout << "\nСписок труб:\n";
            for (size_t i = 0; i < pipes.size(); ++i) {
                std::cout << i + 1 << ". ";
                pipes[i].output();
            }
            std::cout << "\nСписок КС:\n";
            for (size_t i = 0; i < stations.size(); ++i) {
                std::cout << i + 1 << ". ";
                stations[i].output();
            }
            break;
        }
        case 4: {
            size_t index;
            std::cout << "Введите номер трубы для редактирования: ";
            std::cin >> index;
            if (index > 0 && index <= pipes.size()) {
                pipes[index - 1].editRepairStatus();
            }
            else {
                std::cout << "Ошибка: Неверный номер трубы.\n";
            }
            break;
        }
        case 5: {
            size_t index;
            std::cout << "Введите номер КС для редактирования: ";
            std::cin >> index;
            if (index > 0 && index <= stations.size()) {
                stations[index - 1].editWorkshops();
            }
            else {
                std::cout << "Ошибка: Неверный номер КС.\n";
            }
            break;
        }
        case 6: {
            std::ofstream file("data.txt");
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
                std::cout << "Данные сохранены.\n";
            }
            else {
                std::cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 7: {
            std::ifstream file("data.txt");
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
                std::cout << "Данные загружены.\n";
            }
            else {
                std::cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 0:
            return 0;
        default:
            std::cout << "Ошибка: Неверный номер действия.\n";
            break;
        }
    }
}
