#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    int friends[n];
    for (int i = 0; i < n; i++) {
        cin >> friends[i];
    }
 
    int planks[m];
    for (int i = 0; i < m; i++) {
        cin >> planks[i];
    }
 
    sort(friends, friends + n);
    sort(planks, planks + m);
 
 
    int can = 0;
    int barco = 0;
    for (int i = 0; i < n && barco < m; i++) {
        if (friends[i] <= planks[barco]) can++;
        else i--;
        barco++;
    }
 
    cout << can << "\n";
}
