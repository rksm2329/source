#include <bits/stdc++.h>

using namespace std;

namespace Integer {
const string symbol = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template <size_t kMaxLength, int binary, typename T> struct BigInt {
  T n, a[kMaxLength];
  bool f;
  BigInt() { Init(); }
  T &operator[](int i) { return a[i]; }
  void Init() {
    n = f = 1;
    fill(a, a + kMaxLength, 0);
  }
  friend istream &operator>>(istream &tempStream, BigInt &a) {
    string s;
    tempStream >> s;
    a.n = s.size();
    if (s[0] == '-') {
      a.f = 0;
      a.n--, s.erase(0, 1);
    }
    for (int i = 1; i <= a.n; i++) {
      a[i] = (s[a.n - i] >= 'A' && s[a.n - i] <= 'Z' ? s[a.n - i] - 'A' + 10
                                                     : s[a.n - i] - '0');
    }
    return tempStream;
  }
  friend ostream &operator<<(ostream &tempStream, BigInt a) {
    for (; a.n > 1 && !a[a.n]; a.n--) {
    }
    if (!a.f) {
      cout << '-';
    }
    for (int i = a.n; i >= 1; i--) {
      tempStream << symbol[a[i]];
    }
    return tempStream;
  }
  void operator=(int x) {
    Init();
    if (!x) {
      return;
    }
    if (x < 0) {
      x = -x, f = 0;
    }
    n = 0;
    while (x) {
      a[++n] = x % binary;
      x /= binary;
    }
  }
  void operator=(string x) {
    Init();
    int st = 0;
    if (x[0] == '-') {
      f = 0, st++;
    }
    n = 0;
    int len = x.size();
    for (int i = st; i < len; i++) {
      a[++n] = x[len - i - 1] - '0';
    }
  }
  void operator=(BigInt x) {
    Init();
    n = x.n;
    f = x.f;
    for (int i = 1; i <= n; i++) {
      a[i] = x.a[i];
    }
  }
  bool operator==(BigInt x) {
    if (n != x.n) {
      return 0;
    }
    for (int i = n; i >= 1; i++) {
      if (a[i] != x.a[i]) {
        return 0;
      }
    }
    return 1;
  }
  bool operator!=(BigInt x) { return !operator==(x); }
  bool operator<(BigInt x) {
    if (n == x.n) {
      for (int i = n; i >= 1; i--) {
        if (a[i] != x.a[i]) {
          return a[i] < x.a[i];
        }
      }
    }
    return n < x.n;
  }
  bool operator>(BigInt x) {
    if (n == x.n) {
      for (int i = n; i >= 1; i--) {
        if (a[i] != x.a[i]) {
          return a[i] > x.a[i];
        }
      }
    }
    return n > x.n;
  }
  bool operator<=(BigInt x) { return !operator>(x); }
  bool operator>=(BigInt x) { return !operator<(x); }
  bool operator!() {
    if (n != 1) {
      return 0;
    }
    return !a[1];
  }
  bool operator==(int x) {
    BigInt y;
    y = x;
    return operator==(y);
  }
  bool operator!=(int x) {
    BigInt y;
    y = x;
    return operator!=(y);
  }
  bool operator<(int x) {
    BigInt y;
    y = x;
    return operator<(y);
  }
  bool operator>(int x) {
    BigInt y;
    y = x;
    return operator>(y);
  }
  bool operator<=(int x) {
    BigInt y;
    y = x;
    return operator<=(y);
  }
  bool operator>=(int x) {
    BigInt y;
    y = x;
    return operator>=(y);
  }
  BigInt ChangeBinary(BigInt &num) {
    BigInt ans;
    ans[0] = 0, ans.n = 1;
    for (int i = 1; i <= num.n; i++) {
      ans = ans * binary;
      ans = ans + num[i];
    }
    num.n = ans.n;
    return ans;
  }
  BigInt operator+(BigInt x) {
    BigInt y;
    y.n = max(n, x.n);
    int s = 0;
    for (int i = 1; i <= y.n; i++) {
      s += a[i] + x.a[i];
      y.a[i] = s % binary;
      s /= binary;
    }
    for (; s; s /= binary) {
      y.a[++y.n] += s % binary;
    }
    return y;
  }
  void operator+=(BigInt x) {
    BigInt z = *this;
    *this = z + x;
  }
  void operator+=(int x) {
    BigInt z = *this;
    *this = z + x;
  }
  BigInt operator+(int x) {
    BigInt y;
    y = x;
    return operator+(y);
  }
  BigInt operator-(BigInt x) {
    BigInt y, z = *this;
    if (z < x) {
      y.f = 0, swap(z, x);
    }
    y.n = z.n;
    for (int i = 1; i <= y.n; i++) {
      if (z.a[i] < x.a[i]) {
        z.a[i + 1]--;
        z.a[i] += binary;
      }
      y.a[i] = z.a[i] - x.a[i];
    }
    for (; !y.a[y.n] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator-=(BigInt x) {
    BigInt z = *this;
    *this = z - x;
  }
  void operator-=(int x) {
    BigInt z = *this;
    *this = z - x;
  }
  BigInt operator-(int x) {
    BigInt y;
    y = x;
    return operator-(y);
  }
  BigInt operator*(BigInt x) {
    BigInt y;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= x.n; j++) {
        y.a[i + j - 1] += a[i] * x.a[j];
      }
    }
    y.n = n + x.n;
    for (int i = 1; i < y.n; i++) {
      if (y.a[i] >= binary) {
        y.a[i + 1] += y.a[i] / binary;
        y.a[i] %= binary;
      }
    }
    for (; !y.a[y.n] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator*=(BigInt x) {
    BigInt z = *this;
    *this = z * x;
  }
  void operator*=(int x) {
    BigInt z = *this;
    *this = z * x;
  }
  BigInt operator*(int x) {
    BigInt y;
    y = x;
    return operator*(y);
  }
  BigInt operator/(BigInt x) {
    BigInt y, z = *this;
    if (x == y) {
      return x;
    }
    if (binary != 10) {
      x = ChangeBinary(x), z = ChangeBinary(z);
    }
    y.n = z.n - x.n + 1;
    for (int i = y.n; i >= 1; i--) {
      BigInt t = x << (i - 1);
      for (; z >= t; z -= t) {
        y.a[i]++;
      }
    }
    for (; !y.a[y.n] && y.n > 1; y.n--) {
    }
    return y;
  }
  void operator/=(BigInt x) {
    BigInt z = *this;
    *this = z / x;
  }
  void operator/=(int x) {
    BigInt z = *this;
    *this = z / x;
  }
  BigInt operator/(int x) {
    BigInt y;
    y = x;
    return operator/(y);
  }
  BigInt operator%(BigInt x) {
    BigInt z = *this;
    return z - z / x * x;
  }
  void operator%=(BigInt x) {
    BigInt z = *this;
    *this = z % x;
  }
  void operator%=(int x) {
    BigInt z = *this;
    *this = z % x;
  }
  BigInt operator%(int x) {
    BigInt y;
    y = x;
    return operator%(y);
  }
  BigInt operator<<(int l) {
    BigInt x;
    for (int i = 1; i <= n; i++) {
      x.a[i + l] = a[i];
    }
    x.n = n + l;
    return x;
  }
  BigInt operator>>(int l) {
    BigInt x;
    x.n = n - l;
    for (int i = 1; i <= x.n; i++) {
      x.a[i] = a[i + l];
    }
    return x;
  }
};
};

using namespace Integer;

int main() {
  BigInt<10010, 10, int> a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  if (a < b) {
    swap(a, b);
    cout << '-';
  }
  cout << a - b << '\n' << a * b << '\n' << a / b << '\n' << a % b;
  return 0;
}