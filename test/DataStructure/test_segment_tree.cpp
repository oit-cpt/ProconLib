#include "gtest/gtest.h"
#include "lib/DataStructure/segment_tree.h"

// Range Minimum Query
TEST(DataStructureTest, segment_tree_RMQ) {
  vector<int> vec(3, 1e9);
  SegmentTree<int> segmentTree(vec, [](int a, int b) { return min(a, b); },
                               1e9);

  segmentTree.Update(0, 1);
  segmentTree.Update(1, 2);
  segmentTree.Update(2, 3);

  EXPECT_EQ(segmentTree.Query(0, 2 + 1), 1);
  EXPECT_EQ(segmentTree.Query(1, 2 + 1), 2);
}

// Range Sum Query
TEST(DataStructureTest, segment_tree_RSQ) {
  vector<int> vec(3, 0);
  SegmentTree<int> segmentTree(vec, [](int a, int b) { return a + b; }, 0);

  segmentTree.Update(0, 1);
  segmentTree.Update(1, 2);
  segmentTree.Update(2, 3);

  EXPECT_EQ(segmentTree.Query(0, 1 + 1), 3);
  EXPECT_EQ(segmentTree.Query(1, 1 + 1), 2);
}
