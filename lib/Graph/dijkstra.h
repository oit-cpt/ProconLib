#pragma once
#include "graph.h"
#include "template.h"

template <typename T>
class Dijkstra {
 private:
  bool isDir = false;  // 無向グラフ: false, 有向グラフ: true
  T INF = numeric_limits<T>::max() / 10;
  int V;           // 頂点数
  AdjList<T> adj;  // adj[始点][動的配列で始点から伸びる枝]
  vector<int> prever;

 public:
  Dijkstra(int n, bool dir);
  vector<T> cost;
  void AddEdge(int f, int t, int c);
  bool HasPath(int t);                 // tに至るパスはあるか
  vector<int> GetShortestPath(int t);  // tへの最短路
  void Run(int f);
};

template <typename T>
Dijkstra<T>::Dijkstra(int n, bool dir)
    : isDir(dir), V(n + 1), adj(V), prever(vector<int>(V, -1)), cost(V) {
  fill(cost.begin(), cost.end(), INF);
}

template <typename T>
void Dijkstra<T>::AddEdge(int f, int t, int c) {
  adj[f].push_back(Edge<T>(t, c));
  if (!isDir) adj[t].push_back(Edge<T>(f, c));
}

template <typename T>
bool Dijkstra<T>::HasPath(int t) {
  return cost[t] != INF;
}

template <typename T>
vector<int> Dijkstra<T>::GetShortestPath(int t) {
  vector<int> path;
  for (; t != -1; t = prever[t]) path.push_back(t);

  reverse(path.begin(), path.end());
  return path;
}

template <typename T>
void Dijkstra<T>::Run(int firstNode) {
  using Pi = pair<T, int>;
  priority_queue<Pi, vector<Pi>, greater<Pi>> pq;

  cost[firstNode] = 0;
  pq.push(Pi(cost[firstNode], firstNode));

  while (!pq.empty()) {
    Pi currentEdge = pq.top();
    pq.pop();
    if (cost[currentEdge.second] < currentEdge.first) continue;

    for (Edge<T> tmp : adj[currentEdge.second]) {
      T sumCost = currentEdge.first + tmp.cost;
      if (cost[tmp.to] > sumCost) {
        cost[tmp.to] = sumCost;
        prever[tmp.to] = currentEdge.second;
        pq.push(Pi(cost[tmp.to], tmp.to));
      }
    }
  }
}
