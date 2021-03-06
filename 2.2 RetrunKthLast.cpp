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

Node * ReturnKthLast(LinkedList * list, int k){
    Node * it = list->head;
    int count = 0;
    int size = 0;

    while (it != NULL)
    {
        size++;
        it = it->next;
    }

    // cout << "size: " << size << endl;
    
    it = list->head;
    while (it != NULL)
    {
        if (count == (size - k))
        {
            return it;
        }

        count++;
        it = it->next;
    }


    
    return NULL;
    
}

int main(){
    int val;
    int size;
    int k;
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

    cout << "Enter k: ";
    cin >> k;

    cout << "Element @ " << k << ": " << ReturnKthLast(list, k)->value << endl;

 
   


   

}