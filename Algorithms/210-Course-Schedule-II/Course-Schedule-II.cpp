class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> result;
        vector<int> parent(n, 0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            parent[prerequisites[i][0]]++;
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == 0)
                result.push_back(i);
        }
        while (j < result.size()) {
            int node = result[j];
            j++;
            for (int it : adj[node]) {
                parent[it]--;
                if (parent[it] == 0)
                    result.push_back(it);
            }
        }
        if (j == n)
            return result;
        else
            return {};
    }
};