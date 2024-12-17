#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

// k, k+1 , k+2, ....k + n-1, there are n numbers
// return min value, looks like bs
// values are monotonic like +, +, +, -, - , -, -, ...

class Solution {
    int sigma(int n) {
        return (n * (n+1))/2;
    } 
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        int start = k;
        int end = k+n-1;
        int totalSum = sigma(end) - sigma(k-1);

        while(start <= end) {
            int mid = start + (end - start)/2;
            int sum = sigma(mid) - sigma(k-1); // including mid
            int otherSum = totalSum - sum;

            int diff = otherSum - sum;
            if(diff > 0) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        int ans1 = start;
        int ans2 = start - 1;

        int val1 = abs((totalSum - (sigma(start) - sigma(k-1))) - (sigma(start) - sigma(k-1)));
        int val2 = abs((totalSum - (sigma(start-1) - sigma(k-1))) - (sigma(start-1) - sigma(k-1)));

        pn(min(val1, val2));
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
