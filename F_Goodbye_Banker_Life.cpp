#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    bool findIsOdd(int n, int r) {
        int numerator2s = 0;
        int third = n - r;
        while(n) {
            numerator2s += n / 2;
            n /= 2;
        }

        int denominator2s = 0;
        while(r) {
            denominator2s += r/2;
            r /= 2;
        }

        while(third) {
            denominator2s += third / 2;
            third /= 2;
        }

        return (numerator2s - denominator2s) == 0;
    }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            int isOdd = findIsOdd(n-1, i);
            if(isOdd)
                cout<<k<<" ";
            else
                cout<<0<<" ";
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
