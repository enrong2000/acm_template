# 代码部分

## 目录结构

`code/<范畴>/<解决的问题>.cpp`  

在`code/<范畴>/base.cpp`中添加此范畴下最为常用的函数  

### 列表

* 计算几何(calculation_geometry)
* 图论(graph_theory)
* 数论(number_theory)

## 规范

### 算法与数据结构

所有算法/数据结构的实现前应当添加如下注释(以SPFA为例):

```cpp
/*
Dependencies:
    *
Algorithm: 归并排序
Time Complexity: O(nlogn)
Space Complexity: O(n)
Remarks: None
Author: Frank
*/
```

请在remarks中注明使用时的注意事项，包括实现中可能出现的非预期现象  
在Dependencies中注明实现过程中调用的函数的声明  
此注释不仅是为了提高可读性，更是为了之后方便利用程序进行整合  
***注意Author项为必填***

### 文件

所有`code/<范畴>/<解决的问题>.cpp`文件在文件头部必须含有以下内容:

```cpp
#include "base.cpp"
/*
Target: <这个文件内的函数所解决的问题>
Declaration:
    这些函数应接受哪些参数，返回哪些值
*/
```