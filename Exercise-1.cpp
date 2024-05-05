#include<iostream>
using namespace std;
class TreeNode{
    private:
        int* data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode();
        TreeNode(int* val);
        void SetData(int* val);
        void SetLeft(TreeNode* left);
        void SetRight(TreeNode* right);
        int* GetData();
        TreeNode* GetLeft();
        TreeNode* GetRight();
        bool IsLeaf();
};
TreeNode::TreeNode(){
    left = nullptr;
    right = nullptr;
}
TreeNode::TreeNode(int* val){
    data = val;
}
void TreeNode::SetData(int* val){
    data = val;
}
void TreeNode::SetLeft(TreeNode* left){
    this->left = left;
}
void TreeNode::SetRight(TreeNode* right){
    this->right = right;
}
int* TreeNode::GetData(){
    return data;
}
TreeNode* TreeNode::GetRight(){
    return right;
}
TreeNode* TreeNode::GetLeft(){
    return left;
}
bool TreeNode::IsLeaf(){
    if(this->left == nullptr && this->right == nullptr){
        return true;
    }
    return false;
}
int main(){

}