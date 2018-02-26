#include "template.h"

vector<Int> calcInverseFactorial(Int N, Int MOD) {
  vector<Int> factr(N);
  vector<Int> inv(N);
  inv[1] = 1;
  factr[0] = 1;
  rep(i, N) if (i > 1) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  rep(i, N) if (i) factr[i] = factr[i - 1] * inv[i] % MOD;
  return factr;
}
