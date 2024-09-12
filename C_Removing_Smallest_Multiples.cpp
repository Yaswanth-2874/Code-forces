#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

void solve() {
    int size;
    cin>>size;

    string st;
    cin>>st;

    vector<int> removed(size + 1);
    int ans = 0;

    for(int i = 1; i <= size; i++) {
        if (st[i - 1] == '0') {
            for (int j = i; j <= size; j += i) {
                if (st[j - 1] == '1') break;
                if (!removed[j]) {
                    removed[j] = true;
                    ans += i;
                }
            }
        }
    }
    cout<<ans<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
