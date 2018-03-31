#include "template.h"

struct Edge {
  Int cost;
  int to;
  Edge(int t, Int c) {
    cost = c;
    to = t;
  }
  bool operator<(const Edge &e) const { return cost < e.cost; }
  bool operator>(const Edge &e) const { return cost > e.cost; }
};

class Dijkstra {
 private:
  bool isDir = false;  // 無向グラフ: false, 有向グラフ: true
  Int INFl = (Int)1e15;
  int arraySizeOfCost;
  vector<vector<Edge>> adj;  // adj[始点][動的配列で始点から伸びる枝]

 public:
  Dijkstra(int n, bool dir);
  vector<Int> cost;
  vector<int> prever;
  void AddEdge(int f, int t, Int c);
  bool HasPath(int t);  // tに至るパスはあるか
  vector<int> getShortestPath(int t);
  void Run(int f);
};

Dijkstra::Dijkstra(int n, bool dir)
    : isDir(dir),
      arraySizeOfCost(n + 1),
      adj(vector<vector<Edge>>(arraySizeOfCost)),
      cost(vector<Int>(arraySizeOfCost)),
      prever(vector<int>(arraySizeOfCost, -1)) {
  fill(cost.begin(), cost.end(), INFl);
}

void Dijkstra::AddEdge(int f, int t, Int c) {
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

void Dijkstra::Run(int first_state) {
  using State = Edge;
  priority_queue<State, vector<State>, greater<State>> pq;

  cost[first_state] = 0;
  pq.push(Edge(first_state, 0LL));

  while (!pq.empty()) {
    State current_state = pq.top();
    pq.pop();

    if (cost[current_state.to] < current_state.cost) continue;

    for (int i = 0; i < adj[current_state.to].size(); i++) {
      State tmp = adj[current_state.to][i];

      Int sum_cost = current_state.cost + tmp.cost;
      if (cost[tmp.to] > sum_cost) {
        cost[tmp.to] = sum_cost;
        prever[tmp.to] = current_state.to;
        pq.push(Edge(tmp.to, cost[tmp.to]));
      }
    }
  }
}
