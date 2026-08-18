#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

string cards[150];
int nml[40], dp[40][5][2][3][3], lst[40][5][2][3][3];
int top = 1, rev = 0;

struct Player {
  vector<string> crd;
  bool pass;
  int crds;
  int id;
  int NEXT();
  void IN(string);
  void OUT(string);
  void PASS(int);
  void CHOW(string, string, string);
  void PONG(string, string, string);
  void RON();
  void WIN();
  void SELFDRAWN();
  void TakeCard();
  int UseCrd();
  int CanUse();
  bool ChkSpe();
  pair<int, int> GetDist(int);
  void ChkWin(string);
  void CrdUse(string);
} pl[5];

int Player::NEXT() {
  return (rev ? (id - 1 + 4) % 4 : (id + 1) % 4);
}

void Init() {
  // Z, F, B, N, W, S, E
  mp["Z"] = 1, mp["F"] = 2, mp["B"] = 3, mp["N"] = 4, mp["W"] = 5, mp["S"] = 6, mp["E"] = 7;
  // S
  mp["9S"] = 8, mp["8S"] = 9, mp["7S"] = 10, mp["6S"] = 11, mp["5S"] = 12, mp["4S"] = 13, mp["3S"] = 14, mp["2S"] = 15, mp["1S"] = 16;
  // P
  mp["9P"] = 17, mp["8P"] = 18, mp["7P"] = 19, mp["6P"] = 20, mp["5P"] = 21, mp["4P"] = 22, mp["3P"] = 23, mp["2P"] = 24, mp["1P"] = 25;
  // M
  mp["9M"] = 26, mp["8M"] = 27, mp["7M"] = 28, mp["6M"] = 29, mp["5M"] = 30, mp["4M"] = 31, mp["3M"] = 32, mp["2M"] = 33, mp["1M"] = 34;
  // Special
  mp["PASS"] = 35, mp["REVERSE"] = 36, mp["DOUBLE"] = 37;
  pl[1].crds = pl[2].crds = pl[3].crds = pl[4].crds = 12;
  pl[1].id = 0, pl[2].id = 1, pl[3].id = 2, pl[4].id = 3;
}

void Player::IN(string crd) {
  cout << char(id + 'A') << " IN " << crd << '\n';
}

void Player::OUT(string crd) {
  cout << char(id + 'A') << " OUT " << crd << '\n';
}

void Player::PASS(int y) {
  cout << char(id + 'A') << " OUT PASS " << char(y + 'A' - 1) << '\n';
}

void Player::CHOW(string y1, string y2, string y3) {
  cout << char(id + 'A') << " CHOW " << y1 << ' ' << y2 << ' ' << y3 << '\n';
}

void Player::PONG(string y1, string y2, string y3) {
  cout << char(id + 'A') << " PONG " << y1 << ' ' << y2 << ' ' << y3 << '\n';
}

void Player::RON() {
  cout << char(id + 'A') << " RON\n";
  WIN();
}

void Player::WIN() {
  cout << char(id + 'A') << " WIN\n";
  exit(0);
}

void Player::SELFDRAWN() {
  cout << char(id + 'A' - 1) << " SELFDRAWN\n";
  WIN();
}

void DRAW() {
  cout << "DRAW";
  exit(0);
}

void Player::TakeCard() {
  if (top > 148) {
    DRAW();
  }
  crd.push_back(cards[top]);
  top++;
  IN(crd[crd.size() - 1]);
  crds++;
  sort(crd.begin(), crd.end(), [](const string &i, const string &j) {
    return mp[i] > mp[j];
  });
}

int Player::UseCrd() {
  if (crd[crds] == "PASS") {
    pl[NEXT()].pass = 1;
    crds--;
    PASS(NEXT());
    return NEXT();
  } else if (crd[crds] == "REVERSE") {
    rev ^= 1;
    crds--;
    OUT("REVERSE");
    return NEXT();
  } else {
    crds--;
    OUT("DOUBLE");
    TakeCard();
    return UseCrd();
  }
  int t = CanUse();
  if (t == -1) SELFDRAWN();

}

pair<int, int> GetDist(int x) {
  memset(dp, INT_MAX, sizeof(dp));
  memset(lst, -1, sizeof(lst));
  dp[0][0][0][0][0] = 0;
  for (int i = 0; i < 34; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 3 && l + j <= x; l++) {
          for (int o = 0; o < 3 && o + l + j <= x; o++) {
            if (dp[i][j][k][l][o] < 15) {
              for (int q = l + o; q <= 4; q++) {
                int nx = dp[i][j][k][l][o] + max(0, q - nml[i + 1]);
                int ny = (nml[i + 1] > q ? i + 1 : lst[i][j][k][l][o]);
                int t = q - l - o;
                if (t >= 3 && l + j + 1 <= x) {
                  if (nx < dp[i + 1][j + l][k + 1][o][t - 3] || (nx == dp[i + 1][j + l][k + 1][o][t - 3] && ny < lst[i + 1][j + l][k + 1][o][t - 3])) {
                    nx = dp[i + 1][j + l][k + 1][o][t - 3], ny = lst[i + 1][j + l][k + 1][o][t - 3];
                  }
                } else if (t >= 2 && !k) {
                  if (nx < dp[i + 1][j + l][k + 1][o][t - 2] || (nx == dp[i + 1][j + l][k + 1][o][t - 2] && ny < lst[i + 1][j + l][k + 1][o][t - 2])) {
                    nx = dp[i + 1][j + l][k + 1][o][t - 2], ny = lst[i + 1][j + l][k + 1][o][t - 2];
                  }
                } else if (t >= 2) {
                  if (nx < dp[i + 1][j + l][k + 1][o][t] || (nx == dp[i + 1][j + l][k + 1][o][t] && ny < lst[i + 1][j + l][k + 1][o][t])) {
                    nx = dp[i + 1][j + l][k + 1][o][t], ny = lst[i + 1][j + l][k + 1][o][t];
                  }
                }
              }
              if (i % 9 == 0 || i >= 27) break;
            }
            if (i % 9 == 0 || i >= 27) break;
          }
        }
      }
    }
  }
  return {dp[34][x][1][0][0], lst[34][x][1][0][0]};
}

int Player::CanUse() {
  memset(nml, 0, sizeof(nml));
  for (int i = 0; i < crds; i++) {
    if (mp[crd[i]] <= 34) nml[mp[crd[i]]]++;
  }
  return GetDist(4 - (14 - crds) / 3).second;
}

bool Player::ChkSpe() {
  for (int i = 0; i < crds; i++) {
    if (mp[crd[i]] > 34) return 1;
  }
  return 0;
}

void Player::ChkWin(string crd) {
  for (int i = NEXT(); i != id; i = pl[i + 1].NEXT()) {
    if (!pl[i + 1].ChkSpe()) {
      pl[i + 1].crd.push_back(crd);
      crds++;
      if (CanUse() == -1) {
        pl[i + 1].RON();
      }
      crds--;
      pl[i + 1].crd.resize(pl[i + 1].crd.size() - 1);
    }
  }
}

void Player::CrdUse(string card) {
  int id;
  for (id = 0; id < crd.size(); id++) {
    if (card == crd[id]) {
      break;
    }
  }
  swap(crd[id], crd[crd.size() - 1]);
  crd.resize(crd.size() - 1);
  crds--;
  sort(crd.begin(), crd.end(), [](const string &i, const string &j) {
    return mp[i] > mp[j];
  });
  OUT(card);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (int i = 1; i <= 148; i++) {
    cin >> cards[i];
  }
  return 0;
}