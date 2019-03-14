#include <vector>
#include <queue>

typedef std::vector<std::vector<int> > graph;
struct weighted_edge {
    int dest, weight;
};
typedef std::vector<std::vector<weighted_edge> > weighted_graph;
#define V(g) g.size()
// const int E(graph &g) {
//     int i = 0;
//     for (auto j : g) i += (j != -1);
//     return i;
// }