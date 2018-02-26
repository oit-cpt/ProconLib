#include "template.h"

struct Edge{
    int to;
    long long cost;
    Edge(int to, long long cost) : to(to), cost(cost) {}
};

class BellmanFord{
    private:
        long long INFl = (long long)1e15;
        int array_size_of_cost;
        int node_num;
        vector<vector<Edge>> adj; // adj[始点][動的配列で始点から伸びる枝]
        vector<bool> negative; // negative[n] := nに到達するまでに負閉路があるか

    public:
        BellmanFord(int n);
        vector<long long> dist; // 最短経路
        void add_edge(int f, int t, long long c);
        void run(int f);
        bool get_negative(int n);
};

BellmanFord::BellmanFord(int n):
    array_size_of_cost(n + 1),
    node_num(n),
    adj(vector<vector<Edge>>(array_size_of_cost)),
    negative(array_size_of_cost),
    dist(vector<long long>(array_size_of_cost))
{
    fill(dist.begin(), dist.end(), INFl);
    fill(negative.begin(), negative.end(), false);
}

void BellmanFord::add_edge(int f, int t, long long c){
    adj[f].push_back(Edge(t, c));
}

void BellmanFord::run(int first_node){
    dist[first_node] = 0;
    for(int loop = 0; loop < node_num - 1; loop++){
        for(int i = 0; i < node_num; i++){
            for(const Edge& e : adj[i]){
                if(dist[i] == INFl) continue;
                if(dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                }
            }
        }
    }

    for(int loop = 0; loop < node_num; loop++){
        for(int i = 0; i < node_num; i++){
            for(const Edge& e : adj[i]){
                if(dist[i] == INFl) continue;
                if(dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                    negative[e.to] = true;
                }
                if(negative[i] == true){
                    negative[e.to] = true;
                }
            }
        }
    }
}

bool BellmanFord::get_negative(int n){
    return negative[n];
}
