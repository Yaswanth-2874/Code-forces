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
    int n;
    bool check(int timeAvailable, int tasksToDo, map<int, int>& tasksMap) {
        int tasksPerformed = 0;

        for(int i = 1; i <= n; i++) {
            int efficientTasks = tasksMap[i];
            int optimalTasksDone = min(efficientTasks, timeAvailable);
            int remainingTime = timeAvailable - optimalTasksDone;
            int unoptimalTasksDone = remainingTime/2;
            // cout<<"Optimal Tasks done : "<<optimalTasksDone<<endl;
            // cout<<"Unoptimal Tasks done : "<<unoptimalTasksDone<<endl;

            tasksPerformed += optimalTasksDone + unoptimalTasksDone;
            if(tasksPerformed >= tasksToDo)
                return true;
        }

        return false;
    }
    public:
    void solve() {
        int m;
        cin >> n >> m;

        array(int, v, m);
        freqMap(int, v);

        int left = 1, right = 2*m;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(check(mid, m, freq)) {
                right = mid - 1;
                // cout<<"Possible to do all tasks within "<<mid<<endl;
            }
            else {
                left = mid + 1;
                // cout<<"Not Possible to do all tasks within "<<mid<<endl;
            }
        }

        pn(right + 1);     
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
