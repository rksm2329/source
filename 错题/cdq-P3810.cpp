#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct Node {
  int a, b, c, cnt, f;
} a[MAXN], val[MAXN];

struct BIT {
  int n, dat[MAXN << 1];
  void init(int n) {
    this->n = n;
  }
  int get(int x) {
    int res = 0;
    for (; x; res += dat[x], x -= x & -x);
    return res;
  }
  void add(int x, int v) {
    for (; x <= n; dat[x] += v, x += x & -x);
  }
} T;

int n, k, cnt[MAXN];

bool cmp1(const Node &i, const Node &j) {
  if (i.a != j.a) return i.a < j.a;
  if (i.b != j.b) return i.b < j.b;
  return i.c < j.c;
}

bool cmp2(const Node &i, const Node &j) {
  return i.b < j.b;
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid), cdq(mid + 1, r);
  sort(val + l, val + mid + 1, cmp2);
  sort(val + mid + 1, val + r + 1, cmp2);
  int p = l;
  for (int i = mid + 1; i <= r; i++) {
    for (; p <= mid && val[p].b <= val[i].b; p++) {
      T.add(val[p].c, val[p].cnt);
    }
    val[i].f += T.get(val[i].c);
  }
  for (int i = l; i < p; i++) {
    T.add(val[i].c, -val[i].cnt);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    auto &[x, y, z, cnt, f] = a[i];
    cin >> x >> y >> z;
    cnt = 1;
  }
  sort(a + 1, a + n + 1, cmp1);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].a == val[tot].a && a[i].b == val[tot].b && a[i].c == val[tot].c)
      val[tot].cnt++;
    else
      val[++tot] = a[i];
  }
  for (int i = 1; i <= tot; i++) {
    val[i].f = val[i].cnt - 1;
  }
  T.init(k);
  cdq(1, tot);
  for (int i = 1; i <= tot; i++) cnt[val[i].f] += val[i].cnt;
  for (int i = 0; i < n; i++) {
    cout << cnt[i] << '\n';
  }
  return 0;
}
/*
  ! 需要去重
  ? 分治时，重复元素会被计算多次贡献。
  ! 统计答案时，对每个 f(x) 值，要加上当前元素的出现次数
  ? 重复元素的答案要全部计算
  ! f(x) 的初始值应为当前元素的出现次数-1
  ? 重复元素内部的贡献应当计算
  ! 初始排序应当按照三元组排序，而非只按 a 排序
  ? 否则，可能部分可以对其他元素的 f(x) 值产生贡献的元素被放到 x 的右侧，导致无法被计算
  * 如：
    * 1 3 1
    * 1 2 1
  * 排序时，不会将两元素交换。导致 (1, 2, 1) 无法对 (1, 3, 1) 的 f(x) 值产生贡献
*/