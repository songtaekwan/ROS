#include <iostream>
#include <cmath>
#include <string>


using namespace std;

float datax[20];
float datay[20];

float n =0;

float EE(float x0, float x1, float y0, float y1)                     //임계치 설정
{
	return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

float dis(float x, float y, float a, float b)                        //점과 직선사이 거리 공식
{
	return abs(a * x - y + b) / sqrt(a * a + b * b);
}

float  f(float a, float b)                                           //점과 직선사이 거리 평균
{
	float sum;
	sum = 0.0;
	for (int i = 0; i < n; i++) 
	{
		sum += dis(datax[i], datay[i], a, b) / n;
	}
	return sum;
}

float dfabda(float a, float b, float da)                             //수렴하는 a값 구하는 함수
{
	return (f(a + da, b) - f(a, b)) / da;
}
  
float dfabdb(float a, float b, float db)                               //수렴하는 b값 구하는 함수
{
	return (f(a, b + db) - f(a, b)) / db;
}

int main() 
{  
	for (int i = 0; i < 20; i++)
    {
        datax[i] = i+0.5;
        datay[i] = i+1.0;
        n += i;
        printf("%f %f\n", datax[i], datay[i]);
    }
	
	float a0 = 0, b0 = 0;
	int iteration = 0;                                                  //시행횟수
	float eta = 0.0001;
	float psi = 0.005;
	float da = 0.01;
	float db = 0.01;
	float a1 = 2, b1 = 0;                                               //초기 기울기, y절편
	while (EE(a0, b0, a1, b1) > eta && iteration < 100000) 
	{
		a0 = a1;
		b0 = b1;
		a1 -=   psi * dfabda(a0, b0, da);
		b1 -=   psi * dfabdb(a0, b0, db);
		iteration++;
	}
	cout << " y  = " << a1 << "x + " << b1 << endl;
	cout << iteration << "-th  E = " << EE(a0, b0, a1, b1) << endl;
	return 0;
}
