# 关于std的拓展

注：在c++中，有自己的find成员方法的容器有：

1. 关联容器（基于树或哈希表）

   ```c++
   std::set<int> s = {1, 2, 3, 4};
   auto it = s.find(3);  // ✅ O(log n)
   
   std::map<string, int> m = {{"a", 1}, {"b", 2}};
   auto it = m.find("a");  // ✅ O(log n)
   
   std::unordered_set<int> us = {1, 2, 3};
   auto it = us.find(2);  // ✅ O(1) 平均
   
   std::unordered_map<string, int> um = {{"a", 1}};
   auto it = um.find("a");  // ✅ O(1) 平均
   ```

2. 字符串

   ```c++
   std::string str = "hello world";
   size_t pos = str.find("world");  // ✅ 返回位置索引
   size_t pos2 = str.find('o');     // ✅ 查找字符
   ```

没有find（）成员方法的容器（需要使用std::find):

1. 序列容器

   ```c++
   std::vector<int> v = {1, 2, 3, 4};
   auto it = std::find(v.begin(), v.end(), 3);  // ✅ O(n)
   
   std::list<int> l = {1, 2, 3};
   auto it = std::find(l.begin(), l.end(), 2);  // ✅ O(n)
   
   std::deque<int> d = {1, 2, 3};
   auto it = std::find(d.begin(), d.end(), 2);  // ✅ O(n)
   
   std::array<int, 3> a = {1, 2, 3};
   auto it = std::find(a.begin(), a.end(), 2);  // ✅ O(n)
   ```

为什么出现这样的区别：

| 容器类型                        | 数据结构 | 查找复杂度 | 有find成员？     |
| :------------------------------ | :------- | :--------- | :--------------- |
| `vector`                        | 动态数组 | O(n)       | ❌ 用 `std::find` |
| `list`                          | 双向链表 | O(n)       | ❌ 用 `std::find` |
| `deque`                         | 双端队列 | O(n)       | ❌ 用 `std::find` |
| `set`/`map`                     | 红黑树   | O(log n)   | ✅ 有成员         |
| `unordered_set`/`unordered_map` | 哈希表   | O(1) 平均  | ✅ 有成员         |
| `string`                        | 字符串   | O(n)       | ✅ 有成员（特殊） |

设计原因：

- 关联容器利用自身数据结构特性，可以实现更高效的查找，所以提供成员方法
- 序列容器只能线性查找，用std::find通用算法足够，不需要重复实现

使用建议：

```c++
// 对于 vector/list/deque 等
std::vector<int> v = {1, 2, 3};
if (std::find(v.begin(), v.end(), 2) != v.end()) {
    // 找到了
}

// 对于 set/map 等
std::set<int> s = {1, 2, 3};
if (s.find(2) != s.end()) {
    // 找到了
}
```

- 注：std是standard的缩写，在c++中代表标准命名空间

  - 简单理解：std类似于一个大仓库存放了c++标准库提供的所有功能如（输入输出cout,cin,容器vector,string,算法find,sort...)

  - 为什么用：由于c++中有太多名字，为了避免命名冲突，就都放在std中，比如：

    ```c++
    // 假设你自己也定义了一个叫 find 的函数
    int find(int x) { return x * 2; }
    
    // 但你想用标准库的 find
    std::find(v.begin(), v.end(), 3);  // 用 std:: 明确表示：我要用标准库的 find
    ```

  - 使用方法：

    1. 每次加std::

       ```c++
       #include <iostream>
       int main() {
           std::cout << "Hello" << std::endl;  // 明确告诉编译器用的是标准库的 cout
           return 0;
       }
       ```

    2. 使用using namespace std;

       ```c++
       #include <iostream>
       using namespace std;  // 把 std 仓库全部打开
       int main() {
           cout << "Hello" << endl;  // 不用写 std:: 了
           return 0;
       }
       ```

       **缺点**：如果自己定义了和标准库同名的函数，会产生冲突。

    3. 只引入需要的

       ```c++
       #include <iostream>
       using std::cout;
       using std::endl;
       int main() {
           cout << "Hello" << endl;  // 只对 cout 和 endl 免前缀
           std::cin >> x;            // cin 还是要加 std::
           return 0;
       }
       ```

       

