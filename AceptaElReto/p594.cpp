#include <iostream>
#include <queue>
#include <array>
using namespace std;

struct Pos {
    int f, c;
};

int filas, columnas;
char tablero[300][300];
bool visitado[300][300];
queue<Pos> q;

bool esIgual (Pos p1, Pos p2) {
    return (p1.f == p2.f && p1.c == p2.c);
}

void insert (int fila, int col) {
    Pos p;
    p.f = fila;
    p.c = col;

    q.push(p);
}

int main() {
    while (cin >> columnas >> filas) {
        /* Input */

        Pos trofeo, inicial;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> tablero[i][j];

                if (i == filas - 1 && tablero[i][j] == '.') {
                    inicial.f = i;
                    inicial.c = j;
                }

                if (tablero[i][j] == 'T') {
                    tablero[i][j] = '.';
                    trofeo.f = i;
                    trofeo.c = j;
                }

                visitado[i][j] = false;
            }
        }

        Pos pos = inicial;
        
        /* Si la entrada esta tapada, es imposible */
        
        if (tablero[pos.f - 1][pos.c] == '#') {
            cout << "IMPOSIBLE\n";
            continue;
        }

        if (pos.f - 1 == trofeo.f && pos.c == trofeo.c) {
            cout << "IGUAL\n";
            continue;
        }
        


        /* Mano derecha */

        char dir = 'i';
        int pMano = 0;

        while (!esIgual(pos, trofeo)) {
            pMano++;

            if (dir == 'd') {
                if (tablero[pos.f + 1][pos.c] == '.') {
                    pos.f++;
                    dir = 'b';
                }

                else if (tablero[pos.f][pos.c + 1] == '.') {
                    pos.c++;
                    dir = 'd';
                }

                else if (tablero[pos.f - 1][pos.c] == '.') {
                    pos.f--;
                    dir = 'a';
                }

                else if (tablero[pos.f][pos.c - 1] == '.') {
                    pos.c--;
                    dir = 'i';
                }
            }

            else if (dir == 'a') {
                if (tablero[pos.f][pos.c + 1] == '.') {
                    pos.c++;
                    dir = 'd';
                }

                else if (tablero[pos.f - 1][pos.c] == '.') {
                    pos.f--;
                    dir = 'a';
                }

                else if (tablero[pos.f][pos.c - 1] == '.') {
                    pos.c--;
                    dir = 'i';
                }

                else if (tablero[pos.f + 1][pos.c] == '.') {
                    pos.f++;
                    dir = 'b';
                }
            }

            else if (dir == 'i') {
                if (tablero[pos.f - 1][pos.c] == '.') {
                    pos.f--;
                    dir = 'a';
                }

                else if (tablero[pos.f][pos.c - 1] == '.') {
                    pos.c--;
                    dir = 'i';
                }

                else if (tablero[pos.f + 1][pos.c] == '.') {
                    pos.f++;
                    dir = 'b';
                }
                
                else if (tablero[pos.f][pos.c + 1] == '.') {
                    pos.c++;
                    dir = 'd';
                }
            }

            else if (dir == 'b') {
                if (tablero[pos.f][pos.c - 1] == '.') {
                    pos.c--;
                    dir = 'i';
                }

                else if (tablero[pos.f + 1][pos.c] == '.') {
                    pos.f++;
                    dir = 'b';
                }

                else if (tablero[pos.f][pos.c + 1] == '.') {
                    pos.c++;
                    dir = 'd';
                }

                else if (tablero[pos.f - 1][pos.c] == '.') {
                    pos.f--;
                    dir = 'a';
                }
            }

            /* Si hemos vuelto a la posicion inicial, es imposible */
            if (esIgual(pos, inicial)) break;

        }


        bool llegadoMano = esIgual(pos, trofeo);



        /* Algoritmo BFS */

        while(!q.empty()) q.pop();

        q.push(inicial);

        visitado[inicial.f][inicial.c] = true;

        bool posible = false;

        int pLibre = -1;

        do {
            pLibre++;

            int size = q.size();

            for (int i = 0; i < size; i++) {
                pos = q.front();
                q.pop();

                if (esIgual(pos, trofeo)) {
                    while(!q.empty()) q.pop();              // En teoria no es necesario, pero si no, no funciona.
                    break;
                }

                if (pos.c < columnas - 1 && !visitado[pos.f][pos.c + 1] && tablero[pos.f][pos.c + 1] == '.') {
                    insert(pos.f, pos.c + 1); 
                    visitado[pos.f][pos.c + 1] = true;
                }
                if (pos.c > 0 && !visitado[pos.f][pos.c - 1] && tablero[pos.f][pos.c - 1] == '.') {
                    insert(pos.f, pos.c - 1);
                    visitado[pos.f][pos.c - 1] = true;
                }

                if (pos.f < filas - 1 && !visitado[pos.f + 1][pos.c] && tablero[pos.f + 1][pos.c] == '.') {
                    insert(pos.f + 1, pos.c);
                    visitado[pos.f + 1][pos.c] = true;
                }
                if (pos.f > 0 && !visitado[pos.f - 1][pos.c] && tablero[pos.f - 1][pos.c] == '.') {
                    insert(pos.f - 1, pos.c);
                    visitado[pos.f - 1][pos.c] = true;
                }
            }
        } while (!q.empty() && !esIgual(pos, trofeo));

        posible = esIgual(pos, trofeo);


        if (!posible) cout << "IMPOSIBLE\n";

        else if (!llegadoMano) cout << "INF\n";

        else if (pMano == pLibre) cout << "IGUAL\n";

        else cout << pMano - pLibre << '\n';
    }
}