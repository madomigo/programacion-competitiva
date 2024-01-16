#include<iostream>
using namespace std;


int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) 
            break;
        
        int s, e;
        int total = 0;
        while (true) {
            cin >> s >> e;
            if (s == 0 && e == 0)
                break;
            total++;
        }

        cout << total - (n-1) << '\n';
    }
}