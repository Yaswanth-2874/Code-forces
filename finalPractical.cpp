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

class Solution {
    queue<int> storage;

    void reverse(stack<int>& st) {
        if(st.empty())
            return;

        int top = st.top();
        st.pop();
        storage.push(top);
        reverse(st);

        int front = storage.front();
        storage.pop();

        cout<<front<<" ";
        st.push(front);

    }
    public:
    void solve() {
        int n;
        cin >> n;
        stack<int> st;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            st.push(num);
        }

        reverse(st);
        cout<<endl;
    }
};

signed main() {
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
