#include <stdio.h>
main(){
    int a[100]={0};
    int top=-1,c=0,i=0;
    while(c!=5){
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for top\nEnter 4 to view all the elements\nEnter 5 to exit\n");
        scanf("%d",&c);
        if(c==1){
            if(top==99){
                printf("The stack is full\n");
                break;
            }
            else{
                top++;
                printf("Enter the new element:\n");
                scanf("%d",&a[top]);
            }
        }
        if(c==2){
            if(top==-1){
                printf("The stack is empty\n");
                break;
            }
            else {
                printf("Removing the top element %d\n",a[top]);
                a[top]=0;
                top--;
            }
        }
        if(c==3){
            if(top==-1){
                printf("The stack is empty\n");
                break;
            }
            else
            {
                printf("The top element is %d\n",a[top]);
            }
        }
        if(c==4){
             if(top==-1){
                printf("The stack is empty\n");
                break;
            }
            else{
                printf("The elements are:\n");
                for(i=0;i<=top;i++){
                    printf("%d ",a[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
