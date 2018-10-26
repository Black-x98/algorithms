#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


#define INF (1<<20)
int arr[1000][1000];


void floyd_warshall(int N){
    int i,j,k;
    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(arr[i][k]*arr[k][j]!=0&&i!=j){
                    if(arr[i][j]>arr[i][k]+arr[k][j]){
                        arr[i][j]=arr[i][k]+arr[k][j];
                    }
                }
            }
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i<j){
                if(arr[i][j]==INF){
                    printf("%d to %d: No Path\n",i,j,arr[i][j]);
                }
                else{
                    printf("%d to %d: %d\n",i,j,arr[i][j]);
                }
            }
        }
    }
}

int main(){
    int N,E,i,j,k,u,v,w;
    scanf("%d",&N);
    scanf("%d",&E);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=INF;
        }
    }
    for(i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        if(arr[u][v]>w){
            arr[u][v]=w;
            arr[v][u]=w;
        }
    }
    floyd_warshall(N);
    return 0;
}
