#include <iostream>
using namespace std;

int main() {
    int rows, cols, num, mx, mx_i, mx_j;
    mx = 0;
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> num;
            if (num > mx) {
                mx = num;
                mx_i = i;
                mx_j = j;
            }
        }
    }
    cout << mx_i << endl << mx_j << endl;
}