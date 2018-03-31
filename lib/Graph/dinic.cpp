#include "template.h"

struct Edge {
  int to;
  long long cap;
  int rev;
};

class Dinic {
 private:
  int V;  // 頂点数
  vector<long long> minCost;
  vector<int> iter;
  vector<vector<Edge>> graph;
  const long long INFl = 1e15;
  bool Bfs(int s, int t);
  long long Dfs(int idx, const int t, long long flow);

 public:
  Dinic(int n);
  void AddEdge(int from, int to, long long cap);
  long long Run(int s, int t);
};

Dinic::Dinic(int n) : V(n) { graph.assign(V, vector<Edge>()); }

void Dinic::AddEdge(int from, int to, long long cap) {
  graph[from].push_back((Edge){to, cap, (int)graph[to].size()});
  graph[to].push_back((Edge){from, 0, (int)graph[from].size() - 1});
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

long long Dinic::Dfs(int idx, const int t, long long flow) {
  if (idx == t) return flow;
  for (int &i = iter[idx]; i < (int)graph[idx].size(); ++i) {
    Edge &e = graph[idx][i];
    if (e.cap > 0 && minCost[idx] < minCost[e.to]) {
      long long d = Dfs(e.to, t, min(flow, e.cap));
      if (d > 0) {
        e.cap -= d;
        graph[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

long long Dinic::Run(int s, int t) {
  long long flow = 0;
  while (Bfs(s, t)) {
    iter.assign(graph.size(), 0);
    long long f = 0;
    while ((f = Dfs(s, t, INFl)) > 0) {
      flow += f;
    }
  }
  return flow;
}
