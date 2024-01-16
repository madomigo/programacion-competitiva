#include <iostream>
using namespace std;

int main() {
    int rows, columns, number, sum;
    sum = 0;
    cin >> rows >> columns;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> number;
            if (i == 0 && j == 0) sum += number;
            else if (i == 0 && j == columns - 1) sum += number;
            else if (i == rows - 1 && j == 0) sum += number;
            else if (i == rows - 1 && j == columns - 1) sum += number;
        }
    }
    cout << sum << endl;
    

}