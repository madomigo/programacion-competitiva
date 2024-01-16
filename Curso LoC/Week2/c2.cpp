#include <iostream>
using namespace std;

int main () {
    int rows, temp, num, sum;
    sum = 0;
    cin >> rows;
    temp = rows - 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cin >> num;
            if (j == temp) {
                sum += num;
                temp--;
            }
        }
    }
    cout << sum << endl;
}