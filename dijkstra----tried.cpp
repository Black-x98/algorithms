#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001
#define INF (1<<20)
#define edge pair< int,int >

struct comp {
    bool operator()(const edge &a, const edge &b){
        return a.second > b.second;
    }
};

priority_queue< edge, vector<edge>, comp> Q;
vector<edge> G[MAX];
int D[MAX];
bool F[MAX];

int main(){
    int i,u,v,w,sz,nodes,edges,start;

    scanf("%d %d",&nodes,&edges);
    for(i=0;i<nodes;i++){
        G[i].clear();
    }
    for(i=0;i<edges;i++){
        scanf("%d %d %d", &u,&v,&w);
        G[u].push_back(edge(v,w));
        G[v].push_back(edge(u,w));
    }
    scanf("%d",&start);

    for(i=1;i<=nodes;i++){
        D[i]=INF;
        F[i]=false;
    }
    D[start]=0;
    Q.push(edge(start,0));

    while(!Q.empty()){
        u=Q.top().first;
        Q.pop();
        if(F[u]==true) continue;
        sz = G[u].size();
        for(i=0;i<sz;i++){
            v=G[u][i].first;
            w=G[u][i].second;
            if(!F[v] && D[u]+w < D[v]){
                D[v] = D[u]+w;
                Q.push(edge(v,D[v]));
            }
        }
        F[u]=true;
    }

    for(i=1;i<nodes;i++){
        printf("Node %d, min weight = %d\n",i,D[i]);
    }

    return 0;
}
