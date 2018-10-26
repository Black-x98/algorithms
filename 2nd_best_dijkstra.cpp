#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 100000
#define INF (1<<20)
#define edge pair<int,int>

vector<edge> g[MAX];
struct edge_ext{
    edge ed;
    int order;
    edge_ext(edge e, int o){
        ed=e;
        order=o;
    }
     bool operator <(const edge_ext &a)const
    {
        return ed.first < a.ed.first;
    }
    bool operator >(const edge_ext &a)const
    {
        return ed.first > a.ed.first;
    }
};
int N,E;
bool vis[MAX];
int dist[MAX], dist2[MAX];
priority_queue <edge_ext, vector<edge_ext>, greater<edge_ext> > pq;


int main(){
    int i,j,k,u,v,w,sz,total=0;
    scanf("%d",&N);
    scanf("%d",&E);
    for(i=0;i<N;i++){
        g[i].clear();
    }
    for(i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(edge(w,v));
        g[v].push_back(edge(w,u));
    }
    for(i=0;i<N;i++){
        std::sort(g[i].begin(),g[i].end());
        dist[i]=INF;
        dist2[i]=INF;
        vis[i]=false;
    }

    pq.push(edge_ext(edge(0,0),1));
    dist[0]=0;
    int srcdis=0,o=0;
    while(!pq.empty()){
        u=pq.top().ed.second;
        o=pq.top().order;
        if(o==1){
            srcdis=dist[u];
            printf("pop 1 :: %d -- %d\n",u,dist[u]);
        }
        else if(o==2){
            srcdis=dist2[u];
            printf("pop 2 :: %d -- %d\n",u,dist2[u]);
        }
        //vis[u]=true;
        pq.pop();
        for(i=0;i<g[u].size();i++){
            v=g[u][i].second;
            w=g[u][i].first;
            printf("printing dist[1] == %d dist2[1] == %d\n",dist[1],dist2[1]);
            /*if(vis[v]==true){
                continue;
            }*/
            if(dist[v]>srcdis+w){
                dist2[v]=dist[v];
                dist[v]=srcdis+w;
                //printf("push 1 :: %d -- %d\n",v,dist[v]);
                pq.push(edge_ext(edge(dist[v],v),1));
            }
            else if(dist2[v]>srcdis+w){
                dist2[v]=srcdis+w;
                //printf("push 2 :: %d -- %d\n",v,dist2[v]);
                pq.push(edge_ext(edge(dist2[v],v),2));
            }
        }
    }

    for(i=0;i<N;i++){
        printf("%d: ",i);
        if(dist[i]==INF){
            printf("Infinity\n");
        }
        else{
            printf("%d\n",dist[i]);
        }
    }
    for(i=0;i<N;i++){
        printf("%d: ",i);
        if(dist[i]==INF){
            printf("Infinity\n");
        }
        else{
            printf("%d\n",dist2[i]);
        }
    }
    return 0;
}


