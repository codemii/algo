
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// (1,2), (2,4), (4,6), (5,6), (3,5), (1,3), (2,5), (4,5)
int v, e, n=9;
vector<vector<int>> adj= vector<vector<int>>(n);
    
void addEdge(int a, int b){
    cout<<"Inside add Edge and size is : "<<adj.size()<<endl;
    
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void printGraph(){
    for(int i=1; i<adj.size(); i++){
        cout<<i<<" : ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

}

std::queue<int> q;
vector<int> visited(n,0);

//void printQueue(){
//    for(int i=0; i<q)){
//        cout<<i<<" ";
//    }    
//    cout<<endl;
//}

void printVisitedVector(){
    for(auto i : visited){
        cout<<i<<" ";
    }    
    cout<<endl;
}

void BFS(){
    
    q.push(1);
    visited[1]=1;
    //for(auto i : visited){
    //    cout<<i<<endl;
    //}
    int curr;
    while(!q.empty()){
  //      printQueue();
      //  printVisitedVector();
        //cout<<"Inside while"<<endl;
        curr = q.front();
        cout<<curr<<" ";
        for(auto i : adj[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
        q.pop();
    }
    cout<<endl;
}

stack<int> s;
vector<int> visitDFS(n,0);
void DFS(){
    s.push(1);
    visitDFS[1]=1;
    int curr;
    while(!s.empty()){
        curr = s.top();
        s.pop();
        cout<<curr<<" ";
        for(auto i : adj[curr]){
            if(!visitDFS[i]){
                visitDFS[i]=1;
                s.push(i);
            }
        }
    }
    cout<<endl;
}

vector<bool> visitDFSRec(n,false);
void DFSRec(int start){
    visitDFSRec[start]=true;
    cout<<start<<" ";
    for(auto i : adj[start]){
        if(!visitDFSRec[i]){
            DFSRec(i);
        }
    }
}

int main() {

    std::cout << "Start of the DFS and BFS" << endl;
    //int v, e, n=10;
    //vector<vector<int>> adj = vector<vector<int>>(n);
    
    //cout<<endl<<adj.size()<<endl;
    //cout<<adj[0].size()<<endl;
    
    printGraph();
    cout<<"Adding Edges"<<endl;
    
    addEdge(1,2);
    addEdge(2,4);
    addEdge(4,6);
    addEdge(5,6);
    addEdge(3,5);
    addEdge(1,3);
    addEdge(2,5);
    addEdge(4,5);
    
    printGraph();
    
    cout<<"BFS : ";
    BFS();
    cout<<endl;
    cout<<"DFS : ";
    DFS();
    cout<<endl;
    cout<<"DFS Recursive : ";
    DFSRec(1);
    cout<<endl;
    return 0;
}
