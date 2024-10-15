#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

class Solution {
    void fill(vector<pair<int, int>>& activity, int n) {
        for(int i = 0; i < n; i++) {
            int people;
            cin >> people;
            activity.push_back({people, i+1});
        }
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<pair<int, int>> swim, movie, board;
        
        fill(swim, n);
        fill(movie, n);
        fill(board, n);

        sort(all(swim), greater<pair<int, int>> ());
        sort(all(movie), greater<pair<int, int>> ());
        sort(all(board), greater<pair<int, int>> ());

        int maxFun = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    auto [fun1, day1] = swim[i];
                    auto [fun2, day2] = movie[j];
                    auto [fun3, day3] = board[k];

                    if(day1 == day2 || day2 == day3 || day3 == day1)
                        continue;
                    maxFun = max(maxFun, fun1+fun2+fun3);
                }
            }
        }
        pn(maxFun);
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