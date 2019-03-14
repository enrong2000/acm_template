#include "base.cpp"
/*
Target: 求单源/多源最短路径
Declaration:
1. 单源最短路
    vector<int> shortest_path(int source, graph &g);
    vector<int> shortest_path(int source, weighted_graph &g);
2. 多源最短路
    vector<int, vector<int> > shortest_path(graph &g);
    vector<int, vector<int> > shortest_path(weighted_graph &g);
*/

#define declare_reserve_vector(type, x, size) \
    std::vector<type> x;\
    x.reserve(size)

#define start_SPFA                                                                       \
    /*dist 为最终结果；cnt为入队次数，用于判定是否存在负权回路*/ \
    declare_reserve_vector(int, dist, g.size());                                         \
    declare_reserve_vector(int, cnt, g.size());                                          \
    declare_reserve_vector(bool, visited, g.size());                                     \
    std::queue<int> joblist;                                                             \
    memset(dist.data(), 127, sizeof(int) * g.size());                                    \
    /*01111111011111110111111101111111[2] == 2139062143[10]*/                            \
    cnt[source] = 1;                                                                     \
    joblist.push(source);                                                                \
    dist[source] = 0;                                                                    \
    while (joblist.empty() == false) {                                                   \
        static int current;                                                              \
        current = joblist.front();                                                       \
        joblist.pop();                                                                   \
        visited[current] = false;                                                        \
        for (int i = 0; i < g[current].size(); i++) {

#define end_SPFA }}

/*
Dependencies:
    #define start_SPFA
    #define end_SPFA
Algorithm: SPFA(无权图)
Time Complexity: O(VE)
Remarks: 稠密图会被卡, 空间3倍常数
Author: Frank
*/
std::vector<int> shortest_path_SPFA(int source, graph &g){
    start_SPFA// 上面的define
    if (dist[g[current][i]] > dist[current] + 1){
        dist[g[current][i]] = dist[current] + 1;
        if(!visited[g[current][i]]){
            joblist.push(g[current][i]);
            visited[g[current][i]] = true;
        }
    }
    end_SPFA
}

/*
Dependencies:
    #define start_SPFA
    #define end_SPFA
Algorithm: SPFA(有权图)
Time Complexity: O(VE)
Remarks: 稠密图会被卡, 可以判断负权图
Author: Frank
*/
std::vector<int> shortest_path_SPFA(int source, weighted_graph &g) {
    start_SPFA
    if (dist[g[current][i].dest] > dist[current] + g[current][i].weight){
        dist[g[current][i].dest] = dist[current] + g[current][i].weight;
        if(!visited[g[current][i].dest]){
            joblist.push(g[current][i].dest);
            visited[g[current][i].dest] = true;
            if(++cnt[g[current][i].dest] > g.size())
                throw new std::exception();  //出现了负权回路
        }
    }
    end_SPFA
}

/*
Dependencies:
    #define declare_reserve_vector
Algorithm: Dijkstra(堆优化)
Time Complexity: O(E*logE)
Remarks: 
Author: Frank
*/
std::vector<int> shortest_path_dijkstra_heap_optimized(int source, weighted_graph &g) {
    struct node{
        int cost, pos;
        bool operator<(const node &b) const { return cost < b.cost; }
    };
    declare_reserve_vector(int, dist, g.size());
    declare_reserve_vector(bool, visited, g.size());
    std::priority_queue<node> heap;
    memset(dist.data(), 127, sizeof(int) * dist.size());
    dist[source] = 0;
    heap.push((node){source, 0});
    while (!heap.empty()) {
        static node current;
        current = heap.top();
        heap.pop();
        if(visited[current.pos])continue;
        visited[current.pos] = true;
        for (int i = 0; i < g[current.pos].size(); i++) {
            static weighted_edge next;
            next = g[current.pos][i];
            if (!visited[next.dest] &&
                dist[next.dest] > dist[current.pos] + next.weight) {
                dist[next.dest] = dist[current.pos] + next.weight;
                heap.push((node){next.dest, dist[next.dest]});
            }
        }
    }
}