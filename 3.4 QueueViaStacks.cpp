#include <iostream>
#include <stack>

using namespace std;

class MyQueue{

    private:
        stack<int> * stackTailTop;
        stack<int> * stackHeadTop;

    public:
        MyQueue(){
            stackTailTop = new stack<int>();
            stackHeadTop = new stack<int>();
        }
        void enqueue(int data){
            if (stackHeadTop->empty()){
                stackTailTop->push(data);
            }
            else
            {
                while (!stackHeadTop->empty())
                {
                    int item = stackHeadTop->top();
                    stackHeadTop->pop();
                    stackTailTop->push(item);
                }
                stackTailTop->push(data);
            }
        }
        int dequeue(){
            int data;
            if (stackTailTop->empty()){
                data = stackHeadTop->top();
                stackHeadTop->pop();
            }
            else
            {
                while (!stackTailTop->empty())
                {
                    int item = stackTailTop->top();
                    stackTailTop->pop();
                    stackHeadTop->push(item);
                }
                data = stackHeadTop->top();
                stackHeadTop->pop();
            }
            return data;
        }
        bool empty(){
            return stackTailTop->empty() && stackHeadTop->empty();
        }

};


int main(){

    MyQueue * queue = new MyQueue();

    for (int i = 0; i < 10; i++)
    {
        queue->enqueue(i);
    }
    
    cout << "Dequeueing queue one by one..." << endl;
    
    while (!queue->empty())
    {
        cout << queue->dequeue() << endl;
    }
    

}
