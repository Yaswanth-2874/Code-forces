#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"Anna\n"; return;}
#define no {cout<<"Sasha\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

// M Indicates the number of digits
// Sasha tries to eliminate the number with most number of ending zeroes
// count how many digits can sasha remove

class Solution {
    int countDigits(int num) {
        int count = 0;
        while(num) {
            count++;
            num /= 10;
        } 
        return count;
    }
    int countTrailingZeroes(int num) {
        int zeroes = 0;
        while(num && num % 10 == 0) {
            num /= 10;
            zeroes++;
        }
        return zeroes;
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        input(nums);

        vector<int> zeroes;
        int totalSize = 0;
        for(int i = 0; i < n; i++) {
            totalSize += countDigits(nums[i]);
            zeroes.push_back(countTrailingZeroes(nums[i]));
        }

        sort(all(zeroes), greater<int> ());
        int canRemove = 0;

        for(int i = 0; i < n; i+=2) {
            canRemove += zeroes[i];
        }
        int remainingSize = totalSize - canRemove;
        if(remainingSize >= m+1)
            no;
        yes;
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
