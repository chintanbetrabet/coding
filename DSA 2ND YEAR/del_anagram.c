#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str1[10000],str2[10000];
    int ar1[26];
    int i=0,j=0;
    for(i=0;i<26;i++)
        {
            ar1[i]=0;
        }
    scanf("%s",str1);//scanf("\n");
    scanf("%s",str2);
    printf("\nstr1:%s, str2:%s",str1,str2);
    printf("\nstr1[0]=%c",str1[0]);
   while(str1[i]!='\0')
        {
        printf("\nst1: updating:%c to %d at %d", str1[i],ar1[str1[i]-'a']+1,i);
        ar1[str1[i]-'a']++;i++;
    }i=0;
        while(str2[i]!='\0')
        {
            printf("\n updating:%c to %d", str2[i],ar1[str2[i]-'a']+1);
        ar1[str2[i]-'a']--;i++;
    }
    int count=0;
    for(i=0;i<5;i++)
        {
        if(ar1[i]!=0)
            printf("\ndelta is %d at :%c",ar1[i],'a'+i);
        count+=abs(ar1[i]);
    }
    printf("%d",count);
   
    return 0;
}
