#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    // class Trie {
    //     class TrieNode {
    //         public:
    //         unordered_map<char, TrieNode*> nextNode;
    //         bool isEnd, canWin, canLose;
    //         TrieNode() {
    //             isEnd = canWin = canLose = false;
    //         }
    //         TrieNode* insertNode(char nextChar) {
    //             if(nextNode.count(nextChar) == 0)
    //                 nextNode[nextChar] = new TrieNode();
    //             return nextNode[nextChar];
    //         }

    //     };
    //     public:
    //     TrieNode* root;
    //     Trie() {
    //         root = new TrieNode();
    //     }
    //     void insertWord(string& word) {
    //         TrieNode* curr = root;
    //         for(auto letter : word) {
    //             curr = curr->insertNode(letter);
    //         }
    //         curr->isEnd = true;
    //         int size = word.size();
    //         curr->canWin = size % 2;
    //         curr->canLose = !curr->canWin;
    //     }

    //     pair<bool, bool> find(TrieNode* curr, int turn, int initialTurn) { // Return Can Win and Can Lose of children
    //         for(auto& [nextChar, nextAddress] : curr->nextNode) {
    //             auto [canChildWin, canChildLose] = find(nextAddress, !turn, initialTurn);
    //                 if(turn == initialTurn) {
    //                     if(canChildWin)
    //                         curr->canWin = true;
    //                     if(canChildLose)
    //                         curr->canLose = true;
    //                 } else {
    //                     if(canChildLose)
    //                         curr->canWin = true;
    //                     if(canChildWin)
    //                         curr->canLose = true;
    //                 }
    //             }
    //         }
    //         return {curr->canWin, curr->canLose};
    //     }
    // };
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        // Trie T1, T2;
        for(int i = 0; i < n; i++) {
            string word;
            cin >> word;
            // T1.insertWord(word);
            // T2.insertWord(word);
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
