#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // 外层循环：需要 n-1 轮
    for (int i = 0; i < n - 1; i++) {
        // 内层循环：每轮比较相邻元素
        // 每轮结束后，最后 i 个元素已经排好，所以不用再比较
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换相邻元素
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, n);
    
    cout << "排序结果: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}