#include "template.h"

struct Edge {
  int to, cost;
  Edge(int to, int cost) : to(to), cost(cost) {}

  bool operator<(const Edge &e) const { return cost < e.cost; }
  bool operator>(const Edge &e) const { return cost > e.cost; }
};

template <typename T>
class Dijkstra {
 private:
  bool isDir = false;  // 無向グラフ: false, 有向グラフ: true
  T INF = numeric_limits<T>::max();
  int V;                     // 頂点数
  vector<vector<Edge>> adj;  // adj[始点][動的配列で始点から伸びる枝]
  vector<int> prever;

 public:
  Dijkstra(int n, bool dir);
  vector<T> cost;
  void AddEdge(int f, int t, int c);
  bool HasPath(int t);                 // tに至るパスはあるか
  vector<int> getShortestPath(int t);  // tへの最短路
  void Run(int f);
};

template <typename T>
Dijkstra<T>::Dijkstra(int n, bool dir)
    : isDir(dir),
      V(n + 1),
      adj(vector<vector<Edge>>(V)),
      prever(vector<int>(V, -1)),
      cost(vector<T>(V)) {
  fill(cost.begin(), cost.end(), INF);
}

template <typename T>
void Dijkstra<T>::AddEdge(int f, int t, int c) {
  adj[f].push_back(Edge(t, c));
  if (!isDir) adj[t].push_back(Edge(f, c));
}

template <typename T>
bool Dijkstra<T>::HasPath(int t) {
  return cost[t] != INF;
}

template <typename T>
vector<int> Dijkstra<T>::getShortestPath(int t) {
  vector<int> path;
  for (; t != -1; t = prever[t]) path.push_back(t);

  reverse(path.begin(), path.end());
  return path;
}

template <typename T>
void Dijkstra<T>::Run(int firstNode) {
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

  cost[firstNode] = 0;
  pq.push(Edge(firstNode, 0LL));

  while (!pq.empty()) {
    Edge currentEdge = pq.top();
    pq.pop();

    if (cost[currentEdge.to] < currentEdge.cost) continue;

    for (Edge tmp : adj[currentEdge.to]) {
      T sumCost = currentEdge.cost + tmp.cost;
      if (cost[tmp.to] > sumCost) {
        cost[tmp.to] = sumCost;
        prever[tmp.to] = currentEdge.to;
        pq.push(Edge(tmp.to, cost[tmp.to]));
      }
    }
  }
}
