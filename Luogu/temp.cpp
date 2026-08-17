#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXV = 1000000;          // 值域上限
const int MAXN = 500000 + 5;       // 学生人数上限
const int MAXNODE = 11000000 + 5;  // 5e5 * 21 左右足够

int ls[MAXNODE], rs[MAXNODE], cnt[MAXNODE];
ll sum[MAXNODE];

int root[MAXN];
int tot;

// 可持久化插入：pre 是上一版本，cur 是新版本
void update(int &cur, int pre, int l, int r, int pos) {
    cur = ++tot;

    ls[cur] = ls[pre];
    rs[cur] = rs[pre];
    cnt[cur] = cnt[pre] + 1;
    sum[cur] = sum[pre] + pos;

    if (l == r) return;

    int m = (l + r) >> 1;
    if (pos <= m) {
        update(ls[cur], ls[pre], l, m, pos);
    } else {
        update(rs[cur], rs[pre], m + 1, r, pos);
    }
}

// 查询两个版本差值中的第 k 小
int kth(int u, int v, int k) {
    int l = 1, r = MAXV;

    while (l < r) {
        int m = (l + r) >> 1;

        int leftCnt = cnt[ls[u]] - cnt[ls[v]];

        if (k <= leftCnt) {
            u = ls[u];
            v = ls[v];
            r = m;
        } else {
            k -= leftCnt;
            u = rs[u];
            v = rs[v];
            l = m + 1;
        }
    }

    return l;
}

// 查询两个版本差值中最小的 k 个数的和
ll sumFirstK(int u, int v, int k) {
    if (k <= 0) return 0;

    int totalCnt = cnt[u] - cnt[v];
    if (k >= totalCnt) return sum[u] - sum[v];

    ll res = 0;
    int l = 1, r = MAXV;

    while (l < r) {
        int m = (l + r) >> 1;

        int lu = ls[u], lv = ls[v];
        int leftCnt = cnt[lu] - cnt[lv];

        if (k <= leftCnt) {
            u = lu;
            v = lv;
            r = m;
        } else {
            res += sum[lu] - sum[lv];
            k -= leftCnt;
            u = rs[u];
            v = rs[v];
            l = m + 1;
        }
    }

    // 到达叶子，剩余 k 个都在值 l 上
    res += 1LL * l * k;
    return res;
}

// 求满足 b_i <= K + i - 1 的最大 i
// 也就是左边多少个学生适合用 “目标位置 - 原位置” 计算代价
int getLeftCount(int L, int R, int K) {
    int len = R - L + 1;

    int l = 0, r = len;
    int u = root[R], v = root[L - 1];

    while (l < r) {
        int mid = (l + r + 1) >> 1;

        int val = kth(u, v, mid);

        if (1LL * val <= 1LL * K + mid - 1) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(root[i], root[i - 1], 1, MAXV, x);
    }

    while (m--) {
        int l, r, K;
        cin >> l >> r >> K;

        int len = r - l + 1;

        int leftCnt = getLeftCount(l, r, K);

        ll totalSum = sum[root[r]] - sum[root[l - 1]];

        // 所有目标位置之和：K + (K + 1) + ... + (K + len - 1)
        ll totalTarget = 1LL * len * K + 1LL * len * (len - 1) / 2;

        // 左边 leftCnt 个目标位置之和：K + (K + 1) + ... + (K + leftCnt - 1)
        ll leftTarget = 1LL * leftCnt * K + 1LL * leftCnt * (leftCnt - 1) / 2;

        // 左边 leftCnt 个学生原位置之和
        ll leftSum = sumFirstK(root[r], root[l - 1], leftCnt);

        ll ans = totalSum - totalTarget + 2LL * (leftTarget - leftSum);

        cout << ans << '\n';
    }

    return 0;
}