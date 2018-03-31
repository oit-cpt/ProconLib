#include "template.h"

struct Edge {
  long long cost;
  int to;
  Edge(int t, long long c) {
    cost = c;
    to = t;
  }
  bool operator<(const Edge &e) const { return cost < e.cost; }
  bool operator>(const Edge &e) const { return cost > e.cost; }
};

class Dijkstra {
 private:
  bool is_dir = false;  // 無向グラフ: false, 有向グラフ: true
  long long INFl = (long long)1e15;
  int array_size_of_cost;
  vector<vector<Edge>> adj;  // adj[始点][動的配列で始点から伸びる枝]

 public:
  Dijkstra(int n, bool dir);
  vector<long long> cost;
  vector<int> prever;
  void add_edge(int f, int t, long long c);
  bool has_path(int t);  // tに至るパスはあるか
  vector<int> get_shortest_path(int t);
  void run(int f);
};

Dijkstra::Dijkstra(int n, bool dir)
    : is_dir(dir),
      array_size_of_cost(n + 1),
      adj(vector<vector<Edge>>(array_size_of_cost)),
      cost(vector<long long>(array_size_of_cost)),
      prever(vector<int>(array_size_of_cost, -1)) {
  fill(cost.begin(), cost.end(), INFl);
}

void Dijkstra::add_edge(int f, int t, long long c) {
  adj[f].push_back(Edge(t, c));
  if (!is_dir) adj[t].push_back(Edge(f, c));
}

bool Dijkstra::has_path(int t) { return cost[t] != INFl; }

vector<int> Dijkstra::get_shortest_path(int t) {
  vector<int> path;
  for (; t != -1; t = prever[t]) path.push_back(t);

  reverse(path.begin(), path.end());
  return path;
}

void Dijkstra::run(int first_state) {
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

      long long sum_cost = current_state.cost + tmp.cost;
      if (cost[tmp.to] > sum_cost) {
        cost[tmp.to] = sum_cost;
        prever[tmp.to] = current_state.to;
        pq.push(Edge(tmp.to, cost[tmp.to]));
      }
    }
  }
}
