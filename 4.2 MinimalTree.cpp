#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode{
    public:
        int id;
        bool marked = false;
        TreeNode * left;
        TreeNode * right;
        TreeNode(int i){
            id = i;
            left = NULL;
            right = NULL;
        }
};


void visit(TreeNode * n){
    cout << "visit " << n->id << endl;
}

void BFS(TreeNode * root){
    queue<TreeNode*> * Q = new queue<TreeNode*>();

    root->marked = true;
    Q->push(root);


    while (!Q->empty())
    {
        TreeNode * n = Q->front();
        visit(n);
        Q->pop();


        for (int i = 0; i < 2; i++)
        {
            TreeNode * m;
            if (i % 2 == 0)
            {
                m = n->left;
            }
            else
            {
                m = n->right;
            }
            
            if (m != NULL && !m->marked)
            {
                m->marked = true;
                Q->push(m);
            }
        }
    }

}


TreeNode * MinimalTree(vector<int> * arr, int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    TreeNode * n = new TreeNode(arr->at(mid)); 
    n->left = MinimalTree(arr, start, mid-1);
    n->right = MinimalTree(arr, mid+1, end);
    return n;
}

int main(){
    int size;
    vector<int> * arr = new vector<int>();

    cout << "Enter the array size: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        arr->push_back(num);
    }

    for (int i = 0; i < arr->size(); i++)
    {
        cout << arr->at(i) << endl;
    }
    

    TreeNode * root = MinimalTree(arr, 0, size-1);

    cout << "Running BFS..." << endl;
    BFS(root);
}