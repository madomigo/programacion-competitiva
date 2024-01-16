#include <iostream>
#include <array>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    int a[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >>  a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += a[i][y];
    }
    for (int i = 0; i < cols; i++) {
        sum += a[x][i];
    }
    sum -= a[x][y];
    cout << sum << endl;
}