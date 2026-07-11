# C++ 算法竞赛速成笔记

## 1. 比赛里最常用的 C++ 骨架

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    return 0;
}
```

关键点：
- `#include <bits/stdc++.h>`：竞赛常用万能头文件。
- `ios::sync_with_stdio(false); cin.tie(nullptr);`：加速输入输出。
- `long long`：整数可能超过 `int` 时使用，范围约 9e18。

## 2. 必须熟悉的语法

### 变量与类型

```cpp
int a = 10;              // 约 2e9
long long b = 10000000000LL;
double x = 3.14;
char c = 'A';
bool ok = true;
string s = "hello";
```

常见坑：
- 两个 `int` 相乘仍然是 `int`，可能溢出：`1LL * a * b`
- 除法：`5 / 2 == 2`，`5.0 / 2 == 2.5`

### 判断与循环

```cpp
if (x > 0) {
    cout << "positive\n";
} else {
    cout << "non-positive\n";
}

for (int i = 0; i < n; i++) {
    cout << i << '\n';
}

while (n > 0) {
    n--;
}
```

### 函数

```cpp
int add(int a, int b) {
    return a + b;
}

bool isEven(int x) {
    return x % 2 == 0;
}
```

## 3. 数组、vector、string

### 原生数组

```cpp
int a[100];
for (int i = 0; i < n; i++) cin >> a[i];
```

### vector：比赛最常用

```cpp
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

a.push_back(10);
cout << a.size() << '\n';
```

遍历：

```cpp
for (int x : a) {
    cout << x << ' ';
}
```

排序：

```cpp
sort(a.begin(), a.end());                  // 升序
sort(a.rbegin(), a.rend());                // 降序
sort(a.begin(), a.end(), greater<int>());  // 降序
```

### string

```cpp
string s;
cin >> s;

cout << s.size() << '\n';
cout << s[0] << '\n';

reverse(s.begin(), s.end());
```

## 4. 常用 STL 容器

### pair

```cpp
pair<int, int> p = {3, 5};
cout << p.first << ' ' << p.second << '\n';
```

### map / unordered_map

```cpp
map<string, int> mp;
mp["apple"]++;

unordered_map<int, int> cnt;
cnt[7]++;
```

区别：
- `map`：有序，单次操作 `O(log n)`
- `unordered_map`：无序，平均 `O(1)`，多数计数题更快

### set / unordered_set

```cpp
set<int> st;
st.insert(5);
st.erase(5);
if (st.count(5)) cout << "exists\n";
```

### queue / stack

```cpp
queue<int> q;
q.push(1);
q.front();
q.pop();

stack<int> stk;
stk.push(1);
stk.top();
stk.pop();
```

### priority_queue

```cpp
priority_queue<int> big; // 大根堆
big.push(3);
big.push(10);
cout << big.top() << '\n';

priority_queue<int, vector<int>, greater<int>> small; // 小根堆
```

## 5. 竞赛高频算法模板

### 前缀和

适合快速求区间和。

```cpp
vector<long long> pre(n + 1, 0);
for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + a[i];
}

// 查询 [l, r]
long long ans = pre[r] - pre[l - 1];
```

### 双指针

适合有序数组、连续区间、滑动窗口。

```cpp
int l = 0;
for (int r = 0; r < n; r++) {
    while (/* 区间不合法 */) {
        l++;
    }
    // 此时 [l, r] 合法
}
```

### 二分查找

找第一个满足条件的位置。

```cpp
int l = 0, r = n - 1, ans = -1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}
```

### BFS

适合最短步数、网格搜索。

```cpp
queue<int> q;
vector<int> dist(n, -1);

q.push(start);
dist[start] = 0;

while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : graph[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

### DFS

适合连通块、递归搜索、树。

```cpp
void dfs(int u, int parent) {
    for (int v : graph[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
}
```

### 动态规划入门

核心：定义状态，写转移。

```cpp
// dp[i] 表示到第 i 个位置的最优答案
vector<int> dp(n + 1, 0);
for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
}
```

## 6. 算法比赛解题流程

1. 看数据范围，先判断复杂度。
2. 小数据可以暴力，大数据通常需要优化。
3. 写出变量含义，再写代码。
4. 手动跑样例。
5. 检查边界：`n=1`、空区间、重复值、最大值、负数。

复杂度速记：
- `n <= 20`：可能用搜索、状态压缩。
- `n <= 1e3`：`O(n^2)` 常可。
- `n <= 1e5`：通常要 `O(n log n)` 或 `O(n)`。
- `n <= 1e6`：尽量 `O(n)`。

## 7. 建议学习顺序

第一阶段：语法基础
- 输入输出、变量、判断、循环、函数
- 数组、vector、string
- sort、reverse、max、min

第二阶段：基础题型
- 枚举
- 模拟
- 排序
- 前缀和
- 双指针
- 二分

第三阶段：图和搜索
- DFS
- BFS
- 树
- 最短路入门

第四阶段：动态规划
- 一维 DP
- 背包问题
- 区间 DP

第五阶段：进阶
- 并查集
- 堆
- 贪心
- 单调栈/单调队列
- 树状数组/线段树

## 8. 每天 60 分钟练习法

- 10 分钟：复习一个语法点。
- 20 分钟：看一个模板并手敲。
- 25 分钟：做一道同类型简单题。
- 5 分钟：记录错因。

最重要的是手敲，不要只看。

