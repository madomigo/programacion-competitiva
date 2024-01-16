#include <iostream>
using namespace std;

int main () {
    int rows, cols, w1, w2, num;
    num = 0;
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> w1 >> w2;
            if (w1 == 1 || w2 == 1) {
                num++;
            }

        }
    }
    cout << num << endl;
}