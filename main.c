#include <stdio.h>
#define Max(a,b) (a>b?a:b)
double  max(double a,double b,double c)
{
double Max=a;
if(b>a){
    Max=b;
    if(c>b){
        Max=c;
    }
}
else{
    if(c>a){
        Max=c;
    }
}
return Max;
}
int main(){
   double a,b,c;
   scanf("%lf %lf %lf",&a,&b,&c);
   printf("%.3lf\n",max(a,b,c));
   double num1,num2;
   num1=Max(a,b);
   num2=Max(num1,c);
   printf("%.3lf",num2);
   
   return 0;

   
}

