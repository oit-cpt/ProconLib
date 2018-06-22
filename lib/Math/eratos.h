#pragma once
#include "template.h"

template <typename T>
vector<T> eratos(T n) {
  vector<T> primeVec;
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (isPrime[p])
      for (int i = p * 2; i <= n; i += p) isPrime[i] = false;
  }
  for (int p = 2; p <= n; p++)
    if (isPrime[p]) primeVec.pb(p);
  return primeVec;
}
