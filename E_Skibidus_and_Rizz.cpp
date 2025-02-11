#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int zeroes, ones, k;
        cin >> zeroes >> ones >> k;

        if((ones < k && zeroes < k) || abs(ones - zeroes) > k) {
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        }
    
        if(ones >= zeroes) {
            for(int i = 0; i < k; i++)
                cout<<1;
            ones -= k;
            while(ones && zeroes) {
                cout<<"01";
                ones--;
                zeroes--;
            }
            while(ones--){
                cout<<1;
            }
            while(zeroes--){
                cout<<0;
            }
        } else {
            for(int i = 0; i < k; i++)
                cout<<0;
            zeroes -= k;
            while(ones && zeroes) {
                cout<<"10";
                ones--;
                zeroes--;
            }
            while(ones--){
                cout<<1;
            }
            while(zeroes--){
                cout<<0;
            }
        }
        cout<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
