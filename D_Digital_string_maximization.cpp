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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    public:
    void solve() {
        string s;
        cin >> s;

        stack<int> st, st2;
        st.push(s[0] - '0');

        for(int i = 1; i < s.size(); i++) {
            int curr = s[i] - '0';
            while(!st.empty() && st.top() + 1 < curr) {
                st2.push(st.top());
                st.pop();
                curr--;
            }
            st.push(curr);
            while(!st2.empty()) {
                st.push(st2.top());
                st2.pop();
            }
        }

        string ans = "";
        while(!st.empty()) {
            char ch = st.top() + '0';
            ans.push_back(ch);
            st.pop();
        }
        reverse(all(ans));
        pn(ans);
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
