#include <iostream>
using namespace std;

void fastscan(short int &number) {
    /* Variable to indicate sign of the number */
    bool negative = false;
    int c;
 
    number = 0;
 
    /* Extract current char from the buffer */
    c = getchar_unlocked();
    if (c=='-') {
        // number is negative
        negative = true;
 
        /* Extract the char from the buffer */
        c = getchar_unlocked();
    }
 
    /* Keep on extracting characters if they are integers
     * i.e ASCII Value lies from '0'(48) to '9' (57) */
    for (; (c > 47 && c < 58); c = getchar_unlocked())
        number = (number << 3) + (number << 1) + c - 48;
 
    /* If the input number is negative, negate its value */
    if (negative)
        number *= -1;
}
void fastscan2(int &number) {
    /* Variable to indicate sign of the number */
    bool negative = false;
    int c;
 
    number = 0;
 
    /* Extract current char from the buffer */
    c = getchar_unlocked();
    if (c=='-') {
        // number is negative
        negative = true;
 
        /* Extract the char from the buffer */
        c = getchar_unlocked();
    }
 
    /* Keep on extracting characters if they are integers
     * i.e ASCII Value lies from '0'(48) to '9' (57) */
    for (; (c > 47 && c < 58); c = getchar_unlocked())
        number = (number << 3) + (number << 1) + c - 48;
 
    /* If the input number is negative, negate its value */
    if (negative)
        number *= -1;
}


string marcador[20];

int main () {
    int numCasos;
    fastscan2(numCasos);
    

    short int cuantas;
    for (short int i = 0; i < numCasos; i++) {
        fastscan(cuantas);

        for (short int j = 0; j < cuantas; j++) {
            marcador[j] = getchar_unlocked(); 
            marcador[j].push_back(getchar_unlocked()); 
            marcador[j].push_back(getchar_unlocked()); 
            getchar_unlocked();

        }

        for (short int j = 0; j < 3; j++) {
            for (short int k = 0; k < cuantas; k++) {
                putchar_unlocked(marcador[k][j]);
            }
        }
        putchar_unlocked('\n');
    }
}