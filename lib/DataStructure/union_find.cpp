#include "template.h"

class UnionFind {
 private:
  vector<int> parent;  // 親
  vector<int> rank;    // 木の深さ
 public:
  UnionFind(int n);          // n要素で初期化
  int find(int x);           // 木の根を返す
  void unite(int x, int y);  // xとyの属する集合を併合
  bool same(int x, int y);   // xとyが同じ集合に属するか否か
};

UnionFind::UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n)) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int UnionFind::find(int x) {
  if (parent[x] == x) {
    return x;
  } else {
    return parent[x] = find(parent[x]);
  }
}

void UnionFind::unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rank[x] < rank[y]) {
    parent[x] = y;
  } else {
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
  }
}

bool UnionFind::same(int x, int y) { return find(x) == find(y); }
