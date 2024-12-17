#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        array(int, v, n);

        int oddSum = 0, evenSum = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2)
                oddSum += v[i];
            else
                evenSum += v[i];
        }

        int evenTerms = (n+1)/2;
        int oddTerms = n - evenTerms;

        if(evenSum % evenTerms != 0 || oddSum % oddTerms != 0)
            no;
        evenSum /= evenTerms;
        oddSum /= oddTerms;

        if(evenSum == oddSum)
            yes;
        no;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
