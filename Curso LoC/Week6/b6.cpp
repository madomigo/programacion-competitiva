#include <iostream>
#include <algorithm>
using namespace std;

struct Parejas {
    int score, penalty;

    Parejas (){};
    

    Parejas (int s, int p) {
        score = s;
        penalty = p;
    }
};

bool Ordenar (Parejas p1, Parejas p2) {
    if (p1.score > p2.score) return true;
    if (p1.score == p2.score && p1.penalty < p2.penalty) return true;
    return false;
}

int main () {
    int n;
    cin >> n;

    Parejas participants[n];
    int score, penalty;
    for (int i = 0; i < n; i++) {
        cin >> score >> penalty;
        participants[i] = Parejas(score, penalty);
    }

    sort(participants, participants + n, Ordenar);

    for (int i = 0; i < n - 1; i++) {
        cout << participants[i].score << " " << participants[i].penalty << "\n";
    }
    cout << participants[n - 1].score << " " << participants[n - 1].penalty;
}