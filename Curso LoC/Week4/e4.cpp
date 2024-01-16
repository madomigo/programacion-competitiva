#include <iostream>
#include <map>
using namespace std;

int main () {
    int n;
    cin >> n;

    string city, country;
    map<string, string> map;
    for (int i = 0; i < n; i++) {
        cin >> city >> country;
        map[city] = country;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> city;
        if (map.find(city) != map.end()) {
            cout << map[city] << "\n";
        }
        else cout << ":(\n";
    }
}
