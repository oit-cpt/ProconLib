#include "gtest/gtest.h"
#include "template.h"
vector<Int> calcInverseFactorial(Int N, Int MOD);

TEST(MathTest, InverseFactorial) {
    const Int N = 100;
    const Int MOD = 1e9 + 7;
    vector<Int> fact(N);
    fact[0] = 1;
    rep(i, N) if (i) fact[i] = (fact[i - 1] * i) % MOD;
    auto invFact = calcInverseFactorial(N, MOD);
    rep(i, N) if (i) { EXPECT_EQ((invFact[i] * fact[i]) % MOD, 1); }
}
