#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int a=0,b=0;
    cin >> a;
    while(a>0){
        a-=1;
        b+=2;
    }
    cout << a << '\n' << b << endl;
}