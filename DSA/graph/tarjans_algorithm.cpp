#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void find_low_links(vector<vector<int>>& graph_adjacency_list,vector<int>& ids_array,vector<int>& low_links_array,stack<int>& stk,vector<int>& visited,int number,int& id_counter,vector<bool>& stack_membership){
        visited[number] = 1;
        stk.push(number);
        stack_membership[number] = true;
        ids_array[number] = low_links_array[number] = id_counter++;  
        for(int i=0;i<graph_adjacency_list[number].size();i++){
            if(visited[graph_adjacency_list[number][i]] == 0){
                find_low_links(graph_adjacency_list,ids_array,low_links_array,stk,visited,graph_adjacency_list[number][i],id_counter,stack_membership);
            }
            if(stack_membership[graph_adjacency_list[number][i]] == true){
                low_links_array[number] = min(low_links_array[number],low_links_array[graph_adjacency_list[number][i]]);
            }
        
        }

        if(ids_array[number] == low_links_array[number]){
            while(stk.top() != number){
                stack_membership[stk.top()] = false;
                cout<<stk.top()<<" ";
                stk.pop();
            }
            stack_membership[stk.top()] = false;
            cout<<stk.top()<<"\n";
            stk.pop();
        }        
    }

    void criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph_adjacency_list(n,vector<int>());
        stack<int> stk;
        vector<int> visited(n,0);
        vector<bool> stack_membership(n,false);
        for(int i=0;i<connections.size();i++){
            graph_adjacency_list[connections[i][0]].push_back(connections[i][1]);
        }
        vector<int> ids_array(n,0);
        vector<int> low_links_array(n,0);
        int id_counter = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                find_low_links(graph_adjacency_list,ids_array,low_links_array,stk,visited,i,id_counter,stack_membership);
            }
        }
    }
};

int main(){
    int n=8;
    vector<vector<int>> connections;

    connections.push_back({0,1});
    connections.push_back({0,3});
    connections.push_back({1,0});
    connections.push_back({1,2});
    connections.push_back({2,4});
    connections.push_back({2,5});
    connections.push_back({3,2});
    connections.push_back({4,3});
    connections.push_back({4,5});
    connections.push_back({4,7});
    connections.push_back({5,6});
    connections.push_back({6,7});
    connections.push_back({7,5});

    

    
    Solution obj;
    obj.criticalConnections(n,connections);
}

