#include <bits\stdc++.h>
using namespace std;

int n;
vector<set<char>> graph(200);
vector<bool> visited (200);

bool dfs (char x, char y, char z) {
    for (char ch : graph[x]) {
        if (ch == z) return 0;
        if (ch != y && !dfs(ch, x , z)) return 0;
    }
    return 1; 
}

vector<char> v;
void print (char c) {
    visited[c] = true;
    for (char ch : graph[c])
        if (!visited[ch]) print(ch);
    v.push_back(c);
}

int main () {
    cin >> n;
    string s, pr;
    cin >> pr;
    while (--n) {
        cin >> s;
        int p = 0;
        while (s[p] == pr[p]) {
            p++;
            if (p >= min(s.length(), pr.length())) {
                if (s.length() <= pr.length()) {
                    cout << "NO\n";
                    return 0;
                }
                goto here;
            }
        }
        if (!dfs(s[p], '0', pr[p])) {
            cout << "NO\n";
            return 0;
        }
        graph[pr[p]].insert(s[p]);
        here:
        pr = s;
    } 
    cout << "YES\n";
    for (char c = 'a'; c <= 'z'; c++) {
        if (!visited[c]) print(c);
    }
    for (int i = v.size() - 1; i>= 0; i--)
        cout << v[i];

}