#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 100005
using namespace std;

int low[MAXN] = {}, DFN[MAXN] = {}, currentDFN = 0, n, m, a, b, sccCnt = 0;
bool inStack[MAXN] = {false}, isCutPoint[MAXN] = {false};
vector<vector<int>> edges;
stack<int> currentComponent;
string ans = "No";

void dfs(int v, int cnt) {
    if (cnt == sccCnt) {
        ans = "Yes";
        return;
    }
    for (auto i : edges[v]) {
        if (isCutPoint[i]) {
            dfs(i, cnt + 1);
        }
    }
}

void Tarjan(int v) {
    low[v] = DFN[v] = ++currentDFN;
    currentComponent.push(v);
    inStack[v] = true;
    for (int &i : edges[v]) {
        if (!DFN[i]) {
            Tarjan(i);
            low[v] = min(low[v], low[i]);
        } else if (inStack[i]) {
            low[v] = min(low[v], DFN[i]);
        }
    }
    if (low[v] == DFN[v]) {
        int top;
        isCutPoint[v] = true;
        do {
            top = currentComponent.top();
            currentComponent.pop();
            inStack[top] = false;
        } while (top != v);
        sccCnt++;
    }
}

void input() {
    FastIO
    cin >> n >> m;
    edges.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
    }
}

void output() {
    cout << ans;
}

int main() {
    input();
    for (int i = 1; i <= n; i++) {
        if (!DFN[i]) {
            Tarjan(i);
        }
    }
    dfs(1, 1);
    output();
    return 0;
}
