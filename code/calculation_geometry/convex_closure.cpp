#include "base.cpp"


bool cmp(const point &a, const point &b) {
    int c = cross_product(a - base_p, b - base_p);
    // 当坐标为浮点数时注意判定为零时的误差fabs()<eps
    if (c > 0) return true;
    if (c == 0 && dist(base_p, a) < dist(base_p, b)) 
        return true;
    return false;
}
point base_p;  //==s[base]

///利用Graham算法构造凸包
/// complexity: O(n*logn)
/// 依赖函数:
///  bool cmp(const point &a, const point &b);
///  vec2d operator -(const point &a, const point &b) ;
///  int cross_product(const vec2d &a, const vec2d &b);
/// 辅助变量:
///  point base_p;
point_vec build_convex_closure_graham(/*const */ point_vec &s) {
    if (s.size() == 1 || s.size() == 2)
        return point_vec(s);

    int base = 0;
    for (int i = 1; i < s.size(); i++) {
        if (y(s[i]) < y(s[base]) ||
            (y(s[base]) == y(s[i]) &&
             x(s[base]) > x(s[i])))  //最下点中的的最左点
            base = i;
    }

    swap(s[base], s[0]);  //修改了s, 视实际情况
    sort(++s.begin(), s.end(), cmp); //从第二位开始排序

    point_vec ret;
    for (int i = 2; i < s.size(); i++) {
        while (
            ret.size() && 
            cross_product (
                ret[ret.size()-1] - ret[ret.size()-2], 
                ret[i] - ret[ret.size()-2]
            ) <= 0
        ) ret.pop_back();
        ret.push_back(s[i]);
    }
    return ret;
}