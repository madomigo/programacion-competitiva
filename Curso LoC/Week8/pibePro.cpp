#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
 
int n, m;
vector<int> a;
 
bool check(int x) {
    ///if it's possible to assign people so that all distances >= x
    int last_house = 0, cnt_people = 1; ///assign 1 person to the house 0
    for (int i = 1; i < m; i++)
        if (a[i] - a[last_house] >= x) {
            ///assign 1 person to the house i
            last_house = i;
            cnt_people++;
        }
    return (cnt_people >= n);
}
 
int main()
{
    cin >> m >> n;
    a.resize(m);///set size to m
    for (int i = 0; i < m; i++)
        cin >> a[i];
 
    ///l+, r-
    int l = 0, r = 1e9;
    while (l < r - 1) {
        int  m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}