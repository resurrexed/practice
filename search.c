#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * binary_search(int * array, size_t size, int num);
int * linear_search(int * array, size_t size, int num);

int main()
{
   srand(time(NULL));
   int array[1000000] = { 0 };
   int lnum = 0;
   int bnum = 0;
   int size = 1000000;
   for(size_t i = 1; i < size; i++) array[i] = array[i - 1] + rand() % 100 + 1;
   puts("Generated array:");
   for(size_t i = 0; i < size ; i++) printf("%d\n", array[i]);
   puts("\nEnter number to linear search:");
   scanf("%d", &lnum);
   int * res = linear_search((int*)array, size, lnum);
   if(res) printf("\nFounded index - %d\n", res - array);
   else printf("\nNumber not founded\n");
   puts("\nEnter number to binary search:");
   scanf("%d", &bnum);
   res = binary_search((int*)array, size, bnum);
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
 int * linear_search(int * array, size_t size, int num)
{
   for(size_t i = 0; i < size; i++)
      if(num == array[i]) return array + i;

   return NULL;
}
