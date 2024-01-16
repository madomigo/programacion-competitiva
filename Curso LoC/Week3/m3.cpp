#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int j = 0; j < n; j++) {

        string s;
        cin >> s;

        int count, sum;
        count = sum = 0;
        bool go = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' && go == true) count++;
            else if (s[i] == '0' && !go) continue;
            else {
                go = true;
                sum += count;
                count = 0;
            }
        }

        cout << sum << endl;
    }


}