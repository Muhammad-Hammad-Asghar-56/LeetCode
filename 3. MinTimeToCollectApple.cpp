#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int DFS(int node,int parent,vector<vector<int>>& adj,vector<bool>& hasApple){
        int ConsumeTime=0;
        int subtreeTime=0;
        // get the Row of the node's adjency list form the adjency matrix
        vector<int> subMatrixRow;
        for (int i = 0; i < adj[node].size(); i++)
        {
            subMatrixRow.push_back(adj[node][i]);
        }
        // vist all the adjecent
        for (auto i:subMatrixRow)
        {
            // donot visit same node
            if(i!=parent){
                // recursively call the DFS on adjecent nodes
                subtreeTime=DFS(i,node,adj,hasApple);
            }
            // if the subTree have the Apple then Increase the time 
            if(hasApple[i]){
                ConsumeTime+=2;
            }
            ConsumeTime+=subtreeTime;
        }
        return ConsumeTime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        //      Make the Adjacency List
        vector<vector<int>> adj;
        for (int i = 0; i < edges.size() ; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int timeOfApple=DFS(adj[0][0],-1,adj,hasApple);
        return timeOfApple;
    }
};