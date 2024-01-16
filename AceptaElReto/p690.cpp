#include <bits/stdc++.h>
using namespace std;

int main () {
    int w,h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        
        float total = 0;
        bool abierto = false;

        string s;
        for (int i = 0; i < h; i++) {
            abierto = false;
            cin >> s;
            //cout << "mi cadena: " << s << '\n';
            for (int j = 0; j < w; j++) {
                if (s[j] != '.') {
                    abierto = !abierto;
                    total = total + 0.5;
                }
                
                else if (s[j] == '.' && abierto) {
                    total += 1;
                }

            
            }


        } 

        cout << (int) total << '\n';
    
   }

    
}