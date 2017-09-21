#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
	printf("%d",islower('7'));
    char str[1000];scanf("'%s",str);int ar1[26]={0};
    int i=0;
    while(str[i]!=0)
        {
        if(isalpha(str[i]))
            {
           
            if(islower(str[i])){
                 printf("hi %c\n",str[i]);
                ar1[str[i]-'a']++;
            }
            else
                ar1[str[i]-'A']++;
        }
        i++;
    }
    int j;
    for(j=0;j<26;j++)
        {
        if(ar1[j]==0)
            {
           printf("\nnot having:%c\n",ar1[j]+'a');
            printf("not pangram");return 0;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
   printf("pangram");
    return 0;
}
