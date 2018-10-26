#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000
#define INF (1<<20)
#define edge pair<int,int>

vector<edge> g[100000];
int N,E;
int color[100000], dist[100000], pre[100000];
bool vis[100000];



int main(){
    int i,j,k,u,v,w,sz,total=0;
    bool NC = false;
    scanf("%d",&N);
    scanf("%d",&E);
    for(i=0;i<N;i++){
        g[i].clear();
    }
    for(i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(make_pair(w,v));
    }

    for(i=0;i<N;i++){
        color[i]=0;
        dist[i]=INF;
        pre[i]=-1;
    }
    dist[0]=0;
    pre[0]=-1;
    vis[0]=true;
    for(i=0;i<N-1;i++){
        for(j=0;j<N;j++){
            sz=g[j].size();
            for(k=0;k<sz;k++){
                v=g[j][k].second;
                w=g[j][k].first;
                if(dist[v]>dist[j]+w){
                   dist[v]=dist[j]+w;
                   pre[v]=j;
                   vis[v]=true;
                }
            }
        }
    }
    NC=false;
    for(i=0;i<N;i++){
        sz=g[i].size();
        for(j=0;j<sz;j++){
            v=g[i][j].second;
            w=g[i][j].first;
            if(dist[v]>dist[i]+w){
                NC = true;
                break;
            }
        }
        if(NC==true){
            break;
        }
    }
    if(NC==true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}




