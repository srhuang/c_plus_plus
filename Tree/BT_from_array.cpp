/*****************************************************************
Name    :BT_from_array
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20190927 Initial Version
*****************************************************************/
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
/*==============================================================*/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree{
private:
    void LevelorderConstruct(stringstream &ss);
public:
    TreeNode *root;
    BinaryTree(const char *str);

};

BinaryTree::BinaryTree(const char *str)
{
    stringstream ss;
    ss << str;

    root = new TreeNode;
    ss >> root->val;

    LevelorderConstruct(ss);
}

void BinaryTree::LevelorderConstruct(stringstream &ss)
{
    queue<TreeNode*> q;
    TreeNode *current = root;
    string input;

    while(ss >> input){
        //cout << "input=" << input << endl;

        //handle the left child
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->left = newNode;
            q.push(newNode);
        }

        if(!(ss >> input)){
            break;
        }
        
        if(input.compare("x")){
            TreeNode *newNode = new TreeNode(stoi(input));
            current->right = newNode;
            q.push(newNode);
        }

        current = q.front();
        q.pop();
    }
}

int main(int argc, char const *argv[]){
    const char *input = "1 2 3 x x 4 5 6 7";
    BinaryTree BT(input);

    TreeNode *temp = BT.root;
    cout << "test : " << temp->val << endl;

    return 0;
}
/*==============================================================*/