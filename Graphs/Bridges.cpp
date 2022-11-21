int t_low[N],t_in[N],timer;
void DFS(int v,int c){
    used[v]=1;
    t_low[v]=timer;
    t_in[v]=timer;
    timer++;
    for(int k=0;k<g[v].size();k++){
        if(used[g[v][k]]==1 && c!=g[v][k])
            t_low[v]=min(t_low[v],t_in[g[v][k]]);
        if(used[g[v][k]]==0){
            DFS(g[v][k],v);
            t_low[v]=min(t_low[v],t_low[g[v][k]]);
            if(t_in[v]<t_low[g[v][k]]){
                mp[{v,g[v][k]}]=1;
                mp[{g[v][k],v}]=1;
            }
        }

    }
}
