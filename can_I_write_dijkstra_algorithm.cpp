#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001
#define INF (1<<20)
#define edge pair< int,int >

struct comp{
    bool operator()(const edge &a, const edge &b){
        return a.second > b.second;
    }
};

priority_queue< edge, vector<edge>, comp> pq;
vector<edge> g[MAX];
int dist[MAX];
bool taken[MAX];

int main(){
    int i,u,v,w,sz,N,E,start;
    scanf("%d",&N);
    scanf("%d",&E);
    for(i=0;i<N;i++){
        g[i].clear();
    }
    for(i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(edge(v,w));
        g[v].push_back(edge(u,w));
    }
    scanf("%d",&start);
    for(i=0;i<N;i++){
        dist[i]=INF;
        taken[i]=false;
    }

    dist[start]=0;
    pq.push(edge(start,0));

    while(!pq.empty()){
        u=pq.top().first;
        pq.pop();
        if(taken[u]==true){
            continue;
        }
        sz=g[u].size();
        for(i=0;i<sz;i++){
            v=g[u][i].first;
            w=g[u][i].second;
            if(taken[v]==false && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push(edge(v,dist[v]));
            }
        }
        taken[u]=true;
    }
    for(i=0;i<N;i++){
        printf("node %d : min dist %d\n",i,dist[i]);
    }
    return 0;
}
