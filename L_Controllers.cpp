#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; continue;}
#define no {cout<<"NO\n"; continue;}
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

// consider splitting minus also
class Solution {
    bool checkDeeper(int left, int right, int val1, int val2, int minus, int target) {
        while(left <= right) {
            int mid = left + (right - left)/2;
            int current = mid * val1 + (minus - mid) * val2;
            if(current == target)
                return true;
            if(current > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
    bool check(int left, int right, int val1, int val2, int plus, int minus) {
        while(left <= right) {
            int mid = left + (right-left) / 2;
            int current = mid * val1 + (plus - mid - minus)* val2;
            //current value assumes that all minus are given to val 2
            if(current == 0)
                return true;
            if(current > 0) {
                int target = mid * val1 + (plus - mid)*val2;
                if(checkDeeper(0, minus, val1, val2, minus, target))
                    return true;
                right = mid - 1;
            }
                
            else // if current is less than zero, no point of splitting minus
                left = mid + 1;
        }
        return false;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        string st;
        cin >> st;
        int plus = count(all(st), '+');
        int q;
        cin >> q;

        while(q--) {
            int val1, val2;
            cin >> val1 >> val2;

            if(val2 > val1)
                swap(val1, val2);
            
            if(check(0, plus, val1, val2, plus, n-plus))
                yes;
            no;            
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
