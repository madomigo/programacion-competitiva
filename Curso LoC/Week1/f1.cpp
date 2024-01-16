#include <iostream>
#include <array>
using namespace std;

int main () {
    int num, element;
    cin >> num;
    int array1[num];
    int array2[num];
    for (int i = 0; i < num; i++) {
        cin >> element;
        array1.push_back(element);
    }
} 