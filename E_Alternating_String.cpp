#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int countReplacements(string& s) {

}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    map<int, int> odd;
    map<int, int> even;
    multiset<int> freqOdd, freqEven;

    int maxOdd = 0, maxEven = 0;
    int last = n-1;

    for(int i = 0; i < n; i+=2) {
        even[s[i]]++;
    }
    for(int i = 1; i < n; i+=2) {
        odd[s[i]]++;
    }
    for(auto it : odd) {
        freqOdd.insert((it.second));
    }
    for(auto it : even) {
        freqEven.insert((it.second));
    }

    maxOdd = freqOdd.size() ? *freqOdd.rbegin() : 0;
    maxEven = freqEven.size() ? *freqEven.rbegin() : 0;

    if(n % 2 == 0)
        cout<<(n - maxEven - maxOdd)<<endl;
    else {
        if(n == 1) {
            cout<<1<<endl;
            return;
        }
        int mini = INT_MAX;
        while(last > 0){
        if(last % 2 == 0) {
            freqEven.erase(even[s[last]]);
            freqEven.insert(even[s[last]]-1);
            even[s[last]]--;
        }
        else {
            freqOdd.erase(odd[s[last]]);
            freqOdd.insert(odd[s[last]]-1);
            odd[s[last]]--;
        }
         maxOdd = freqOdd.size() ? *freqOdd.rbegin() : 0;
         maxEven = freqEven.size() ? *freqEven.rbegin() : 0;
        mini = min(mini, n - maxOdd - maxEven);
        if(last % 2 == 0) {
            freqOdd.erase(odd[s[last]]);
            freqOdd.insert(odd[s[last]]+1);
            odd[s[last]]++;
        }
        else {
            freqEven.erase(even[s[last]]);
            freqEven.insert(even[s[last]]+1);
            even[s[last]]--;
        }
        last--;
        }
        cout<<mini+1<<endl;
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
