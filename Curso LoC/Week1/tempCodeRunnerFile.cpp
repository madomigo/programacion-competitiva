#include <iostream>
using namespace std;

int main() {
    int length, width, cells;
    cin >> length >> width >> cells;
    if (cells < length && cells < width) {
        cout << "NO" << endl;
    }
    if (cells % length == 0 || cells % width == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}