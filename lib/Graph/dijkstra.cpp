#include "template.h"

struct Edge {
  int cost, to;
  Edge(int t, int c) {
    cost = c;
    to = t;
  }
  bool operator<(const Edge &e) const { return cost < e.cost; }
  bool operator>(const Edge &e) const { return cost > e.cost; }
};

class Dijkstra {
 private:
  bool isDir = false;  // 無向グラフ: false, 有向グラフ: true
  long long INFl = (long long)1e15;
  int V;                     // 頂点数
  vector<vector<Edge>> adj;  // adj[始点][動的配列で始点から伸びる枝]
  vector<int> prever;

 public:
  Dijkstra(int n, bool dir);
  vector<long long> cost;
  void AddEdge(int f, int t, int c);
  bool HasPath(int t);                 // tに至るパスはあるか
  vector<int> getShortestPath(int t);  // tへの最短路
  void Run(int f);
};

Dijkstra::Dijkstra(int n, bool dir)
    : isDir(dir),
      V(n + 1),
      adj(vector<vector<Edge>>(V)),
      prever(vector<int>(V, -1)),
      cost(vector<long long>(V)) {
  fill(cost.begin(), cost.end(), INFl);
}

void Dijkstra::AddEdge(int f, int t, int c) {
  adj[f].push_back(Edge(t, c));
  if (!isDir) adj[t].push_back(Edge(f, c));
}

bool Dijkstra::HasPath(int t) { return cost[t] != INFl; }

vector<int> Dijkstra::getShortestPath(int t) {
  vector<int> path;
  for (; t != -1; t = prever[t]) path.push_back(t);

  reverse(path.begin(), path.end());
  return path;
}

void Dijkstra::Run(int firstNode) {
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

  cost[firstNode] = 0;
  pq.push(Edge(firstNode, 0LL));

  while (!pq.empty()) {
    Edge currentEdge = pq.top();
    pq.pop();

    if (cost[currentEdge.to] < currentEdge.cost) continue;

    for (Edge tmp : adj[currentEdge.to]) {
      long long sumCost = currentEdge.cost + tmp.cost;
      if (cost[tmp.to] > sumCost) {
        cost[tmp.to] = sumCost;
        prever[tmp.to] = currentEdge.to;
        pq.push(Edge(tmp.to, cost[tmp.to]));
      }
    }
  }
}
