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

#### 算法

算法应当包装在特定格式声明的函数内
所有算法的实现前应当添加如下注释(以SPFA为例):

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

#### 数据结构

数据结构应在保证可读性的情况下包装在类/结构体内

* C++中class关键字与struct关键字等价, 但请尽量使用class关键字来标记含各种操作的数据结构, 而用struct关键字标记特定的一组数据

所有数据结构的实现前(class 前)应添加如下注释:

```cpp
/*
Dependencies:
    *
DataStructure: Linked List
Operations:
    Insert: O(1)
    Find: O(n)
    Delete: O(1)
Space Complexity: O(n)
Remarks: None
Author: Frank
*/
```

其中Operations应当与public成员函数名保持同步

***注意两组注释中Author项为必填***

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