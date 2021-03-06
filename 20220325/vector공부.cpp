//개념 정리
//벡터 선언
vector<int> v;
v.pushback(7);

//2차원 벡터 선언
vector<vector<int>> v;
vector<int> v2;

v.pushback(v2);

//1차원 벡터 초기화
/*
해당 vector는 10개의 원소를 가지고 있고, 각 값은 0으로 초기화
*/
vector<int> v(10,0);


//2차원 벡터 초기화
/*
위와 같이 10개의 원소를 가지고 있고, 각 원소(vector)는 10개의 원소를 가지고 이 원소들은 0으로 초기화 된다.
v[0][0] ~ v[10][10] 까지 전부 0인 2차원 vector로 초기화했음을 의미한다.
*/
vector<vector <int>> v(10,vector <int>(10,0));
