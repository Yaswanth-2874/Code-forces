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
    pair<int, int> findTotal(vector<int>& a, vector<int>& b, int lowerBound) {
        int totalTerms = 0;
        int totalSum = 0;

        for(int i = 0; i < a.size(); i++) {
            int currNum = a[i]; // starting term of AP
            int d = b[i]; // common difference
            if(currNum < lowerBound)
                continue;

            int terms = max(0ll, (a[i] - lowerBound )/d + 1);
            // cout<<"Terms for "<<a[i]<<" are "<<terms<<endl;
            totalTerms += terms;
            int sumTerms = (terms * (2 * currNum + (terms - 1) * (-d)))/2;

            totalSum += sumTerms;
        }
        // cout<<totalTerms<<" and totalSum is "<<totalSum<<endl;
        return {totalTerms, totalSum};
    }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        array(int, a, n);
        array(int, b, n);

        int left = 0, right = 1e10;
        findTotal(a, b, 9);
        while(left <= right) {
            int mid = left + (right - left)/2;
            auto [terms, sum] = findTotal(a, b, mid);
            if(terms >= k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // // my right points at a value which is not enough to cross k
        // cout<<right+1<<" is the value which will not cross k"<<endl;

        auto [terms, maxSum] = findTotal(a, b, right+1);
        if(right == -1)
            pn(maxSum);
        // cout<<"Used "<<terms<<" and right is "<<right<<endl;
        int remaining = k - terms;
        maxSum += right * remaining;
        pn(maxSum)
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
