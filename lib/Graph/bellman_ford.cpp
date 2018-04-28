#include "graph.h"
#include "template.h"

template <typename T>
class BellmanFord {
 private:
  T INF = numeric_limits<T>::max() / 10;
  int V;
  int nodeNum;
  AdjList<T> adj;  // adj[始点][動的配列で始点から伸びる枝]
  vector<bool> negative;  // negative[n] := nに到達するまでに負閉路があるか

 public:
  explicit BellmanFord(int n);
  vector<Int> dist;  // 最短経路
  void AddEdge(int f, int t, Int c);
  void Run(int f);
  bool HasNegativeCycle(int n);
};

template <typename T>
BellmanFord<T>::BellmanFord(int n)
    : V(n + 1), nodeNum(n), adj(V), negative(V, false), dist(V, INF) {}

template <typename T>
void BellmanFord<T>::AddEdge(int f, int t, Int c) {
  adj[f].push_back(Edge<T>(t, c));
}

template <typename T>
void BellmanFord<T>::Run(int firstNode) {
  dist[firstNode] = 0;
  for (int loop = 0; loop < nodeNum - 1; loop++) {
    for (int i = 0; i < nodeNum; i++) {
      for (const Edge<T>& e : adj[i]) {
        if (dist[i] == INF) continue;
        if (dist[e.to] > dist[i] + e.cost) {
          dist[e.to] = dist[i] + e.cost;
        }
      }
    }
  }

  for (int loop = 0; loop < nodeNum; loop++) {
    for (int i = 0; i < nodeNum; i++) {
      for (const Edge<T>& e : adj[i]) {
        if (dist[i] == INF) continue;
        if (dist[e.to] > dist[i] + e.cost) {
          dist[e.to] = dist[i] + e.cost;
          negative[e.to] = true;
        }
        if (negative[i] == true) {
          negative[e.to] = true;
        }
      }
    }
  }
}

template <typename T>
bool BellmanFord<T>::HasNegativeCycle(int n) {
  return negative[n];
}
