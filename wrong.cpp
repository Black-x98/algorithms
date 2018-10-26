#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define inf (1<<20)
#define MX 100000


struct node{
    int nd, cost;
    node(){}
    node(int _nd,int _cost){
        nd = _nd;
        cost = _cost;
    }
    bool operator >(const node &a)const{
        return cost > a.cost;
    }
};

vector<node> g[MX];
priority_queue<node, vector<node>, greater<node> > q;
int d[MX], par[MX];

void dijkstra(int n,int source,int dest){
    for(int i = 0; i < n; i++){
        d[i] = inf;
        par[i] = -1;
    }
    d[source] = 0;
    q.push(node(source,0));
    while(!q.empty()){
        int u = q.top().nd;
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].nd;
            int w = g[u][i].cost;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                par[v] = u;
                q.push(node(v,d[v]));
            }
            else if((d[v] == d[u] + w) && u < par[v])par[v] = u;
        }
    }
    if(d[dest]<inf){
        int u = dest;
        vector<int> path;
        while(u!=source){
            path.push_back(u);
            u = par[u];
        }
        path.push_back(source);
        reverse(path.begin(),path.end());
        for(int i = 0; i < path.size(); i++){
            printf("%d\n",path[i]);
        }
    }
    else printf("Not Reachable\n");
}

int main(){
    int n,m,u,v,i,w;
    scanf("%d %d",&n, &m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(node(v,w));
        g[v].push_back(node(u,w));
    }
    dijkstra(n, 0, 1);

    return 0;
}
