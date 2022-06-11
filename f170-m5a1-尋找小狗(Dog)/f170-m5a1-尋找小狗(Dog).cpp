#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 100000
using namespace std;

bool vis[1005][1005] = {false};
queue<pair<int, int> > nextVis;
int n, ans = 0, Move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, newX, newY, graph[1005][1005], currentX, currentY;
pair<int, int> startPoint;

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void input() {
    cin >> n;
    cin >> startPoint.first >> startPoint.second;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
}

void BFS() {
    nextVis.push(startPoint);
    
    while (!nextVis.empty()) {
        currentX = nextVis.front().first, currentY = nextVis.front().second;
        nextVis.pop();
        if (vis[currentX][currentY]) continue;
        vis[currentX][currentY] = true;
        ans++;

        for (int i = 0; i < 4; i++) {
            newX = currentX + Move[i][0], newY = currentY + Move[i][1];

            if (inside(newX, newY) && abs(graph[newX][newY] - graph[currentX][currentY]) <= 2 && !vis[newX][newY]) {
                nextVis.push(make_pair(newX, newY));
            }
        }
    }
}

void output() {
    cout << ans << '\n';
}

int main()  {
    FastIO
    input();
    BFS();
    output();
    return 0;
}
