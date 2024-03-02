#include<stdio.h>
#include<math.h>
double Max(double,double,double);
double Min(double,double,double);
int main()
{
	double R,G,B,H,S,V;
	scanf("%lf %lf %lf",&R,&G,&B);
	double max=Max(R,G,B)/255,min=Min(R,G,B)/255;
	V=max;
	if(V==0)S=0;
	else S=(max-min)/max;
	if(max==min) H=0;
	else if(max==R/255) H=60*(0+(G-B)/(max-min)/255);
	else if(max==G/255) H=60*(2+(B-R)/(max-min)/255);
	else H=60*(4+(R-G)/(max-min)/255);
	if(H<0)H+=360; 
	printf("%.4lf,%.4lf%%,%.4lf%%",H,100*S,100*V);
	return 0;
}
double Max(double R,double G,double B)
{
	double max;
	if(R>G) max=R;
	else max=G;
	if(max<B) max=B;
	return max; 
}
double Min(double R,double G,double B)
{
	double min;
	if(R<G) min=R;
	else min=G;
	if(min>B) min=B;
	return min; 
}