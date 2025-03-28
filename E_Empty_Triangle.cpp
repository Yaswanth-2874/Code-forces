#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}

bool stop = false;

class Solution {
    int query(int a, int b, int c) {
        cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        int a = 1, b= 2, c = 3;
        int changeTurn = 0;

        queue<tuple<int, int, int>> q;
        q.push({1, 2, 3});

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [a, b, c] = q.front();
                q.pop();
                int res = query(a, b, c);


                if(res == 0) {
                    cout<<"! "<<a<<" "<<b<<" "<<c<<endl;
                    return;
                }
                if(res == -1) {
                    stop = true;
                    return;
                }

                int r = rand() % 3;

                if(r == 0)
                    q.push({a, b, res});
                if(r == 1)
                    q.push({a, c, res});
                if(r == 2)
                    q.push({c, b, res});
            }
        }
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
        if(stop)
            break;
    }
    return 0; 
}

