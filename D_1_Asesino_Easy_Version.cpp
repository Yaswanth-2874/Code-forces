#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}


// 1 2 3 4 5 6 7
// 1 2 1 3 2 2 1
// First ask about person b to a
// Then ask about person a to b
// if both are knights then a to b and b to a is same
// if one is knight other is knave then answer is still same
// if both are knave then both answers are still same
// If both answers are different, definitely means that one is a impostor


class Solution {
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        int a = 1;
        int b = a + 1;
        for(a = 1; a <= n - 1; a += 2) {
            b = a + 1;
            int q1 = query(a, b);
            int q2 = query(b, a);
            if(q1 != q2)
                break;
        }
        // One out of a and b is a impostor
        // Select one safe member and do the testing
        // basically i know that one of a, b is a impostor
        int i = 1;
        for(i = 1; i <= n; i++)
            if(i != a && i != b)
                break;
        int q1 = query(i, a);
        int q2 = query(a, i);
        if(q1 != q2)
            printAns(a);
        printAns(b);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

