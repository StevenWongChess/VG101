#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926
#include"universal_set.h"
#include "list.h"

void ex1(){
	int n;
	scanf("%d",&n);
	getchar();
	int *arr = calloc(n,sizeof(int));
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
		if (arr[i] > max)
			max = arr[i];
	}
	getchar();
	srand((unsigned)time(NULL));
	int r = rand()%max;
	printf("all numbers larger than %d\n", r);
	for(int i=0;i<n;i++){
		if (arr[i] > r)
			printf("%d ", arr[i]);
	}
	printf("\n");
};

typedef struct ptcartesian{
	float x, y;
}pt_cartesian;

typedef struct ptpolar{
	float r, theta;
}pt_polar;

void p2c(pt_polar *p, pt_cartesian *c, size_t n){
	for (int i=0;i<0;i++){
		c[i] = (pt_cartesian){p[i].r*cos(p[i].theta),p[i].r*cos(p[i].theta)};
	}
};

void c2p(pt_cartesian *c, pt_polar *p, size_t n){
	for (int i=0;i<0;i++){
		float r = sqrt(c[i].x*c[i].x+c[i].y*c[i].y);
		if (c[i].y >= 0)
			p[i] = (pt_polar){r, acos(c[i].x/r)};
		else
			p[i] = (pt_polar){r, acos(c[i].x/r)+PI/2};
	}	
};

void ex2(){
	pt_cartesian c[4]={{3,4.0/5.0},{0,log(4)},{45.245,0.235},{4*cos(PI/9),4*sin(PI/9)}};
	pt_polar p[2]={{3,PI/17},{1,PI/12}};
	pt_polar result_p[4];
	pt_cartesian result_c[2];
	c2p(c,result_p,4);
	p2c(p,result_c,2);
	// printing is easy.
};

void ex3(){
	char line[100];
	char word[10];
	int count = 0;
	FILE* fd = fopen("sentence.txt","r");
	fscanf(fd,"%[^\n]",line);
	fclose(fd);
	FILE* fd2 = fopen("word.txt","r");
	fscanf(fd2,"%[^\n]",word);
	fclose(fd2);
	int line_l = strlen(line);
	int word_l = strlen(word);
	for (int i = 0; i < line_l; i++){
		if(strncmp(word,line+i,word_l) == 0)
			count ++;
	}
	FILE* fd3 = fopen("count.txt","w");
	fprintf(fd3,"the string \'%s\' occurs %d times\n", word, count);
	fclose(fd3);
};

void ex4(){
	FILE* fd = fopen("matrices.txt", "r");
	int n = 1;
	char test[100];
	fscanf(fd, "%[^\n]", test);
	for(int i=0;i<100;i++){
		if(test[i] == ' ')
			n++;
	}
	int a[n][n];
	int b[n][n];
	//printf("%d\n",n);
	rewind(fd);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fd, "%d", &a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(fd, "%d", &b[i][j]);
		}
	}
	fclose(fd);

	FILE* fd2 = fopen("result.txt","w");
	fprintf(fd2, "first we print sum\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fprintf(fd2, "%d", a[i][j]+b[i][j]);
			if (j<n-1){
				fprintf(fd2, " ");
			}
		}
		fprintf(fd2, "\n");
	}
	fclose(fd);
};

void newSet(uset *set, int type){
	set->card = 0; set->type = type; set->mem = INITSETSIZE*type;
	set->elem = malloc(INITSETSIZE*type);
};
void deletSet(uset *set){
	free(set->elem);
}; 
void addElem(void *elem, uset *set){
	for(int i=0;i<set->card;i++){
		if(*(char*)(set->elem+i) == *(char*)elem)
			return;
	}
	if (set->card * set->type == set->mem){
		set->mem+=64;
		set->elem = (void*)realloc(set->elem,set->mem);
	}
	*(char*)(set->elem+set->card) = *(char*)elem;
	set->card++;
};
void remElem(void *elem, uset *set){
	//memmove
};

void ex5(){
	uset u;
	newSet(&u, CHAR);
	char a = 'a';
	void* p = &a;
	addElem(p, &u);
	deletSet(&u);
};

void ex6(){
	char line[100]; int choice; char alpha, beta;
	scanf("%[^\n]", line); 
	scanf("%d", &choice); // 1 to replace, 2 to delete
	getchar(); scanf("%c %c", &alpha, &beta);
	//printf("%c %c\n", alpha, beta);
	if (choice == 1){
		for (int i=0;i<100;i++){
			if (line[i] == alpha)
				line[i] = beta;
		}
	}
	else{
		for (int i=0;i<100;i++){
			if (line[i] == alpha){
				memmove(&line[i], &line[i+1], (99-i));
				i--;
			}
		}
	}
	printf("%s\n", line);

};

// Ex7 starts

node_t *Initialize(char ch) {
	node_t *head;
	head=(node_t*)calloc(1,sizeof(node_t));
	if(head==NULL){ 
		fprintf(stderr,"Failed to assign memory!\n"); 
		exit(-1); 
	} 
	head->next=NULL; head->ch=ch;
	return head;
};

void PrintList(node_t *head) {
	node_t *temp=head;
	printf("***Print Linked List***\n");
	while(temp!=NULL) { 
		printf("%c ",temp->ch); 
		temp=temp->next; 
	} 
	printf("\n****Print Finished****\n\n");
};

void FreeList(node_t **head) {
	node_t *tmp=NULL; 
	node_t *pHead=*head;
	while(pHead->next!=NULL) { 
		tmp=pHead; 
		pHead=pHead->next; 
		free(tmp); 
	} 
	free(pHead);
};

bool IsEmptyList(node_t *head){
	// Return true if the list is empty, false otherwise
	if (head == NULL)
		return true;
	else
		return false;
}; 

void InsertFirstList(node_t **head,char insert_char){
	// Prepend a node
	node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
	newNode->ch = insert_char;
	newNode->next = *head;
	*head = newNode;
};

void InsertLastList(node_t **head,char insert_char){
	// Append a node
	node_t *newNode = (node_t*)calloc(1,sizeof(node_t));
	newNode->ch = insert_char;
	newNode->next = NULL;
	if(!*head)
		*head = newNode;
	else{
		node_t *it = *head;
		while(it->next){
			it = it->next;
		}
		it->next = newNode;
	}
};

void DeleteFirstList(node_t **head){
	// Delete the first element in the list
	if (IsEmptyList(*head))
		return;
	node_t *tmp = *head;
	*head = (*head)->next;
	free(tmp);
};

void DeleteLastList(node_t **head){
	// Delete the last element in the list
	node_t* it = *head;
	if(!(*head))
		return;
	if(!(*head)->next){
		free(*head);
		*head = NULL;
		return;
	}
	while(it->next->next){
		it = it->next;
	}
	free(it->next);
	it->next = NULL;
};

int SizeList(node_t *head){
	// Return the size of the list
	int size = 0;
	node_t *it = head;
	while(it){
		size++;
		it = it->next;
	}
	return size;
};

int SearchList(node_t **head, char target){
	// Count how many times target appears
	int count = 0;
	node_t* it = *head;
	while(it){
		if (target == it->ch)
			count++;
		it = it->next;
	}
	return count;
};

void SplitList(node_t **head, node_t **tail, int pos){
	// Split into [0;pos-1] and [pos,end]
	node_t *it = *head;
	int countdown = pos - 1;
	for(int i=0;i<pos;i++){
		it = it->next;
	}
	*tail = it->next;
	it->next = NULL;
};

void MergeList(node_t **head1, node_t **head2){
	// Merge two lists
	if(!(*head1)){
		*head1 = *head2;
		*head2 = NULL;
		return;
	}
	node_t *it = *head1;
	while(it->next){
		it = it->next;
	}
	it->next = *head2;
	*head2 = NULL;
};

void ex7(){
	node_t *a=Initialize('1'); 
	node_t *b=NULL; 
	PrintList(a);
	InsertFirstList(&a, 'V'); 
	InsertFirstList(&a, 'M');
	PrintList(a); 
	InsertLastList(&a, 'C'); 
	PrintList(a);
	SplitList(&a, &b, 2); 
	PrintList(a); 
	PrintList(b);
	DeleteFirstList(&a); 
	PrintList(a); 
	InsertLastList(&a, 'G');
	DeleteLastList(&b); 
	PrintList(b); 
	InsertLastList(&b,'0');
	PrintList(b); 
	InsertLastList(&b, '1'); 
	PrintList(b);
	MergeList(&a,&b); 
	PrintList(a);
	char target='G';
	printf("Count '%c': %d\n",target, SearchList(&a,target)); 
	target='1';
	printf("Count '%c': %d\n",target, SearchList(&a,target)); 
	FreeList(&a);
	return;
};

int main(int argc, char const *argv[])
{
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	//ex6();
	//ex7();
	return 0;
}




