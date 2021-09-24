#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct Edge{
    int src, dest;
};

class Node{
    public:
        int id;
        bool marked;
        vector<Node *> * adj = new vector<Node *>();
        Node(int i){
            id = i;
            marked = false;
        } 
};

class Graph{
    public:
        vector<vector<int>> adjList;
        vector<Node *> * nodes = new vector<Node *>();
        int N;
        
        Graph(vector<Edge> edges, int n){
            N = n;

            adjList.resize(n);
            // prepare node representation
            for (int i = 0; i < N; i++)
            {
                Node * node = new Node(i);
                nodes->push_back(node);
            }
            
            for (auto& it : edges)
            {
                adjList[it.src].push_back(it.dest);
                Node * s = nodes->at(it.src);
                Node * d = nodes->at(it.dest);
                s->adj->push_back(d);

            }          

        }
        void print(){
            cout << "Print adj list:" << endl;
            for (int u = 0; u < N; u++)
            {
                cout << u << " -> " ;
                for (int v : adjList[u])
                {
                    cout  << v << " ";
                }
                cout << endl;
            }
        }
        void printNodes(){
            cout << "Print nodes:" << endl;
            for (int i = 0; i < nodes->size(); i++)
            {
                Node * n = nodes->at(i);
                string mark = n->marked?" [marked] " : " [      ] ";
                cout << n->id << mark << "-> ";
                for (int j = 0;  j < n->adj->size(); j++)
                {
                    cout << n->adj->at(j)->id << " ";
                }
                cout << endl;
            }
            
        }
        void resetMark(){
            for (int i = 0; i < nodes->size(); i++)
            {
                nodes->at(i)->marked = false;
            }
        }
};

void visit(Node * n){
    cout << "visit " << n->id << endl;
}

void BFS(Graph * g, int start){
    g->resetMark();
    queue<Node*> * Q = new queue<Node*>();

    Node* n = g->nodes->at(start);
    n->marked = true;
    Q->push(n);

    while (!Q->empty())
    {
        Node * n = Q->front();
        visit(n);
        Q->pop();

        for (int i = 0; i < n->adj->size(); i++)
        {
            Node * m = n->adj->at(i);
            if (!m->marked)
            {
                m->marked = true;
                Q->push(m);
            }
        }
    }
}


void DFS(Graph * g, int start){
    Node * n = g->nodes->at(start); 
    visit(n);
    n->marked = true;

    for (int i = 0; i < n->adj->size(); i++)
    {
        Node * m = n->adj->at(i);
        if (!m->marked)
        {
            DFS(g, m->id);
        }
    }
    

}

// implemented by bfs
bool RouteBetweenNodes(Graph * g, int start, int end){
    g->resetMark();
    queue<Node*> * Q = new queue<Node*>();

    Node* n = g->nodes->at(start);
    n->marked = true;
    Q->push(n);

    while (!Q->empty())
    {
        Node * n = Q->front();
        visit(n);
        Q->pop();

        for (int i = 0; i < n->adj->size(); i++)
        {
            Node * m = n->adj->at(i);
            if (!m->marked)
            {
                m->marked = true;
                Q->push(m);
                if (m->id == end)
                {
                    return true;
                }
                
            }
        }
    }
    return false;

}



int main(){
    vector<Edge> edges =
    {
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
        { 2, 3 }, { 3, 4 }, { 3, 5 },  {1, 4}, {4,6}
    };

    int n = 7;
    Graph* g = new Graph(edges, n);
    g->print();
    g->printNodes();

    cout << "\nRunning BFS..." << endl;
    BFS(g, 0);
    g->printNodes();

    g->resetMark();
    cout << "\nRunning DFS..." << endl;
    DFS(g, 0);
    g->printNodes();

    int node1, node2;
    cout << "Enter a node in  0 ... " << n-1 << ": " ;
    cin >> node1;
    cout << "Enter another node in  0 ... " << n-1 << ": " ;
    cin >> node2;
    cout << endl;

    bool isThere = RouteBetweenNodes(g, node1, node2);

    string msg = isThere? "There is " : "There is not ";

    cout << msg << "a route between the nodes" << endl;

}