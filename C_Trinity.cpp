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

class Solution {
    int search(vector<int>& v, int n, int left, int max) {
        int right = n-1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(v[mid] <= max) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        array(int, v, n);
        sort(all(v));
        int maxSize = 0;

        for(int i = 0; i < n-1; i++) {
            int val = v[i] + v[i+1] - 1;
            int pos = search(v, n, i, val);
            // cout<<pos<<endl;
            int size = pos - i + 1;
            maxSize = max(maxSize, size);
        }

        pn(n - maxSize);
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
