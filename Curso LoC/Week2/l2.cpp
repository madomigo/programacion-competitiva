#include <iostream>
#include <array>
using namespace std;

int main () {
    int rows, cols, sum1, sum2, sum, maxSum;
    sum = sum2 = sum1 = maxSum = 0;
    cin >> rows >> cols;

    int a[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        sum1 = 0;
        for (int j = 0; j < cols; j++) {
            sum1 += a[i][j];
        }    
        for (int j = 0; j < cols; j++) { 
            sum2 = 0;   
            for (int k = 0; k < rows; k++) {
                sum2 += a[k][j];
            }
            sum = sum1 + sum2 - a[i][j];
            if (sum > maxSum) maxSum = sum;
        }

    }
    cout << maxSum << endl;
}