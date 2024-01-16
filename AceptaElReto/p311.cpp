#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        string letra, nombre;
        int gravedad;
        priority_queue<pair<pair<int,int>, string>> q;
        while (n--) {
            cin >> letra;
            if (letra == "I") {
                cin >> nombre >> gravedad;
                q.push({{gravedad, n}, nombre});
            }   
            else {
                cout << q.top().second << '\n';
                q.pop();
            }      
        }

        cout << "----\n";
    }
}