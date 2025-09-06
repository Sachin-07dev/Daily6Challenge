
// Array/String Question:
// Two Sum: Given an array of integers, return indices of the two numbers that add up to a specific target.
// naive approach

// #include<bits/stdc++.h>
// using namespace std;

// pair<int,int> findIndex(vector<int> &arr, int n,int target){

//     for(int i=0;i<n;i++){
//         int val = target-arr[i];

//         for(int j=i+1;j<n;j++){
//             if(arr[j] == val){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }
// int main(){
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     int target;
//     cout << "Enter the target value: ";
//     cin >> target;

//     pair<int,int> ans =  findIndex(arr,n,target);
//     cout << ans.first << endl;
//     cout << ans.second;

//     return 0;
// }

// Stacks / Queues -->  Parenthesis Checker: Check if a given string of parentheses is balanced.

// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
// An input string is valid if:
//          1. Open brackets must be closed by the same type of brackets.
//          2. Open brackets must be closed in the correct order.
// Examples :

// Input: s = "[{()}]"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "[()()]{}"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "([]"
// Output: false
// Explanation: The expression is not balanced as there is a missing ')' at the end.
// Input: s = "([{]})"
// Output: false
// Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.

// #include<bits/stdc++.h>
// using namespace std;

// bool isValid(string &str){
//     stack<char> st;
//     int n = str.size();

//     if(n==1) return false;
//     for(int i=0;i<n;i++){
//         if(str[i] == '{' || str[i] == '[' || str[i] == '('){
//             st.push(str[i]);
//         }else{
//             if(st.empty()) return false;
//             else{
//                 char top = st.top();
//                 if(str[i] == '}' && top == '{' ||
//                    str[i] == ']' && top ==  '[' ||
//                    str[i] == ')' && top == '(' ){
//                     st.pop();
//                 }else{
//                     return false;
//                 }
//             }
//         }
//     }
//     return st.empty();
// }
// int main(){
    
//     string str;
//     cout << "Enter the string: ";
//     cin >> str;

//     if(isValid(str)){
//         cout << "True";
//     }else{
//         cout << "False";
//     }

//     return 0;
// }

// Topic-3 : LinkedList

// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again 
// by continuously following the next pointer. Internally, pos is used to denote the index of the 
// node that tails next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

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

// Node* insert(Node* &head, int data){
//     Node* newNode = new Node(data);
//     if(head == NULL){
//         return newNode;
//     }

//     Node* temp = head;
//     while(temp->next != nullptr){
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     return head;
// }

// bool hasCycleUsingSet(Node* &head){
//     set<Node* > s;

//     Node* curr = head;
//     while(curr != NULL){
//         if(s.find(curr) != s.end()){
//             return true;
//         }
//         s.insert(curr);
//         curr = curr->next;
//     }
//     return false;
// }

// bool hasCycleUsingFloyd(Node* &head){
//     if(!head && !head->next)
//         return head;
    
//     Node* slow = head;
//     Node* fast = head;

//     while(fast && fast->next){
//         slow = slow->next;
//         fast = fast->next->next;
//         if(fast == slow) return true;
//     }
//     return false;
// }
// void printList(Node* head, int k){
//     int cnt = 0;
//     while(head && cnt < k){
//         cout << head->data << "->";
//         head = head->next;
//         cnt++;
//     }cout << "null" << endl;
// }
// int main(){

//     Node* head = NULL;

//     int data;
//     int k= 0;
//     while(cin >> data && data != -1){
//         head = insert(head, data);
//         k++;
//     }
//     printList(head,k);
//     int pos;
//     cout << "Enter pos to create a cylce or (-1 for no cycle)";
//     cin >> pos;

//     if (pos != -1) {
//         Node* cycleNode = head;
//         for (int i = 0; i < pos && cycleNode; i++) {
//             cycleNode = cycleNode->next;
//         }
//         Node* temp = head;
//         while(temp->next != nullptr){
//             temp = temp->next;
//         }
//         if (cycleNode) temp->next = cycleNode;
//     }

//     printList(head,k);


//     //Cycle or loop in list can be detected by approaches
//     //First one is using set;
//     if(hasCycleUsingSet(head)){
//         cout << "Cylcle is present in the list.";
//     }else{
//         cout << "Cylcle is not present in the list(Set).";
//     }
//     cout << endl;
    
//     if(hasCycleUsingFloyd(head)){
//         cout << "Cylcle is present in the list.";
//     }else{
//         cout << "Cylcle is not present in the list(Floyd).";
//     }
//     return 0;
// }

// Topic4: Trees:
// question : Find the height  of the tree

// Given a binary tree, find its height.
// The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.
// Examples:
// Input: root[] = [12, 8, 18, 5, 11] 
// Output: 2
// Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.

// #include<bits/stdc++.h>
// using namespace std;

// class Node {
//     public:
//         int data;
//         Node* left;
//         Node* right;

//         Node(int val) {
//             data = val;
//             left = right = NULL;
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
//  int solve(Node* node){
        
//     if(node == nullptr){
//         return -1;
//     }
    
//     int left = solve(node->left);
//     int right = solve(node->right);
    
//     return max(left,right)+1;
// }
// void inOrder(Node* &root){

//    if(root){
//        inOrder(root->left);
//        cout << root->data << " ";
//        inOrder(root->right); 
//    }
// }
// int main(){

//     Node* root = NULL;
//     root = buildTree();

//     inOrder(root);
//     cout << endl;
//     cout << "Height of tree is: " << solve(root);

//     return 0;
// }

// Topic: DP:Climbing Stairs: How many distinct ways to climb to the top of a staircase of n steps when you can take either 1 or 2 steps at a time?

// #include<bits/stdc++.h>
// using namespace std;


// int countWays(int n,vector<int> dp){

//     if(n==1) return 1;
//     if(n==2) return 2;

//     if(dp[n] != -1) return dp[n];

//     return dp[n] = countWays(n-1,dp) + countWays(n-2,dp);
// }
// int main(){

//     int n;
//     cin >> n;
//     vector<int> dp(n,-1);
//     cout << countWays(n,dp);

//     return 0;
// }