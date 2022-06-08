#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 100000
using namespace std;

bool graph[55][55], vis[55][55], foundDepth;
queue<pair<int, int> > nextVis;
int n, m, Move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, newX, newY, dp[55][55], currentX, currentY;
pair<int, int> startPoint, endPoint;

void init() {
    memset(graph, false, sizeof(graph));
    memset(vis, false, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    foundDepth = false;
}

void input() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
            graph[i][j] = !graph[i][j]; // 0 means wall, 1 means road
        }
    }
    cin >> startPoint.first >> startPoint.second >> endPoint.first >> endPoint.second;
    startPoint.first++;
    startPoint.second++;
    endPoint.first++;
    endPoint.second++;
}

void BFS() {
    nextVis.push(startPoint);
    dp[startPoint.first][startPoint.second] = 1;
    
    while (!nextVis.empty()) {
        currentX = nextVis.front().first, currentY = nextVis.front().second;
        nextVis.pop();
        if (vis[currentX][currentY]) continue;
        vis[currentX][currentY] = true;

        // a little optimization, when you reach the end, the deeper points won't be on the shortest path
        if (currentX == endPoint.first && currentY == endPoint.second) foundDepth = true;

        for (int i = 0; i < 4; i++) {
            newX = currentX + Move[i][0], newY = currentY + Move[i][1];

            // the current point inherit the shortest paths from the four surrounding points
            dp[currentX][currentY] = (dp[newX][newY] + dp[currentX][currentY]) % MOD;


            if (graph[newX][newY] && !vis[newX][newY] && !foundDepth) {
                nextVis.push(make_pair(newX, newY));
            }
        }
    }
}

void output() {
    cout << dp[endPoint.first][endPoint.second] << '\n';
}

int main()  {
    FastIO
    while (cin >> n >> m) {
        init();
        input();
        BFS();
        output();
    }
    return 0;
}
