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

    vector<int> want(size), have(size), diff(size);

    input(want);
    input(have);
    
    for(int i = 0; i < size; i++)
        diff[i] = have[i] - want[i];
    sort(full(diff));

    int left = 0, right = size - 1;
    int count = 0;

    while(left < right) {
        if(diff[left++] + diff[right] >= 0) {
            right--;
            count++;
        }
    }
    cout<<count<<endl;

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
