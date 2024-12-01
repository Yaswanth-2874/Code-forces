#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}

map<int, pair<int, int>> possible;
// NOT TESTING THIS, HAVING A LOT OF FAITH

class Solution {
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    string find3Num(int l) {
        int res = query(l, l+1);
        auto [num1, num2] = possible[res];
        res = query(l+1, l+2);
        auto [num3, num4] = possible[res];

        int expectedNum2 = -1;
        if(num1 == num3)
            expectedNum2 = num1;
        else if(num1 == num4)
            expectedNum2 = num1;
        else
            expectedNum2 = num2;
        
        int expectedNum1 = (num1 * num2)/expectedNum2;
        int expectedNum3 = (num3 * num4)/expectedNum2;

        return to_string(expectedNum1) + " " + to_string(expectedNum2) + " " + to_string(expectedNum3);
    }
    public:
    void solve() {
        string ans = find3Num(1);
        ans = ans + " " + find3Num(4);
        printAns(ans);
    }
};

int32_t main() {
    vector<int> v = {4, 8, 15, 16, 23, 42};
    for(int i = 0; i < 6; i++) {
        for(int j = i+1; j < 6; j++) {
            int product = v[i] * v[j];
            possible[product] = {v[i], v[j]};
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

