/* main.c simple program to run assembler subroutines */

#include <stdio.h>
#include <string.h>

/* Prototypes (declarations without definitions) of the subroutines that
 * are defined in assembly language.  All parameters and return values
 * are 64-bit values, either of type long long int or pointers to
 * arrays or strings.  */

// Compute the sum of a[0], a[1], ..., a[count-1]
extern long long int arraysum(long long int a[], long long int count);

// Compute a*b + c
extern long long int muladd(long long int a, long long int b, long long int c);

// Count the number of occurrences of the char ch in the string str, where len is the length of the string
extern long long int countchars( char* str, long long int len, long long int ch);

// Copy a[0], a[1], ..., a[ct-1] into b[0], b[1], ..., b[ct]
extern void arraycopy( long long int A[], long long int B[], long long int ct);


int main(void) {

	/* Start with two calls to arraysum.  Values should be 65 and 75. */

	long long int a[] = { 10, 20, 30, 5, 4, 3, 2, 1 };
    long long int s = arraysum(a, 4);
    printf("\n\nResult of arraysum(a,4) = %lld\n", s);
    s = arraysum(a, 8);
    printf("Result of arraysum(a,8) = %lld\n\n", s);

    /* call muladd(x,y,z), which simply computes x*y + z.  Should return 89. */

    long long int x = 7, y = 12, z = 5;
    long long int ans = muladd(x,y,z);
    printf("x*y + z is %lld\n\n", ans);

    /* Call countchars to count the number of times 'e' occurs in a string.
     * The value should be 7. */

    char* saying = "In world without walls, who needs Windows? In a world without fences, who needs Gates?";
    long long int len = strlen(saying);  // (use a standard C function)
    long long int ct = countchars(saying, len, 'e');
    printf("Number of e's in the saying is %lld\n\n", ct);


    /* Call arraycopy to copy 5 values from one array to another
     * Output should be 10, 20, 30, 5, 4 */

    long long int b[5];  // an array of length 5
    arraycopy(a,b,5);
    for (int i = 0; i < 5; i++) {
    	printf("b[%d] = %lld\n", i, b[i]);
    }


    return 0;
}
