#include <iostream>
using namespace std;

int main() {
    char c;

    while (true) {
        int v, i;
        v = i = 0;
        cin >> c;
        if (c == '.') break;

        while (c != '.') {
            switch(c) {
                case 'V':
                    v++;
                    break;
                case 'I':
                    i++;
                    break;
                case 'A':
                    v++;
                    i++;
                    break;
            }
            cin >> c;

        }

        if (v == i) cout << "EMPATE" << endl;
        else if (v > i) cout << "VERANO" << endl;
        else cout << "INVIERNO" << endl;
    }
}