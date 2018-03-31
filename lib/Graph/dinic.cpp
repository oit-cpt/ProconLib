#include "template.h"

struct Edge {
  int to;
  Int cap;
  int rev;
};

class Dinic {
 private:
  int V;  // 頂点数
  vector<Int> minCost;
  vector<int> iter;
  vector<vector<Edge>> graph;
  const Int INFl = 1e15;
  bool Bfs(int s, int t);
  Int Dfs(int idx, const int t, Int flow);

 public:
  explicit Dinic(int n);
  void AddEdge(int from, int to, Int cap);
  Int Run(int s, int t);
};

Dinic::Dinic(int n) : V(n) { graph.assign(V, vector<Edge>()); }

void Dinic::AddEdge(int from, int to, Int cap) {
  graph[from].push_back((Edge){to, cap, static_cast<int>(graph[to].size())});
  graph[to].push_back(
      (Edge){from, 0, static_cast<int>(graph[from].size() - 1)});
}

bool Dinic::Bfs(int s, int t) {
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

Int Dinic::Dfs(int idx, const int t, Int flow) {
  if (idx == t) return flow;
  for (int &i = iter[idx]; i < static_cast<int>(graph[idx].size()); ++i) {
    Edge &e = graph[idx][i];
    if (e.cap > 0 && minCost[idx] < minCost[e.to]) {
      Int d = Dfs(e.to, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        graph[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

Int Dinic::Run(int s, int t) {
  Int flow = 0;
  while (Bfs(s, t)) {
    iter.assign(graph.size(), 0);
    Int f = 0;
    while ((f = Dfs(s, t, INFl)) > 0) {
      flow += f;
    }
  }
  return flow;
}
