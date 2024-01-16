#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    for (int t = 0; t < n; t++) {
        int cae, num;
        cin >> cae >> num;

        int contador = 0;
        int palmeras[num];
        int i = 0;
        int k = 0; 
        int longitud = 0;

        for (int j = 0; j < num; j++) {
            cin >> palmeras[j];

            if (palmeras[j] >= cae) {
                contador++;

                while (contador > 5) {
                    if (palmeras[i] >= cae) {
                       contador--; 
                    }
                    i++;
                }
            }

            if (longitud < (k - i + 1)) {
                longitud = k - i + 1;
            }

            k++;
        }   

        cout << longitud << "\n";
    }

    return 0;
}

