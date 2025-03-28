#include <iostream>
#include <cstdlib> 

using namespace std;

int getHours() {
    int hours;
    cout << "Введите часы (0-23): ";
    cin >> hours;
    return hours;
}

int getMinutes() {
    int minutes;
    cout << "Введите минуты (0-59): ";
    cin >> minutes;
    return minutes;
}

int toTotalMinutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

int timeDifference(int totalMinutes) {
    int referenceTime = 12 * 60; 
    return abs(totalMinutes - referenceTime); 
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    int H = 0, M = 0; // Переменные для хранения введенных данных

    do {
        cout << "1. Ввести часы" << endl;
        cout << "2. Ввести минуты" << endl;
        cout << "3. Перевести время в минуты" << endl;
        cout << "4. Разница с 12:00" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
            case 1:
                H = getHours();
                break;
            case 2:
                M = getMinutes();
                break;
            case 3: {
                int total = toTotalMinutes(H, M);
                cout << "Общее время в минутах: " << total << endl;
                break;
            }
            case 4: {
                int total = toTotalMinutes(H, M);
                int diff = timeDifference(total);
                cout << "Разница с 12:00 (в минутах): " << diff << endl;
                break;
            }
            case 0:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор!" << endl;
                break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}