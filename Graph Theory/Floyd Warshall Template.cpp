/**
Maximum time needed to pass a signal from source node to all other node in the graph
Problem Link: https://leetcode.com/problems/network-delay-time/
**/

class Solution {
public:
    void FloydWarshall(int n, vector<vector<int>>& dist, vector<vector<int>>& times)
    {
        for(auto time : times) {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            dist[u][v] = w;
        }
        
        for(int k=0 ; k<n ; k++) {
            for(int i=0 ; i<n ; i++) {
                for(int j=0 ; j<n ; j++) {
                    dist[i][j] = min((i == j)? 0 : dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        int ans = 0, src = k-1;
        
        FloydWarshall(n, dist, times);
        for(int i=0 ; i<n ; i++) {
            ans = max(ans, dist[src][i]);
        }
        
        return (ans == 1e9)? -1 : ans;
    }
};
