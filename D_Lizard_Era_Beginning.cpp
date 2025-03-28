#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<tuple<int, int, int>> mat;
    void generateSubset(vector<tuple<int, int, int, vector<pair<int, int>>>>& subset, int a, int b, int c, int index, int last, vector<pair<int, int>>& order) {
        if(index > last) {
            subset.push_back({a, b, c, order});
            return;
        }
        auto [aInc, bInc, cInc] = mat[index];

        order.push_back({index, 0});
        generateSubset(subset, a + aInc, b + bInc, c, index + 1, last, order);
        order.pop_back();

        order.push_back({index, 1});
        generateSubset(subset, a + aInc, b, c + cInc, index + 1, last, order);
        order.pop_back();    

        order.push_back({index, 2});
        generateSubset(subset, a, b + bInc, c + cInc, index + 1, last, order);
        order.pop_back();
    }
    public:
    void solve() {
        int n;
        cin >> n;
        mat.resize(n);
        
        for(int i = 0; i < n; i++) {
            auto& [a, b, c] = mat[i];
            cin >> a >> b >> c;
        }

        vector<tuple<int, int, int, vector<pair<int, int>>>> subset1, subset2;
        vector<pair<int, int>> order;

        generateSubset(subset1, 0, 0, 0, 0, (n-1)/2, order);
        generateSubset(subset2, 0, 0, 0, (n-1)/2 + 1, n-1, order);
        int firstIndex = -1, secondIndex = - 1;
        int currAns = LLONG_MIN;

        sort(begin(subset2), end(subset2));

        // for(auto [a, b, c, d] : subset2) {
        //     cout<<"( "<<a<<", "<<b<<", "<<c<<" )"<<endl;
        // }

        set<int> possibleA;
        for(auto& [a, b, c, d] : subset2) {
            possibleA.insert(a);
        }

        for(int i = 0; i < subset1.size(); i++) {
            auto& [currA, currB, currC, _] = subset1[i];
            int maxVal = max({currA, currB, currC});
            // cout<<currA<<" "<<currB<<" "<<currC<<" is the current \n";

            for(int posA : possibleA) {
                int j = posA + currA;
                int targetA = j - currA, targetB = j - currB, targetC = j - currC;
                vector<pair<int, int>> nullVec = {{-1, -1}};
                tuple<int, int, int, vector<pair<int, int>>> toCheck = {targetA, targetB, targetC, nullVec};
                // cout<<targetA<<" "<<targetB<<" "<<targetC<<" is the target "<<endl;

                int index = lower_bound(begin(subset2), end(subset2), toCheck) - begin(subset2);
                if(index != subset2.size()) {
                    auto [gotA, gotB, gotC, __] = subset2[index];
                    if(gotA == targetA && gotB == targetB && gotC == targetC && j > currAns) {
                        firstIndex = i;
                        secondIndex = index;
                        currAns = j;
                        break;
                    }
                }
            }
        }

        if(firstIndex == -1)
            cout<<"Impossible";
        else {
            auto& [_, __, ___, ops] = subset1[firstIndex];
            auto& [_2, __2, ___2, ops2] = subset2[secondIndex];

            for(auto& op : ops2) {
                ops.push_back(op);
            }

            sort(begin(ops), end(ops));
            vector<string> toPrint = {"LM", "LW", "MW"};
            for(auto& [i, _3] : ops) {
                // cout<<i<<endl;
                cout<<toPrint[_3]<<endl;
            }
        
        }
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
