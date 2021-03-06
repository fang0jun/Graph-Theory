vector < VL > graph ;
VL visited ,parent,in,low ;
VL edges ;
ll root ;
VLL bridges ;
ll t  ;
void setting(ll n) {
    visited.clear();
    visited.resize(n+2,0);
    graph.clear();
    graph.resize(n+2);
    parent.clear();
    parent.resize(n+2,-1);
    in.clear();
    in.resize(n+2,0);
    low.clear();
    low.resize(n+2,0);
    bridges.clear();
}
void dfs(ll node) {
    visited[node] = 1 ;
    low[node] = in[node] = ++t ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) {
            parent[child] = node ;
            dfs(child);
            low[node] = min(low[node],low[child]);
            if ( low[child] > in[node]) {
                bridges.PB({min(node,child),max(node,child)});
            }
        }
        else if ( parent[node] != child) {
               low[node] = min(low[node],in[child]);
        }
    }
}

int main() {
      setting(n) ;
     INC(i,0,n-1) {
                if ( !visited[i]) {
                    t = 0 ;
                    root = i ;
                    dfs(i);
                }
            }

}
