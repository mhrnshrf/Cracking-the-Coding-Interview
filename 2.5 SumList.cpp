#include <iostream>

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
        cout << "\nLinked list items:" << endl;
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


LinkedList *  SumList(LinkedList * l1, LinkedList * l2){
    Node * it1 = l1->head;
    Node * it2 = l2->head;
    LinkedList * sum = new LinkedList();
    int residue = 0;

    while (it1 != NULL || it2 != NULL)
    {
        int op1 = (it1 != NULL) ? it1->value : 0;
        int op2 = (it2 != NULL) ? it2->value : 0;

        int val = op1 + op2 + residue;
        residue = (val >= 10) ? 1 : 0; 
        Node * n = new Node(val % 10);
        sum->append(n);

        if (it1 != NULL)
        {
            it1 = it1->next;
        }
        if (it2 != NULL)
        {
            it2 = it2->next;
        }
    }
    if (residue != 0)
    {
        Node * r = new Node(residue);
        sum->append(r);
    }
    
    return sum;
}


int main(){
    int val;
    int size;
    cout << "Enter a size for linked list: ";
    cin >> size;
    
    LinkedList * list1 = new LinkedList();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number: ";
        cin >> val;
        Node * n = new Node(val);
        list1->append(n);
    }


    cout << "Enter a size for linked list: ";
    cin >> size;
    
    LinkedList * list2 = new LinkedList();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number: ";
        cin >> val;
        Node * n = new Node(val);
        list2->append(n);
    }
    
    list1->print();
    list2->print();

    LinkedList * sum = SumList(list1, list2);
    
    sum->print();
}