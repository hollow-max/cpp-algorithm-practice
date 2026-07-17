# unordered_map和unordered_set

## 关系概述

`unordered_set` 和 `unordered_map` 是 C++ 标准库中的两个**关联容器**，它们都基于**哈希表**实现，但用途不同：

- **`unordered_set`**：存储**唯一的键**（只有键，没有值）
- **`unordered_map`**：存储**键-值对**（既有键，又有对应的值）

可以这样理解：

- `unordered_set` 就像一个**集合**（只关心元素是否存在）
- `unordered_map` 就像一个**字典**（根据键查找对应的值）

## 形象比喻

### `unordered_set` - 签到表

```
unordered_set<string> 参加聚会的人;

参加聚会的人 = {"张三", "李四", "王五"};

// 检查：张三来了吗？→ 来了
// 检查：赵六来了吗？→ 没来
```



### `unordered_map` - 电话簿

```
unordered_map<string, string> 电话簿;

电话簿 = {
    {"张三", "13800138000"},
    {"李四", "13900139000"},
    {"王五", "13700137000"}
};

// 查询：张三的电话是多少？→ "13800138000"
// 查询：赵六的电话是多少？→ 找不到
```



## 语法对比

### `unordered_set` 的用法

```c++
#include <unordered_set>
using namespace std;

unordered_set<int> s;

// 插入元素（只插入键）
s.insert(5);        // 插入 5
s.insert(10);       // 插入 10
s.insert(5);        // 5 已存在，不会重复插入

// 查询元素是否存在
if (s.find(5) != s.end()) {
    cout << "5 存在" << endl;
}
// 或者
if (s.count(5) > 0) {
    cout << "5 存在" << endl;
}

// 获取大小
cout << s.size();   // 输出 2（只有 5 和 10）

// 遍历
for (int x : s) {
    cout << x << " ";
}
```



### `unordered_map` 的用法

```c++
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

// 插入键值对
m["apple"] = 5;     // 苹果有5个
m["banana"] = 3;    // 香蕉有3个
m["apple"] = 8;     // 更新苹果的数量为8

// 或者使用 insert
m.insert({"orange", 2});

// 访问值
cout << m["apple"];   // 输出 8
cout << m["grape"];   // 如果键不存在，会自动插入并初始化为0

// 安全访问（检查是否存在）
if (m.find("banana") != m.end()) {
    cout << m["banana"];  // 输出 3
}

// 遍历（每个元素是一个键值对）
for (auto& p : m) {
    cout << p.first << ": " << p.second << endl;
}
// 输出：
// apple: 8
// banana: 3
// orange: 2
```



## 在本题中的应用对比

### 使用 `unordered_set` 统计颜色种类

```c++
unordered_set<int> colors;  // 只记录颜色是否出现过

for (int i = top; i <= bottom; i++) {
    for (int j = left; j <= right; j++) {
        colors.insert(a[i][j]);  // 插入颜色值
    }
}
// colors.size() = 不同颜色的数量
```



### 使用 `unordered_map` 统计颜色出现次数

```c++
unordered_map<int, int> colorCount;  // 记录每种颜色出现的次数

for (int i = top; i <= bottom; i++) {
    for (int j = left; j <= right; j++) {
        int color = a[i][j];
        colorCount[color]++;  // 这种颜色出现次数+1
    }
}
// colorCount.size() = 不同颜色的数量
// colorCount[5] = 颜色5出现的次数
```



## 共同点

两者都是：

1. **基于哈希表**实现
2. **无序存储**（元素顺序不固定）
3. **插入、删除、查找**的平均时间复杂度都是 **O(1)**
4. 不允许有**重复的键**

## 主要区别

| 特性     | `unordered_set`      | `unordered_map`                           |
| :------- | :------------------- | :---------------------------------------- |
| 存储内容 | 只有键               | 键 + 值                                   |
| 声明方式 | `unordered_set<Key>` | `unordered_map<Key, Value>`               |
| 插入     | `insert(key)`        | `insert({key, value})` 或 `[key] = value` |
| 访问元素 | 只能查找是否存在     | 可以获取对应的值                          |
| 适用场景 | 需要判断元素是否存在 | 需要根据键查找对应的值                    |

## 实际例子对比

### 场景1：统计字符串中不同字符的数量

```c++
// 使用 unordered_set
string str = "hello";
unordered_set<char> chars;
for (char c : str) {
    chars.insert(c);
}
cout << chars.size();  // 输出 4 (h, e, l, o)
```



### 场景2：统计字符串中每个字符出现的次数

```c++
// 使用 unordered_map
string str = "hello";
unordered_map<char, int> count;
for (char c : str) {
    count[c]++;  // 统计每个字符出现次数
}
// count['h'] = 1, count['e'] = 1, count['l'] = 2, count['o'] = 1
```



## 记忆技巧

- **`set`** = 集合（只有元素本身）
- **`map`** = 映射（从键映射到值）

前缀 `unordered_` 表示"无序的"，相对的还有 `set` 和 `map`（它们是有序的，基于红黑树实现）。

## 总结

在本题中：

- 只需要统计**颜色种类数** → 用 `unordered_set` 就够了
- 如果需要统计**每种颜色出现多少次** → 用 `unordered_map`

两种容器都很常用，根据具体需求选择合适的即可。