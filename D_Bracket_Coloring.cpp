#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

// ))()(( -> (()())
// )()()( -> ()()()
// ())))(((
class Solution {
    bool solveAgain;
    vector<int> reSolve(int n, string& st) {
        vector<int> colors(n, -1);
        int remaining = 0;
        stack<int> lastOpening;

        for(int i = 0; i < n; i++) {
            if(st[i] == '(')
                lastOpening.push(i);

            if(st[i] == ')' && lastOpening.size()) {
                int top = lastOpening.top();
                lastOpening.pop();

                colors[i] = colors[top] = 1;
            } else {
                remaining++;
            }
        }
        int ans = 1;
        int oneCount = count(all(colors), 1);

        for(int& color : colors) {
            if(color == -1) {
                ans = (oneCount != 0) + 1;
                color = oneCount == 0 ? 1 : 2;
            }
        }

        if(ans == 2 && solveAgain) {
            reverse(all(st));
            solveAgain = false;
            vector<int> ans = reSolve(n, st);
            reverse(all(ans));
            return ans;
        }
        cout<<ans<<endl;
        return colors;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        solveAgain = true;

        string st;
        cin >> st;

        int opening = 0, closing = 0;
        for(char& bracket : st)
            opening += bracket == '(';
        closing = n - opening;

        if(opening != closing)
            pn(-1);
        
        // Two colors are enough at most
        vector<int> colors = reSolve(n, st);
        print(colors);
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
