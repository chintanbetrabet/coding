#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int isKaprekar(int n)
    {
	    
    int sq=n*n;
    int dig=log10(n);
    dig+=1;
   // printf("%d   ",dig);
    int h1=sq/(int)pow(10,dig);
    int h2=sq-h1*(int)pow(10,dig);
    
   if(n==(h1+h2))return 1;
    else return 0;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
   printf("%d", isKaprekar(77778));
    return 0;
}