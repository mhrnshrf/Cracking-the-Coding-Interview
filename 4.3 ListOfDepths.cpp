#include <iostream>
#include <queue>

using namespace std;

class Node{
    public: Node * next = NULL;
    int value;

    public: Node(int v){
        value = v;
    }
};

class LinkedList{
    public: Node * head = NULL;
    // Node * tail = NULL;

    // public: LinkedList(){
        
    // }

    public: 
    void append(Node * n){

        Node * it = head;
        if (it == NULL)
        {
            head = n;
            return;
        }
        
        while(it->next != NULL)
        {
            it = it->next;
        }

        it->next = n;
    }

    void print(){
        Node * it = head;
        // cout << "Linked list items:" << endl;
        while (it != NULL)
        {
            cout << it->value << endl;
            it = it->next;
        }
        
    }

    void remove(Node * n){
        if (n == head)
        {
            head = head->next;
            free(n);
            return;
        }
        
        // Node * it = head->next;
        Node * it = head;
        while (it != NULL)
        {
            if (it->next == n)
            {
                it->next = n->next;
                free(n);
            }
            
            it = it->next;
        }
    }
    
    bool contain(int data){
        Node * it = head;
        while (it != NULL)
        {
            if (it->value == data)
            {
                return true;
            }
            
            it = it->next;
        }
        return false;
    }
};

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



vector<LinkedList * > * ListOfDepthsBFS(TreeNode * root){
    queue<TreeNode*> * Q = new queue<TreeNode*>();

    vector<LinkedList * > * arrOfList = new vector<LinkedList *>();

    root->marked = true;
    Q->push(root);

    TreeNode * prev = root;

    int level = 0;
    LinkedList * list = new LinkedList();
    arrOfList->push_back(list);
    
    while (!Q->empty())
    {
        TreeNode * n = Q->front();
        visit(n);
        Q->pop();

        Node * node = new Node(n->id);

        if (prev->left == NULL && prev->right == NULL)
        {
            prev = n;
        }
        


        if ((n == prev->left || n == prev->right) )
        {
            level++;
            prev = n;
            LinkedList * list = new LinkedList();
            arrOfList->push_back(list);
        }
        
        arrOfList->at(level)->append(node);


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

    return arrOfList;

}


void ListOfDepthsDFS(TreeNode * n, int level, vector<LinkedList * > * arrOfList){
    if (n == NULL)
    {
        return;
    }

    visit(n);
    n->marked = true;

    Node * node = new Node(n->id);

    if (arrOfList->size() == level)
    {
        LinkedList * list = new LinkedList();
        list->append(node);
        arrOfList->push_back(list);
    }
    else
    {
        arrOfList->at(level)->append(node);
    }
    
    ListOfDepthsDFS(n->left, level+1, arrOfList);
    ListOfDepthsDFS(n->right, level+1, arrOfList);

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

    TreeNode * root = MinimalTree(arr, 0, size-1);

    // vector<LinkedList *> * arrOfList1 = ListOfDepthsBFS(root);
    // cout << "ListOfDepths BFS:" << endl;
    // for (int i = 0; i < arrOfList1->size(); i++)
    // {
    //     cout << "level " << i << ":" << endl;
    //     arrOfList1->at(i)->print();
    // }

    vector<LinkedList *> * arrOfList2 = new vector<LinkedList *>();
    ListOfDepthsDFS(root, 0, arrOfList2);
    cout << "ListOfDepths DFS:" << endl;
    for (int i = 0; i < arrOfList2->size(); i++)
    {
        cout << "level " << i << ":" << endl;
        arrOfList2->at(i)->print();
    }
}