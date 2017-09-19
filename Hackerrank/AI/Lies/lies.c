#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a,b) a>b?a:b

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
        max_Set_size-max(max_Set_size,size[findroot(a)]+size[findroot(b)]);
		size[findroot(a)]+=size[findroot(b)];
		sets[findroot(b)]=findroot(a);	
        /*if(size[findroot(a)]<n-1)
            return true;
        return false;*/
	}
	else{
	size[findroot(b)]+=size[findroot(a)];
		sets[findroot(a)]=findroot(b);
       /* if(size[findroot(b)]<n-1)
            return true;
        return false;*/
	}
    return -1;
}
int find(int a,int b)
{
	return findroot(a)==findroot(b);
}

void nextQuestion(int n, int plularity, int lies, int color, int exact_lies, int query_size, int query[ n ][ n ])
{
int i,j;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(!find(i,j) && (findroot(i)==i&&findroot(j)==j) )
            {
                    printf("%d %d",i,j);
                    return;
            }
        }
    }
    
        for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(!find(i,j))
            {
                    printf("%d %d",i,j);
                    return;
            }
        }
    }
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
    int query[ n ][ n ];
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
            int found=union_set(x,y);
            if(found!=-1)
            {
                printf("%d",found);
                return 0;
            }
        }
        else
        {
            query[ x ][ y ] = 0;
            query[ y ][ x ] = 0;
        }
    }
    nextQuestion(n, plularity, lies, color, exact_lies, query_size, query);
    return 0;
}

