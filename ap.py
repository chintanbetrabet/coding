'''
#include<stdio.h>
#define ll unsigned long long
#define ill(x) scanf("%llu",&x)
#define pll(x) printf("%llu ",x)
#define nl printf("\n")
int main()
{
ll t;
ill(t);
	while(t--)
	{
	ll a,b,c;
	ll i;
	ll d,start,len;
	ill(a);ill(b);ill(c);
	if(a!=b)
	{
	len=(2*c)/(a+b);
	pll(len);
	nl;
	d=(len-(b-a))/5;
	start=a-2*d;
	}
	else
	{
	start=a;
	len=c/start;
	d=0;
	}
	pll(len);
	for(i=0;i<len;i++)
	pll(start+i*d);
	nl;
	}
}

/*
a+2d=x
a+(l-3)d=y
l-5d=y-x
l=2z/(x+y)
*/
'''
t=input()
while t>0:
	t-=1
	a,b,c=map(int,raw_input().split())
	l=c/a
	s=a
	d=0
	if a!=b:
		l=(2*c)/(a+b)
		d=(l-(b-a))/5
		s=a-2*d
	
	print l
	for x in range(l):
		print s+x*d,
	print
