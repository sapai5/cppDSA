/*
* Graph Creator by Sahil Pai
* Got some help from Uno and Avanish on this regarding adjecncy tables and using iterators
* Date: 6/6/23
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class node {
    char* name;
    vector<node*> connect;
public:
    char* getName();
    void setName(char*);
    vector<node*> getVect();
    void vectPush(node* toPush) {
        connect.push_back(toPush);
    }
    void vectErase(vector<node*>::const_iterator it) { //https://stackoverflow.com/questions/64996845/remove-elements-from-adjacency-list-c
        connect.erase(it);
    }
};

char* node::getName() {
    return name;
}

void node::setName(char* newname) {
    name = newname;
}

vector<node*> node::getVect() {
    return connect;
}


struct edge {
    node* firstp = NULL;
    node* secondp = NULL;
    char* weight;
};

//prototypes
void addVert(vector<node*>&);
void delVert(vector<node*>&, vector<edge*>&);
void addEdge(vector<node*>&, vector<edge*>&);
vector<node*> delEdge(vector<node*>&, vector<edge*>&);
void print(vector<node*>);
void printAllConn(vector<node*>);
void printSingleConn(vector<node*>, vector<node*>::const_iterator);
void printEdgeCont(vector<edge*>);


int main() {
    vector<node*> graph = vector<node*>(); //vector for nodes
    vector<edge*> edgecont = vector<edge*>(); //vector for edges
    bool run = true;
    cout << "Graph Creator: " << endl;
    while (run == true) { //will continue running till quit
        char* input = new char[80]; //takes in input
        cout << "Enter your choice: (addv, removev, adde, removee, print, quit)" << endl;
        cin.getline(input, 80);
        if (strcmp(input, "addv") == 0) {
            addVert(graph); //calls add vertice
        }
        else if (strcmp(input, "removev") == 0) {
            delVert(graph, edgecont); //calls delete vert
        }
        else if (strcmp(input, "adde") == 0) {
            addEdge(graph, edgecont); //calls add edge
        }
        else if (strcmp(input, "removee") == 0) {
            graph = delEdge(graph, edgecont); //calls delete add 
        }
        else if (strcmp(input, "print") == 0) {
            print(graph); //prints adjacency
            printAllConn(graph);
            printEdgeCont(edgecont);
        }
        else if (strcmp(input, "quit") == 0) {
            run = false;
        }
    }
}

void addVert(vector<node*>& graph) {
    cout << "Please input a name for the node" << endl;
    node* newnode = new node(); 
    char* input = new char[80];
    cin.getline(input, 80); 
    newnode->setName(input); 
    graph.push_back(newnode); //add to vector
}

void delVert(vector<node*>& graph, vector<edge*>& edgecont) {
    vector<node*>::iterator i;
    vector<node*>::iterator j;
    vector<edge*>::iterator k;
    if (edgecont.empty() == true) {
        cout << "\n";
    }
    cout << "Please input the name of the node to delete" << endl;
    node* newnode = new node();
    char* input = new char[80];
    cin.getline(input, 80);
    int count = 0;
    auto it = graph.begin();  // Iterator for traversing the graph
    //int count = 0;  // Counter for keeping track of the current position

    // Traverse the graph
    while (it != graph.end()) {
        if (*it && strcmp((*it)->getName(), input) == 0) {
            // If the current node matches the input name, erase it from the graph
            it = graph.erase(it);
            break;  // Exit the loop after erasing the node
        }
        ++it;  // Move to the next node
        ++count;  // Increment the position counter
    }

    cout << count;  // Output the final count after traversal

    for (i = graph.begin(); i != graph.end(); ++i) {
        vector<node*> connect = (*i)->getVect();
        for (j = connect.begin(); j != connect.end(); ++j) {
            if ((*j) != NULL && strcmp((*j)->getName(), input) == 0) {
                connect.erase(j);
            }
        }
    }
    // Check if edgecont is not empty
    if (!edgecont.empty()) {
        // Traverse each element in the edgecont vector
        for (auto k = edgecont.begin(); k != edgecont.end(); ++k) {
            // Check if the firstp pointer is not NULL
            if ((*k)->firstp->getName() != nullptr) {
                // Check if either the firstp or secondp node's name matches the input
                if (strcmp((*k)->firstp->getName(), input) == 0 || strcmp((*k)->secondp->getName(), input) == 0) {
                    // Erase the current element from the edgecont vector
                    k = edgecont.erase(k);
                    // The erase function returns an iterator to the next element, so we don't need to increment k
                }
            }
        }
    }

}

void addEdge(vector<node*>& graph, vector<edge*>& edgecont) {
    vector<node*>::const_iterator i; //iterators for the node vector
    vector<node*>::const_iterator j;
    edge* newe = new edge(); 
    cout << "Please enter the first node" << endl;
    char* firstnode = new char[80];
    cin.getline(firstnode, 80); 
    bool flag = false;
    for (i = graph.begin(); i != graph.end(); ++i) { //runs thru node vector
        if (strcmp((*i)->getName(), firstnode) == 0) { 
            newe->firstp = (*i); //records node which match input
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "The node you entered does not exist" << endl;
        return;
    }

    cout << "Please enter the second node" << endl;
    char* secondnode = new char[80];
    cin.getline(secondnode, 80);
    flag = false;
    for (j = graph.begin(); j != graph.end(); ++j) {
        if (strcmp((*j)->getName(), secondnode) == 0) {
            newe->secondp = (*j);
            (*i)->vectPush(*j); //Add as a connection
            flag = true;
        }
    }
    if (flag == false) { 
        cout << "The node you entered does not exist" << endl;
        return;
    }

    cout << "Please enter the length" << endl; //for length
    char* weightval = new char[80];
    cin.getline(weightval, 80);
    newe->weight = weightval; //puts into the edge
    edgecont.push_back(newe); //puts edge into vector
}

vector<node*> delEdge(vector<node*>& graph, vector<edge*>& edgecont) {
    vector<edge*>::const_iterator k;
    vector<node*>::const_iterator i;
    vector<node*>::const_iterator j;
    cout << "Please enter the first node" << endl;
    char* firstnode = new char[80];
    cin.getline(firstnode, 80);
    cout << "Please enter the second node" << endl;
    char* secondnode = new char[80];
    cin.getline(secondnode, 80);
    for (k = edgecont.begin(); k != edgecont.end(); ++k) {
        if ((*k)->firstp->getName() != NULL) {
            if (strcmp((*k)->firstp->getName(), firstnode) == 0 || strcmp((*k)->secondp->getName(), secondnode) == 0) {
                edgecont.erase(k);
                break;
            }
        }
    }
    cout << "I" << endl;
    for (i = graph.begin(); i != graph.end(); ++i) {
        if (strcmp((*i)->getName(), firstnode) == 0) {
            vector<node*> connect = (*i)->getVect();
            cout << "a" << endl;
            for (j = connect.begin(); j != connect.end(); ++j) {
                cout << (*j)->getName();
                if ((*j) != NULL && strcmp((*j)->getName(), secondnode) == 0) {
                    connect.erase(j);
                    break;
                }
            }
        }
    }
    return graph;

}

void print(vector<node*> graph) {
    vector<node*>::const_iterator i;//all iterators needed for adjacency table -- help from Uno with this
    vector<node*>::const_iterator j;
    vector<node*>::const_iterator k;
    vector<node*>::const_iterator l;
    cout << "  ";
    for (i = graph.begin(); i != graph.end(); ++i) {
        cout << (*i)->getName() << " "; //prints all node names at top
    }
    cout << endl;
    for (i = graph.begin(); i != graph.end(); ++i) { 
        cout << (*i)->getName() << " ";
        for (j = graph.begin(); j != graph.end(); ++j) {
            vector<node*> connect = (*j)->getVect(); 
            bool flag = false;
            for (k = connect.begin(); k != connect.end(); ++k) {//for connected vector
                for (l = graph.begin(); l != graph.end(); ++l) {
                    if ((*l) == (*k) && (*i) == (*l)) {
                        cout << "T"; //indicates there is connection
                        flag = true;
                    }
                }
            }
            if (flag == false) {
                cout << "F"; //indicates no connection
            }
            cout << " ";
        }
        cout << endl;
    }

}

void printAllConn(vector<node*> graph) {
    vector<node*>::const_iterator i;
    vector<node*>::const_iterator k;

    for (i = graph.begin(); i != graph.end(); ++i) {
        vector<node*> connect = (*i)->getVect();
        printSingleConn(graph, i);
    }
}


void printSingleConn(vector<node*> graph, vector<node*>::const_iterator it)
{
    vector<node*>::const_iterator j; //iterator for node vector
    int connctr = 0;

    if ((*it) == NULL) //if passed in iterator null
    {
        cout << "Error - invalid iterator passed to printSingleConn" << endl;
        exit(-1);
    }
    cout << "connections for node =  ";
    cout << (*it)->getName() << " ";
    cout << endl;

    vector<node*> connect = (*it)->getVect(); 

    for (j = connect.begin(); j != connect.end(); ++j) 
    { 
        connctr++;
        cout << "  connects with " << (*j)->getName() << " " << endl;
    }
    if (connctr == 0)
        cout << "  no connection entries for this node" << endl;
}

void printEdgeCont(vector<edge*> edgecont)
{
    vector<edge*>::iterator k; //iterator for edge vector

    for (k = edgecont.begin(); k != edgecont.end(); ++k) { //runs thru edge vector
        if ((*k) == NULL) //if iterator is null
        { 
            cout << "No Edge entries" << endl;
            break;
        }
        //print all data on edge
        cout << "Edge entry: " << endl;
        cout << "  firstnode = " << (*k)->firstp->getName() << endl;
        cout << "  secondnode = " << (*k)->secondp->getName() << endl;
        cout << "  weight = " << (*k)->weight << endl;
    }
}
