#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

int isprime(int n){
	if (n<2)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i < sqrt(n)+1; i++){
		if (n%i == 0)
			return 0;
	}
	return 1;
};

void ex1(){
	int n;
	scanf("%d", &n);
	int *arr = calloc(n,sizeof(int));
	// actually size of arr can be changed into O(log n)
	int num = 0;
	for(int i = 1; i < n; i++){
		if (isprime(i)){
			arr[num] = i;
			num++;
		}
	}
	for(int i = 0; i < num; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	free(arr);
};

void ex2(){
	int month;
	char first_day[10];
	scanf("%d %s", &month, first_day);
	const char *month_arr[] = {"January","February","March","April",
		"May","June","July","August","September","October",
		"November","December"};
	const char *day_arr[] = {"Sun","Mon","Tue","Wed","Thu",
		"Fri","Sat","Sun"};
	const int days_arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	int blank;
	int days = days_arr[month-1];
	for(int i = 0; i < 7; i++){
		if(strncmp(first_day,day_arr[i],3) == 0)
		//if(strcmp(first_day,day_arr[i]) == 0)
			blank = i;
	}

	printf("%s\n", month_arr[month-1]);
	for(int i = 0; i < 7; i++){
		printf("%s\t", day_arr[i]);
	}
	printf("\n");

	for(int i = 0; i < blank + days; i++){
		if (i<blank)
			printf("\t");
		else{
			printf("%d\t", i-blank+1);
		}
		if((i+1)%7 == 0)
			printf("\n");
	}
	if ((blank + days)%7 != 0)
		printf("\n");
};

void ex3(){
	char line[100];
	char word[10];
	int count = 0;
	scanf("%[^\n]", line);
	getchar();
	scanf("%[^\n]", word);
	getchar();
	int line_l = strlen(line);
	int word_l = strlen(word);
	for (int i = 0; i < line_l; i++){
		if(strncmp(word,line+i,word_l) == 0)
			count ++;
	}
	printf("the string \'%s\' occurs %d times\n", word, count);
};

float v,theta,height;

float f(float x){
	float y = 1.5 + tan(theta)*x - 9.81*x*x/(2*v*v*cos(theta)*cos(theta));
	return y;
}

void ex4(){
	//printf("%e\n", FLT_EPSILON);
	float left, right,mid;
	scanf("%f %f %f %f %f", &v, &theta, & height, &left, &right);
	mid = (left+right)/2;
	theta = theta/180*3.1415926;
	//while(mid-left>FLT_EPSILON){
	while(mid-left>0.00001){
		if (f(left)*f(mid) <= 0)
			right = mid;
		else
			left = mid;
		mid = (left+right)/2;
	}
	printf("%f is the answer\n", mid);
};

const char *point[] = {"2","3","4","5","6","7","8",
	"9","10","Jack","Queen","King","Ace"};
const char *color[] = {"Spades","Hearts","Diamonds",
	"Clubs"};

void print_deck(int *deck){
	printf("-----printing starts-----\n");	
	for(int i = 0;i < 52; i++){
		char str[20] = {};
		strcat(str, point[(deck[i]/4)%13]);
		strcat(str, color[deck[i]%4]);
		printf("%s\n", str);
	}
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shuffle(int *deck){
	srand((unsigned)time(NULL));
	int range = rand()%100 + 100;
	for(int i = 0;i < range; i++){
		int a = rand()%52;
		int b = rand()%52;
		swap(&deck[a], &deck[b]);
	}
}

int cmpf(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void ex5(){
	int deck[52];
	for(int i = 0;i < 52; i++)
		deck[i] = i;
	print_deck(deck);
	shuffle(deck);
	print_deck(deck);
	qsort(deck, 52, sizeof(int), cmpf);
	print_deck(deck);
};

#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; }
unsigned long int mult(unsigned long int a, unsigned long int b){
	int i, n, N;
	unsigned long int x0,y0,z0,z1=1;
	if(a<b) SWAP(a,b);
	if(b==0) return 0;
	for(n=-1, i = 1; i <= b; i<<=1, n++)
		; /* not optimal */ 
	for(N=n; i <= a; i<<=1, N++)
		;
	y0=b&((1<<n)-1); 
	x0=a&((1<<N)-1); 
	z0=mult(x0,y0); 
	i=N+n;
	return ((z1<<i)+(x0<<n)+(y0<<N)+z0);
};

//#define TEST 1
void ex6(){
	unsigned long int a, b;
	srand(time(NULL));
	#ifndef TEST
    	a=rand(); b=rand();
		printf("%ld*%ld=%ld %d\n",a,b,mult(a,b), RAND_MAX); 
	#endif
	#ifdef TEST
		int i;
		for(i=0; i< 1000000; i++) {
			a=rand(); b=rand(); 
			if(mult(a,b)!=a*b) {
				fprintf(stderr, "Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n" , i,a,b,a*b,mult(a,b));
				exit(-1); 
			}
		}
	#endif
};

int main(int argc, char const *argv[])
{
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	//ex6();
	return 0;
}






