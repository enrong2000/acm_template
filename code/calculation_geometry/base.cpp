#include <unordered_set>
#include <utility>  //std::pair
#include <vector>
#include <math.h>

typedef std::pair<int, int> point;
typedef std::pair<int, int> vec2d;
#define x(p) p.first
#define y(p) p.second
// typedef std::unordered_set<point> point_set;
typedef std::vector<point> point_vec;

inline vec2d operator-(const point &a, const point &b) {
    return vec2d(x(a) - x(b), y(a) - y(b));
}
float dist(const point &a, const point &b){
    return sqrt(
        (x(a)-x(b))*(x(a)-x(b))+
        (y(a)-y(b))*(y(a)-y(b))
    );
}
int cross_product(const vec2d &a, const vec2d &b) { 
    return x(a) * y(b) - x(b) * y(a);
}
