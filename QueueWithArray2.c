#include <stdio.h>
main(){
    int a[100]={'\0'};
    int top=-1,c=0,i=0,max=99,cnt=0,start=0,end=99;
    while(c!=4){
        printf("Enter 1 for enqueue\nEnter 2 for dequeue\nEnter 3 to view all the elements\nEnter 4 to exit\n");
        scanf("%d",&c);
        if(c==1){
                while(a[end]=='\0'){
                    end--;
                }
                if(end==99){
                    printf("There is no space\n");
                    break;
                }
                printf("Enter the new element:\n");
                scanf("%d",&a[end+1]);
                end=99;
                cnt++;
        }
        if(c==2){
            if(cnt==0){
                printf("The queue is already empty\n");
                break;
            }
            else {
                while(a[start]=='\0'){
                    start++;
                }
                printf("Removing the front element %d\n",a[start]);
                a[start]=0;
                start=0;
                cnt--;
            }
        }
        if(c==3){
             if(cnt==0){
                printf("The queue is empty\n");
                break;
            }
            else{
                printf("The elements are:\n");
                for(i=0;i<=99;i++){
                    if(a[i]!='\0')
                        printf("%d ",a[i]);
                }
                if(end==99){
                    printf("There is no space\n");
                    break;
                }
                printf("\n");
                }
            }
    }
    return 0;
}
