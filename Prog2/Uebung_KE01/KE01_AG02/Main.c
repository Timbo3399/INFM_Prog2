#include <stdio.h>

void main()
{
	printf("Sizeof char in Bytes ist: %zu\n", sizeof(char));
	printf("Sizeof signed char in Bytes ist: %zu\n", sizeof(signed char));
	printf("Sizeof unsigned char in Bytes ist: %zu\n", sizeof(unsigned char));
	printf("Sizeof short int in Bytes ist: %zu\n", sizeof(short int));
	printf("Sizeof int in Bytes ist: %zu\n", sizeof(int));
	printf("Sizeof unsigned short int in Bytes ist: %zu\n", sizeof(unsigned short int));
	printf("Sizeof unsigned int in Bytes ist: %zu\n", sizeof(unsigned int));
	printf("Sizeof long int in Bytes ist: %zu\n", sizeof(long int));
	printf("Sizeof unsigned long int in Bytes ist: %zu\n", sizeof(unsigned long int));
	printf("Sizeof long long int in Bytes ist: %zu\n", sizeof(long long int));
	printf("Sizeof unsigned long long int in Bytes ist: %zu\n", sizeof(unsigned long long int));
	printf("Sizeof float in Bytes ist: %zu\n", sizeof(float));
	printf("Sizeof double in Bytes ist: %zu\n", sizeof(double));
}