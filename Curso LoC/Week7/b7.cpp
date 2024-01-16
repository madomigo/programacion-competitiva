#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int first, last = -1;

    Pos () {
        first = INT32_MAX;
        last = INT32_MIN;
    };

    Pos (int f, int l) {
        first = f;
        last = l;
    }
};


int main() {
    int n, q;
    cin >> n >> q;

    int nums[n];
    map<int, Pos> mapa;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        
        mapa[nums[i]].first = min(mapa[nums[i]].first, i);
        mapa[nums[i]].last = max(mapa[nums[i]].last, i);
    }

    
    sort(nums, nums + n);

    int num;
    while (q--){
        cin >> num;
        int low = 0, high = n - 1, mid;
        bool found = false;
        while (low <= high && !found) {
            mid = (high + low) / 2;

            if (nums[mid] == num) {
                found = true;
            }
            if (nums[mid] < num) low = mid + 1;
            else high = mid - 1;
            
        }
        

        if (found) {
            cout << mapa[num].first + 1 << " " << mapa[num].last + 1 << "\n";
        }
        else cout << "-1 -1\n";
    }
        
}