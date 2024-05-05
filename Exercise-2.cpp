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
        void Display();
};
TreeNode::TreeNode(){
    data = nullptr;
    left = nullptr;
    right = nullptr;
}
TreeNode::TreeNode(int* val){
    data = val;
    left = nullptr;
    right = nullptr;
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
void TreeNode::Display(){
    if(data!=nullptr){
        cout << "Data is : " << *data ;
        if(left!=nullptr){
            cout << " | Left child is : " << *left->GetData();
        }
        if(right != nullptr){
            cout << " | Right child is : " << *right->GetData();
        }
    }
    cout << endl;
}
class Tree{
    private:
        TreeNode* root;
    public:
        Tree();
        void InsertNode(int* info);
        void Display();
        TreeNode* GetRoot();
        void Display(TreeNode* node);
};

Tree::Tree(){
    root = nullptr;
}
TreeNode* Tree::GetRoot(){
    return root;
}
void Tree::InsertNode(int* info){
    TreeNode* newNode = new TreeNode(info);
    
    if(root == nullptr){
        root = newNode;
    }
    else{
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        while(current != nullptr){
            parent = current;
            if(*(newNode->GetData()) < *(current->GetData())){
                current = current->GetLeft();
            }
            else{
                current = current->GetRight();
            }
        }
        if(*(newNode->GetData()) < *(parent->GetData())){
            parent->SetLeft(newNode);
        }
        else{
            parent->SetRight(newNode);
        }
    }
}

void Tree::Display(){
    cout << "<-------------Displaying Tree------------->" << endl;
    Display(root);
}
void Tree::Display(TreeNode* node){
    if(node!=nullptr){
        node->Display();
        Display(node->GetLeft());
        Display(node->GetRight());
    }
}
void PreOrder(TreeNode* root){
    if(root!=nullptr){
        cout << *(root->GetData()) << " " ;
        PreOrder(root->GetLeft());
        PreOrder(root->GetRight());
    }
}
void PostOrder(TreeNode* root){
    if(root!=nullptr){
        PostOrder(root->GetLeft());
        PostOrder(root->GetRight());
        cout << *(root->GetData()) << " ";
    }

}
void InOrder(TreeNode* root){
    if(root!= nullptr){
        InOrder(root->GetLeft());
        cout << *(root->GetData()) << " ";
        InOrder(root->GetRight());
    }
}

int main(){
    
}
