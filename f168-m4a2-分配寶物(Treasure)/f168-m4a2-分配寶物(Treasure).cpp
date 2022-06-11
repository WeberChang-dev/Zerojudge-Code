#include <bits/stdc++.h>
#define ll long long
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, val[20], earn[3] = {}, sum = 0;
bool found = false;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        sum += val[i];
    }
}

void DFS(int num) {
    if (earn[2] == sum / 3 && earn[1] == sum / 3 && earn[0] == sum / 3) {
        found = true;
        return;
    }
    if (n == num) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        if (earn[i] + val[num] <= sum / 3) {
            earn[i] += val[num];
            DFS(num + 1);
            earn[i] -= val[num];
        }
    }
}

int main() {
    FastIO
    input();
    if (sum % 3) {

        cout << "NO";

    } else {

        DFS(0);

        if (found) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}
