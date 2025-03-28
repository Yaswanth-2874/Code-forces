#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}

// assuming this should fail but still wanna test

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

        unordered_set<int> missing;

        for(int i = 1; i <= n; i++) {
            missing.insert(i);
        }
        int first = -1;
        int onePos = -1; int nPos = -1;

        for(int i = 0; i < n; i++) {
            int input;
            cin >> input;
            if(first == -1)
                first = input;
            if(input == 1)
                onePos = i+1;
            if(input == n)
                nPos = i+1;
            
            missing.erase(input);
        }

        if(missing.size()) {
            int best = *missing.begin();
            int q1 = query(best, first);
            if(q1 == 0)
                printAns("A");
            printAns("B");
        }

        int q1 = query(onePos, nPos);
        int q2 = query(nPos, onePos);

        if(q1 == q2)
            printAns("B");
        printAns("A");
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

