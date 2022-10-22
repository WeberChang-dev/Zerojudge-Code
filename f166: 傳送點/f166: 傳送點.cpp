#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MAX 1000005
using namespace std;

bool finished = false;
queue<int> nextVis;
int n, p, l, r, transport[MAX], steps[MAX] = {}, current;

void input() {
    cin >> n >> p >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> transport[i];
        steps[i] = MAX;
    }
}

void BFS() {
    nextVis.push(0);
    steps[0] = 0;
    
    while (!nextVis.empty()) {
        current = nextVis.front();
        nextVis.pop();
        // cout << current << " ";
        if (current == p) {
            finished = true;
            break;
        }

        if (current - l >= 0 && transport[current - l] >= 0 && transport[current - l] < n && steps[current] + 1 < steps[transport[current - l]]) {
            nextVis.push(transport[current - l]);
            steps[transport[current - l]] = steps[current] + 1;
        }
        if (current + r < n && transport[current + r] >= 0 && transport[current + r] < n && steps[current] + 1 < steps[transport[current + r]]) {
            nextVis.push(transport[current + r]);
            steps[transport[current + r]] = steps[current] + 1;
        }
    }
}

void output() {
    if (finished) cout << steps[p];
    else cout << -1;
}

int main()  {
    FastIO
    input();
    BFS();
    output();
    return 0;
}
