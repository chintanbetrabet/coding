#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int t;
    char str[1000];
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
        {
	        int br=0,bs=0,bc=0;
        scanf("%s",str);
        char test[1000];
        int c=0,bal=1,top=-1;
        int l=strlen(test);
       
        while(str[c]!='\0')
            {
            if(str[c]=='{'||str[c]=='['||str[c]=='(')
            {
                top++;
                test[top]=str[c];
                if(str[c]=='{')bc++;
                if(str[c]=='[')bs++;
                if(str[c]=='(')br++;
            }
            else if(str[c]=='}')
                {bc--;
                if(test[top]=='{'){top--;}
                else {bal=0;}
            }
                else if(str[c]==')')
                {br--;
                if(test[top]=='('){top--;}
                else {bal=0;}
            }
                else if(str[c]==']')
                {bs--;
                if(test[top]=='['){top--;}
                else {bal=0;}
            }
            c++;
            //int p;
            //printf("\n");
            //for(p=0;p<top;p++)printf("%c ",test[p]);
        }
        
        
        if(bc+bs+br==0&&bal==1)
            {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}