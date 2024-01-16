#include <iostream>
using namespace std;

void bubbleSort(int numbers[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;

    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    bubbleSort(numbers, n);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }

}