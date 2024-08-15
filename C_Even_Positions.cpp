#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int calcCost(string& st) {
    stack<int> s;
    int ans = 0;

    for(int i = 0; i < st.size(); i++) {
        if(st[i] == '(')
            s.push(i);
        else {
            int top = s.top();
            s.pop();
            ans += i - top;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;

    string st;
    stack<char> s;
    cin>>st;
    for(char& ch : st) {
        if(ch == '(') {
            s.push(ch);
            }
        else if(ch == ')') {
            s.pop();
        }
        else {
            if(s.empty()) {
                s.push('(');
                ch = '(';
            }
            else {
                s.pop();
                ch = ')';
            }
        }
    }
    cout<<calcCost(st)<<endl;
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
