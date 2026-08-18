#include <bits/stdc++.h>

using namespace std;

#define CRD_USED true
#define CRD_CAN_USE false
#define PIG_DEAD true
#define PIG_NOT_DEAD false
#define PIG_JUMPED true
#define PIG_NOT_JUMPED false
#define PIG_LIKE_BAD true
#define PIG_NOT_LIKE_BAD false
#define HAVE_Z true
#define NOT_HAVE_Z false

struct Card {
  char crd;
  bool used;
};

Card crds[2010];
int n, m, np, top = 1;
char tp[15];

struct Pig {
  int hp, id;
  bool usedK, haveZ, jumped, likeBad, dead;
  string type;
  vector<Card> card;
  Pig() {
    hp = 4;
    dead = PIG_NOT_DEAD;
    jumped = PIG_NOT_JUMPED;
    haveZ = NOT_HAVE_Z;
    likeBad = PIG_NOT_LIKE_BAD;
    usedK = CRD_CAN_USE;
  }
  void TakeCard();
  void ClearCard();
  void DelCard(int);
  int FindTo(char);
  int FindCard(char);
  void UseCard(Card &);
  void Die(int);
  void Hurt(int);
  bool CanUse(char);
  bool Resp(char);
  void Jump();
  bool FindJ(int);
  bool BackJ(int);
  void Turn();
  void K(int);
  void F(int);
  void N();
  void W();
} pg[15];
void Pig::TakeCard() {
  card.push_back(crds[top++]);
  top = min(top, m);
}
void Pig::ClearCard() {
  card.clear();
  haveZ = NOT_HAVE_Z;
}
void Pig::DelCard(int crd) { card[crd].used = CRD_USED; }
int Pig::FindTo(char crd) {
  if (crd == 'K') {
    if (usedK == CRD_USED && haveZ == NOT_HAVE_Z) return 0;
    if (type == "MP") {
      for (int i = id % n + 1; i != id; i = i % n + 1) {
        if (pg[i].dead == PIG_DEAD) {
          continue;
        }
        if (pg[i].likeBad == PIG_LIKE_BAD || (pg[i].type == "FP" && pg[i].jumped == PIG_JUMPED)) {
          return i;
        } else {
          return 0;
        }
      }
    } else if (type == "ZP") {
      for (int i = id % n + 1; i != id; i = i % n + 1) {
        if (pg[i].dead == PIG_DEAD) {
          continue;
        }
        if (pg[i].type == "FP" && pg[i].jumped == PIG_JUMPED) {
          return i;
        } else {
          return 0;
        }
      }
    } else if (type == "FP") {
      for (int i = id % n + 1; i != id; i = i % n + 1) {
        if (pg[i].dead == PIG_DEAD) {
          continue;
        }
        if (pg[i].type != "FP" && pg[i].jumped == PIG_JUMPED) {
          return i;
        } else {
          return 0;
        }
      }
    }
  } else if (crd == 'F') {
    if (type == "MP") {
      for (int i = id % n + 1; i != id; i = i % n + 1) {
        if (pg[i].dead == PIG_DEAD) {
          continue;
        }
        if (pg[i].likeBad == PIG_LIKE_BAD || (pg[i].type == "FP" && pg[i].jumped == PIG_JUMPED)) {
          return i;
        }
      }
    } else if (type == "ZP") {
      for (int i = id % n + 1; i != id; i = i % n + 1) {
        if (pg[i].dead == PIG_DEAD) {
          continue;
        }
        if (pg[i].type == "FP" && pg[i].jumped == PIG_JUMPED) {
          return i;
        }
      }
    } else if (type == "FP") {
      return 1;
    }
    return 0;
  }
}
int Pig::FindCard(char crd) {
  for (int i = 0; i < card.size(); i++) {
    if (card[i].used != CRD_USED && card[i].crd == crd) {
      return i;
    }
  }
  return -1;
}
void Pig::UseCard(Card &crd) {
  if (crd.crd == 'K') {
    int x = FindTo('K');
    if (x) {
      crd.used = CRD_USED;
      K(x);
    }
  } else if (crd.crd == 'P') {
    if (hp < 4) {
      crd.used = CRD_USED;
      hp++;
    }
  } else if (crd.crd == 'F') {
    int x = FindTo('F');
    if (x) {
      crd.used = CRD_USED;
      F(x);
    }
  } else if (crd.crd == 'N') {
    crd.used = CRD_USED;
    N();
  } else if (crd.crd == 'W') {
    crd.used = CRD_USED;
    W();
  } else if (crd.crd == 'Z') {
    crd.used = CRD_USED;
    haveZ = HAVE_Z;
  }
}
void Over(string winner) {
  cout << winner << '\n';
  for (int i = 1; i <= n; i++) {
    if (pg[i].dead == PIG_DEAD) {
      cout << "DEAD";
    } else {
      for (int j = 0; j < pg[i].card.size(); j++) {
        if (pg[i].card[j].used == CRD_CAN_USE) {
          cout << pg[i].card[j].crd << ' ';
        }
      }
    }
    cout << '\n';
  }
  exit(0);
}
void Pig::Die(int pig) {
  dead = PIG_DEAD;
  if (type == "MP") {
    Over("FP");
  } else if (type == "FP") {
    np--;
    if (!np) {
      Over("MP");
    }
    for (int i = 1; i <= 3; i++) {
      pg[pig].TakeCard();
    }
  } else if (type == "ZP" && pg[pig].type == "MP") {
    pg[pig].ClearCard();
  }
}
void Pig::Hurt(int pig) {
  hp--;
  if (!hp) {
    int x = FindCard('P');
    if (x == -1) {
      Die(pig);
    } else {
      DelCard(x);
      hp++;
    }
  }
}
bool Pig::CanUse(char crd) {
  if (crd == 'P' && hp < 4) return 1;
  if ((crd == 'K' && FindTo('K')) || (crd == 'F' && FindTo('F')) || crd == 'N' || crd == 'W' || crd == 'Z') return 1;
  return 0;
}
bool Pig::Resp(char crd) {
  int x;
  if (crd == 'K' || crd == 'W') {
    x = FindCard('D');
  } else if (crd == 'N') {
    x = FindCard('K');
  }
  if (x == -1)
    return 0;
  DelCard(x);
  return 1;
}
void Pig::Jump() {
  jumped = PIG_JUMPED;
}
bool Pig::FindJ(int killer) {
  if (jumped == PIG_NOT_JUMPED) return 0;
  bool first = 1;
  for (int i = killer; i != killer || first; i = i % n + 1) {
    first = 0;
    if (pg[i].dead == PIG_DEAD || (type != "FP" && pg[i].type == "FP") || (type == "FP" && pg[i].type != "FP")) {
      continue;
    }
    int x = pg[i].FindCard('J');
    if (x != -1) {
      pg[i].DelCard(x);
      pg[i].Jump();
      return !pg[i].BackJ(id);
    }
  }
  return 0;
}
bool Pig::BackJ(int pig) {
  for (int i = id % n + 1; i != id; i = i % n + 1) {
    if (pg[i].dead == PIG_DEAD) {
      continue;
    }
    if (type == "ZP" && pg[i].type != "FP") {
      continue;
    }
    if (type != "FP" && pg[i].type == "ZP") {
      continue;
    }
    if (type == "FP" && pg[i].type == "FP") {
      continue;
    }
    int x = pg[i].FindCard('J');
    if (x != -1) {
      pg[i].DelCard(x);
      pg[i].Jump();
      return !pg[pig].FindJ(i);
    }
  }
  return 0;
}
void Pig::Turn() {
  TakeCard(), TakeCard();
  bool usedCard = 1;
  while (usedCard) {
    usedCard = 0;
    for (int i = 0; i < card.size(); i++) {
      if (card[i].used == CRD_USED) {
        continue;
      }
      if (!CanUse(card[i].crd)) {
        continue;
      }
      UseCard(card[i]);
      if (dead == PIG_DEAD) {
        return;
      }
      i = -1;
      usedCard = 1;
    }
  }
  pg[id].usedK = CRD_CAN_USE;
}
void Pig::K(int pig) {
  if (usedK == CRD_USED && haveZ == NOT_HAVE_Z)
    return;
  Jump();
  likeBad = PIG_NOT_LIKE_BAD;
  usedK = CRD_USED;
  if (!pg[pig].Resp('K')) {
    pg[pig].Hurt(id);
  }
}

void Pig::F(int pig) {
  Jump();
  likeBad = PIG_NOT_LIKE_BAD;
  if (pg[pig].FindJ(id))
    return;
  if (type == "MP" && pg[pig].type == "ZP") {
    pg[pig].Hurt(id);
    return;
  }
  int victim;
  while (1) {
    int x = pg[pig].FindCard('K');
    if (x == -1) {
      victim = 2;
      break;
    } else {
      pg[pig].DelCard(x);
    }
    x = FindCard('K');
    if (x == -1) {
      victim = 1;
      break;
    } else {
      DelCard(x);
    }
  }
  if (victim == 2) {
    pg[pig].Hurt(id);
  } else if (victim == 1) {
    Hurt(pig);
  }
}

void Pig::N() {
  for (int i = id % n + 1; i != id; i = i % n + 1) {
    if (pg[i].dead == PIG_DEAD) {
      continue;
    }
    if (pg[i].FindJ(id)) {
      continue;
    }
    if (!pg[i].Resp('N')) {
      pg[i].Hurt(id);
      if (pg[i].type == "MP" && jumped == PIG_NOT_JUMPED) {
        likeBad = PIG_LIKE_BAD;
      }
    }
  }
}

void Pig::W() {
  for (int i = id % n + 1; i != id; i = i % n + 1) {
    if (pg[i].dead == PIG_DEAD) continue;
    if (pg[i].FindJ(id)) continue;
    if (!pg[i].Resp('W')) {
      pg[i].Hurt(id);
      if (pg[i].type == "MP" && jumped == PIG_NOT_JUMPED) {
        likeBad = PIG_LIKE_BAD;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> pg[i].type;
    pg[i].id = i;
    np += (pg[i].type == "FP");
    for (int j = 1; j <= 4; j++) {
      Card crd;
      cin >> crd.crd;
      pg[i].card.push_back({crd.crd, CRD_CAN_USE});
    }
  }
  for (int i = 1; i <= m; i++) {
    Card crd;
    cin >> crd.crd;
    crds[i] = {crd.crd, CRD_CAN_USE};
  }
  pg[1].Jump();
  int i = 0;
  while (1) {
    i = i % n + 1;
    if (pg[i].dead == PIG_DEAD) continue;
    pg[i].Turn();
  }
  return 0;
}