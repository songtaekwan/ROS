#include <stdio.h>

float arr_x[4]={2, 4, 6, 8};
float arr_y[4]={81, 93, 91, 97};


float aver(float arr[])                                           //평균 값
{
	float sum=0;
	float average;
	
	for(int i=0; i<4; i++)
	{
		sum += arr[i];
	}
	average= sum / 4;
	
	return average;	
}
 
float a(float arrx[], float arry[])                                //기울기
{
	float divisor=0;
	float dividend=0;
	for(int i=0; i<4; i++)
	{
		divisor += (arrx[i]-aver(arr_x))*(arry[i]-aver(arr_y));
	}
	for(int i=0; i<4; i++)
	{
		dividend += (arrx[i]-aver(arr_x))*(arrx[i]-aver(arr_x));
	}
	return divisor / dividend;
}

float b(float mx, float my, float a)                               //y절편
{
	return my - (mx * a);
}

int main (void)
{
	float average_x = aver(arr_x);
	float average_y = aver(arr_y);
	
	float gradient = a(arr_x, arr_y);
	printf("기울기: %f\n", gradient);
	
	float intercept = b(average_x, average_y, gradient);
	printf("y절편: %f\n", intercept);
	
	printf("y = %fx + %f", gradient, intercept);
	
	return 0;
}
