#include "base.cpp"
/*
Target: 单模式串字符串匹配
Declaration:
std::vector<int> get_matches(std::string src, std::string pattern);
*/

std::vector<int> build_next(const std::string &pattern) {
    std::vector<int> next;
    next.resize(pattern.size());

    int len = next[0] = 0;
    // 这样写的话复杂度关系比较明显
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == pattern[len]) {
            next[i] = ++len;
            continue;
        }
        if (len /*!=0*/) {
            len = next[len - 1];
            i--;
        } else {
            next[i] = 0;
        }
    }
    return next;
}
/*
Dependencies:
    std::vector<int> build_next(std::string pattern);
Algorithm: KMP
Time Complexity: O(n+k)
Remarks: 在调用build_next函数获得next数组后传入到第三个参数
Author: Frank
*/
std::vector<int> get_matches_kmp(const std::string &src,
                                 const std::string &pattern,
                                 const std::vector<int> &next) {
    //auto next = build_next(pattern);
    std::vector<int> match_pos;
    int index_src = 0, index_pat = 0;
    while (index_src < src.size()) {
        if (src[index_src] == pattern[index_pat]) {
            ++index_pat, ++index_src;
        }
        if (index_pat == pattern.size()) {
            match_pos.push_back(index_src - index_pat);
            /// match found
            index_pat = next[index_pat - 1];
        } else if (index_src < src.size() &&
                   src[index_src] != pattern[index_pat]) {
            if (index_pat /*!=0*/)
                index_pat = next[index_pat - 1];
            else
                index_src++;
        }
    }
    return match_pos;
}