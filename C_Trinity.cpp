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

//Sum of 2 mins should always be greater than max
//Obviously sort
//2 choices, increase least value or decrease max
//dont use dp for such constraints
//binary search + greedy???
//find number of elements that are >= minValid

class Solution {
    int bs(vector<int>& v, int left, int right) {
        int minElement = v[left], maxElement = v[right];
        int startPos = left;

        while(left <= right) {
            int mid = left + (right - left)/2;
            int sum = minElement + v[mid];
            if(sum > maxElement)
                right = mid - 1;
            else
                left = mid + 1;
        }
       
        // cout<<"Invalid Positions are "<<max(right - startPos, 0LL)<<endl;
        
        return max(right - startPos, 0LL);
    }

    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> v(n);
        input(v);

        sort(all(v));
        int left = 0, right = n-1;
        //v1 + v2 > vn => v1 + v2 - 1 = vn(min valid) => v2 = vn - v1 + 1
        int minValidElement = v[right] - v[left] + 1;
        int dontRemove = bs(v, 0, n-1);
        if(dontRemove == 0)
            pn(0);
        int removed = 1;

        while(left <= right) {
            int removeLeft = bs(v, left+1, right);
            int removeRight = bs(v, left, right-1);

            if(removeLeft == 0|| removeRight == 0)
                break;
            if(removeLeft < removeRight) {
                left++;
                // cout<<"Removed Left"<<endl;
            }
            else {
                right--;
                // cout<<"Removed Right"<<endl;
            }
            removed++;
        }
        pn(removed);
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