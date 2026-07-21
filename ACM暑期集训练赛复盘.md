# ACM暑期训练赛复盘

## 2026“钉耙编程”中国大学生算法设计暑期联赛（1）

### 1001 小丑牌

#### 题目

![image-20260721215741176](C:\Users\zrn09\AppData\Roaming\Typora\typora-user-images\image-20260721215741176.png)

![image-20260721215800762](C:\Users\zrn09\AppData\Roaming\Typora\typora-user-images\image-20260721215800762.png)

![image-20260721215823578](C:\Users\zrn09\AppData\Roaming\Typora\typora-user-images\image-20260721215823578.png)

#### 我的代码（`TLE`）

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int n,m;
        long long x,y;
        cin >> n >> m >> x >> y;
        long long ai,bi;
        if (x>0){
            long long maxa=0;
            for (int i=0;i<n;i++){
                long long a;
                cin >> a;
                if (a>maxa){
                    maxa=a;
                }
            }
            ai = maxa;
        }else{
            long long mina=0;
            for (int i=0;i<n;i++){
                long long a;
                cin >> a;
                if (a<mina){
                    mina=a;
                }
            }
            ai = mina;
        }

        if (y>0){
            long long maxb=0;
            for (int i=0;i<n;i++){
                long long b;
                cin >> b;
                if (b>maxb){
                    maxb=b;
                }
            }
            bi = maxb;
        }else{
            long long minb=0;
            for (int i=0;i<n;i++){
                long long b;
                cin >> b;
                if (b<minb){
                    minb=b;
                }
            }
            bi = minb;
        }
        cout << (x+ai)*(y+bi) << endl;
    }
    return 0;
}
```

```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long x,y;
        int n,m;
        cin >> n >> m >> x >> y;
        long long maxa=10000,mina=-10000;
        long long maxb=10000,minb=-10000;
        long long a1=0,b1=0;
        if(n==0) maxa=0,mina=0;
        if(m==0) maxb=0,minb=0;
        while(n--){
            long long a;
            cin >> a;
            maxa=max(maxa,a);
            mina=min(mina,a);
        }
        while(m--){
            long long b;
            cin >> b;
            maxb=max(maxb,b);
            minb=min(minb,b);
        }
        // if(x>0&&y>0) x1=x+maxa,y1=y+maxb;
        // if(x>0&&y<0) x1=x+maxa,y1=y+minb;
        // if(x<0&&y>0) x1=x+mina,y1=y+maxb;
        // if(x<0&&y<0) x1=x+mina,y1=y+minb;
        long long ax=(x>0) ? maxa : mina;
        long long by=(y>0) ? maxb : minb;
        cout << (ax+x)*(y+by) << "\n";
    }
    return 0;
}
```



#### 题解

![image-20260721221840374](C:\Users\zrn09\AppData\Roaming\Typora\typora-user-images\image-20260721221840374.png)

```c++
#include<bits/stdc++.h>
#define int long long
#define mx(a,n) *max_element(a+1,a+n+1)
#define mn(a,n) *min_element(a+1,a+n+1)
using namespace std;
const int N=100010,M=1000010,INF=0x3f3f3f3f;
int T,x,y,n,m,ans,a[N],b[N];
void solve(){
    cin>>x>>y>>n>>m,ans=x*y;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    a[++n]=b[++m]=0;
    for(int u:{mx(a,n),mn(a,n)})
        for(int v:{mx(b,m),mn(b,m)})
            ans=max(ans,(x+u)*(y+v));
    cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
    while(T--)solve();
	return 0;
}

```

#### 队友AC的代码

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        int n, m;
        cin >> x >> y >> n >> m;
        ll max_a, min_a;
        if (n > 0) {
            ll a;
            cin >> a;
            max_a = min_a = a;
            for (int i = 1; i < n; ++i) {
                cin >> a;
                max_a = max(max_a, a);
                min_a = min(min_a, a);
            }
        }
        ll max_b, min_b;
        if (m > 0) {
            ll b;
            cin >> b;
            max_b = min_b = b;
            for (int i = 1; i < m; ++i) {
                cin >> b;
                max_b = max(max_b, b);
                min_b = min(min_b, b);
            }
        }
        ll ans = x * y; 
        if (n > 0) {
            ll v1 = (x + max_a) * y;
            ll v2 = (x + min_a) * y;
            ans = max(ans, max(v1, v2));
        }
        if (m > 0) {
            ll v1 = x * (y + max_b);
            ll v2 = x * (y + min_b);
            ans = max(ans, max(v1, v2));
        }
        if (n > 0 && m > 0) {
            ll v1 = (x + max_a) * (y + max_b);
            ll v2 = (x + max_a) * (y + min_b);
            ll v3 = (x + min_a) * (y + max_b);
            ll v4 = (x + min_a) * (y + min_b);
            ll tmp = max(max(v1, v2), max(v3, v4));
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}
```

#### 我的 VS AC的【`dpsk` 版解释】

##### 对比

1. **输入顺序的修正**

```c++
// 你的版本
cin >> n >> m >> x >> y;  // ❌ 顺序错误

// 正确版本
cin >> x >> y >> n >> m;  // ✅ 与题目要求一致
```



**这是最关键的区别！** 如果输入顺序错误，程序会读取到错误的数据，可能导致：

- 读取到非预期的数据
- 输入流错位，可能读不到足够的数据
- 程序一直等待输入，导致超时

2. **更稳健的初始化方式**

```c++
// 你的版本：使用 LLONG_MIN/LLONG_MAX 初始化
long long maxa = LLONG_MIN, mina = LLONG_MAX;

// 正确版本：用第一个元素初始化
if (n > 0) {
    ll a;
    cin >> a;
    max_a = min_a = a;  // ✅ 直接用第一个值初始化
    for (int i = 1; i < n; ++i) {
        // 继续读取剩余数据
    }
}
```



这样避免了使用极端值，代码更安全、更清晰。

3. **逻辑的完整性**

```c++
// 正确版本考虑了所有情况：
ll ans = x * y;  // 基础情况：不选任何点

if (n > 0) {
    // 只从第一组选一个点
    ans = max(ans, (x + max_a) * y);
    ans = max(ans, (x + min_a) * y);
}
if (m > 0) {
    // 只从第二组选一个点
    ans = max(ans, x * (y + max_b));
    ans = max(ans, x * (y + min_b));
}
if (n > 0 && m > 0) {
    // 从两组各选一个点
    // 考虑所有极值组合
}
```

4. **避免重复代码和计算**

```c++
// 你的版本：多个 if 分支，代码重复
if(x>0&&y>0) x1=x+maxa,y1=y+maxb;
if(x>0&&y<0) x1=x+maxa,y1=y+minb;
// ...

// 正确版本：统一处理所有情况
// 直接计算所有可能的组合取最大值
```

5. **更清晰的命名和代码结构**

- 使用 `ll` 别名，代码更简洁
- 变量命名更规范（`max_a`, `min_a`）
- 逻辑分层清晰

##### 为什么你的代码会超时？

综合来看，**最可能的原因是输入顺序错误**：

```c++
// 如果题目要求是：x y n m
cin >> n >> m >> x >> y;  // ❌ 读成了 n m x y

// 实际输入：5 3 2 1
// 你的代码：n=5, m=3, x=2, y=1  → 读错了
// 正确应该：x=5, y=3, n=2, m=1
```



这会导致：

1. 读取的数据完全错位
2. 可能读到非数字字符或格式不匹配
3. 程序可能在 `while(T--)` 中无法正常退出
4. 最终被判定为超时

##### 进一步的改进建议

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        int n, m;
        cin >> x >> y >> n >> m;  // ✅ 正确顺序
        
        ll max_a, min_a;
        if (n > 0) {
            ll a;
            cin >> a;
            max_a = min_a = a;
            for (int i = 1; i < n; ++i) {
                cin >> a;
                max_a = max(max_a, a);
                min_a = min(min_a, a);
            }
        }
        
        ll max_b, min_b;
        if (m > 0) {
            ll b;
            cin >> b;
            max_b = min_b = b;
            for (int i = 1; i < m; ++i) {
                cin >> b;
                max_b = max(max_b, b);
                min_b = min(min_b, b);
            }
        }
        
        // 优化：使用一个 vector 存储所有可能的情况
        vector<pair<ll, ll>> candidates = {{x, y}};
        if (n > 0) {
            candidates.push_back({x + max_a, y});
            candidates.push_back({x + min_a, y});
        }
        if (m > 0) {
            candidates.push_back({x, y + max_b});
            candidates.push_back({x, y + min_b});
        }
        if (n > 0 && m > 0) {
            candidates.push_back({x + max_a, y + max_b});
            candidates.push_back({x + max_a, y + min_b});
            candidates.push_back({x + min_a, y + max_b});
            candidates.push_back({x + min_a, y + min_b});
        }
        
        ll ans = LLONG_MIN;
        for (auto &p : candidates) {
            ans = max(ans, p.first * p.second);
        }
        cout << ans << '\n';
    }
    return 0;
}
```

##### 总结

代码超时的根本原因是：

1. **输入顺序错误**（最致命）
2. 使用 `while(n--)` 会修改 `n` 的值，导致后续判断错误
3. 代码逻辑不如正确版本清晰完整

正确版本的代码虽然时间复杂度相同（都是 O(n+m)），但因为输入正确，所以能正常完成执行。