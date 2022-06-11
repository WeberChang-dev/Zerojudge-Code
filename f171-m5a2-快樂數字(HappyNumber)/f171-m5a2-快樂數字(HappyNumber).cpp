#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD (1000 * 1000 * 1000 + 7)
using namespace std;

int n, dp[1005][10][512] = {}, p, q; // dp[位數][這一位放哪個數字][之前放的狀態]

void init() {
    for (int i = 1; i <= 9; ++i)
            dp[1][i][1 << (i - 1)] = 1;
}

void solve() {
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 1; j <= 9; ++j) {
            for (int k = j - 2; k <= j + 2; ++k) {
                if (k > 0 && k <= 9) {
                    for (int l = 1; l < 512; ++l) {
                        if (l & (1 << (k - 1))) {
                            dp[i][j][l | (1 << (j - 1))] = (dp[i][j][l | (1 << (j - 1))] + dp[i - 1][k][l]) % MOD;
                        }
                    }
                }
            }
        }
    }
}

void output() {
    cout << dp[p][q][511] << '\n';
}

int main() {
    FastIO
    init();
    solve();
    cin >> n;
    while (n--) {
        cin >> p >> q;
        output();
    }
    return 0;
}
