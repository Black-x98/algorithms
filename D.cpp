#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define ii64 long long int


struct work{
    ii64 s,e;
    work(){}
    work(int _s, int _e){
        s = _s;
        e = _e;
    }
    bool operator <(const work &a)const
    {
        return e < a.e;
    }

    bool operator >(const work &a)const
    {
        return e > a.e;
    }
};

ii64 t;
ii64 n,l[1005],r[1005],cnt=0;
vector<work> arr;

priority_queue<work, vector<work>, greater<work> > qqq;

main(){
    ii64 res=0;
    ii64 fin=-1,str=0;
    scanf("%lld",&t);
    for(int i=0;i<t;i++){
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&l[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&r[i]);
        }
        for(int i=0;i<n;i++){
            qqq.push(work(l[i],r[i]));
        }
        cnt=0;
        fin=0;
        for(int i=0;i<n;i++){
            work f=qqq.top();
            qqq.pop();

            if(fin<=f.s){
                cnt++;
                fin=f.e;
            }
        }
        printf("%lld\n",cnt);
    }

    return 0;
}
