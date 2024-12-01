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
#pragma endregion

// Number is high as 1e9, so i can atmost multiply 1e9 without overflow
// Lets try doing division first, integer overflow obv

class Solution {
    bool possibleToObtain(int multiplyFactor, int targetCorrect, int targetWrong, int x, int y) {
        int totalQuestions = targetCorrect + targetWrong;

        totalQuestions *= multiplyFactor;
        int tc = (totalQuestions / (targetCorrect + targetWrong)) * targetCorrect;
        int tw = (totalQuestions / (targetCorrect + targetWrong)) * targetWrong;

        // cout<<"Total correct now : "<<tc<<" and total wrong now is "<<tw<<endl;

        if(x > tc || y > tw)
            return false;
        return true;
    }
    public:
    void solve() {
        int correct, total, targetCorrect, targetTotal;
        cin >> correct >> total >> targetCorrect >> targetTotal;

        int wrong = total - correct;
        int targetWrong = targetTotal - targetCorrect;

        if(targetWrong == 0) {
            if(correct != total)
                pn(-1);
            pn(0);
        }
        if(targetWrong == targetTotal) {
            if(correct)
                pn(-1);
            pn(0);
        }


        int left = 1, right = 1e9;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(possibleToObtain(mid, targetCorrect, targetWrong, correct, wrong))
                right = mid - 1;
            else
                left = mid + 1;
        }

        // cout<<"Need "<<(right + 1)<<" extra questions"<<endl;
        int sum = targetCorrect + targetWrong;
        sum *= (right + 1);
        sum -= (correct + wrong);
        cout<<sum<<endl;
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
