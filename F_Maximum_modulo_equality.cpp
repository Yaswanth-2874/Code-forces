#include <bits/stdc++.h>
#define int long long
using namespace std;

// using my own segment tree

class Solution {
    class SegmentTree {
        vector<int> segTree;
        vector<int> source;
        public:
        SegmentTree (int n, vector<int>& source) {
            segTree.resize(4*n);
            this->source = source;
            build(0, 0, source.size() - 1);
        }
        void build(int index, int low, int high) {
            // low and high are ranges, 0 based indexing
            if(low == high) {
                segTree[index] = source[low];
                return;
            }

            int mid = low + (high - low)/2;
            build(index * 2 + 1, low, mid);
            build(index *2 + 2, mid+1, high);

            segTree[index] = gcd(segTree[2 * index + 1], segTree[2 * index + 2]);
        }
        int findVal(int index, int low, int high, int l, int r) {
            if(l > high || r < low)
                return 0;
            if(l <= low && r >= high)
                return segTree[index];
            int mid = low + (high - low)/2;
            int left = findVal(index * 2 + 1, low, mid, l, r);
            int right = findVal(index * 2 + 2, mid + 1, high, l, r);          

            return gcd(left, right);
        }

    };
    public:
    void solve() {
        int n, q;
        cin >> n >> q;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }
        if(n == 1) {
            while(q--) {
                int l, r;
                cin >> l >> r;
                cout<<0<<" ";
            }
            cout<<endl;
            return;   
        }
        vector<int> diff;
        for(int i = 1; i < n; i++) {
            diff.push_back(abs(v[i] - v[i-1]));
        }
        SegmentTree st(n-1, diff);

        while(q--) {
            int l, r;
            cin >> l >> r;
            
            if(l == r) {
                cout<<0<<" ";
                continue;
            }
            cout<<st.findVal(0, 0, n-2, l-1, r-2)<<" ";
        }
        cout<<endl;
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
