 #include<ctype.h>
 #include<stdio.h>
 #include<string.h>
 //#include<bits/stdc++.h>
 //using namespace std;
 
char s[10000];
string longestPalindrome(string A) {
        int dp[A.length()][A.length()];
    int i,j,l;
    for(i=0;i<A.length();i++)for(j=0;j<A.length();j++)dp[i][j]=0;
    int ml=1;
    int sti=0;
    for(i=0;i<A.length();i++)
    {
        dp[i][i]=1;
    }
    for(i=0;i<A.length()-1;i++)
    {
        if(A[i]==A[i+1])
        {
            dp[i][i+1]=1;
            if(ml!=2)sti=i;
            ml=2;
        }
        else
        dp[i][i+1]=0;
        
    }
    for(l=2;l<A.length();l++)
    {
        for(i=0;i+l<A.length();i++)
        {
            int j=i+l;
            if(A[i]==A[l+i])
            {
                dp[i][l+i]=dp[i+1][j-1];
                if(dp[i][l+i]==1 && ml<l+1)
                {
                    sti=i;
                    ml=l+1;
                    //printf("ML=%d \n",ml);	
                }
                
                
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    /*printf("  ");
    for(i=0;i<A.length();i++)
    printf("%c ",A[i]);
    printf("\n");
    for(i=0;i<A.length();i++)
    {
    printf("%c ",A[i]);
    for(int j=0;j<A.length();j++)
    	{
    	printf("%d ",dp[i][j]);//<<"  ";
    	}
    	printf("\n");
    }
    printf("\n");
    */
    int size=0;
    string s;
    for(i=sti;i<ml+sti;i++)
    s+=A[i];
    s+='\0';
    return s;
}
int main()

{
printf("%s",longestPalindrome("abb"));
}
