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

    vector<ll> array(size);
    input(array, size);
    int n = 2;
    for(int i = 1; i < 57; i++) {
        unordered_set<int> set;
        ll power = 1LL << i;
        for(ll num : array)
            set.insert(num % power);
        if(set.size() == 2) {
            cout << power << endl;
            return;
        }
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
