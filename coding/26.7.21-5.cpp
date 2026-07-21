#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        long long k;
        cin >> k;

        string S;
        long long rem=k;
        while(rem>0){
            long long rem2 = rem*2;
            long long m_ = sqrt(rem2);
            for (long long m=m_+1;m>0;m--){
                if (m*(m-1)<=rem2){
                    S.append(m,'a');
                    S.push_back('b');
                    rem-=m*(m-1)/2;
                    break;
                }
            }
        }
        if (!S.empty()&&S.back()=='b'){
            S.pop_back();
        }
        cout << S.length() << " " << 2 << "\n";
        cout << S << "\n";
    }
    return 0;
}