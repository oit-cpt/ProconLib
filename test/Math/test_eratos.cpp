#include "gtest/gtest.h"
#include "lib/Math/eratos.h"

TEST(MathTest, eratos_100) {
  const int N = 100;
  vector<int> fact = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  auto primeVec = eratos(N);
  rep(i, primeVec.size()) { EXPECT_EQ(fact[i], primeVec[i]); }
}
TEST(MathTest, eratos_10000) {
  const int N = 10000;
  int fact = 1229;
  auto primeVec = eratos(N);
  EXPECT_EQ(fact, (int)primeVec.size());
}
