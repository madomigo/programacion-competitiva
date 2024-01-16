#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


struct Tram {
    int from, to, level;
};

Tram trams[100001];

bool mySort (Tram a1, Tram a2) {
    if (a1.to < a2.to) return 1;
    return 0;
}



int nTrams;
int lastPoint;

bool esPosible (int level) {
    int pos = 1;

    for (int i = 0; i < nTrams; i++) {
        if (trams[i].level <= level && trams[i].from <= pos && trams[i].to > pos) {
            pos = trams[i].to;
        }
    }

    return (pos == lastPoint);
}


int main() {

    cin >> lastPoint >> nTrams;

    for (int i = 0 ; i < nTrams; i++) {
        cin >> trams[i].from >> trams[i].to >> trams[i].level;
    }

    sort(trams, trams + nTrams, mySort);

    int low = 1, high = 1000000001, mid;
    while (high > low) {
        mid = (high + low) / 2;
        if (!esPosible(mid)) low = mid + 1;
        else high = mid;
    }

    cout << low << '\n';
}
