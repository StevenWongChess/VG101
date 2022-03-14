#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>

typedef struct complex_{
	float re;
	float im;
}complex;

complex sum(complex x, complex y){
	complex a = {x.re+y.re, x.im+y.im};
	return a;
};
complex product(complex x, complex y){
	complex a = {x.re*y.re-x.im*y.im, x.re*y.im+y.re*x.im};
	return a;
};
void write(complex a){
	if (a.im >= 0)
		printf("%.1f+%.1fi\n",a.re,a.im);
	else
		printf("%.1f%.1fi\n",a.re,a.im);
};

void ex1(){
	complex a,b;
	char op;
	scanf("%f%fi %f%fi %c",&a.re,&a.im,&b.re,&b.im, &op);
	if (op == '+')
		write(sum(a,b));
	else if (op == '*')
		write(product(a,b));
	else
		printf("wrong!!!\n");
};

int gcd(int x, int y){
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	if (x >= y)
		return gcd(x-(x/y)*y,y);
	else
		return gcd(x,y-(y/x)*x);
};

void ex2(int a, int b){
	int x = abs(a);
	int y = abs(b);
	printf("gcd is %d\n", gcd(x,y));
};

void ex3(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if (b*b-4*a*c < 0)
		printf("error, no root\n");
	else{
		float r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		float r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		printf("roots are %.2f and %.2f\n", r1, r2);
	}

};

int main () { 
	//ex1();
	//ex2(-20,0);
	//ex3();
	return 0;
}
