#include "template.h"
#include "graph.h"

template <typename T>
class Dinic {
 private:
  int V;  // 頂点数
  vector<T> minCost;
  vector<int> iter;
  AdjList<T> graph;
  const T INF = numeric_limits<T>::max() / 10;
  bool Bfs(int s, int t);
  T Dfs(int idx, const int t, T flow);

 public:
  explicit Dinic(int n);
  void AddEdge(int from, int to, T cap);
  T Run(int s, int t);
};

template <typename T>
Dinic<T>::Dinic(int n) : V(n), graph(n) {}

template <typename T>
void Dinic<T>::AddEdge(int from, int to, T cap) {
  graph[from].push_back(Edge<T>(to, cap, static_cast<int>(graph[to].size())));
  graph[to].push_back(
      Edge<T>(from, 0, static_cast<int>(graph[from].size() - 1)));
}

template <typename T>
bool Dinic<T>::Bfs(int s, int t) {
  minCost.assign(graph.size(), -1);
  queue<int> que;
  minCost[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (auto &e : graph[p]) {
      if (e.cap > 0 && minCost[e.to] < 0) {
        minCost[e.to] = minCost[p] + 1;
        que.push(e.to);
      }
    }
  }
  return (minCost[t] != -1);
}

template <typename T>
T Dinic<T>::Dfs(int idx, const int t, T flow) {
  if (idx == t) return flow;
  for (int &i = iter[idx]; i < static_cast<int>(graph[idx].size()); ++i) {
    Edge<T> &e = graph[idx][i];
    if (e.cap > 0 && minCost[idx] < minCost[e.to]) {
      T d = Dfs(e.to, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        graph[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

template <typename T>
T Dinic<T>::Run(int s, int t) {
  T flow = 0;
  while (Bfs(s, t)) {
    iter.assign(graph.size(), 0);
    T f = 0;
    while ((f = Dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
  return flow;
}
