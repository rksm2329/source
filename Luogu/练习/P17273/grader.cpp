#include "automata.h"
#include <cassert>
#include <cstdio>

int main() {
  int N, Q;
  assert(2 == scanf("%d %d", &N, &Q));
  std::vector<int> P(N);
  for (int i = 0; i < N; i++) {
    assert(1 == scanf("%d", &P[i]));
  }
  std::vector<std::vector<int>> queries;
  for (int i = 0; i < Q; i++) {
    int K;
    assert(1 == scanf("%d", &K));
    std::vector<int> X(K);
    for (int j = 0; j < K; j++) {
        assert(1 == scanf("%d", &X[j]));
    }
    queries.push_back(X);
  }
  fclose(stdin);

  std::vector<bool> A(Q);

  initialize(P);

  for (int i = 0; i < Q; i++) {
    A[i] = exists_program(queries[i]);
  }

  for (int i = 0; i < Q; i++) {
    if (A[i]) printf("1");
    else printf("0");
  }
  printf("\n");
  fclose(stdout);

  return 0;
}
