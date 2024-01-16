#include <iostream>
#include <array>
using namespace std;

int main() {
    int rows, cols, num;
    cin >> rows >> cols;
    int a[cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> num;
            if (i == 0) {
                a[j] = num;
            }
            else {
                if (num > a[j]) {
                    a[j] = num;
                }
            }

        }
    }

    for (int i = 0; i < cols - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[cols - 1] << endl;
}