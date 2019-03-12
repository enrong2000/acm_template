#include <vector>

typedef std::vector<int> graph;
struct weighted_edge {
    int dest, weight;
};
typedef std::vector<weighted_edge> weighted_graph;