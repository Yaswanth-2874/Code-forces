#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    string wordSeq;
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> memo;

    int calc(vector<string>& words, int index, int gptScore, int myScore, int currCharIndex) {
        if (index >= words.size()) {
            gptScore += currCharIndex;
            return myScore - gptScore;
        }

        if (memo[index][gptScore][myScore].find(currCharIndex) != memo[index][gptScore][myScore].end())
            return memo[index][gptScore][myScore][currCharIndex];

        int dontSelectWord = calc(words, index + 1, gptScore, myScore, currCharIndex);

        int newGPTScore = gptScore, newMyScore = myScore, newCurrCharIndex = currCharIndex;
        for (char ch : words[index]) {
            if (wordSeq[newCurrCharIndex] == ch) {
                newCurrCharIndex++;
                if (newCurrCharIndex == 5) {
                    newMyScore += 5;
                    newCurrCharIndex = 0;
                }
            } else {
                if (ch == 'n' || ch == 'a' || ch == 'r' || ch == 'e' || ch == 'k') {
                    newGPTScore++;
                }
            }
        }

        int selectWord = calc(words, index + 1, newGPTScore, newMyScore, newCurrCharIndex);

        return memo[index][gptScore][myScore][currCharIndex] = max(selectWord, dontSelectWord);
    }

public:
    void solve() {
        wordSeq = "narek";
        int n, m;
        cin >> n >> m;
        vector<string> words(n);
        input(words);
        memo.clear();
        cout << calc(words, 0, 0, 0, 0) << endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}
