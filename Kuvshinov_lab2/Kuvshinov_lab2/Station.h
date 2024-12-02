#ifndef STATION_H
#define STATION_H

#include <iostream>
#include <fstream>

class Station {
private:
    int id;                     // Уникальный идентификатор
    std::string name;           // Название
    int totalWorkshops;         // Общее количество цехов
    int workingWorkshops;       // Количество работающих цехов
    double efficiency;          // Эффективность

public:
    // Конструктор по умолчанию
    Station() : id(0), name(""), totalWorkshops(0), workingWorkshops(0), efficiency(0) {}

    // Конструктор с ID
    Station(int id) : id(id), name(""), totalWorkshops(0), workingWorkshops(0), efficiency(0) {}

    // Геттер для ID
    int getId() const { return id; }

    // Ввод данных
    void input();

    // Вывод данных
    void output() const;

    // Редактирование цехов
    void editWorkshops();

    // Сохранение в файл
    void saveToFile(std::ofstream& out) const;

    // Загрузка из файла
    void loadFromFile(std::ifstream& in);
};

#endif
