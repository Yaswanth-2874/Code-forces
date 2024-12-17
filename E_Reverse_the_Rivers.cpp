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

//NOT THE FIRST TIME I GOT WA DUE TO EARLY EXITING FROM QUERIES !!
class Solution {
    vector<vector<int>> mat;
    int binarySearch(int low, int high, int target, bool greater, int r) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            // cout<<greater<<" is the value of greater"<<endl;
            // cout<<"Mid is "<<mat[mid][r]<<" where mid index is "<<mid<<endl;
            if(greater == 1) {
                if(mat[mid][r] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                // cout<<"NOT GREATER"<<endl;
                if(mat[mid][r] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        // high ends up at a position that is just lesser than the required value
        // cout<<"High ends at "<<high<<endl;
        // cout<<"Returned "<<(high + greater)<<endl;
        return high + greater;
    }
    public:
    void solve() {
        int n, k, q;
        cin >> n >> k >> q;

        array(int, v, k);
        mat.push_back(v);
        // print(v)

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                cin >> v[j];
                v[j] |= mat[i-1][j];
            }
            // print(v)
            mat.push_back(v);
        }
        // 100% sure my matrix is correct, so assuming no mistake till this point

        while(q--) {
            int top = 0, bottom = n-1, m;
            bool flag = false;
            // binary search must be done on rows, looks correct so far
            cin >> m;
            while(m--) {
                int r, v;
                char op;
                cin >> r >> op >> v;
                if(flag != 1) {
                    int bestIndex = binarySearch(top, bottom, v, op == '>', r-1);
                    // even converted the index to 0 based, still looks correct

                    if(bestIndex > bottom || bestIndex < top) {
                        // bestIndex would stop at an index just greater than the required value, if it goes higher, obv exit
                        flag = 1;
                    }
                    if(op == '>')
                        top = bestIndex;
                    else
                        bottom = bestIndex;
                }
            }
            if(!flag)
                cout<<top+1<<endl;
            else
                cout<<-1<<endl;
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
