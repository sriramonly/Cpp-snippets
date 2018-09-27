#include <bits/stdc++.h>

using namespace std;

// https://e-maxx-eng.appspot.com/data_structures/disjoint_set_union.html

const int maxn = 200000;
int size[maxn];
int p[maxn];
int n;

void init(int n) {
    ::n = n;
    fill(size, size + n, 1);
    for (int i = 0; i < n; i++) p[i] = i;
}

int root(int x) {
    return x == p[x] ? x : (p[x] = root(p[x])); // path compression
}

void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    p[b] = a;
    size[a] += size(b); //union by rank/size: 
}

// usage example
int main() {
    init(3);
    unite(0, 2);
    cout << (0 == root(0)) << endl;
    cout << (1 == root(1)) << endl;
    cout << (0 == root(2)) << endl;
}
