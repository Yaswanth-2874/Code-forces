#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array, size) for(int i = 0; i < size; i++)cin>>array[i];
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;

void solve() {
    int size;
    cin>>size;

    map<int, int> freq;
    int count = size;

    for(int i = 0; i < (size * (size - 1)) / 2; i++) {
        int num;
        cin>>num;
        freq[num]++;
    }

    vector<int> nums;

    for(auto it : freq) {
        while(it.second) {
            nums.push_back(it.first);
            it.second -= --count;
        }
    }
    
    while(count--)
      nums.push_back(1e9);
    print(nums);   
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
