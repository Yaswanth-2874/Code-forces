#include <bits/stdc++.h>
#define int long long
using namespace std;

// need max of (amax - amin - |(maxIndex - minIndex)|)
// if(maxIndex >= minIndex) -> (amax - maxIndex) - (amin - minIndex) -> depends on minPrefix
// else ->                     (amax + maxIndex) - (amin + minIndex) -> depends on maXPrefix

// TOO DIFFICULT FOR ME :( WILL RETRY SOON

class Solution {
    class SegmentTree {
        vector<int> maxSegTree, minSegTree, source;
        int n;
        public:
        SegmentTree(vector<int>& source) {
            this->source = source;
            n = source.size();
            maxSegTree.resize(4*n);
            minSegTree.resize(4*n);

            buildTree(0, 0, n-1);
        }
        int buildTree(int index, int left, int right) {
            if(left == right) {
                return minSegTree[index] = maxSegTree[index] = source[right];
            }
            int mid = left + (right - left)/2;
            int leftTree = buildTree(index * 2 + 1, left, mid);
            int rightTree = buildTree(index * 2 + 2, mid+1, right);
            
            maxSegTree[index] = max(leftTree, rightTree);
            return minSegTree[index] = min(leftTree, rightTree); 
        }
        int query(int index, int left, int right, int l, int r, bool isMax) {
            if(left > r || right < l) {
                if(isMax)
                    return LLONG_MIN;
                return LLONG_MAX;
            }
            if(left >= l && right <= r) {
                if(isMax)
                    return maxSegTree[index];
                return minSegTree[index];
            }
            int mid = left + (right - left)/2;
            if(isMax)
                return max(query(index*2+1, left, mid, l, r, isMax), query(index*2+2, mid+1, right, l, r, isMax));
            return min(query(index*2+1, left, mid, l, r, isMax), query(index*2+2, mid+1, right, l, r, isMax));
        }
        void update(int index, int left, int right, int newVal, int updateIndex) {
            if(left == right) {
                maxSegTree[index] = minSegTree[index] = newVal;
                return;
            }
            int mid = left + (right - left)/2;
            if(mid >= updateIndex)
                update(index * 2 + 1, left, mid, newVal, updateIndex);
            else
                update(index * 2 + 2, mid+1, right, newVal, updateIndex);
            minSegTree[index] = min(minSegTree[index * 2 + 1], minSegTree[index * 2 + 2]);
            maxSegTree[index] = max(maxSegTree[index * 2 + 1], maxSegTree[index * 2 + 2]);
        }
    };
    public:
    void solve() {
        int n, q;
        cin >> n >> q;
        
        vector<int> v(n), minus, plus, ans1, ans2;
        int minPrefix, maxPrefix;
        int i = 1;
        for (auto& input : v) {
            cin >> input;
            minus.push_back(input - i);
            plus.push_back(input + i++);
            minPrefix = min(minPrefix, minus.back());
            maxPrefix = max(maxPrefix, plus.back());

            ans1.push_back(minus.back() - minPrefix); //current number - min before it
            ans2.push_back(maxPrefix - plus.back()); //maxNumber - currentNumber
        }
        SegmentTree minusSt(minus), plusSt(plus);
        

        // cout<<st.query(0, 0, n-1, 0, n-1, true) - st.query(0, 0, n-1, 0, n-1, false)<<endl;
        while(q--) {
            int index, val;
            cin >> index >> val;
            // v[index-1] = val-index;
            // st.update(0, 0, n-1, val-index, index-1);
            // cout<<"Max val is "<<st.query(0, 0, n-1, 0, n-1, true)<<endl;
            // cout<<"Min val is "<<st.query(0, 0, n-1, 0, n-1, false)<<endl;
            // /* Print array*/ {
            //     for(auto& val : v) {
            //         cout << val << " ";
            //     }
            //     cout << endl;
            // }
            // cout<<st.query(0, 0, n-1, 0, n-1, true) - st.query(0, 0, n-1, 0, n-1, false)<<endl;
        }
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
