#include <bits/stdc++.h>
using namespace std;
 
string encodeTree(int node, int parent, vector< vector<int>> &adj){
    string code;
    vector<string>encodedChild;

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i] != parent){
            encodedChild.push_back(encodeTree(adj[node][i], node, adj));
        }
    }
    sort(encodedChild.begin(),encodedChild.end());

    code="0";
    for(int i=0;i<encodedChild.size();i++){
        code+=encodedChild[i];
    }
    code+="1";
    return code;
}
 
vector<int> getCenter( vector< vector<int>> &adj){    
    vector<int> centers, dist(adj.size(),0);
    vector<bool> visited( adj.size(), false);
    int maxDist=0;
    queue<int>  bfs;

    for(int i=0; i<adj.size(); i++){
        if(adj[i].size() == 1){
            bfs.push(i);
            visited[i] = true;
        }            
    } 
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                visited[adj[node][i]] = true;
                dist[adj[node][i]] = dist[node]+1;
                maxDist = max(maxDist, dist[adj[node][i]]);
                bfs.push(adj[node][i]);
            }
        }
    } 
    for(int i=0; i<adj.size(); i++){
        if(dist[i] == maxDist){
            centers.emplace_back(i);
        }
    }
    return centers;
}
 
void sol(){
    int n;
    cin>>n;
    vector< vector< int>> adjA(n), adjB(n);    
    for(int i=0; i<n-1; i++){
        int a,b;cin>>a>>b;
        adjA[ a-1].emplace_back( b-1);
        adjA[ b-1].emplace_back( a-1);
    }
    for(int i=0; i<n-1; i++){
        int a,b;cin>>a>>b;
        adjB[ a-1].emplace_back( b-1);
        adjB[ b-1].emplace_back( a-1);
    }    

    vector<int> centerA,centerB; 
    centerA = getCenter(adjA);
    centerB = getCenter(adjB); 

    string encodeA,encodeB;
    encodeA = encodeTree(centerA[0], -1, adjA);    

    for(int i=0; i<centerB.size() ; i++ ){
        encodeB = encodeTree(centerB[i], -1, adjB);
        if(encodeA == encodeB){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}
