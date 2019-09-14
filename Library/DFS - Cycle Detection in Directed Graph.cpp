// make visited int array with 1-indexing
// g is graph(vector<vector<int>>)  

bool findLoop(int v) 
{
    if(vis[v]==1)
        return 1;
    if(vis[v]==2)
        return 0;
    vis[v]=1;
    for(auto &it:g[v])
    {
        if(findLoop(it))
            return 1;
    }
    vis[v]=2;
    return 0;
}

bool checkLoop()
{
    fill(vis+1, vis+n+1, 0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && findLoop(i))
            return 1;
    }
    return 0;
}