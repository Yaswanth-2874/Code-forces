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

    map<int, int> freq;
    int count = 0;
    for(int i = 0; i < size; i++) {
        int num;
        cin>>num;
        freq[num]++;
    }
    for(auto it : freq) {
        int occurances = it.second;
        while(occurances--) {
            int initialNum = it.first;
            while(freq.find(initialNum + 1) != freq.end()) {
                freq[++initialNum]--;
                if(freq[initialNum] == 0)
                    freq.erase(initialNum);
            }
            count++;
        } 
    }
    cout<<count<<endl;
    // 2 2 3 4 4
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
