#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

// I need to divide the people into k groups such that height of people in same groups dont differ by 2 or more
// In each group there could be min of 1 person and max could go LLMAX(sum of all elements fit inside this)
// Now i see if it is possible to create k groups with equal size members

//I WAS TRYING TO USE CURRENT PEOPLE FIRST BUT ISNT IT MORE OPTIMAL TO USE PREVIOUS PEOPLE??
//First use previous people.. then subtract them and find the left over ones

class Solution {
    bool canDivide(vector<int>& heightsMap, int groupSize, int groups) {
        int prevExtra = 0;
        int generatedGroups = 0;

        for(int people : heightsMap) {

            int needExtra = groupSize - prevExtra;
            if(people >= needExtra) {
                people -= needExtra;
                generatedGroups++;
            }
            int minGroups = (people)/groupSize;
            // cout<<"generated groups of "<<minGroups<<endl;
            generatedGroups += minGroups;
          
            prevExtra = (people) % groupSize;
            // cout<<people<<" remaining"<<endl;
        }
        // cout<<"can generate "<<generatedGroups<<" with groupSize "<<groupSize<<endl;
        return generatedGroups >= groups;
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;
        //m = persons in each group

        vector<int> heights(n);
        input(heights);

        // canDivide(heights, 6LL, m);

        int left = 1, right = LLONG_MAX;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(canDivide(heights, mid, m))
                left = mid + 1;
            else
                right = mid -1;
        }

        cout<<(left - 1)*(m)<<endl;        
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

