#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
 
    while (q--) {
        int num;
        cin >> num;
        bool found = false;

        int left = -1, right = n;
 
        while (right > left + 1) {
            int mid = (left + right) / 2;
            if (a[mid] < num)
                left = mid;
            else
                right = mid;
        }
        if (right != n && a[right] == num) {
            cout << right + 1 << ' ';
        } else {
            cout << "-1 -1\n";
            continue;
        }
 
        left = -1, right = n;
 
        while (right > left + 1) {
            int mid = (left + right) / 2;
            if (a[mid] <= num)
                left = mid;
            else
                right = mid;
        }
        cout << left + 1<< endl;
    }
 
    return 0;
}