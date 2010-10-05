#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fib.h"

#define TESTCASE	1

#define COUNT	100000
#define DIF	1000
#define MAXEXT	10
#define VERBOSE	1

int cmp(void *, void *);

int
cmp(void *x, void *y)
{
	if ((char *) x < (char *) y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

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
main(void)
{
#if !TESTCASE
	struct fibheap_el *w;
#else
	int e, j, k;
#endif
	struct fibheap *a;
	int i, x;

	a = fh_makeheap();
	fh_setcmp(a, cmp);

	srandom(time(NULL));
#if TESTCASE
#if VERBOSE
	printf("inserting: ");
#endif
	e = 0;
	for (i = 0; i < COUNT; i++) {
#if VERBOSE
		if (i)
			printf(", ");
#endif
		fh_insert(a, int_to_pointer(x = random()/10));
#if VERBOSE
		printf("%d", x);
#endif
		if (i - e > DIF) {
			k = random() % MAXEXT;
			for (j = 0; j < k; j++, e++)
				printf("throwing: %lld\n", pointer_to_ll(fh_extractmin(a)));
		}
	}

#if VERBOSE
	printf("\nremaining: %d\n", COUNT - e);
	printf("extracting: ");
#endif
	for (i = 0; i < COUNT - e; i++) {
#if VERBOSE
		if (i)
			printf(", ");
		printf("%lld", pointer_to_ll(fh_extractmin(a)));
#else
		fh_extractmin(a);
#endif
	}
#if VERBOSE
	printf("\n");
#endif
	if (fh_extractmin(a) == 0)
		printf("heap empty!\n");
	else {
		printf("heap not empty! ERROR!\n");
		exit(1);
	}
#else
	w = fh_insert(a, (void *)6);
	printf("adding: %d\n", 6);
	fh_insert(a, (void *)9);
	printf("adding: %d\n", 9);
	fh_insert(a, (void *)1);
	printf("adding: %d\n", 1);
	for(i = 0; i < 5; i++) {
		x = random()/10000;
		printf("adding: %d\n", x);
		fh_insert(a, (void *)x);
	}
	fh_insert(a, (void *)4);
	printf("adding: %d\n", 4);
	fh_insert(a, (void *)8);
	printf("adding: %d\n", 8);
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("deleting: %d\n", (int)fh_delete(a, w));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	for(i = 0; i < 5; i++) {
		x = random()/10000;
		printf("adding: %d\n", x);
		fh_insert(a, (void *)x);
	}
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
	printf("first: %d\n", (int)fh_extractmin(a));
#endif

	fh_deleteheap(a);

	return 0;
}
