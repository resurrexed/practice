#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * binary_search(int * array, size_t size, int num);
int * linear_search(int * array, size_t size, int num);

int main()
{
   srand(time(NULL));
   int array[20] = { 0 };
   int lnum = 0;
   int bnum = 0;
   for(size_t i = 1; i < 20; i++) array[i] = array[i - 1] + rand() % 100 + 1;
   puts("Generated array:");
   for(size_t i = 0; i < 20; i++) printf("%d\t", array[i]);
   
   puts("\nEnter number to linear search:");
   scanf("%d", &lnum);
   int * res = linear_search((int*)array, 20, lnum);
   if(res) printf("\nFounded index - %d\n", res - array);
   else printf("\nNumber not founded\n");

   puts("\nEnter number to binary search:");
   scanf("%d", &bnum);
   res = binary_search((int*)array, 20, bnum);
   if(res) printf("\nFounded index - %d\n", res - array);
   else printf("\nNumber not founded\n");

   return 0;
}
int * binary_search(int * array, size_t size, int num)
{
   int pivot = (size - 1) / 2;
   int step = size / 2;
   do
   {
      if(step != 1) step += step % 2;
      step = step / 2;
      if(array[pivot] == num) return array + pivot;
      else if(array[pivot] < num) pivot += step; 
      else if(array[pivot] > num) pivot -= step;
      if(pivot < 0) pivot = 0;
      if(pivot >= size) pivot = size - 1;
   } while(step);

   return NULL;
}

