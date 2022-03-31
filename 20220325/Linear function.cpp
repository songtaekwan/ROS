// x, y값을 받아서 1차 함수를 출력하는 프로그램
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main (void)
{
	vector<int> vec_x(5);
	vector<int> vec_y(5);
	float a, b;
		
	for(int i=0; i<5; i++)
	{
		cin>> vec_x[i];
	}
	for (int i = 0; i < vec_x.size(); i++)
        cout << "x = " << vec_x.at(i) << " ";
	
	for(int i=0; i<5; i++)
	{
		cin>> vec_y[i];
	}
	for (int i = 0; i < vec_y.size(); i++)
        cout << "y = "<< vec_y.at(i) << " ";
	
	a = (vec_y[1] - vec_y[0]) / (vec_x[1] - vec_x[0]);
	b = vec_y[1] - (a * vec_x[1]);
	
	cout << "" <<endl;
	cout << " y = " << a << " x + " << b << endl;
}
