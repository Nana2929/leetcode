#include<stdio.h>



int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int * p = arr;  // p指向arr[0]
    int v = ++*p;
    int v2 = *p++;
    int v3 = *++p;
    printf("++*p: %d\n", v);  
    printf("*p++: %d\n", v2);
    printf("*++p: %d\n", v3);

    // print final value of arr
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
}