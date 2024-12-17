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
    int findSum(vector<int>& permutations) {
        int sum = 0;
        // print(permutations);
        for(int i = 0; i < permutations.size(); i++) {
            int num = permutations[i];
            for(int j = i; j < permutations.size(); j++) {
                num = min(num, permutations[j]);
                sum += num;
            }
        }
        return sum;
    }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> permutation;
        for(int i = 1; i <= n; i++) {
            permutation.push_back(i);
        }
        int targetSum = 0;
        int num = 1;
        for(int i = n; i >= 1; i--) {
            targetSum += num * i;
            num++;
        }
        int fact = 5*4*3*2*1;
        while(fact--) {
            int sum = findSum(permutation);
            if(sum == targetSum)
                print(permutation);
            next_permutation(all(permutation));
        }
        // cout<<targetSum<<endl;

    }
};

int32_t main() {
    vector<double> logs(2, 0);
    double sum = 0;
    for(int i = 2; i <= 2e5; i++) {
        sum += log10(i);
        logs.push_back(sum);
    }
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
