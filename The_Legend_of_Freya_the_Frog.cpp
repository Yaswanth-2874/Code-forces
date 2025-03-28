#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(int N, vector<vector<string>> &A, string D, string V) {
    unordered_map<string, int> fieldMap = {
        {"bank_account_number", 0},
        {"account_holder_first_name", 1},
        {"account_holder_last_name", 2},
        {"registered_mobile_number", 3},
        {"branch_code", 4}
    };

    int column_index = fieldMap[D];

    unordered_set<string> uniqueAccounts, uniqueMobiles;
    vector<vector<string>> filtered_accounts;

    for (auto &account : A) {
        if (account[column_index] == V) {
            string bank_account = account[0];
            string mobile_number = account[3];

            if (uniqueAccounts.find(bank_account) == uniqueAccounts.end() &&
                uniqueMobiles.find(mobile_number) == uniqueMobiles.end()) {
                
                uniqueAccounts.insert(bank_account);
                uniqueMobiles.insert(mobile_number);
                filtered_accounts.push_back(account);
            }
        }
    }

    sort(filtered_accounts.begin(), filtered_accounts.end(), [](vector<string> &a, vector<string> &b) {
        return stoll(a[0]) < stoll(b[0]);
    });

    return filtered_accounts;
}
int main() {
    int N = 3;
    vector<vector<string>> A = {
        {"11221909566", "shivam", "kumar", "9128494856", "1022"},
        {"11221909312", "rohan", "garg", "7384728384", "1022"},
        {"11201339211", "shivam", "sharma", "7384728384", "1987"}
    };

    string D = "branch_code";
    string V = "1022";

    vector<vector<string>> result = solve(N, A, D, V);

    // Print the result
    if (result.empty()) {
        cout << "No record found\n";
    } else {
        for (auto &row : result) {
            for (auto &item : row) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    return 0;
}