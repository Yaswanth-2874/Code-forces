#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    string st;
    int returnCost(vector<int>& learnt) {
        int cost = 0;
        int currCost = 1;

        // for(int i = 0; i < 5; i++)
        //     cout<<learnt[i]<<" ";
        // cout<<endl;

        for(char ch : st) {
            if(learnt[ch - 'A'] == false)
                cost += currCost++;
        }

        return cost;
    }

    int findCost(vector<int>& learnt, int index, int c) {
        if(index == 5)
            return returnCost(learnt);
            
        learnt[index] = 1;
        int learn = c + findCost(learnt, index+1, c);
        learnt[index] = 0;
        int dontLearn = findCost(learnt, index+1, c);

        return min(learn , dontLearn);
    }

    public:
    void solve() {
        int n, m;
        cin >> n >> m >> st;
        vector<int> learnt(5);
        cout<<findCost(learnt, 0, m)<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
