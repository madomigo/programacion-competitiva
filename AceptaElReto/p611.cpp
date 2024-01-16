#include <iostream>
using namespace std;

int main () {
    int ano, obras;
    string autor;
    while (cin >> ano) {
        getchar();
        getline(cin, autor);
        
        cin >> obras;

        int year, fecha1;
        fecha1 = 0;
        string title, primera;
        bool antes = false;
        
        for (int i = 0; i < obras; i++) {
            cin >> year;
            getchar();
            getline(cin, title);

            if (year >= ano && (year < fecha1 || fecha1 == 0)) {
                fecha1 = year;
                primera = title;
            }
            if (year < ano) antes = true;
        }

        if (!antes) {
            cout << "TODAS\n";
        }
        else if (fecha1 == 0) {
            cout << "NINGUNA\n";
        }
        else {
            cout << primera << "\n";
        }
    }
}