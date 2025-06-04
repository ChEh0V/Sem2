#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <list>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Задача 1: Чередование букв из двух слов
void task1() {
    string word1, word2;
    cout << "Введите первое слово: ";
    cin >> word1;
    cout << "Введите второе слово: ";
    cin >> word2;

    string result;
    size_t max_len = max(word1.size(), word2.size());

    for (size_t i = 0; i < max_len; ++i) {
        if (i < word1.size()) result += word1[i];
        if (i < word2.size()) result += word2[i];
    }

    cout << "Результат: " << result << endl;
}

// Задача 2: Укорачивание ФИО до фамилии и имени
void task2() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string fullname;
    cout << "Введите ФИО (Фамилия Имя Отчество): ";
    getline(cin, fullname);

    size_t first_space = fullname.find(' ');
    size_t second_space = fullname.find(' ', first_space + 1);

    if (first_space != string::npos && second_space != string::npos) {
        string result = fullname.substr(0, second_space);
        cout << "Результат: " << result << endl;
    } else {
        cout << "Неверный формат ввода. Ожидается Фамилия Имя Отчество." << endl;
    }
}

// Задача 3: Удвоение пробелов в файле
void task3() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input_filename, output_filename;
    cout << "Введите имя входного файла: ";
    getline(cin, input_filename);
    cout << "Введите имя выходного файла: ";
    getline(cin, output_filename);

    ifstream input(input_filename);
    ofstream output(output_filename);

    if (!input.is_open()) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return;
    }

    if (!output.is_open()) {
        cerr << "Ошибка открытия выходного файла!" << endl;
        input.close();
        return;
    }

    char c;
    while (input.get(c)) {
        output.put(c);
        if (c == ' ') output.put(' ');
    }

    input.close();
    output.close();
    cout << "Файл обработан успешно!" << endl;
}

// Задача 4: Телефонная книга на векторах
void task4() {
    vector<string> names;
    vector<string> phones;
    string name, phone;

    cout << "Вводите пары 'Имя Номер' (для окончания введите 'end'):" << endl;
    while (true) {
        cin >> name;
        if (name == "end") break;
        cin >> phone;
        names.push_back(name);
        phones.push_back(phone);
    }

    auto print_vectors = [](const vector<string>& n, const vector<string>& p) {
        cout << "Телефонная книга:" << endl;
        for (size_t i = 0; i < n.size(); ++i) {
            cout << n[i] << " - " << p[i] << endl;
        }
    };

    print_vectors(names, phones);

    cout << "\nВведите имя для поиска: ";
    cin >> name;

    auto it = find(names.begin(), names.end(), name);
    if (it != names.end()) {
        size_t index = distance(names.begin(), it);
        cout << "Найден: " << names[index] << " - " << phones[index] << endl;

        names.erase(names.begin() + index);
        phones.erase(phones.begin() + index);

        cout << "\nОбновленная телефонная книга:" << endl;
        print_vectors(names, phones);
    } else {
        cout << "Абонент не найден!" << endl;
    }
}

// Класс для задач 5 и 7
class Graduate {
    string name;
    double rating;
public:
    Graduate() : name(""), rating(0) {}
    Graduate(string Name, double Rating) : name(Name), rating(Rating) {}

    bool operator<(const Graduate& other) const { return rating < other.rating; }
    bool operator==(const Graduate& other) const { return name == other.name && rating == other.rating; }

    string getName() const { return name; }
    double getRating() const { return rating; }
    void setRating(double r) { rating = r; }
};


// Задача 5: Работа с выпускниками
void task5() {
    vector<Graduate> graduates = {
        Graduate("Иванов", 99),
        Graduate("Петров", 430),
        Graduate("Семенов", 70),
        Graduate("Котов", 540),
        Graduate("Белых", 230),
        Graduate("Черных", 350)
    };

    auto print_graduates = [](const vector<Graduate>& grads) {
        cout << "Список выпускников:" << endl;
        for (const auto& g : grads) {
            cout << g.getName() << ": " << g.getRating() << endl;
        }
    };

    print_graduates(graduates);

    auto max_it = max_element(graduates.begin(), graduates.end());
    cout << "\nВыпускник с максимальным рейтингом: "
         << max_it->getName() << ": " << max_it->getRating() << endl;

    double increase;
    cout << "\nВведите число для увеличения рейтинга: ";
    cin >> increase;

    for (auto& g : graduates) {
        g.setRating(g.getRating() + increase);
    }

    cout << "\nОбновленный список выпускников:" << endl;
    print_graduates(graduates);
}

// Задача 6: Телефонная книга на map
void task6() {
    map<string, string> phonebook;
    string name, phone;

    cout << "Вводите пары 'Имя Номер' (для окончания введите 'end'):" << endl;
    while (true) {
        cin >> name;
        if (name == "end") break;
        cin >> phone;
        phonebook[name] = phone;
    }

    auto print_phonebook = [](const map<string, string>& pb) {
        cout << "Телефонная книга:" << endl;
        for (const auto& entry : pb) {
            cout << entry.first << " - " << entry.second << endl;
        }
    };

    print_phonebook(phonebook);

    cout << "\nВведите имя для поиска: ";
    cin >> name;

    auto it = phonebook.find(name);
    if (it != phonebook.end()) {
        cout << "Найден: " << it->first << " - " << it->second << endl;

        phonebook.erase(it);

        cout << "\nОбновленная телефонная книга:" << endl;
        print_phonebook(phonebook);
    } else {
        cout << "Абонент не найден!" << endl;
    }
}

// Класс Point для задачи 7
class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}

    double distance() const {
        return sqrt(x*x + y*y);
    }

    bool operator<(const Point& other) const {
        return distance() < other.distance();
    }
};

// Задача 7: Работа с точками
void task7() {
    list<Point> points = {
        Point(1.2, 6.3),
        Point(4.0, 0.7),
        Point(7.2, 0.8),
        Point(5.3, 3.0),
        Point(4.9, 6.6),
        Point(9.3, 0.2)
    };

    auto print_points = [](const list<Point>& pts) {
        cout << "Список точек:" << endl;
        for (const auto& p : pts) {
            cout << fixed << setprecision(2);
            cout << "(" << p.x << ", " << p.y << ")" << endl;
        }
    };

    print_points(points);

    auto max_it = max_element(points.begin(), points.end());
    cout << "\nНаиболее удаленная точка: ("
         << fixed << setprecision(2)
         << max_it->x << ", " << max_it->y << ")" << endl;

    double shift;
    cout << "\nВведите сдвиг по оси X: ";
    cin >> shift;

    for (auto& p : points) {
        p.x -= shift;
    }

    cout << "\nСдвинутые точки:" << endl;
    print_points(points);
}

// Задача 8: Работа с map
void task8() {
    map<int, double> m;
    for (int i = 1; i <= 9; ++i) {
        m[i] = i * 100.0;
    }

    cout << "Исходное отображение:" << endl;
    double sum = 0;
    for (const auto& pair : m) {
        cout << pair.first << " - " << pair.second << endl;
        sum += pair.second;
    }

    cout << fixed << setprecision(2);
    cout << "\nСумма значений: " << sum << endl;

    cout << "\nНормализованное отображение:" << endl;
    for (auto& pair : m) {
        pair.second /= sum;
        cout << pair.first << " - " << pair.second << endl;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        cout << "\nВыберите задачу (1-8) или 0 для выхода: ";
        int choice;
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            default: cout << "Неверный выбор!" << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nНажмите Enter для продолжения...";
        cin.get();
    }

    return 0;
}
