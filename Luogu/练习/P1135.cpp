#include<cstdio>
#include<queue>

using namespace std;

int n, x, y, t, l[400000];

bool b[400000];

struct g {

    int x, s;
} a;

int main() {

    scanf("%d%d%d",&n,&x,&y);

    for (int i = 1; i <= n; i++) {

        scanf("%d",&l[i]);
    }

    queue<g> q;

    a.x = x;

    a.s = 0;

    q.push(a);

    while (!q.size()) {

        g h = q.front();

        q.pop();

        if (h.x == y) {

            printf("%d\n",h.s);

            return 0;
        }

        for (int i = 0; i < 2; i++) {

            t = 0;

            if (i == 0) {

                t = h.x + l[h.x];

            }

            if (i == 1) {

                t = h.x - l[h.x];
            }

            if (b[t] || t <= 0 || t > n) {

                continue;
            }

            b[t] = 1;

            a.x = t;

            a.s = h.s + 1;

            q.push(a);
        }
    }

    printf("-1");

    return 0;
}