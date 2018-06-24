#include "gtest/gtest.h"
#include "template.h"
vector<int> eratos(int N);

TEST(MathTest, eratos) {
  const int N = 100;
  vector<int> fact = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  auto sosuuList = eratos(N);
  rep(i, sosuuList.size()) { EXPECT_EQ(fact[i], sosuuList[i]); }
}
TEST(MathTest, eratos) {
  const int N = 10000;
  int fact = 1229;
  auto sosuuList = eratos(N);
  EXPECT_EQ(fact, (int)sosuuList.size());
}
