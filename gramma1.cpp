#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> courses(n);  // 存储所有课程代码
    vector<int> scores(n, -1);  // 存储每个课程的成绩，-1表示未录入
    
    // 读入课程代码
    for (int i = 0; i < n; i++) {
        cin >> courses[i];
    }
    
    // 处理成绩录入
    for (int i = 0; i < m; i++) {
        int c, s;
        cin >> c >> s;
        
        // 找到该课程在数组中的位置
        for (int j = 0; j < n; j++) {
            if (courses[j] == c) {
                scores[j] = s;  // 更新成绩（覆盖之前的）
                break;
            }
        }
    }
    
    // 统计结果
    int noScore = 0;      // 没有成绩的课程数
    int below60 = 0;      // 低于60分的课程数
    
    for (int i = 0; i < n; i++) {
        if (scores[i] == -1) {
            noScore++;
        } else if (scores[i] < 60) {
            below60++;
        }
    }
    
    cout << noScore << " " << below60 << endl;
    
    return 0;
}