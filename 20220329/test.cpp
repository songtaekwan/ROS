#include <stdio.h>
#include <string>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	
	printf("%s + %s = %f\n", argv[1],argv[2],atof(argv[1])+atof(argv[2]));
	printf("%s - %s = %f\n", argv[1],argv[2],atof(argv[1])-atof(argv[2]));
	printf("%s * %s = %f\n", argv[1],argv[2],atof(argv[1])*atof(argv[2]));
	printf("%s / %s = %f\n", argv[1],argv[2],atof(argv[1])/atof(argv[2]));
	
	return 0;
	
	
	/*
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	printf("a+b= %d\n",a+b);
	printf("a-b= %d\n",a-b);
	printf("a*b= %d\n",a*b);
	printf("a/b= %d\n",a/b);
	
	return 0;
/*
 printf("argc = %d\n",argc);
 
 printf(" %s\n",argv[0]);
 
 return 1;
 */
}
