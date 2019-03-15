#include "base.cpp"
/*
Target: 求单源/多源最短路径
Declaration:
class Union_Find{
public:
    void _union(int a,int b);
    void is_union(int a,int b);
}
*/

/*
Dependencies:
    *
DataStructure: Union_Find
Operations:
    union: O(1)
    find: O(1)
Remarks:
Author: Ctrl+C
*/
class Union_Find {
    std::vector<int> pat;
    int find(int x) {  //查找根节点
        int root = x;
        while (pat[root] != root)  //返回根节点 root
            root = pat[root];
        int i = x, j;
        while (i != root) {  //路径压缩
            j = pat[i];  // 在改变上级之前用临时变量  j 记录下他的值
            pat[i] = root;  //把上级改为根节点
            i = j;
        }
        return root;
    }

   public:
    Union_Find(int size) {
        pat.resize(size);
        for (int i = 1; i <= size; i++) pat[i] = i;
    }
    void _union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) pat[a] = b;
    }
    bool is_union(int a, int b) { return find(a) == find(b); }
};