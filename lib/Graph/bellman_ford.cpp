#include "template.h"

struct Edge {
  int to;
  Int cost;
  Edge(int to, Int cost) : to(to), cost(cost) {}
};

class BellmanFord {
 private:
  Int INF_L = (Int)1e15;
  int arraySizeOfCost;
  int nodeNum;
  vector<vector<Edge>> adj;  // adj[始点][動的配列で始点から伸びる枝]
  vector<bool> negative;  // negative[n] := nに到達するまでに負閉路があるか

 public:
  explicit BellmanFord(int n);
  vector<Int> dist;  // 最短経路
  void AddEdge(int f, int t, Int c);
  void Run(int f);
  bool HasNegativeCycle(int n);
};

BellmanFord::BellmanFord(int n)
    : ArraySizeOfCost(n + 1),
      nodeNum(n),
      adj(vector<vector<Edge>>(ArraySizeOfCost)),
      negative(ArraySizeOfCost),
      dist(vector<Int>(ArraySizeOfCost)) {
  fill(dist.begin(), dist.end(), INF_L);
  fill(negative.begin(), negative.end(), false);
}

void BellmanFord::AddEdge(int f, int t, Int c) { adj[f].push_back(Edge(t, c)); }

void BellmanFord::Run(int firstNode) {
  dist[firstNode] = 0;
  for (int loop = 0; loop < nodeNum - 1; loop++) {
    for (int i = 0; i < nodeNum; i++) {
      for (const Edge& e : adj[i]) {
        if (dist[i] == INF_L) continue;
        if (dist[e.to] > dist[i] + e.cost) {
          dist[e.to] = dist[i] + e.cost;
        }
      }
    }
  }

  for (int loop = 0; loop < nodeNum; loop++) {
    for (int i = 0; i < nodeNum; i++) {
      for (const Edge& e : adj[i]) {
        if (dist[i] == INF_L) continue;
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

bool BellmanFord::HasNegativeCycle(int n) { return negative[n]; }
