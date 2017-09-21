#include<stdio.h>
void disp(int n)
{
	char x[3];
	x[2]='\0';
	if(n>=0)
	{
		x[0]=(n/10 )+'0';
		x[1]=(n%10) +'0';
	}

	printf("%s",x);
}
int main()
{
	long long int a;
	int h,m;
	char c;
	scanf("%d",&h);
	scanf("%c",&c);
	scanf("%d",&m);
	//printf("%d %d",h,m);
	scanf("%llu",&a);
	m+=a;
	
	h+=m/60;
	m%=60;
	h%=24;
	disp(h);
	printf(":");disp(m);

}