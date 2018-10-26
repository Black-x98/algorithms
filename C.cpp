#include <stdio.h>
#include <algorithm>


using namespace std;

#define ii64 long long int

int t;
ii64 n,a,val[33]={0},cnt=0;


ii64 min_coin(){
    std::sort(val,val+n);
    if((a%val[0])!=0){
        return -1;
    }
    ii64 amount=a;
    cnt=0;
    ii64 m,took=0;
    for(m=n-1;m>=0;m--){
        if(amount>=val[m]){
            took=(amount/val[m]);
            cnt+=took;
            amount-=took*val[m];
        }
    }
    return cnt;
}


main(){
    ii64 res=0;
    scanf("%lld",&t);
    for(int i=0;i<t;i++){
        scanf("%lld %lld",&n,&a);
        for(int i=0;i<n;i++){
            scanf("%lld",&val[i]);
        }
        res=min_coin();
        if(res==-1){
            printf("Impossible\n");
        }
        else{
            printf("%lld\n",res);
        }
    }

    return 0;
}
