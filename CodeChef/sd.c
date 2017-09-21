#include<stdio.h>
void S(int f,int l,char A[])
{
	char b[l-f];int m=0,i=f,j=(f+l)/2;
	while(i<(f+l)/2&&j<l)
	{
		if(A[i]>A[j])b[m]=A[j++];
		else b[m]=A[i++];
	}
	while(i<(f+l)/2)b[m]=A[i++];
	while(j<l)b[m++]=A[j++];
	for(i=0;i<m;i++)A[f+i]=b[i];	
}
void CM(int f,int l,char a[])
{
	if(f<l-1){		CM(f,(f+l)/2,a);CM((f+l)/2,l,a);S(f,l,a);}
}
int main()
{
	char s[1000];int i;s[0]='a';
	for(i=-1;s[i]!='\n';i++)scanf("%c",&s[i+1]);s[i]='\0';CM(0,i,s);printf("%s",s);
}