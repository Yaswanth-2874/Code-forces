#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    stack<char> stack;

    void undo(string& s) {
        if(s.size() == 0)
            return;
        char ch = s.back();
        stack.push(ch);
        s.pop_back();
    }
    void redo(string& s) {
        if(stack.size() == 0)
            return;
        char top = stack.top();
        stack.pop();
        s.push_back(top);
    }

    public:
    void solve() {
        string input;
        cin >> input;
        while(true) {
            // Enter 1 to perform undo, 2 to redo, anything else to exit;
            int num;
            cin >> num;
            if(num == 1) {
                undo(input);
                cout<<input<<endl;
            } else if(num == 2) {
                redo(input);
                cout<<input<<endl;
            } else {
                break;
            }
        }
    }
};

int32_t main() {
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

