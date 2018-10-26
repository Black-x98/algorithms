#include <stdio.h>
#include <algorithm>


using namespace std;


int t;
int n,c,wt[33]={0},pr[33]={0},cnt=0;


int max_num(){
    std::sort(wt,wt+n);
    int cap=c;
    cnt=0;
    for(int i=0;i<n;i++){
        if(cap-wt[i]>=0){
            cnt++;
            cap=cap-wt[i];
        }
        else{break;}
    }
    return cnt;
}


main(){

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++){
            scanf("%d",&wt[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&pr[i]);
        }
        printf("%d\n",max_num());
    }

    return 0;
}


