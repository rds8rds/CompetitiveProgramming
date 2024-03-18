#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permutations(const vector<int>& data) {
    if (data.size() == 1) {
        return {data};
    }
    vector<vector<int>> permutations_list;
    for (size_t i = 0; i < data.size(); ++i) {
        int element = data[i];
        vector<int> remaining(data.begin(), data.end());
        remaining.erase(remaining.begin() + i);
        vector<vector<int>> perms = permutations(remaining);
        for (const auto& perm : perms) {
            vector<int> new_perm = {element};
            new_perm.insert(new_perm.end(), perm.begin(), perm.end());
            permutations_list.push_back(new_perm);
        }
    }
    return permutations_list;
}

int main() {
    vector<int> data = {1, 2, 3};
    vector<vector<int>> perms = permutations(data);
    for (const auto& perm : perms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
