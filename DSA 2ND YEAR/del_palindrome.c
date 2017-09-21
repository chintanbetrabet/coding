#include<stdio.h>
#include<string.h>
int palindrome_index(char * a)
{
	int i=0,len=strlen(a);
		for(i=0;i<len/2;i++)
		{
			int j=len-1-i;
			if(a[i]!=a[j])
			{
				if(a[i]==a[j-1])
				return j;
				else return i;
			}
		}
		return -1;
}
int main()
{
int t,i;
scanf("%d",&t);
for(i=0;i<t;i++)
	{
		char str[100005];
		scanf("%s",str);
		printf("%d\n",palindrome_index(str));
	}
	return 0;
}