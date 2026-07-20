class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int m = prerequisites.size();
        vector<int>parent(n,0);
        vector<vector<int>>adj(n);
        for(int i = 0; i < m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            parent[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i = 0;i < n ;i++){
            if(parent[i] == 0)q.push(i);
        }
        int k = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            k++;
            for(int it : adj[node]){
                parent[it]--;
                if(parent[it] == 0)q.push(it);
            }
        }
        return k == n;
    }
};