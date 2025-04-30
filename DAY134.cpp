// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    //adjacency matrix
    //undirected unweighted graph
    // int vertex,edges;
    // cin>>vertex>>edges;
    // vector<vector<bool>>adjmat(vertex,vector<bool>(vertex,0));
    // int u,v;
    // for(int i=0;i<edges;i++){
    //     cin>>u>>v;
    //     adjmat[u][v]=1;
    //     adjmat[v][u]=1;
    // }
    // for(int i=0;i<vertex;i++){
    //     for(int j=0;j<vertex;j++){
    //         cout<<adjmat[i][j];
    //     }
    //     cout<<endl;
    // }
     //adjacency matrix
     //undirected weighted graph
    // int vertex,edges;
    // cin>>vertex>>edges;
    // vector<vector<int>>adjmat(vertex,vector<int>(vertex,0));
    // int u,v,weight;
    // for(int i=0;i<edges;i++){
    //     cin>>u>>v>>weight;
    //     adjmat[u][v]=weight;
    //     adjmat[v][u]=weight;
    // }
    // for(int i=0;i<vertex;i++){
    //     for(int j=0;j<vertex;j++){
    //         cout<<adjmat[i][j];
    //     }
    //     cout<<endl;
    // }
    //adjacency matrix
    //directed weighted graph
    // int vertex,edges;
    // cin>>vertex>>edges;
    // vector<vector<int>>adjmat(vertex,vector<int>(vertex,0));
    // int u,v,weight;
    // for(int i=0;i<edges;i++){
    //     cin>>u>>v>>weight;
    //     adjmat[u][v]=weight;
    //     // adjmat[v][u]=weight;
    // }
    // for(int i=0;i<vertex;i++){
    //     for(int j=0;j<vertex;j++){
    //         cout<<adjmat[i][j];
    //     }
    //     cout<<endl;
    // }

    // //ADJACENCY LIST
    // // undireted unweighted
    // int vertex,edges;
    // cin>>vertex>>edges;
    // vector<int>adjlist[vertex];
    // int u,v;
    // for(int i=0;i<edges;i++){
    //     cin>>u>>v;
    //     adjlist[u].push_back(1);
    //     adjlist[v].push_back(1);
    // }
    // for(int i=0;i<vertex;i++){
    //     cout<<i<<"->";
    //     for(int j=0;j<adjlist[i].size();j++){
    //         cout<<adjlist[i][j]<<" ";
    //     }cout<<endl;
    // }

    //ADJACENCY LIST
    // undireted weighted
    int vertex,edges;
    cin>>vertex>>edges;
    vector<pair<int,int>>adjlist[vertex];
    int u,v,weight;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>weight;
        adjlist[u].push_back(make_pair(v,weight));
        adjlist[v].push_back(make_pair(u,weight));
    }
    for(int i=0;i<vertex;i++){
        cout<<i<<"->";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j].first<<" "<<adjlist[i][j].second;
        }cout<<endl;
    }
    // 5 6
    // 0 1 10
    // 0 2 5
    // 1 2 9
    // 1 3 85
    // 3 4 11
    // 2 4 5
    
    return 0;
}
