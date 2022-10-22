#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define MAXH (1e9)
#define MAXK 5005
#define MAXN 200005
using namespace std;

int n, k, h[MAXN], w[MAXK], l = 0, r = MAXH, mid;

void input() {
    FastIO
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < k; i++) cin >> w[i];
}

bool fit(int x) {
    int currentPoster = 0, currentWidth = 0;
    for (int i = 0; i < n; i++) {
        if (currentPoster == k) break;
        if (h[i] >= x) {
            currentWidth++;
            if (currentWidth >= w[currentPoster]) {
                currentPoster++;
                currentWidth = 0;
            }
        }
        else currentWidth = 0;
    }
    return currentPoster == k;
}

int  binarySearch() {
    while (l <= r) {
        mid = (l + r) >> 1;
        if (fit(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

int main() {
    input();
    cout << binarySearch();
    return 0;
}
