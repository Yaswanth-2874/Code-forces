#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];

void solve() {
    int size;
    cin>>size;

    string ans ="";
    while(size--) {
        string st;
        cin>>st;
        for(int i = 0; i < st.size(); i++) {
            if(st[i] == '#')
            ans = (char)(i + '1') + ans;
        }
    }
    for(char ch : ans) {
        cout<<ch<<" ";
    }
    cout<<endl;

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
