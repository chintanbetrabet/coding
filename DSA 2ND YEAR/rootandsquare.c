#include<stdio.h>
#include<math.h>
#include<conio.h>
long long ste=0;
long sq(long int x)
{
	if(x==1)
	return 1;
	if(x%2==0)
	return 4*sq(x/2);
	else return 4*sq(x/2)+2*x-1;
}
double root(long long x,double upper,double lower)
{
	ste++;
	if(ste%100==0){
	//printf("\n%d %f %f",ste,upper,lower);getch();
	}
	double v=(upper+lower)/2,est=pow(v,2);
//	printf("\n%lf %lf %d %lf %lf",est,v,x,upper,lower);//getch();
	if(upper-lower<0 && upper-lower>-0.00000000001||upper-lower>0&&upper-lower<.00000000001)
	return v;
	//if((est-x)<0.001&&(est-x)>0||(est-x)>-0.001&&(est-x)<0)
//	return v;
	//printf("FOUND:%lf",v);
	else if(est<x){
	//	printf(" gret");
	return root(x,v,lower);
	}
	else {//printf(" less");
		return root(x,upper,v);}
	
}
void main()
{
	long long int x=200000000000;int i,im=2;
	for(i=1;i<im;i++){
		double val=root(x,0,x);
	printf("\n%lf %f",ste,(val*val));
	ste=0;
	x*=10;
	}
}