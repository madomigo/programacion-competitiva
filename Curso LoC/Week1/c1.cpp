#include <iostream>
using namespace std;

int main () {
    int num, score, maxScore; 
    maxScore = 0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> score;
        if (score > maxScore) {
            maxScore = score;
        }
    }
    cout << maxScore << endl;
}