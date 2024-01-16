#include <bits/stdc++.h>
using namespace std;

int main () {
    long long x1, y1, x2, y2;
    while (true) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;
            
        long long x, y;
        x = x2 - x1;
        y = y2 - y1;

        if (x == 0 || y == 0 || x == y || x == -y)
            cout << "SI\n";
        else 
            cout << "NO\n";
    
        
        
    }
}