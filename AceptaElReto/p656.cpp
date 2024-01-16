#include <bits/stdc++.h>
using namespace std;
#define CHILDREN 5
 
vector<pair<int, int>> a;

// Trie node
struct trie {
    char c;
    vector<trie*> child;

    int ways; //different ways to reach the end of a word from this node
};
 
// Function will return the new node
trie* createNode(char ch)
{
    trie* temp = new trie();
    temp->c = ch;
    temp->ways = 0;
    return temp;
}
/*function will insert the string in a trie recursively*/
void insertRecursively(trie* itr, string str, int i, int times)
{
    if (i < str.length()) {     

        // checks if it is already used
        bool is = false;
        int index = itr->child.size();
        for (int j = 0; j < itr->child.size(); j++) {
            if (itr->child[j]->c == str[a[i].second]) {
                is = true;
                //if it is found, I save the index to use it later
                index = j;
                break;
            }
        }

        // if it was not found, I add it
        if (!is) {
            itr->child.push_back(createNode(str[a[i].second]));
        }

        // Recursive call for insertion of a string
        insertRecursively(itr->child[index], str, i + 1, times);
        
        int ans = 0;
        for (int j = 0; j < itr->child.size(); j++) {
            ans += (itr->child[j]->ways);
        }
        itr->ways = ans;

    }

    // if it is the last char of the word
    else if (i == str.length()) {
            itr->ways = times;
            return;
    }
}
// Function call to insert a string
void insert(trie* itr, string str, int times)
{
    // Function call with necessary arguments
    insertRecursively(itr, str, 0, times);
}
 
// Function to search the string in a trie recursively
int searchRecursively(trie* itr, string str, int i, int len)
{

    if (i == len) {
        return itr->ways;
    }

    if (str[a[i].second] == '-') {
        int ans = 0;
        for (int j = 0; j < itr->child.size(); j++) {
            ans += searchRecursively(itr->child[j], str, i + 1, len);
        }
        return ans;
    }
    int ans = 0;
    for (int j = 0; j < itr->child.size(); j++) {
        
        if (itr->child[j]->c == '-' || itr->child[j]->c == str[a[i].second]) {
            ans += searchRecursively(itr->child[j], str, i + 1, len);
        }
    }
    return ans;
}
 
// Function call to search the string
int search(trie* root, string str, int last)
{
    return searchRecursively(root, str, 0, last + 1);
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    while (cin >> t) {
        trie* root = createNode('.');
        string s;
        unordered_map<string, pair<int,int>> m; //nTimes, ans
        vector<string> v (t);
        cin >> s;
        v[0] = s;
        m[s].first++;
        m[s].second = -1;

        int size = s.size();

        a.clear();
        a.resize(size);

        for (int i = 0; i < size; i++) {
            a[i].first = 0;
            a[i].second = i;
            if (s[i] == '-') {
                    a[i].first++;
            }
        }

        for (int i = 1; i < t; i++) {
            cin >> s;
            v[i] = s;
            m[s].first++;
            m[s].second = -1;

            for (int j = 0; j < size; j++) {
                if (s[j] == '-') {
                    a[j].first++;
                }
            }
        }
        sort(a.begin(), a.end());

        for (auto i : m) {
            insert(root, i.first, i.second.first);
        }
        vector<int> ans;

        bool full = true;
        int last;
        for (auto i : v) {
            full = true;
            for (int j = 0; j < size; j++) {
                if (i[a[j].second] != '-') {
                    full = false;
                    last = j;
                }
            }
            if (full) ans.push_back(t - 1);
            else if (m[i].second == -1) {
                ans.push_back(search(root, i, last) - 1);
                m[i].second = ans[ans.size() - 1];
            }
            else ans.push_back(m[i].second);
            
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << ' ' << ans[i];
        }
        cout << '\n';
    }
}