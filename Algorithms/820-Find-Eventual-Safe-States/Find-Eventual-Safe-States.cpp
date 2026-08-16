class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& visited){
        if(visited[i] > 0){
            return visited[i] == 2;
        }
        visited[i] = 1;
        for(int it : graph[i]){
            if(!dfs(graph,it,visited)){
                return false;
            }
        }
        visited[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> result;
        vector<int> visited(n, 0);
        for (int i = 0; i < n ; i++) {
            if(dfs(graph, i, visited))result.push_back(i);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
