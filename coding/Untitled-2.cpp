#include<vector>
#include<string>
#include<iostream>
using namespace std;
#include<chrono>


int process1(){
    int N = 100000;
    volatile int a = 0;//volatile告诉编辑器不要优化这个变量
    for (int i = 0 ; i < N ; i++){
        a += 1;
    }
    return a;
}

int process2(){
    int N = 100000;
    volatile int a = 0;
    for (int i = 0 ; i < N ;i++){
        a |= 2;
        a = a^120;
    }
    return a;
}

int main(){
    //预热（让CPU缓存和分支预测稳定）
    process1();
    process2();
    //正式测试
    const int runs = 10;
    long long total1 = 0,total2 = 0;
    
    for (int run = 0;run < runs;run++){
        auto start1 = chrono::high_resolution_clock::now();
        process1();
        auto end1 = chrono::high_resolution_clock::now();
        total1 == chrono::duration_cast<chrono::nanoseconds>(end1-start1).count();
        

        auto start2 = chrono::high_resolution_clock::now();
        process2();
        auto end2 = chrono::high_resolution_clock::now();
        total2 += chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();

    
    }

    cout << "====time====" << endl;
    cout << "process1:" << total1/runs << "ns" << endl;
    cout << "process2:" << total2/runs << "ns" << endl;
    cout << "\n=== average time cost ===" << endl;
    cout << "process1:" << (double)total1/runs << "ns" << endl;
    cout << "process2:" << (double)total2/runs << "ns" << endl;
    return 0;
}
