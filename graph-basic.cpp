// Check graph connectedness 
int N; // number of vertices
vector<vector<int>> W; // graph
vector< int > V; // V is a visited flag 

void dfs(int i) {
    if(!V[i]) {
        V[i] = true;
        for_each(W[i].begin(), W[i].end(), dfs);
    }
} 

bool check_graph_connected_dfs() {
    int start_vertex = 0;
    vector< int > V(N, false);
    dfs(start_vertex);
    return (find(V.begin(), V.end(), 0) == V.end());
}


