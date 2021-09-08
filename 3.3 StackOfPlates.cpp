#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class SetOfStacks{
private:
    vector<stack<int> *> stacks;

public: 
    int capacity;
    SetOfStacks(int cap){
        capacity = cap;
        stack<int> * s = new stack<int>();
        stacks.push_back(s);
    }
    void push(int data){
        if (stacks.back()->size() < capacity){
            stacks.back()->push(data);
        }
        else{
            stack<int> * s = new stack<int>();
            s->push(data);
            stacks.push_back(s);
        }
    }
    int pop(){
        int data = stacks.back()->top();
        stacks.back()->pop();
        if (stacks.back()->empty() && stacks.size() > 1)
        {
            stacks.pop_back();
        }
        return data;
    }
    int size(){
        return stacks.size();
    }

    int popAt(int index){
        int data = stacks.at(index)->top();
        stacks.at(index)->pop();
        return data;
    }
};


int main(){
    int cap;
    cout << "Enter a capacity for set of stacks:  ";
    cin >> cap;
    SetOfStacks * ss = new SetOfStacks(cap);

    for (int i = 0; i < 9; i++)
    {
        ss->push(i);
        cout << " @> push size: " << ss->size() << endl;
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     cout << ss->pop() << endl;
    //     cout << " @> pop size: " << ss->size() << endl;
    // }
    
    cout << ss->popAt(2) << endl;
    

}