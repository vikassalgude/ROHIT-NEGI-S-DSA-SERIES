#include <iostream>
#include <vector>
using namespace std;

void permut(vector<int>& arr, vector<vector<int>>& ans, int index) {
    // Base case: if index reaches the size of the array
    if (index == arr.size()) {
        ans.push_back(arr);
        return;
    }
    
    for (int i = index; i < arr.size(); i++) {
        swap(arr[i], arr[index]);  // Swap current index with the index
        permut(arr, ans, index + 1); // Recurse for the next index
        swap(arr[i], arr[index]);  // Backtrack to restore original array
    }
}

int main() {
    vector<int> arr = {1, 2, 3}; // Example input
    vector<vector<int>> ans;     // To store all permutations

    permut(arr, ans, 0); // Start generating permutations from index 0

    // Output all permutations
    for (const auto& perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
