#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

pair<int, int> findMax(unordered_map<char, int>& odd, unordered_map<char, int>& even){
    int maxOdd = 0, maxEven = 0;
    for(auto [_, count] : odd) {
        maxOdd = max(maxOdd, count);
    }
    for(auto [_, count] : even) {
        maxEven = max(maxEven, count);
    }
    return {maxOdd, maxEven};
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char, int> odd, even;
    int last = n-1;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)
            even[s[i]]++;
        else
            odd[s[i]]++;
    }
    
    pair<int, int> maxValues = findMax(odd, even);
    if(n % 2 == 0)
        cout<< n - maxValues.first - maxValues.second <<endl;
    else {
        int ans = INT_MAX;
        while(last  >= 0) {
            if(last % 2 == 0)
                even[s[last]]--;
            else
                odd[s[last]]--;
            maxValues = findMax(odd, even);
            // cout<<maxValues.first<<" "<<maxValues.second<<endl;
            ans = min(ans, n - maxValues.first - maxValues.second);
            if(last % 2 == 0)
                odd[s[last]]++;
            else
                even[s[last]]++;
            last--;
    }
    cout<<ans<<endl;
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
