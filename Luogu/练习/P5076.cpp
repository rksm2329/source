#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10, INF = -1e9;

int q, root, cnt, op, x;

struct Tree {
  int left, right, size, value, num;
  Tree(int l, int r, int s, int v) {
    left = l, right = r, size = s, value = v, num = 1;
  }
  Tree() {}
} tree[MAXN];

void update(int root) {
  tree[root].size = tree[tree[root].left].size + tree[tree[root].right].size + tree[root].num;
}

int rnk(int x, int root) {
  if (root) {
    if (x < tree[root].value) {
      return rnk(x, tree[root].left);
    }
    if (x > tree[root].value) {
      return rnk(x, tree[root].right) + tree[tree[root].left].size + tree[root].num;
    }
    return tree[tree[root].left].size + tree[root].num;
  }
  return 1;
}

int kth(int x, int root) {
  if (!x) {
    return INF;
  }
  if (x <= tree[tree[root].left].size) {
    return kth(x, tree[root].left);
  }
  if (x <= tree[tree[root].left].size + tree[root].num) {
    return tree[root].value;
  }
  return kth(x - tree[tree[root].left].size - tree[root].num, tree[root].right);
}

void insert(int x, int &root) {
  if (x < tree[root].value) {
    if (!tree[root].left) {
      tree[tree[root].left = ++cnt] = Tree(0, 0, 1, x);
    } else {
      insert(x, tree[root].left);
    }
  } else if (x > tree[root].value) {
    if (!tree[root].right) {
      tree[tree[root].right = ++cnt] = Tree(0, 0, 1, x);
    } else {
      insert(x, tree[root].right);
    }
  } else {
    tree[root].num++;
  }
  update(root);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> q;
  tree[root = ++cnt] = Tree(0, 0, 1, INT_MAX);
  while (q--) {
    cin >> op >> x;
    if (op == 1) {
      cout << rnk(x, root) << '\n';
    } else if (op == 2) {
      cout << kth(x, root) << '\n';
    } else if (op == 3) {
      int t = kth(rnk(x, root) - 1, root);
      if (t == INF) {
        cout << -2147483647 << '\n';
      } else {
        cout << t << '\n';
      }
    } else if (op == 4) {
      int t = kth(rnk(x + 1, root), root);
      if (t == INF) {
        cout << 2147483647 << '\n';
      } else {
        cout << t << '\n';
      }
    } else {
      insert(x, root);
    }
  }
  return 0;
}