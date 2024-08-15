#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

void solve() {
    string st;
    cin>>st;

    int size = st.size();
    string newString = "";
    char prev = '#';
    bool pushed = false;

    for(char ch : st) {
        if(ch == prev && !pushed) {
            char chClone = ch;
            chClone = ((chClone -'a' + 1) % 26 )+ 'a';
            newString.push_back(chClone);
            pushed = true;
        }
        prev = ch;
        newString.push_back(ch);
    }
    if(!pushed) {
        char ch = st[size - 1] - 'a';
        ch += 1;
        ch %= 26;
        ch = ch + 'a';
        newString.push_back(ch);
    }
    cout<<newString<<endl;
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
