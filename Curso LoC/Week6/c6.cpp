#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long list1[n];
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }

    long long list2[n];
    for (int i = 0; i < n; i++) {
        cin >> list2[i];
    }

    sort(list1, list1 + n);
    sort(list2, list2 + n);

    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += list1[i] * list2[i];
    }

    cout << ans;


}