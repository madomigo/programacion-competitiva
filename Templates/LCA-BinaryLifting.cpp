// Tutorial de https://aprende.olimpiada-informatica.org/algoritmia-lca

// En este código asumimos que la raíz es el nodo 0.
// Antes de poder calcular el LCA eficientemente hay que precalcular los valores de P, first y last (llamar a la función init() en el código anterior). Calcular esos valores tiene coste O(nlog2n). Una vez calculados, cada llamada a la función LCA tiene coste O(log2n)

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
 
// L = log2(n) y cnt es un contador para las iteraciones del DFS.
int L, cnt;
// P[v][i] es el ancestro 2^i-ésimo del nodo v
vvi P;
// G es la lista de adyacencia del grafo (G[v] contiene los vecinos de v).
vvi G;
// Primera y última vez que visitamos cada nodo.
vi first, last;
 
// Hacemos un DFS desde v donde parent es el padre de v (el padre de la raíz
// es la propia raíz) para calcular P[w][i] para todo nodo w. Aprovechamos
// también para calcular la primera y última vez que visitamos cada nodo.  
void dfs(int v, int parent){
    // Esta es la primera vez que visitamos v. Anotamos el tiempo y
    // añadimos 1 al contador del tiempo.
    first[v] = cnt++;
    // Nos guardamos quien es nuestro ancestro a distancia 1 (nuestro padre).
    P[v][0] = parent;
    
    // Calculamos P[v][.]:
    for (int i = 1; i <= L; ++i){
        // El ancestro a distancia 2^i es el ancestro a distancia 2^(i-1)
        // de nuestro ancestro a distancia 2^(i-1).
        P[v][i] = P[P[v][i-1]][i-1];
    }
    
    // Visitamos todos nuestros hijos:
    for (int u : G[v]){
        // Vamos a todos nuestros vecinos que no sean nuestro padre.
        if (u != parent) dfs(u, v);
    }
    
    // Anotamos cuando dejamos de visitar v y añadimos 1 al contador.
    last[v] = cnt++;
} 
 
// Devuelve true si u es un ancestro de v 
bool ancestor(int u, int v){
    // u es ancestro de v si lo hemos visitado antes que v y lo hemos
    // dejado de visitar tras haber dejado de visitar v.
    return (first[u] <= first[v] and last[u] >= last[v]);
}
 
// Devuelve el LCA de u y v (se asume que P, first y last ya estan
// calculados), es decir, que hemos llamado a la function init() antes.
int LCA(int u, int v){
    // Si u es ancestro de v el LCA es u.
    if (ancestor(u, v)) return u;
    // Si v es ancestro de u el LCA es v.
    if (ancestor(v, u)) return v;
    
    // Visitamos todas las potencias de 2 de mayor a menor empezando por 2^L
    for (int i = L; i >= 0; --i){
        // Si el ancestro 2^i de u no es ancestro de v, subimos esa cantidad
        // de nodos y actualizamos u.
        if (not ancestor(P[u][i], v)) u = P[u][i];
    }
    
    // Ahora u es el nodo más lejano de la u original que no es ancestro de v.
    // Por tanto, su padre es el LCA. 
    return P[u][0];
}

// Al llamar a esta función, calculamos los valores de L, P, first, last y cnt.
void init(int n){
    L = 1 + log2(n);
    P = vvi(n, vi(L+1));
    first = last = vi(n);
    cnt = 0;

    // Cambiar los siguientes dos valores por el nodo raíz si este no fuera el nodo 0.
    dfs(0, 0);
}
