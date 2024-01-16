#include <iostream>
using namespace std;

int main() {
    int length, width, cells;
    cin >> length >> width >> cells;
    if (length * width < cells) {
        cout << "NO" << endl; 
        return 0;
    }
    if (cells % length == 0 || cells % width == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}