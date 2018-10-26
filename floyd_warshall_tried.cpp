#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


#define INF (1<<20)
int arr[10000][10000];


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
        printf("From source %d: ",i);
        for(j=0;j<N;j++){
            if(j==N-1){
                printf("%d\n",arr[i][j]);
            }
            else{
                printf("%d ",arr[i][j]);
            }
        }
    }
}

int main(){
    int N,E,i,j,k,u,v,w;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=INF;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&u);
            if(u==-1){
                arr[i][j]=INF;
            }
            else{
                arr[i][j]=u;
            }
        }
    }
    floyd_warshall(N);
    return 0;
}
