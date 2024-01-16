#include <iostream>
#include <vector>

using namespace std;

int main () {
    int num, pits;
    pits = 0;
    cin >> num;
    int vector[num];
    for (int i = 0; i < num; i++) {
        cin >> vector[i];
    }
    for (int i = 1; i < num - 1; i++) {
        if (vector[i] < vector[i-1] && vector[i] < vector[i+1]) {
            pits++;
        }
    }
    cout << pits << endl;
}