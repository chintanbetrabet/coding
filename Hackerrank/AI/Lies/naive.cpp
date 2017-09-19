#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
#define max(a,b) a>b?a:b
#define pi pair<int,int> 
#define ppi pair<pair<int,int>,pair<int,int> >
int sets[112345];
int size[112345];
int max_Set_size=1;
int N;
void initialize_set()
{
	for(int i=0;i<112345;i++)
	{
		sets[i]=i;
		size[i]=1;
	}
}
int find(int,int);
int findroot(int a)
{
	int i=a;
	while(sets[i]!=i)
	{
	i=sets[i];
	}
	return i;
}
int union_set(int a,int b)
{
//cout<<"merging "<<a<<"  "<<b<<"\n";
    if(find(a,b))return -1;
    if(size[findroot(a)]+size[findroot(b)]>N/2)return a;
    
    max_Set_size-max(max_Set_size,size[findroot(a)]+size[findroot(b)]);
	if(size[a]>size[b])
	{
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
	sets[findroot(a)]=findroot(b);
	}
    return -1;
}
int find(int a,int b)
{
	return findroot(a)==findroot(b);
}

void nextQuestion(int n, int plularity, int lies, int color, int exact_lies, int query_size, int query[100][100],int next)
{
int i,j;

    //Check all atleast once
        if(size[findroot(0)]>=N/2)
    	{
	printf("0");return;
	}
	else if(next-size[findroot(0)]>=N/2)
    {
    for(int i=1;i<next;i++){if(!find(0,i)){printf("%d\n",i);return;}}
    printf("0");
    return ;
    }
    printf("%d %d\n",i,next);
	
    //Check the two largest sets

    
}
int main(void)
{
    int n,plularity, lies, color, exact_lies, query_size,x,y;
    scanf("%d", &N);
    scanf("%d", &plularity);
    scanf("%d", &lies);
    scanf("%d", &color);
    scanf("%d", &exact_lies);
    scanf("%d", &query_size);
    initialize_set();
    n=N;
    int query[ 100][ 100 ];
    for(int i=0;i<n; i++) {
        for( int j=0;j<n;j++ ) {
            query[ i ][ j ] = -1;
        }
    }
    char *answer = (char *)malloc(5);
    for(int i=0;i<query_size;i++) {
        scanf("%d %d %s", &x,&y, answer);
        if(!strcmp(answer,"YES"))
        {
            query[ x ][ y ] = 1;
            query[ y ][ x ] = 1;
            union_set(x,y);
        }
        else
        {
            query[ x ][ y ] = 0;
            query[ y ][ x ] = 0;
        }
    }
    nextQuestion(n, plularity, lies, color, exact_lies, query_size, query,query_size+1);
    return 0;
}

