#include <iostream>
using namespace std;

int main() {
    int rows, sum, temp;
    cin >> rows >> sum;
    temp = rows - 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (j != temp) {
                cout << 1 << " ";
            }
            else {
                cout << sum - (rows - 1) << " ";
            }
        }
        temp--;
        cout << endl;

    
    }
}