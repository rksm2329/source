#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

struct FBITreeNode {
  int valueType, leftChild, rightChild;
  string T;
} tree[MAXN];

int n;
string s;

void S(int x) {
  if (tree[x].T.size() > 1) {
    tree[x].leftChild = x * 2, tree[x].rightChild = x * 2 + 1;
    for (int i = 0; i < tree[x].T.size() / 2; i++) {
      tree[x * 2].T.push_back(tree[x].T[i]);
    }
    for (int i = tree[x].T.size() / 2; i < tree[x].T.size(); i++) {
      tree[x * 2 + 1].T.push_back(tree[x].T[i]);
    }
    string t = tree[x * 2].T;
    if (count(t.begin(), t.end(), '1') == t.size()) {
      tree[x * 2].valueType = 3;
    } else if (count(t.begin(), t.end(), '0') == t.size()) {
      tree[x * 2].valueType = 2;
    } else {
      tree[x * 2].valueType = 1;
    }
    t = tree[x * 2 + 1].T;
    if (count(t.begin(), t.end(), '1') == t.size()) {
      tree[x * 2 + 1].valueType = 3;
    } else if (count(t.begin(), t.end(), '0') == t.size()) {
      tree[x * 2 + 1].valueType = 2;
    } else {
      tree[x * 2 + 1].valueType = 1;
    }
    S(x * 2), S(x * 2 + 1);
  }
}

void E(int x) {
  if (!x) {
    return;
  }
  E(tree[x].leftChild);
  E(tree[x].rightChild);
  cout << (tree[x].valueType == 1 ? 'F' : (tree[x].valueType == 2 ? 'B' : 'I'));
}

int main() {
  cin >> n >> s;
  if (count(s.begin(), s.end(), '1') == (1 << n)) {
    tree[1].valueType = 3;
  } else if (count(s.begin(), s.end(), '0') == (1 << n)) {
    tree[1].valueType = 2;
  } else {
    tree[1].valueType = 1;
  }
  tree[1].T = s;
  S(1);
  E(1);
  return 0;
}