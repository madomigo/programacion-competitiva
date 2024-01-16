#include <iostream>
using namespace std;

int main () {
    int rows, sum;
    cin >> rows >> sum;
    int a[rows][rows];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {

            if (i != 0 && a[i][j] + a[i - 1][j] == sum) {
                cout << "YES" << endl;
                return 0;
            }
            if (i + 1 != rows && a[i][j] + a[i + 1][j] == sum) {
                cout << "YES" << endl;
                return 0;
            }
            if (j != 0 && a[i][j] + a[i][j - 1] == sum) {
                cout << "YES" << endl;
                return 0;
            }
            if (j + 1 != rows && a[i][j] + a[i][j + 1] == sum) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;


}