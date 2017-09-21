#include<stdio.h>
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n); 
        if(n<8)
            {
                if(n==0)
                    print("0");
                else if(n==3)
                    print("555");
                   else if(n==5)
                    {
                    print("33333");
                    }
            else print("-1");
            }
        else {
            int num5=(n/3),rem=n%3,num3=0;
            if(rem==1)
                {
                num5-=3;
                num3+=2;
                }
            if(rem==2)
                {
                num5-=1;
                num3+=1;
            }
            int i;
           for(i=0;i<num5;i++)
               printf("5");
           for(i=0;i<num3;i++)
               printf("3");
        }
    }
    return 0;
}