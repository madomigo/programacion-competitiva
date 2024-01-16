#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int num, value;
    cin >> num;
    vector<int> v;
    for (int i = 0; i < num; i++) {
        cin >> value;
        if (find(v.begin(), v.end(), value) != v.end()) {
            v.erase(remove(v.begin(), v.end(), value), v.end());
            
        }
        v.push_back(value);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
}