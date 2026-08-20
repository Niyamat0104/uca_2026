#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

void generateRandom(int *a, int s) {
    int i;
    for(int i = 0 ;  i < s; i++) {
        *(a+i) = rand() % s + 1 ;
    }
}

void swap(void *a , int i , int j , int sz) {
    char *temp = malloc(sizeof(char *));
    char *t1= (char *)(a+i*sz);
    char *t2= (char *)(a+j*sz);
    memcpy(temp,t1,sz);
    memcpy(t1,t2,sz);
    memcpy(t2,temp,sz);
    free(temp);



}

void print(int *a,int s) {
    int i;
    for(i=0;i<s;i++) {
        printf("%d",*(a+i));

    }
    printf("\n");
}

struct student {
    int id;
    float cgpa;

};

int intCmparator(void *i,void *j) {
    int x = *(int *)i;
    int y = *(int *)j;
    if(x==y){
        return 0;
    }
    if(x<y){
        return -1;
    }
    return +1;
}

int floatCmparator(void *i,void *j) {
    float x = *(float *)i;
    float y = *(float *)j;
    if(x==y){
        return 0;
    }
    if(x<y){
        return -1;
    }
    return +1; 
}

int studentIdCmp(void *i,void *j) {
    struct student *x = (struct student*)(i);
    struct student *y = (struct student*)(j);

    return x->id - y->id;
}


void genericHeapify(void *a,int i ,int n , int sz,int(*cmp)(void *,void *)){
    int largest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    char *base = (char *)a;

    void *current = base + i *sz;
    void *left;
    void *right;

    if(L<n) {
        left = base + L* sz;
       if(cmp(left,current) > 0){
        largest = L;
       }
    }
    current = base + largest * sz;
    if(R < n) {
        right = base + R*sz;
        if(cmp(right,current) > 0) {
            largest = R;
        }
    }

    if(largest != i) {
        swap(a,i,largest,sz);
        genericHeapify(a,largest,n,sz,cmp);
    }



}

void genericHeapSort(void *a,int n , int sz, int(*cmp)(void* , void*)){

    for(int i = n/2 -1; i>=0;i--){
        genericHeapify(a,i,n,sz,cmp);
    }

    for(int i = n-1 ; i>0;i--){
        swap(a,0,i,sz);
        genericHeapify(a,0,i,sz,cmp);
    }
}

void printFloat(float *a, int n) {

    for(int i = 0; i < n; i++) {

        printf("%.2f ", a[i]);
    }

    printf("\n");
}


 

void printStudents(struct student *a, int n) {

    for(int i = 0; i < n; i++) {

        printf(
            "ID = %d, CGPA = %.2f\n",
            a[i].id,
            a[i].cgpa
        );
    }

    printf("\n");
}


int main() {
    int a[] = {
        50,20,40,10,30
    };

    int n = sizeof(a) / sizeof(a[0]);
    printf("Integer before sorting: \n");
    print(a,n);

    genericHeapSort(a,n,sizeof(int),intCmparator);

    printf("Integer after sorting: \n");
    print(a,n);

    float f[] = {
        4.5 ,1.2,7.8,2.4,3.6
    };
    int fn = sizeof(f)/sizeof(f[0]);

    printf("\n Float before sorting: \n");
    printFloat(f,fn);
    genericHeapSort(f,fn,sizeof(float),floatCmparator);
    printf("Floast after sorting: \n");
    printFloat(f,fn);

    struct student s[] = {
        {103, 8.5},
        {101,9.2},
        {105,7.8},
        {102,8.9},
        {104,9.0}
    };
    int sn = sizeof(s)/sizeof(s[0]);

    printf("\n Students before sorting:\n");
    printStudents(s,sn);

    genericHeapSort(s,sn,sizeof(struct student),studentIdCmp);

    printf("Students after sorting by ID: \n");
    printStudents(s,sn);
    return 0;

}

