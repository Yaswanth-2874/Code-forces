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
    int l1, l2;
    int findFactors(int r2, int num, int n) {
        int count = 0;
        for(int p = 0; true; p++) {
            if(num > r2)
                return p;
            // cout<<num<<" and "<<count<<endl;
            num *= n;
        }

    }
    int findDelete(int num, int n) {
        int c = 0;
        for(int p = 0; true; p++) {
            if(num >= l2)
                return c;
            c++;
            num *= n;
        }
    }
    int findLast(int l1, int r1, int factors, int n) {
        int left = l1, right= r1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int f = findDelete(mid, n);
            if(f < factors)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
    int findLastValid(int l1, int r1, int r2, int factors, int n) {
        int left = l1, right = r1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            int f = findFactors(r2, mid, n);
            if(f < factors)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
    public:
    void solve() {
        int n, r1, r2;
        cin >> n >> l1 >> r1 >> l2 >> r2;
        int factors = findFactors(r2, l1, n);
        int ans = 0;
        int start = l1;

        // brute force for testing
        // for(int i = l1; i <= r1; i++) {
        //     int num = i;
        //     while(num < l2) {
        //         num *= n;
        //     }
        //     while(num <= r2) {
        //         num *= n;
        //         ans++;
        //     }
        // }
        // pn(ans);

        while(start <= r1) {
            int next = findLastValid(l1, r1, r2, factors, n);
            // cout<<"Start : "<<start<<" and next : "<<next<<endl;
            // cout<<"factors : "<<factors<<endl;
            int nums = next - start + 1;
            ans += factors * (nums);
            factors--;
            start = next + 1;
        }
        start = l1;
        factors = findDelete(l1, n);
        // cout<<factors<<endl;
        while(factors > 0 && start <= r1) {
            int next = findLast(l1, r1, factors, n);
            // cout<<"Start : "<<start<<" and next : "<<next<<endl;
            // cout<<"factors : "<<factors<<endl;
            int nums = next - start + 1;
            ans -= factors * (nums);
            factors--;
            start = next + 1;
        }
        pn(ans)

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
