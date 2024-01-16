#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string t = s;
        sort(t.begin(), t.end());

        if (t == s) {
            cout << "0\n";
            continue;

        }

        cout << 1 << "\n";
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i])
                ans.push_back(i+1);
        }
        cout << ans.size() << " ";

        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << '\n';
    }
}