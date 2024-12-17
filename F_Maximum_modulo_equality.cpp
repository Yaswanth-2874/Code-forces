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
// To store segment tree

class Solution {
        int* st;
    
    /*  A recursive function to get gcd of given
        range of array indexes. The following are parameters for
        this function.
    
        st    --> Pointer to segment tree
        si --> Index of current node in the segment tree.
    Initially 0 is passed as root is always at index 0 ss &
    se  --> Starting and ending indexes of the segment
                    represented by current node, i.e.,
    st[index] qs & qe  --> Starting and ending indexes of
    query range */
    int findGcd(int ss, int se, int qs, int qe, int si)
    {
        if (ss > qe || se < qs)
            return 0;
        if (qs <= ss && qe >= se)
            return st[si];
        int mid = ss + (se - ss) / 2;
        return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                    findGcd(mid + 1, se, qs, qe, si * 2 + 2));
    }
    
    // Finding The gcd of given Range
    int findRangeGcd(int ss, int se, int arr[], int n)
    {
        if (ss < 0 || se > n - 1 || ss > se) {
            cout << "Invalid Arguments"
                << "\n";
            return -1;
        }
        return findGcd(0, n - 1, ss, se, 0);
    }
    
    // A recursive function that constructs Segment Tree for
    // array[ss..se]. si is index of current node in segment
    // tree st
    int constructST(int arr[], int ss, int se, int si)
    {
        if (ss == se) {
            st[si] = arr[ss];
            return st[si];
        }
        int mid = ss + (se - ss) / 2;
        st[si]
            = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                    constructST(arr, mid + 1, se, si * 2 + 2));
        return st[si];
    }
    
    /* Function to construct segment tree from given array.
    This function allocates memory for segment tree and
    calls constructSTUtil() to fill the allocated memory */
    int* constructSegmentTree(int arr[], int n)
    {
        int height = (int)(ceil(log2(n)));
        int size = 2 * (int)pow(2, height) - 1;
        st = new int[size];
        constructST(arr, 0, n - 1, 0);
        return st;
    }
    public:
    void solve() {
        int n, q;
        cin >> n >> q;
        array(int, v, n);

        int diffArray[n-1];
        if(n == 1) {
            
            vector<int> ans(q, 0);
            while(q--) {
                int l, r;
                cin >> l >> r;
            }
            print(ans);
            return;
        }
        for(int i = 1; i < n; i++) {
            int diff = abs(v[i] - v[i-1]);
            diffArray[i-1] = diff;
            
        }

        // print(diffArray);

        // testing whether my math is correct or not
        constructSegmentTree(diffArray, n-1);
        while(q--) {
            int l, r;
            cin >> l >> r;
            if(l == r) {
                cout<<0<<" ";
                continue;
            }
            
            cout<<findRangeGcd(l-1, r-2, diffArray, n-1)<<" ";
            
        }
        cout<<endl;
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
