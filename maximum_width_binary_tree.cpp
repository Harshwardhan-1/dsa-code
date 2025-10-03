// Program to find maximum width of binary tree
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node*buildTree(vector<int>arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    Node*root=new Node(arr[idx]);
    root->left=buildTree(arr);
    root->right=buildTree(arr);
    return root;
}
int maximum(Node*root){
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int maxi=0;
    while(q.size()>0){
        int currSize=q.size();
        int st=q.front().second;
        int end=q.back().second;
        maxi=max(maxi,end-st+1);
        for(int i=0;i<currSize;i++){
            auto curr=q.front();
            q.pop();
            if(curr.first->left){
                q.push({curr.first->left,curr.second*2+1});
            }
            if(curr.first->right){
                q.push({curr.first->right,curr.second*2+2});
            }
        }
    }
    return maxi;
}
int main(){
    vector<int>arr={1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
    Node*root=buildTree(arr);
   cout<<maximum(root);
}
