vector < VL > graph;
ll dfsRoot;
ll rootChildren = 0;
ll t = 1;
VL in;
VL low;
VL parent;
VL visited;
SL cutvertices ;
void DFS(int u)
{
    visited[u] = 1 ;
    in[u] = low[u] = t++;
    for ( ll v : graph[u] )
    {
        if (visited[v] == 0)
        {
            parent[v] = u;
            if (u == dfsRoot)
                ++rootChildren;
            DFS(v);
            if (u != dfsRoot && low[v] >= in[u])
                cutvertices.insert(u);

            low[u] = min(low[u],low[v]);
        }
        else if (v != parent[u]) 
            low[u] = min(low[u],in[v]); 
    }
}
int main() {
           for (int p = 1; p < graph.size(); ++p)
        {
            if (!visited[p])
            {
                dfsRoot = p;
                rootChildren = 0;
                DFS(p);
                if (rootChildren > 1)
                    cutvertices.insert(p);
            }
        }
}
