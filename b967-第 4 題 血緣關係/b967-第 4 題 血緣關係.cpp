#include <bits/stdc++.h>
#define ll long long
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, a, b, ans = 0, treeRoot;
bool in[100005] = {false};
vector<vector<int>> related;

int DFS(int root) {
    int maxHeight = 0, secondHeight = 0, currentHeight = 0;
    for (auto it : related[root]) {
        currentHeight = DFS(it);
        if (currentHeight > maxHeight) {
            secondHeight = maxHeight;
            maxHeight = currentHeight;
        } else if (currentHeight > secondHeight) {
            secondHeight = currentHeight;
        }
    }
    ans = max(ans, maxHeight + secondHeight);
    return maxHeight + 1;
}

int main() {
    FastIO
    while(cin >> n) {
        ans = 0;
        related.clear();
        related.resize(n);
        memset(in, false, n);
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            related[a].push_back(b);
            in[b] = true;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == false) {
                treeRoot = i;
                break;
            }
        }
        DFS(treeRoot);
        cout << ans << '\n';
    }
    return 0;
}
