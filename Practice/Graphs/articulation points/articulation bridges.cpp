
// Articulation Bridges,
// those bridges whose removal will make the u and v disconnected.

class Solution {
public:
    vector<vector<int>> gr, res;
    vector<int> AP, in, low;
    int timer = 0;

    void dfs(int x, int par = -1) {
        in[x] = low[x] = timer++;
        for (auto nbr : gr[x]) {
            if (in[nbr] == -1) { // not visited.
                dfs(nbr, x);
                low[x] = min(low[x], low[nbr]);
                if (low[nbr] > in[x])
                    res.push_back({x, nbr});
            } else if (in[nbr] != -1 and nbr != par) { //already visited, backedge & not parent.
                low[x] = min(low[x], in[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        gr.assign(n, {});
        in.assign(n, -1);
        low.assign(n, -1);

        //created graph.
        for (int i = 0; i < connections.size(); i++) {
            gr[connections[i][0]].push_back(connections[i][1]);
            gr[connections[i][1]].push_back(connections[i][0]);
        }

        dfs(0);
        // for(int i=0; i<n; i++){
        //     cout<<in[i]<<" "<<low[i]<<endl;
        // }
        return res;
    }
};