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
#define pn(num){cout<<num<<endl; continue;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

// WORST QUALITY CODE,NOT KIDDING, WORST CODE THAT I HAVE EVER WRIITEN! WILL IMPROVE ONE I GET GRASP OF HARDER PROBLEMS

class Solution {
    int findBestNext(set<int>& colorSet, int i) {
        auto it = colorSet.lower_bound(i);
        if(it == colorSet.end())
            return -1;
        return *it;
    }
    int findBestPrev(set<int>& colorSet, int i) {
        auto it = colorSet.lower_bound(i);
        if(it == colorSet.begin())
            return -1;
        return *prev(it);
    }
    public:
    void solve() {
        int n, q;
        cin >> n >> q;
        vector<string> colors;
        set<int> bg, br, by, gr, gy, ry;

        for(int i = 0; i < n; i++) {
            string st;
            cin >> st;
            colors.push_back(st);

            if(st == "BG") {
                bg.insert(i);
            } else if (st == "BR") {
                br.insert(i);
            } else if (st == "BY") {
                by.insert(i);
            } else if (st == "GR") {
                gr.insert(i);
            } else if (st == "GY") {
                gy.insert(i);
            } else if (st == "RY") {
                ry.insert(i);
            }
        }

        while(q--) {
            int q1, q2;
            cin >> q1 >> q2;
            q1--;
            q2--;

            if(q1 > q2)
                swap(q1, q2);
            if(q1 == q2)
                pn(0);
            
            int minDistance = LLONG_MAX;
            int jumpNext = n, jumpBefore = n;
            bool skip = false;

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    if(colors[q1][i] == colors[q2][j]) {
                        i = j = 69;
                        skip = true;
                        pn(q2 - q1);
                    }
                }
            }
            if(skip)
                continue;
            int bestPrev = LLONG_MIN, bestNext = LLONG_MAX;

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    string currentColor = "";
                    currentColor.push_back(colors[q1][i]);
                    currentColor.push_back(colors[q2][j]);
                    // cout<<currentColor<<" ";
                    if(currentColor == "BG" || currentColor == "GB") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(bg, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(bg, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                    if(currentColor == "BR" || currentColor == "RB") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(br, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(br, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                    if(currentColor == "BY" || currentColor == "YB") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(by, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(by, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                    if(currentColor == "GR" || currentColor == "RG") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(gr, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(gr, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                    if(currentColor == "GY" || currentColor == "YG") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(gy, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(gy, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                    if(currentColor == "RY" || currentColor == "YR") {
                        // cout<<"Currently in "<<currentColor<<endl;
                        int currNext = findBestNext(ry, q1);
                        if(currNext != -1)
                            bestNext = min(bestNext, currNext);
                        int currPrev = findBestPrev(ry, q1);
                        if(currPrev != -1)
                            bestPrev = max(bestPrev, currPrev);
                    }
                }
            }

            // cout<<"For "<<q1<<" and "<<q2<<" best before is "<<bestPrev<<" and best After is "<<bestNext<<endl;

            if(bestPrev != LLONG_MIN) {
                int currDist = abs(q1 - bestPrev) + abs(q2 - bestPrev);
                minDistance = min(minDistance, currDist);
            }
            if(bestNext != LLONG_MAX) {
                int currDist = abs(q1 - bestNext) + abs(q2 - bestNext);
                minDistance = min(minDistance, currDist);
            }

            if(minDistance == LLONG_MAX) 
                cout<<-1<<endl;
            else
                cout<<minDistance<<endl;
            
        }
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
