#include <bits/stdc++.h>
using namespace std;

int main () {
    bool escalera;
    string carta;
    char palo, paloOR;
    
    while (true) {
        escalera = true;
        string baraja [] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        cin >> carta;
        if (carta == "0") break;
        cin >> palo;
        paloOR = palo;
        for (int i = 0; i < 4; i++) {
            if (i != 0) {
                cin >> carta >> palo;
                if (palo != paloOR) escalera = false;
            }

            for (int j = 0; j < 13; j++) {
                if (baraja[j] == carta) baraja[j] = "0";
            }
        }

        if (!escalera) {
            cout << "NADA\n"; 
            continue;
        }
        int cnt = 0;
        bool h = false;
        bool can = false;
        string ans;

        for (int i = 0; i < 13; i++) {
            if (baraja[i] == "0") {
                cnt++;
            }
            else if (cnt != 0) {
                if (h) {
                    break;
                }
                h = true;
                ans = baraja[i];
            }
            if (cnt == 4 && h) {
                cout << ans << " " << palo << '\n';
                can = true;
                break;
            }
            if (cnt == 4 && i + 1 < 13) {
                cout << baraja[i + 1] << " " << palo << '\n';
                can = true; 
                break;
            }
            else if (cnt == 4) {
                cout << baraja[i - 4] << " " << palo << '\n';
                can = true;
                break;
            }
        }
        if (!can) cout << "NADA\n";
    }
}