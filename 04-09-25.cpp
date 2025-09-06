
//Topic: Array/String
// Valid Anagram (LeetCode #242)
// Check if two strings are anagrams of each other.

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
    
//     string s;
//     cin >> s;
//     string t;
//     cin >> t;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     if(s == t){
//         cout << "Strings are anagram.";
//     }else{
//         cout << "Strings are not anagram.";
//     }

//     return 0;
// }

// Topic:Stack/queue :-Next Greater Element II

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
// return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array,
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 // Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
// Example 2:

// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]
// Constraints:
// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109

// #include<bits/stdc++.h>
// using namespace std;

// //Brute-force:

// vector<int> findNextGreater(vector<int> &arr, int n){
//     vector<int> ans(n,-1);
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<=i+n;j++){
//             int idx = j%n;
//             if(arr[i] < arr[idx]){
//                 ans[i] = arr[idx];
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// //Better Approach using stack
// vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n,-1);
//         stack<int> st;

//         for(int i=2*n-1;i>=0;i--){
//             while(!st.empty() && st.top() <= nums[i%n]){
//                 st.pop();
//             }
//             if(i<n){
//                 if(!st.empty()){
//                     ans[i] = st.top();
//                 }
//             }
//             st.push(nums[i%n]);
//         }
//         return ans;
//     }

// int main(){

//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }

//     vector<int> ans = findNextGreater(arr,n);
//     vector<int> ans1 = nextGreaterElements(arr);
//     for(auto x : ans1){
//         cout << x << " ";
//     }
//     return 0;
// }

//Topic Linkedlist -: Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

//Brute Force Approach:Convert the list in the array/vector and after that sort the vector and then 
// convert the vector into the linkedlist;
//T.C : O(N) for collecting the list into the vector + O(Log N) for sorting the vector + O(N) for coverint the vecotr into linkedlist
//So. Final T.C = O(N) + O(Log N) + O(N)
//S.C : O(N) for storing list element in vector
// N-> number of element in KLists


// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node* next;

//         Node(int data){
//             this->data = data;
//             this->next = NULL;
//         }
// };

// Node* mergeLists(vector<Node*> &KLists, int k){

//     Node* head = NULL;
//     Node* tail = NULL;
//     vector<int> ans;
//     for(int i=0;i<k;i++){
//         Node* curr = KLists[i];
//         while(curr != nullptr){
//             ans.push_back(curr->data);
//             curr = curr->next;
//         }
//     }
//     sort(ans.begin(),ans.end());
//     int n = ans.size();
//     for(int i=0;i<n;i++){
//         Node* newNode = new Node(ans[i]);
//         if(head == nullptr){
//             head = tail =  newNode;
//         }
//         tail->next = newNode;
//         tail = newNode;
//     }
//     return head;
// }

// void printList(Node* head){
//     while(head != NULL){
//         cout << head->data << "->";
//         head = head->next;
//     }cout << "NULL";
// }
// int main(){

//     vector<Node*> KLists;
//     int k;
//     cout << "Enter the number of lists in an array: ";
//     cin >> k;

//     for(int i=0;i<k;i++){

//         Node* head = NULL;
//         Node* tail = NULL;

//         int temp;
//         cin >> temp;

//         while(temp != -1){
//             Node* newNode = new Node(temp);
//             if(head == NULL){
//                 head = tail = newNode;
//             }
//             tail->next = newNode;
//             tail = newNode;
//             cin >> temp;
            
//         }

//         KLists.push_back(head);
//     }
//     Node* head = mergeLists(KLists,k);
//     printList(head);
//     return 0;
// }


//Better Appraoch: 

    // #include<bits/stdc++.h>
    // using namespace std;

    // class Node{
    //     public:
    //         int data;
    //         Node* next;

    //         Node(int data){
    //             this->data = data;
    //             this->next = NULL;
    //         }
    // };

    // class compare{
    //     public:
    //         bool operator()(Node* a, Node* b){
    //             return a->data > b->data;
    //         }
    // };


    // Node* mergeListsUsingPriorityqueue(vector<Node*> &KLists, int k){

    //     priority_queue<Node* ,vector<Node*> ,compare> pq;
    //     //inserting the first node of evering List
    //     for(int i=0;i<k;i++){
    //         if(KLists[i] != NULL){
    //             pq.push(KLists[i]);
    //         }
    //     }

    //     Node* head = NULL;
    //     Node* tail = NULL;

    //     //compareing next node;
    //     while(pq.size() > 0){
    //         Node* top = pq.top();
    //         pq.pop();

    //         if(top->next != NULL){
    //             pq.push(top->next);
    //         }

    //         if(head == NULL){
    //             head = tail = top;
    //         }else{
    //             tail->next = top;
    //             tail = top;
    //         }
    //     }
    //     return head;
    // }

    // void printList(Node* head){
    //     while(head != NULL){
    //         cout << head->data << "->";
    //         head = head->next;
    //     }cout << "NULL";
    // }

    // int main(){

    //     vector<Node*> KLists;
    //     int k;
    //     cout << "Enter the number of lists in an array: ";
    //     cin >> k;

    //     for(int i=0;i<k;i++){

    //         Node* head = NULL;
    //         Node* tail = NULL;

    //         int temp;
    //         cin >> temp;

    //         while(temp != -1){
    //             Node* newNode = new Node(temp);
    //             if(head == NULL){
    //                 head = tail = newNode;
    //             }
    //             tail->next = newNode;
    //             tail = newNode;
    //             cin >> temp;
                
    //         }

    //         KLists.push_back(head);
    //     }
    //     Node* head = mergeListsUsingPriorityqueue(KLists,k);
    //     printList(head);
    //     return 0;
    // }

// Topic : Tree:-Symmetric Tree (LeetCode #101)
// Check whether a binary tree is symmetric (mirror of itself).

// #include<bits/stdc++.h>
// using namespace std;


// class Node{
//     public:
//         int data;
//         Node* left;
//         Node* right;

//         Node(int data){
//             this->data = data;
//             this->left = NULL;
//             this->right = NULL;
//         }
// };

// Node* buildTree(){

//     int data;
//     cin >> data;

//     if(data == -1){
//         return NULL;
//     }

//     Node* root = new Node(data);
//     root->left = buildTree();
//     root->right = buildTree();

//     return root;
// }

// bool isMirror(Node* t1,Node* t2){
//     if(!t1 && !t2) return true;
//     if(!t1 || !t2) return false;

//     return (t1->data == t2->data) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
// }
// bool isSymmetric(Node* root) {
//     if(!root) return false;
//     return isMirror(root->left, root->right);
// }

// int main(){
//     Node* root = NULL;
//     root = buildTree();
//     if(isSymmetric(root)){
//         cout << "true";
//     }else{
//         cout << "false";
//     }
//     return 0;
// }

//Topic :DP- Coin Change (LeetCode #322)
// Given coins of different denominations, find the minimum number of coins needed to make up a given amount.

// You are given an integer array coins representing coins of different denominations
// and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
//If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Example 3:
// Input: coins = [1], amount = 0
// Output: 0

//Recursive Solution which for bigger amoount will give TLE:

// #include<bits/stdc++.h>
// using namespace std;

// int solveRec(vector<int> &coins, int amount, int n ){
//     if(amount==0) return 0;
//     if(amount<0) return INT_MAX;

//     int mini = INT_MAX;

//     for(int i=0;i<n;i++){
//         int ans = solveRec(coins, amount-coins[i], n);
//         if(ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     return mini;
// }

// int solveMem(vector<int> &coins, int amount, int n,vector<int> &dp){
//     if(amount==0) return 0;
//     if(amount<0) return INT_MAX;

//     int mini = INT_MAX;

//     for(int i=0;i<n;i++){
//         int ans = solveMem(coins, amount-coins[i], n,dp);
//         if(ans != INT_MAX){
//             mini = min(mini, 1+ans);
//         }
//     }
//     return dp[amount] = mini;
// }

// int coinChange(vector<int> &arr, int amount){
//     int n = arr.size();
//     vector<int> dp(n,-1);
//     int ans1 = solveRec(arr,amount,n);
//     int ans2 = solveMem(arr,amount,n,dp);
//     return ans2 == INT_MAX ? -1 : ans2;
// }

// int main(){
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//      vector<int> arr(n);
//      cout << "Enter arrays elements: ";
//      for(int i=0;i<n;i++) cin >> arr[i];

//      int amount;
//      cout << "Enter amount: ";
//      cin >> amount;

//      cout << coinChange(arr, amount);
//      return 0;
// }

//Topic: Graph Course Schedule III (LeetCode #630)
// Find the maximum number of courses you can take given deadlines and durations.
// There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] 
//indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
// You will start on the 1st day and you cannot take two or more courses simultaneously.
// Return the maximum number of courses that you can take.

// Example 1:
// Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
// Output: 3
// Explanation: 
// There are totally 4 courses, but you can take 3 courses at most:
// First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
// Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
// Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
// The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

// Example 2:
// Input: courses = [[1,2]]
// Output: 1

// Example 3:
// Input: courses = [[3,2],[4,3]]
// Output: 0

// #include<bits/stdc++.h>
// using namespace std;

// int scheduleCourse(vector<vector<int>>& courses) {
//         // Sort courses by their end time (lastDay)
//         sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
//             if (a[1] == b[1]) return a[0] < b[0];
//             return a[1] < b[1];
//         });

//         priority_queue<int> pq; // max-heap
//         int time = 0;

//         for (auto& course : courses) {
//             int duration = course[0], lastDay = course[1];

//             // Only consider if course can be completed before its deadline
//             if (duration <= lastDay) {
//                 if (time + duration <= lastDay) {
//                     pq.push(duration);
//                     time += duration;
//                 } else if (!pq.empty() && pq.top() > duration) {
//                     // Replace the longest course with this shorter one
//                     time -= pq.top();
//                     pq.pop();
//                     pq.push(duration);
//                     time += duration;
//                 }
//             }
//         }
//         return pq.size();
//     }
// int main(){

//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> courses(n,vector<int>(m));

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin >> courses[i][j];
//         }
//     }

//     cout << "Maximum no of courses that can be taken are: " << scheduleCourse(courses);
//     return 0;

// }