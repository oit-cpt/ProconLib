#include "template.h"

template <typename T>
struct Edge {
  int to;
  T cost;
  Edge(int to, T cost) : to(to), cost(cost) {}
};

template <typename T>
class Prim {
 private:
  vector<vector<Edge<T>>> graph;
  vector<bool> used;

 public:
  Prim(int n);
  void AddEdge(int from, int to, T cost);
  T Run();
};

template <typename T>
Prim<T>::Prim(int n) : graph(n), used(n, false) {}

template <typename T>
void Prim<T>::AddEdge(int from, int to, T cost) {
  graph[from].push_back(Edge<T>(to, cost));
}

template <typename T>
T Prim<T>::Run() {
  using Pi = pair<T, int>;
  T total = 0;
  priority_queue<Pi, vector<Pi>, greater<Pi>> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    Pi p = que.top();
    que.pop();
    if (used[p.second]) continue;
    used[p.second] = true;
    total += p.first;
    for (auto &e : graph[p.second]) {
      que.emplace(e.cost, e.to);
    }
  }
  return total;
}
