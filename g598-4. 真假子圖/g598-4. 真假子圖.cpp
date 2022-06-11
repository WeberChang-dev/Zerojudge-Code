#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MAX 20005
using namespace std;

int n, m, a[20005], b[20005], p, k, ans = 0, parent[40005], Rank[40005], c[10005][25], d[20005][25];

int findAndCompressPath(int x) {
    return x == parent[x] ? x : parent[x] = findAndCompressPath(parent[x]);
}

void unionByRank(int x, int y) {
    int rootA = findAndCompressPath(x), rootB = findAndCompressPath(y);
    if(rootA == rootB) return;

    if (Rank[rootA] > Rank[rootB]) {
        Rank[rootA] += Rank[rootB];
        parent[rootB] = parent[rootA];
    } else {
        Rank[rootB] += Rank[rootA];
        parent[rootA] = parent[rootB];
    }

    return;
}

void init() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        parent[i + MAX] = i + MAX;
        Rank[i] = 1;
        Rank[i + MAX] = 1;
    }

    for (int i = 0; i < m; i++) {
        unionByRank(a[i], b[i] + MAX);
        unionByRank(a[i] + MAX, b[i]);
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> p >> k;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < k; j++) {
            cin >> c[i][j] >> d[i][j];
        }
    }
}

void solve() {
    for (int i = 0; i < p; i++) {
        bool falseInfo = false;
        for (int j = 0; j < k; j++) {
            if (findAndCompressPath(c[i][j]) == findAndCompressPath(d[i][j]) || findAndCompressPath(c[i][j] + MAX) == findAndCompressPath(d[i][j] + MAX)) {
                cout << i + 1 << '\n';
                falseInfo = true;
                break;
            }
            unionByRank(c[i][j], d[i][j] + MAX);
            unionByRank(c[i][j] + MAX, d[i][j]);
        }
        if (falseInfo) init();
    }
}


int main() {
    FastIO
    input();
    init();
    solve();
    return 0;
}
