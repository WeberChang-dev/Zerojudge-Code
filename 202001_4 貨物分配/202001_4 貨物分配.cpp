#include <iostream>
#define ll long long
#define FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, m, a, b, cargo[1000005], queries[10005];
struct treeNode {
    int num, left, right, leftSum = 0, rightSum = 0;
} tree[1000005];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cargo[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }
    for (int i = 0; i < n; i++) {
        treeNode tmp;
        cin >> tmp.num >> tmp.left >> tmp.right;
        tree[tmp.num] = tmp;
    }
}

int DFS_build(int x) {
    if (x >= n) {
        return cargo[x - n];
    }
    tree[x].leftSum += DFS_build(tree[x].left);
    tree[x].rightSum += DFS_build(tree[x].right);
    return tree[x].leftSum + tree[x].rightSum;
}

void DFS_modify(int x, int val) {
    if (x >= n) {
        cout << x << " ";
        return;
    }
    if (tree[x].leftSum <= tree[x].rightSum) {
        tree[x].leftSum += val;
        DFS_modify(tree[x].left, val);
    } else {
        tree[x].rightSum += val;
        DFS_modify(tree[x].right, val);
    }
}

int main() {
    FastIO
    input();
    DFS_build(1);
    for (int i = 0; i < m; i++) {
        DFS_modify(1, queries[i]);
    }
    return 0;
}
 
