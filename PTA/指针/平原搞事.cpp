#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	double x, v, res;
	cin >> v >> x;
	res = (x * 9.8) / (v * v);
	printf("%lf %lf", (res * 57.2957), res);
	return 0;
}