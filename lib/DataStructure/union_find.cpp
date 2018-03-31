#include "template.h"

class UnionFind {
 private:
  vector<int> parent;  // 親
  vector<int> rank;    // 木の深さ
 public:
  UnionFind(int n);          // n要素で初期化
  int Find(int x);           // 木の根を返す
  void Unite(int x, int y);  // xとyの属する集合を併合
  bool Same(int x, int y);   // xとyが同じ集合に属するか否か
};

UnionFind::UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n)) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int UnionFind::Find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return parent[x] = Find(parent[x]);
  }
}

void UnionFind::Unite(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;

  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
}

bool UnionFind::Same(int x, int y) { return Find(x) == Find(y); }
