#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        int left = 1, right = n-2;

        while(left < right) {
            int num1 = v[left], prev = v[left - 1], num2 = v[right], next = v[right+1];

            int disturbance1 = (num1 == prev) + (num2 == next);
            int disturbance2 = (num2 == prev) + (num1 == next);

            if(disturbance2 < disturbance1) {
                swap(v[left], v[right]);
            }
            left++;
            right--;
        }
       

        int disturbance = 0;

        for(int i = 1; i < n; i++) {
            if(v[i] == v[i-1])
                disturbance++;
        }
        /* Print number*/ {
            cout<<disturbance<<endl;
            return;
        }


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
