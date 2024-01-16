#include <iostream>
using namespace std;

int main() {
    int rows, num, temp2, sum;
    sum = 0;
    cin >> rows;
    temp2 = rows - 1; 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cin >> num;
            if (i == j) {
                sum += num;                
            }
            else if (j == temp2) {
                sum += num;
            }
            else if (i == (rows - 1) / 2) {
                sum += num;
            }
            else if (j == (rows - 1) / 2) {
                sum += num;
            }
        }
        temp2--;
    }
    cout << sum << endl;
}