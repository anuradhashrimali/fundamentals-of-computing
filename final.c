#include <stdio.h>
#include <math.h>


int main(void)
{
int tn=12;
double yn1=0.0;
int divi=1;
int n=0, i=0, j=0, k=0;
int n1=0, n2=0;
printf("Enter a number\n");
scanf("%d", &divi);
double h=12.0/divi;
double en[10000]={0.0},hn[10000]={0.0},mn[10000]={0.0};
double t=0.0;

FILE *fp;
fp=fopen("plotval2.m","w");
en[0]=0.1, hn[0]=0.1, mn[0]=0.1;
fprintf(fp, "x=[");
for (k=1; k<=divi; k++){
fprintf(fp, "%d;\n", k);
}
fprintf(fp, "];\neuler=[%f;\n", en[0]);

for (t=0; t<=tn ; t=t+h){
if (n==divi) break;
en[n+1]=en[n]+h*sin(t)*cos(en[n]);
//printf("Euler %f %d\n", yn[n], n);
fprintf(fp, "%f;\n",en[n+1]);
n++;
}
fprintf(fp, "];\nheun=[%f;\n", hn[0]);
//fprintf(fp, "heun=[%f;\n", yn[0]);

for (i=0; i<=tn ; i=i+h){
if (n1==divi) break;
yn1=hn[n1]+h*sin(i)*cos(hn[n1]);
hn[n1+1]=hn[n1]+0.5*h*(sin(i)*cos(hn[n1])+sin(i+h)*cos(yn1));
//printf("Heun %f %d\n", yn[n1], n1);
fprintf(fp, "%f;\n",hn[n1+1]);
n1++;

}

fprintf(fp, "];\nmidp=[%f;\n",mn[0]);

for (j=0; j<=tn ; j=j+h){
if (n2==divi) break;
mn[n2+1]=mn[n2]+h*sin(j+0.5*h)*cos(mn[n2]+0.5*h*sin(j)*cos(mn[n2]));
//printf("Midpoint %f %d\n", yn[n], n);
fprintf(fp, "%f;\n",mn[n2+1]);
n2++;
}
fprintf(fp, "];");
fclose(fp);
return 0;
}

