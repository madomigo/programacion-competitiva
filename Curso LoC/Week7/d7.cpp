#include <iostream>
#include <algorithm>
using namespace std;
 

 
int main(){
    int n;
    cin >> n;

    int low = 1, high = n, mid;
    int minimo = INT32_MAX;

    int solved;

    while (low <= high) {
        mid = (low + high) / 2;

        solved = mid;

        int i = 1;
        while (i < mid) {
            i++;
            solved += mid / i;
        }

        if (solved >= n) {
            high = mid - 1;
            minimo = min(minimo, mid);
        }
        else low = mid + 1;
    }

    cout << minimo << "\n";

}