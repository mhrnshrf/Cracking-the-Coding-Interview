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


void RemoveDups(LinkedList * list){
    Node * it1 = list->head;
    Node * it2 = list->head->next;
    Node * temp;
    while (it1 != NULL && it1->next != NULL) 
    {
        if (it1->value == it2->value)
        {
            temp = it2->next;
            list->remove(it2);
            it2 = temp;
        }
        else
        {
            it2 = it2->next;
        }

        if(it2 == NULL)
        {
            it1 = it1->next;
            if (it1 != NULL)
            {
                it2 = it1->next;
            }
        }
    }
}

int main(){
    int val;
    int size;
    cout << "Enter a size for linked list: ";
    cin >> size;
    
    LinkedList * list = new LinkedList();
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number: ";
        cin >> val;
        Node * n = new Node(val);
        list->append(n);
    }
    
    list->print();

    // test remove item:
    // Node * it = list->head;
    // for (int i = 0; i < size; i++)
    // {
    //     if (i == size-1)
    //     {
    //         list->remove(it);
    //     }
        
    //     it = it->next;
    // }
    
    // cout << "After remove..." << endl;
    // list->print();

    // Node * af = new Node(6);
    // list->append(af);
    // list->print();

    RemoveDups(list);
    cout << "After remove dups..." << endl;
    list->print();


   

}