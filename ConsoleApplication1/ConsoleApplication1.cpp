#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> kolejka;
    int opcja, element;

    setlocale(LC_ALL, "pl_PL");

    do {
        cout << "Wybierz jedn¹ z opcji:\n";
        cout << "1. Wstaw element na pocz¹tek\n";
        cout << "2. Usuñ element z pocz¹tku\n";
        cout << "3. Wstaw element na koniec\n";
        cout << "4. Usuñ element z koñca\n";
        cout << "5. Wyœwietl pierwszy element\n";
        cout << "6. Wyœwietl ostatni element\n";
        cout << "7. Wyœwietl wszystkie elementy\n";
        cout << "8. Odwróæ kolejnoœæ elementów\n";
        cout << "9. Zlicz liczbê elementów\n";
        cout << "0. Wyjœcie\n";
        cin >> opcja;

        switch (opcja) {
        case 1:
            cout << "Podaj element: ";
            cin >> element;
            kolejka.push_front(element);
            break;
        case 2:
            if (!kolejka.empty()) {
                kolejka.pop_front();
            }
            else {
                cout << "Kolejka jest pusta!\n";
            }
            break;
        case 3:
            cout << "Podaj element: ";
            cin >> element;
            kolejka.push_back(element);
            break;
        case 4:
            if (!kolejka.empty()) {
                kolejka.pop_back();
            }
            else {
                cout << "Kolejka jest pusta!\n";
            }
            break;
        case 5:
            if (!kolejka.empty()) {
                cout << "Pierwszy element: " << kolejka.front() << endl;
            }
            else {
                cout << "Kolejka jest pusta!\n";
            }
            break;
        case 6:
            if (!kolejka.empty())
            {
                cout <<"Ostatni element: " << kolejka.back() << endl;
            }
            break;
        case 7:
            if (!kolejka.empty()) {
                cout << "Elementy kolejki: ";
                for (int i : kolejka) {
                    cout << i << " ";
                }
                cout << endl;
            }
            else {
                cout << "Kolejka jest pusta!\n";
            }
            break;
        case 8:
            if (!kolejka.empty()) {
                reverse(kolejka.begin(), kolejka.end());
            }
            else {
                cout << "Kolejka jest pusta!\n";
            }
            break;
        case 9:
            cout << "Liczba elementów w kolejce: " << kolejka.size() << endl;
            break;
        case 0:
            cout << "Koniec programu.\n";
            break;
        default:
            cout << "Nieprawid³owa opcja!\n";
            break;
        }
    } while (opcja != 0);

    return 0;
}
