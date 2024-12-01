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
    int log(int num, int base) {
        // dont trust inbuilt log rounding errors
        int count = 0;
        while(num % base == 0) {
            num /= base;
            count++;
        }

        return count;
    }

    int performOp(int oldPrice, int log2, int log5, int num, int increments) {
        int ans = 1;
        while(ans * num <= increments && log2 != log5) {
            ans *= num;
            if(num == 2)
                log2++;
            else
                log5++;
        }
        while(ans * 10 <= increments) {
            ans *= 10;
        }

        int res = increments/ans * ans * oldPrice;
        return res;
    }
    public:
    void solve() {
        int oldPrice, increments;
        cin >> oldPrice >> increments;

        int log2 = log(oldPrice, 2);
        int log5 = log(oldPrice, 5);
        
        if(log2 == log5) {
            int ans = performOp(oldPrice, log2, log5, 10, increments);
            pn(ans);
        }

        if(log2 < log5) {
            int ans = performOp(oldPrice, log2, log5, 2, increments);
            pn(ans);

        }
        int ans = performOp(oldPrice, log2, log5, 5, increments);
        pn(ans);
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
