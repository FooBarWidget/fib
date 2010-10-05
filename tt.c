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
	
    for (i=1 ; i < 8 ; i++)
     {
      arr[i]= fh_insertkey(a,0,int_to_pointer(i));
      printf("adding: 0 %d \n",i);
     }
     
     printf(" \n");

     fh_replacekey(a, arr[1],-2);
     fh_replacekey(a, arr[4],-3);
     fh_replacekey(a, arr[7],-5);
	  
     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a))); 
        
     fh_replacekey(a, arr[3],-2);
     fh_replacekey(a, arr[6],-1);
	
     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	
     fh_replacekey(a, arr[1],-9);
     fh_replacekey(a, arr[5],-3);

     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

     fh_replacekey(a, arr[2],-4);
     fh_replacekey(a, arr[5],-5);
     fh_replacekey(a, arr[6],-3);
        	
     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

     fh_replacekey(a, arr[2],-6);
     fh_replacekey(a, arr[6],-6);

     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));

     printf("Wert(minkey) %d\n",fh_minkey(a));
     printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
       	
     fh_deleteheap(a);

	return 0;
}

