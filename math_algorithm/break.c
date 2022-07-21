#include <stdio.h>

int
main()
{
 int i;

 for (i = 0; i < 10; i++) {
   printf("before if : %d\n", i);

   if (i > 2) {
     break;
   }

   printf("after if : %d\n", i);
 }

 return 0;
}