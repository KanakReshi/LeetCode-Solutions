class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int result = 0;
        queue<int>q;
        vector<bool>visited(n,false);
        for(int i = 0 ; i < n ;i++){
            if(visited[i])continue;
            result++;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(int j = 0 ; j < n ;j++){
                    if(isConnected[front][j] == 1 && visited[j] == false){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }

        }
        return result;
    }
};