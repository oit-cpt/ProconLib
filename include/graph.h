template <typename T>
struct Edge {
  int from, to;
  T cost;
  Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
using Edges = vector<Edge<T>>;
template <typename T>
using AdjList = vector<Edges<T>>;
