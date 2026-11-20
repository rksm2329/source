#include <bits/stdc++.h>

using namespace std;

int main() {
  char s[20];
  scanf("%s", s);
  int code = 0;
  int len = strlen(s);
  if (s[len - 1] == 'X') {
    code = 10;
  } else {
    code = s[len - 1] - '0';
  }
  for (int i = 0; i < len; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      s[i] -= '0';
    }
  }
  if ((s[0] + s[2] * 2 + s[3] * 3 + s[4] * 4 + s[6] * 5 + s[7] * 6 + s[8] * 7 +
       s[9] * 8 + s[10] * 9) %
          11 !=
      code) {
    for (int i = 0; i < len - 1; i++) {
      printf("%c", s[i]);
    }
    if ((s[0] + s[2] * 2 + s[3] * 3 + s[4] * 4 + s[6] * 5 + s[7] * 6 +
         s[8] * 7 + s[9] * 8 + s[10] * 9) %
            11 ==
        10) {
      printf("X");
    } else {
      printf("%d", (s[0] + s[2] * 2 + s[3] * 3 + s[4] * 4 + s[6] * 5 +
                    s[7] * 6 + s[8] * 7 + s[9] * 8 + s[10] * 9) %
                       11);
    }
  } else {
    printf("Right");
  }
  return 0;
}