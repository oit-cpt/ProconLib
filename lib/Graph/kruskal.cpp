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

template <typename T>
struct Edge {
  int src, to;
  T cost;
  Edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  Edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
};

template <typename T>
using Edges = vector<Edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
class Kruskal {
 private:
  int V;  // 頂点数
  Edges<T> edges;
  WeightedGraph<T> minimumSpanningTree;

 public:
  Kruskal(int n);
  void AddEdge(int from, int to, T cost);
  T Run();
  WeightedGraph<T> GetMinimumSpanningTree();
};

template <typename T>
Kruskal<T>::Kruskal(int n) : V(n), minimumSpanningTree(n) {}

template <typename T>
void Kruskal<T>::AddEdge(int from, int to, T cost) {
  edges.push_back(Edge<T>(from, to, cost));
}

template <typename T>
T Kruskal<T>::Run() {
  sort(edges.begin(), edges.end(),
       [](const Edge<T> &a, const Edge<T> &b) { return a.cost < b.cost; });
  UnionFind tree(V);
  T total = 0;

  for (auto &e : edges) {
    if (!tree.Same(e.src, e.to)) {
      tree.Unite(e.src, e.to);
      total += e.cost;
      minimumSpanningTree[e.src].push_back(Edge<T>(e.to, e.cost));
      minimumSpanningTree[e.to].push_back(Edge<T>(e.src, e.cost));
    }
  }

  return total;
}

template <typename T>
WeightedGraph<T> Kruskal<T>::GetMinimumSpanningTree() {
  return minimumSpanningTree;
}
