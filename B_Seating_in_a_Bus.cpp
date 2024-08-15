#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

string solve() {
    int size;
    cin>>size;
    vector<int> arr(size);
    vector<bool> occupied(size+2, false);
    bool ans = true;
    occupied[size + 1] = false;
    occupied[0] = false;
    for(int i = 0; i < size; i++) {
        cin>>arr[i];
        if(!occupied[arr[i] - 1] && !occupied[arr[i] + 1] && i != 0)
            ans = false;
        occupied[arr[i]] = true;
    }
    return ans ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
    return 0;
}
