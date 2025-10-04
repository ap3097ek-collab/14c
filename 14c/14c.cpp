

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//
//struct Data {
//    int day;
//    string month;
//    int year;
//};
//
//struct Man {
//    string surname;
//    string name;
//    int age;
//    Data birth;
//};
//
//string toLower(const string& s) {
//    string res = s;
//    for (char& c : res) c = tolower(c);
//    return res;
//}
//
//
//void zapis(const vector<Man>& arr) {
//    for (size_t i = 0; i < arr.size(); i++) {
//        const Man& m = arr[i];
//        cout << i + 1 << ". " << m.surname << " " << m.name
//            << ", вік: " << m.age
//            << ", дата народження: " << m.birth.day << " " << m.birth.month << " " << m.birth.year
//            << endl;
//    }
//}
//
//
//void dii(vector<Man>& arr) {
//    cout << "1. Додати запис\n2. Видалити запис\n3. Редагувати запис\n";
//    int choice;
//    cin >> choice;
//    cin.ignore();
//
//    switch (choice) {
//    case 1: {
//        Man m;
//        cout << "Прізвище: "; cin >> m.surname;
//        cout << "Ім'я: "; cin >> m.name;
//        cout << "Вік: "; cin >> m.age;
//        cout << "Дата народження (день місяць рік): ";
//        cin >> m.birth.day >> m.birth.month >> m.birth.year;
//        arr.push_back(m);
//        cout << "Запис додано.\n";
//        break;
//    }
//    case 2: {
//        int nomer;
//        cout << "Введіть номер запису для видалення: ";
//        cin >> nomer;
//        if (nomer >= 1 && nomer <= (int)arr.size()) {
//            arr.erase(arr.begin() + nomer - 1);
//            cout << "Запис видалено.\n";
//        }
//        else cout << "Невірний номер.\n";
//        break;
//    }
//    case 3: {
//        int nomer;
//        cout << "Введіть номер запису для редагування: ";
//        cin >> nomer;
//        if (nomer >= 1 && nomer <= (int)arr.size()) {
//            Man& m = arr[nomer - 1];
//            cout << "Прізвище: "; cin >> m.surname;
//            cout << "Ім'я: "; cin >> m.name;
//            cout << "Вік: "; cin >> m.age;
//            cout << "Дата народження (день місяць рік): ";
//            cin >> m.birth.day >> m.birth.month >> m.birth.year;
//            cout << "Запис відредаговано.\n";
//        }
//        else cout << "Невірний номер.\n";
//        break;
//    }
//    default: cout << "Невірний вибір\n"; break;
//    }
//}
//
//
//bool sortS(const Man& s1, const Man& s2) { return s1.surname < s2.surname; }
//bool sortN(const Man& n1, const Man& n2) { return n1.name < n2.name; }
//
//void sortR(vector<Man>& arr) {
//    cout << "Сортувати:\n1. Прізвище\n2. Ім'я\n";
//    int choice; cin >> choice;
//    switch (choice) {
//    case 1: sort(arr.begin(), arr.end(), sortS); break;
//    case 2: sort(arr.begin(), arr.end(), sortN); break;
//    default: cout << "Невірний вибір\n"; break;
//    }
//}
//
//void search(const vector<Man>& arr) {
//    cout << "Пошук за:\n1. Прізвищем\n2. Ім'ям\n";
//    int choice; cin >> choice;
//    string key;
//    cin.ignore();
//    bool found = false;
//
//    if (choice == 1) {
//        cout << "Введіть прізвище: "; getline(cin, key);
//        for (const Man& m : arr)
//            if (toLower(m.surname) == toLower(key)) {
//                cout << m.surname << " " << m.name << " " << m.age
//                    << " " << m.birth.day << " " << m.birth.month << " " << m.birth.year << endl;
//                found = true;
//            }
//    }
//    else if (choice == 2) {
//        cout << "Введіть ім'я: "; getline(cin, key);
//        for (const Man& m : arr)
//            if (toLower(m.name) == toLower(key)) {
//                cout << m.surname << " " << m.name << " " << m.age
//                    << " " << m.birth.day << " " << m.birth.month << " " << m.birth.year << endl;
//                found = true;
//            }
//    }
//    else {
//        cout << "Невірний вибір\n";
//        return;
//    }
//
//    if (!found) cout << "Записів не знайдено.\n";
//}
//
//void birthday(const vector<Man>& arr) {
//    string curMonth;
//    cout << "Введіть поточний місяць: ";
//    cin.ignore();
//    getline(cin, curMonth);
//
//    bool found = false;
//    for (const Man& m : arr)
//        if (toLower(m.birth.month) == toLower(curMonth)) {
//            cout << m.name << " " << m.surname << " - " << m.birth.day << " " << m.birth.month << endl;
//            found = true;
//        }
//    if (!found) cout << "Іменинників у цьому місяці немає.\n";
//}
//
//int main() {
//    system("chcp 1251>null");
//
//    vector<Man> arr{
//        {"Петров", "Петро", 24, {12, "вересень", 2001}},
//        {"Кравчук", "Оксана", 45, {9, "березень", 1980}},
//        {"Винник", "Олег", 22, {22, "грудень", 1982}}
//    };
//
//    int choice;
//    do {
//        cout << "\nМеню програми:\n"
//            << "1. Вивести усі записи\n"
//            << "2. Дії з записом\n"
//            << "3. Сортування записів\n"
//            << "4. Пошук запису\n"
//            << "5. Виведення іменинників\n"
//            << "0. Вихід\n";
//        cin >> choice;
//
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore(1000, '\n');
//            cout << "Невірний ввід, спробуйте ще раз.\n";
//            continue;
//        }
//
//        switch (choice) {
//        case 1: zapis(arr); break;
//        case 2: dii(arr); break;
//        case 3: sortR(arr); break;
//        case 4: search(arr); break;
//        case 5: birthday(arr); break;
//        case 0: break;
//        default: cout << "Невірний вибір\n"; break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}




//2
#/*include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 10;


void mazee(char maze[SIZE][SIZE], int playerX, int playerY, int lives) {
    system("cls");
    cout << "Життя: " << lives << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) cout << 'P';
            else cout << maze[i][j];
        }
        cout << endl;
    }
}


void trapRand(char maze[SIZE][SIZE], int numTraps = 5) {
    int ex, ey;
    do {
        ex = rand() % SIZE;
        ey = rand() % SIZE;
    } while (maze[ex][ey] != ' ');
    maze[ex][ey] = 'X';

    for (int i = 0; i < numTraps; i++) {
        int tx, ty;
        do {
            tx = rand() % SIZE;
            ty = rand() % SIZE;
        } while (maze[tx][ty] != ' ');
        maze[tx][ty] = '!';
    }
}

int main() {
    srand(time(0));
    system("chcp 1251>null");

    char maze[SIZE][SIZE] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#','#',' ','#',' ','#'},
        {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
        {'#',' ','#','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
        {'#',' ',' ',' ','#','#',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    int playerX = 1, playerY = 1; 
    int* x = &playerX;
    int* y = &playerY;

    int live = 3;

    trapRand(maze, 5); 
    mazee(maze, *x, *y, live);

    while (true) {
        char move = _getch();
        int nx = *x;
        int ny = *y;

        if (move == 'w' || move == 'W') nx--;
        else if (move == 's' || move == 'S') nx++;
        else if (move == 'a' || move == 'A') ny--;
        else if (move == 'd' || move == 'D') ny++;

        if (nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue; 
        if (maze[nx][ny] == '#') continue; 
        if (maze[nx][ny] == '!') {
            live--;
            cout << "Упс! Потрапили на пастку! Життя: " << live << endl;
            maze[nx][ny] = ' '; 
            _getch();
        }
        if (maze[nx][ny] == 'X') {
            cout << "Вітаємо! Ви знайшли вихід!\n";
            break;
        }

        *x = nx;
        *y = ny;
        mazee(maze, *x, *y, live);

        if (live <= 0) {
            cout << "Гру закінчено! Життя закінчились.\n";
            break;
        }
    }

    return 0;
}*/