#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand_int(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rng);
}

// 生成保证无重坐标 (x, t) 的点集
pair<ll, ll> gen_unique_pos(set<pair<ll, ll>> &used, ll max_x, ll max_t) {
  ll x = rand_int(1, max_x);
  ll t = rand_int(1, max_t);
  while (used.count({x, t})) {
    x = rand_int(1, max_x);
    t = rand_int(1, max_t);
  }
  used.insert({x, t});
  return {x, t};
}

// 核心数据生成逻辑
void generate_case(int subtask_id) {
  int k = 0, n = 0;
  ll max_v = 1e9; // w_i, s_i 范围

  if (subtask_id == 1) {
    // Subtask 1: 小规模（供 DFS 暴力拿分）
    k = rand_int(1, 2);
    n = rand_int(8, 12);
    max_v = 100;
  } else if (subtask_id == 2) {
    // Subtask 2: 中规模（供 O(N^2) DP 拿分）
    k = rand_int(2, 5);
    n = rand_int(500, 1000);
    max_v = 1e5;
  } else if (subtask_id == 3) {
    // Subtask 3: 大规模综合数据（测试常规正解）
    k = rand_int(5, 10);
    n = rand_int(100000, 200000);
    max_v = 1e8;
  } else {
    // Subtask 4: 极限数据 & 乱搞 Hack 专项
    k = 10;
    n = 200000;
    max_v = 1e9; // 彻底拉满系数，卡掉 long long
  }

  // 1. 生成手指初始位置
  vector<ll> p(k);
  set<ll> p_set;
  while ((int)p_set.size() < k) {
    p_set.insert(rand_int(1, subtask_id == 1 ? 20 : 200000));
  }
  int p_idx = 0;
  for (ll x : p_set) p[p_idx++] = x;

  cout << k << "\n";
  for (int i = 0; i < k; i++) {
    cout << p[i] << (i == k - 1 ? "" : " ");
  }
  cout << "\n" << n << "\n";

  set<pair<ll, ll>> used;
  ll cur_t = 1;

  for (int i = 1; i <= n; i++) {
    ll x, t, w, s;

    if (subtask_id == 4) {
      // ===== Hack 1: 构造超长连续 Combo 链，让 Combo 得分爆 long long =====
      if (i <= n - 100) {
        t = i; // t 严格递增
        x = p[0] + (i % 2 == 0 ? 0 : 1); // 始终在 p[0] 附近，绝对可接
        w = 1e9;
        s = 1e9; // 高额系数：Sum(i * s_i) 轻松达到 4 * 10^19
        used.insert({x, t});
      } 
      // ===== Hack 2: 构造“高 w_i 诱导断 Combo”陷阱键卡贪心 =====
      else {
        t = i;
        if (i % 2 == 0) {
          x = 100000; // 偏远位置，接了这个会导致后面连续 50 个键接不到
          w = 1e9;    // 诱饵：单击分极高
          s = 1;
        } else {
          x = p[0];   // 主轨道，虽然单键分低，但保持连击总分更高
          w = 10;
          s = 1e9;
        }
        used.insert({x, t});
      }
    } else if (subtask_id == 3) {
      // 80% 概率连续构链，20% 随机跳跃（测试多手指分工）
      if (rand_int(1, 100) <= 80) {
        cur_t += rand_int(0, 1);
        int f_id = rand_int(0, k - 1);
        x = max(1LL, min(200000LL, p[f_id] + rand_int(-cur_t, cur_t)));
        t = max(1LL, min(200000LL, cur_t));
        if (used.count({x, t})) tie(x, t) = gen_unique_pos(used, 200000, 200000);
        else used.insert({x, t});
      } else {
        tie(x, t) = gen_unique_pos(used, 200000, 200000);
      }
      w = rand_int(1, max_v);
      s = rand_int(1, max_v);
    } else {
      // 随机生成基础数据（Subtask 1 & 2）
      ll max_coord = (subtask_id == 1 ? 20 : 1000);
      tie(x, t) = gen_unique_pos(used, max_coord, max_coord);
      w = rand_int(1, max_v);
      s = rand_int(1, max_v);
    }

    cout << x << " " << t << " " << w << " " << s << "\n";
  }
}

int main(int argc, char* argv[]) {
  cin.tie(0)->sync_with_stdio(0);

  int subtask_id = 4; // 默认输出 Subtask 4 Hack 数据
  if (argc > 1) subtask_id = atoi(argv[1]);

  generate_case(subtask_id);

  return 0;
}