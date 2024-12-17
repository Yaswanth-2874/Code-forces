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
    int sum(int n, int start) {
        int sumV = 0;
        while(n && start) {
            sumV += start;
            start /= 2;
            n--;
        }
        return sumV;
    }
    public:
    void solve() {
        int x, n;
        cin >> x >> n;

        int left = 1, right = LLONG_MAX;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int currSum = sum(n, mid);
            if(currSum == x)
                pn(mid);
            if(currSum > x)
                right = mid - 1;
            else
                left = mid+1;
        }
        pn(-1);
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
