//Topic : Array/String - Medium
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0
// Notice that the solution set must not contain duplicate triplets.

// Approaches

// Brute Force (O(n³))
// Pick every triplet (i, j, k) and check if sum = 0.
// Use set to avoid duplicates.

// Better (O(n² log n))
// Fix two numbers, search third using binary search.

// Optimal (Two Pointers O(n²))
// Sort array.
// Fix one element, then use two pointers (l, r) to find other two.

#include<bits/stdc++.h>
using namespace std;

// //In O(n3) T.c
// vector<vector<int>> triplets(vector<int> &arr, int n){
//     set<vector<int>> st;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k =j+1;k<n;k++){
//                 if((arr[i] + arr[j] + arr[k]) == 0){
//                     vector<int> temp = {arr[i],arr[j],arr[k]};
//                     sort(temp.begin(), temp.end()); // avoid duplicates
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     return vector<vector<int>>(st.begin(), st.end());
// }


//In O(N^2 logN)
// vector<vector<int>> threeSum(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     set<vector<int>> st;

//     for(int i=0; i<n; i++) {
//         for(int j=i+1; j<n; j++) {
//             int target = -(nums[i] + nums[j]);
//             if(binary_search(nums.begin()+j+1, nums.end(), target)) {
//                 st.insert({nums[i], nums[j], target});
//             }
//         }
//     }
//     return vector<vector<int>>(st.begin(), st.end());
// }


//In O(n^2) T.C
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    
    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // avoid duplicates
        
        int l = i+1, r = n-1;
        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;
                l++; r--;
            }
            else if(sum < 0) l++;
            else r--;
        }
    }
    return res;
    }
int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Triplets that sums to zeroes are: ";
    vector<vector<int>> res = threeSum(arr);
    for(int i=0;i<res.size();i++){
        cout << "[";
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout <<  "],";
        }
    return 0;
}