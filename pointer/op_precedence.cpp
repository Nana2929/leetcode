#include <stdio.h>

/*
prefix ++與 *的運算優先權相同，因此關聯性為從右到左。<-
postfix ++的運算優先權高於 prefix ++與 *，因此關聯性為從左到右。 ->
Prefix ++: 在變數前面，先加1再取值，效果會反映在該行的運算中
Postfix ++: 在變數後面，先取值再加1，效果會反映在下一行的運算中 
*/

void test1()
{

   int arr[] = {10, 20, 30, 40, 50};
   int * p = arr;  // p指向arr[0]
   int v = ++*p;
   printf("++*p: %d\n", v);  // 兩者優先權相同時，靠近變數的運算子優先權越高，相當於++(*p)= 11,取值拿到10後+1
   // *p = 11,會改變arr[0]的值！！
   // stdout: 11
}

void test2()
{
   int arr[] = {10, 20, 30, 40, 50};
   int * p = arr;
   int v = *p++;  // 相當於 *(p++), ++的動作要在;後才執行因此取值時拿到的是p原本的位置,效果上等同 v=*(p)=10, p=p+1
   // *p = 20
   printf("*p++: %d\n", v);
   // stdout: 10
}
void test3()
{
   int arr[] = {10, 20, 30, 40, 50};
   int *p = arr;
   int v = *++p;  // 相當於*(++p), ++的動作要在;前執行因此取值時拿到的是p+1的位置,效果上等同 v=*(p+1)=20
                  // 沒有改變arr
   printf("*++p: %d\n", v);
   // stdout: 20
}

int main()
{
   test1();
   test2();
   test3();
   return 0;
}