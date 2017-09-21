#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
void Inorder(node *root) {
   int visited[112345]={};
    vector<node *> stack;
    node * c=root;
    stack.push_back(c);
    
    while(!stack.empty())
        {
        node * lc = stack.back()->left;
        if(lc && visited[lc->data]==0)
            stack.push_back(lc);
        else {
            c=stack.back();
            visited[c->data]=1;
            cout<<c->data<<" ";
            stack.pop_back();
            if(c->right&&visited[c->right->data]==0)
                stack.push_back(c->right);
            else {
                if(c->right)
                    cout<<"\nVisited"<<c->right->data;
                else cout<<"\n"<<c->data<<" has no right";
            }
            
        }
    }
    

}
