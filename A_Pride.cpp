#include <bits/stdc++.h>
#define int long long
using namespace std;

// this can be solved without seg tree also 

class Solution {
    class SegmentTree {
        vector<int> segTree, source;
        int n;
        public: 
        SegmentTree (vector<int>& source) {
            n = source.size();
            segTree.resize(4 * n);
            this->source = source;
            buildTree(0, 0, n-1);
        }
        void buildTree(int index, int left, int right) {
            if(left == right) {
                segTree[index] = source[left];
                return;
            }
            int mid = left + (right - left)/2;
            buildTree(index * 2 + 1, left, mid);
            buildTree(index * 2 + 2, mid+1, right);
            segTree[index] = gcd(segTree[index * 2 + 1], segTree[index * 2 + 2]);
        }
        int query(int index, int left, int right, int l, int r) {
            if(left > r || right < l)
                return 0;
            if(left >= l && right <= r)
                return segTree[index];
            
            int mid = left + (right - left)/2;
            int leftQ = query(index * 2 + 1, left, mid, l, r);
            int rightQ = query(index * 2 + 2, mid + 1, right, l, r);

            return gcd(leftQ, rightQ);
        }
    };
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        int oneCount = 0;
        for (auto& input : v) {
            cin >> input;
            oneCount += input == 1;
        }
        if(oneCount) {
            cout<<n-oneCount<<endl;
            return;
        }

        SegmentTree st(v);
        int minSize = INT_MAX;
        for(int i = 0; i < n; i++) {
            int left = i, right = n-1;
            int ans = -1;
            while(left <= right) {
                int mid = left + (right - left)/2;
                int rangeGcd = st.query(0, 0, n-1, i, mid);
                if(rangeGcd != 1) {
                    left = mid + 1;
                } else {
                    ans = mid;
                    right = mid - 1;
                }
            }
            if(ans != -1) {
                // cout<<"range for index "<<i<<" is "<<ans<<endl;
                minSize = min(minSize, ans - i);
                
            }
        }
        // cout<<minSize<<endl;
        if(minSize == INT_MAX)
            cout<<-1<<endl;
        else
            cout<<(minSize + (n - 1));
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
