#include <stdio.h>
#include <queue>


using namespace std;

struct item{
    double w,p,rat;
    item(){}
    item(int _w, int _p){
        w = _w;
        p = _p;
        rat=p/w;
    }
    bool operator <(const item &a)const
    {
        return rat < a.rat;
    }

    bool operator >(const item &a)const
    {
        return rat > a.rat;
    }
};

priority_queue<item, vector<item>, less<item> > qqq;
int t;
int n,c;
double cnt=0,wt[33]={0},pr[33]={0},rat[33];



main(){

    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++){
            scanf("%lf",&wt[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%lf",&pr[i]);
        }
        for(int i=0;i<n;i++){
            qqq.push(item(wt[i],pr[i]));
        }
        double cap=c;
        cnt=0;
        for(int i=0;i<n&&cap>=0;i++){
            item f=qqq.top();
            qqq.pop();
            //printf(" f w f p  %.2lf %.2lf\n",f.w,f.p);
            if(cap>=f.w){
                cnt+=f.p;
                cap-=f.w;
            }
            else{
                double left=cap/f.w;
                cnt+=f.p*left;
                cap-=f.w*left;
            }
            //printf("vitore %.2lf\n",cnt);
        }
        printf("%.2lf\n",cnt);
    }

    return 0;
}



