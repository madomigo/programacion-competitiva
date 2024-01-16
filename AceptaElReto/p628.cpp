#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;

int main () {
    long long sabor, grosor;
    while (cin >> sabor >> grosor) {
        long long mx = sabor;
        long long mn = grosor;
        bool hayuva = true;

        while (true) {
            cin >> sabor >> grosor;

            if (sabor == 0 && grosor == 0) break;


            if (sabor >= mx && grosor <= mn) {
                mx = sabor;
                mn = grosor;
                hayuva = true;
            }
            else if (sabor > mx && grosor > mn) {
                mx = sabor;
                hayuva = false;
            }
            else if (sabor < mx && grosor < mn) {
                mn = grosor;
                hayuva = false;
            }

        }

        if (hayuva) {
            cout << mx << " " << mn << "\n";
        }
        else cout << "NO HAY MEJOR\n";



    }
}