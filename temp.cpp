#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXN = 1e6 + 10;
const ull BASE = 1331;

char s[MAXN];
int n;
ull h[MAXN], pw[MAXN];

ull get(int l, int r) {  // 获取子串 hash
    if (l > r) return 0;
    return h[r] - h[l - 1] * pw[r - l + 1];
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * BASE;
        h[i] = h[i - 1] * BASE + (s[i] - 'a');
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int j = n - i + 1;          // 后缀起点

        // 二分求最长公共前缀长度
        int l = 1, r = i, now = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(1, mid) == get(j, j + mid - 1)) {
                now = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (now == i) {             // 完全匹配
            ans = i;
            continue;
        }

        now++;                      // 第一个不同的位置（前缀中）
        bool flag = false;

        // 情况1：修改前缀中的 now 位置
        ull hs = get(1, i) - (s[now] - 'a') * pw[i - now];
        for (int c = 0; c < 26; c++) {
            ull a = hs + c * pw[i - now];
            ull b = get(j, n);
            if (j <= now)   // 该位置也在后缀中，需更新后缀 hash
                b += c * pw[n - now] - (s[now] - 'a') * pw[n - now];
            if (a == b) {
                flag = true;
                ans = i;
                break;
            }
        }
        if (flag) continue;

        // 情况2：修改后缀中对应的位置（原串下标）
        now = j + now - 1;          // 后缀中该位置的原下标
        hs = get(j, n) - (s[now] - 'a') * pw[n - now];
        for (int c = 0; c < 26; c++) {
            ull b = hs + c * pw[n - now];
            ull a = get(1, i);
            if (i >= now)   // 该位置也在前缀中，需更新前缀 hash
                a += c * pw[i - now] - (s[now] - 'a') * pw[i - now];
            if (a == b) {
                flag = true;
                ans = i;
                break;
            }
        }
        // 若成功，ans 已更新；若失败则不变
    }

    printf("%d\n", ans);
    return 0;
}