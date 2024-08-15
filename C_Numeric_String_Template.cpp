#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    int m;
    cin>>m;
    while(m--) {
        string st;
        cin>>st;
        bool ans = true;
        if(st.size() != n) {
            cout<<"NO"<<endl;
            continue;
        }
        unordered_map<char, int> chars;
        unordered_map<int, char> intmp;
        for(int i = 0; i < n; i++) {
            char ch = st[i];
            int num = nums[i];
            if(chars.find(ch) != chars.end()) {
                if(chars[ch] != num) {
                    ans = false;
                    break;
                }
            }
            else
                chars[ch] = num;
            if(intmp[num]) {
                if(intmp[num] != ch) {
                    ans = false;
                    break;
                }
            }
            else
                intmp[num] = ch;
        }
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
