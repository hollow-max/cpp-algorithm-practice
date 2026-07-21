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