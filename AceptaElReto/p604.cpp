#include <iostream>
using namespace std;

int main() {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        int c, d, p, t, sum;
        c = d = p = t = sum = 0;
        char carta;
        char palo;
        for (int j = 0; j < 13; j++) {
            cin >> carta;
            cin >> palo;
            if (palo == '0') cin >> palo;

            switch (carta) {
                case 'A': 
                    sum += 4;
                    break;
                case 'K':
                    sum += 3;
                    break;
                case 'Q':
                    sum += 2;
                    break;
                case 'J':
                    sum += 1;
                    break;
            }

            switch (palo) {
                case 'C': 
                    c++;
                    break;
                case 'D':
                    d++;
                    break;
                case 'P':
                    p++;
                    break;
                case 'T':
                    t++;
                    break;
            }

            
        }
        switch (t) {
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 2;
                break;
            case 2:
                sum += 1;
                break;  
        }

        switch (p) {
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 2;
                break;
            case 2:
                sum += 1;  
                break;  
        }

        switch (d) {
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 2;
                break;
            case 2:
                sum += 1; 
                break;  
        }

        switch (c) {
            case 0:
                sum += 3;
                break;
            case 1:
                sum += 2;
                break;
            case 2:
                sum += 1; 
                break;   
        }
        cout << sum << endl;
    }
}