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

int
main(void) {
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
	 fh_replacekey(a, arr[1],-38);
         fh_replacekey(a, arr[7],-34);
  
        printf("wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	 fh_replacekey(a, arr[2],-55);
         fh_replacekey(a, arr[5],-56);
        printf("Wert(minkey) %d\n",fh_minkey(a));
        printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	
	 fh_replacekey(a, arr[4],-1);
         fh_replacekey(a, arr[2],-102);
	 fh_replacekey(a, arr[6],-1);
         fh_replacekey(a, arr[9],-1);
	 fh_replacekey(a, arr[8],-4);
        printf("Wert(minkey) %d\n",fh_minkey(a));
        printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	 fh_replacekey(a, arr[3],-74);
         fh_replacekey(a, arr[8],-55);
	 fh_replacekey(a, arr[4],-2);
        	
        printf("Wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	 fh_replacekey(a, arr[4],-3);
         fh_replacekey(a, arr[6],-2);
         fh_replacekey(a, arr[7],-99);
        printf("Wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	 fh_replacekey(a, arr[6],-3);
         fh_replacekey(a, arr[4],-4);
	 fh_replacekey(a, arr[8],-94);
         fh_replacekey(a, arr[9],-2);
        printf("Wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
        fh_replacekey(a, arr[6],-4);
	
        printf("Wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	
        printf("Wert(minkey) %d\n",fh_minkey(a));
        printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
	/*fh_replacekey(a, arr[9],-3);*/
        printf("Wert(minkey) %d\n",fh_minkey(a));
	printf("Knoten: %lld\n\n", pointer_to_ll(fh_extractmin(a)));
     
        /*fh_replacekey(a, arr[9],-49);*/
 
	fh_deleteheap(a);

	return 0;
}
