#include <stdio.h>
#include <stdlib.h>
#include "fib.h"

void *
int_to_pointer(int x)
{
    /* Using a union to prevent aliasing issues and compiler warnings. */
    union {
        void *pointer;
        int value;
    } u1;
    union {
        void *pointer;
        long long value;
    } u2;
    
    if (sizeof(void *) == sizeof(int)) {
        u1.value = x;
        return u1.pointer;
    } else if (sizeof(void *) == sizeof(long long)) {
        u2.value = x;
        return u2.pointer;
    } else {
        fprintf(stderr, "Pointer size unsupported...");
        abort();
        return 0;
    }
}

long long
pointer_to_ll(void *p) {
    /* Using a union to prevent aliasing issues and compiler warnings. */
    union {
        void *pointer;
        int value;
    } u1;
    union {
        void *pointer;
        long long value;
    } u2;
    
    if (sizeof(void *) == sizeof(int)) {
        u1.pointer = p;
        return u1.value;
    } else if (sizeof(void *) == sizeof(long long)) {
        u2.pointer = p;
        return u2.value;
    } else {
        fprintf(stderr, "Pointer size unsupported...");
        abort();
        return 0;
    }
}

int main(void)
{
	struct fibheap *a;
	void *arr[10];
	int i;

	a = fh_makekeyheap();
	
	for (i=1 ; i < 10 ; i++)
	  {
              arr[i]= fh_insertkey(a,0,int_to_pointer(i));
	      printf("adding: 0 %d \n",i);
	  }
     
	printf(" \n");
	 fh_replacekey(a, arr[1],-1);
         fh_replacekey(a, arr[6],-1);
	 fh_replacekey(a, arr[4],-1);
         fh_replacekey(a, arr[2],-1); 
         fh_replacekey(a, arr[8],-1); 
	  
        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));          
     
	 fh_replacekey(a, arr[7],-33);
/* -> node 7 becomes root node, but is still pointed to by node 6 */
         fh_replacekey(a, arr[4],-36);
	 fh_replacekey(a, arr[3],-1);
         fh_replacekey(a, arr[9],-81); 	
	
        printf("value(minkey) %d\n",fh_minkey(a));
        printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	
	 fh_replacekey(a, arr[6],-68);
         fh_replacekey(a, arr[2],-69);

        printf("value(minkey) %d\n",fh_minkey(a));
        printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

	 fh_replacekey(a, arr[1],-52);
         fh_replacekey(a, arr[3],-2);
	 fh_replacekey(a, arr[4],-120);
         fh_replacekey(a, arr[5],-48); 	

        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

	 fh_replacekey(a, arr[3],-3);
         fh_replacekey(a, arr[5],-63);

        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

	 fh_replacekey(a, arr[5],-110);
         fh_replacekey(a, arr[7],-115);

        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

         fh_replacekey(a, arr[5],-188);

        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

         fh_replacekey(a, arr[3],-4);

        printf("value(minkey) %d\n",fh_minkey(a));
	printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	
        printf("value(minkey) %d\n",fh_minkey(a));
        printf("id: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

	fh_deleteheap(a);

	return 0;
}
