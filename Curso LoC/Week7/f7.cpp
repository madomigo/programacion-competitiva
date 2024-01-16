#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> v;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> num;

    sort(v.begin(), v.end());

    int i = 0;
    int j = n - 1;
    int sum = 0;
    int mx = INT32_MIN;
    while (i != j) {
        sum = v[i] + v[j];
        if (sum == num) {
            mx = sum;
            break;
        }
        else if (sum < num) {
            mx = max(mx, sum);
            i++;
        }
        else j--;
    }

    cout << mx;

}
