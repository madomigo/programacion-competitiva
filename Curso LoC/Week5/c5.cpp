#include <iostream> 
using namespace std;

int main () {
    int n;
    cin >> n;
    string line;
    cin >> line;


    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (line[i] == 'L') {
            left++;
        }
        else if (line[i] == 'R') right++;
    }

    cout << left + right + 1 << "\n";
}