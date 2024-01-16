#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int num, ans;
    while (n--) {
        cin >> num;
        ans = 0;
        num /= 5;
        while (num > 0) {
            ans += num;
            num /= 5;
        }
        cout << ans << '\n';
    }
}