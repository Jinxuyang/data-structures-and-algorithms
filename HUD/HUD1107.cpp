#include <iostream>
using namespace std;

typedef struct
{
	int nl, wy, sm, x, y;
	char name;
} inf;
int i = 1;
void move(inf &dz ) {

	if (dz.name == 'S') {
		if (dz.y + 1 > 11 && i == 1) i = -1;
		else if (dz.y - 1 < 0 && i == -1) i = 1;
		dz.y += i;
	}
	else if (dz.name == 'W') {
		if (dz.x + 1 > 11 && i == 1) i = -1;
		else if (dz.x - 1 < 0 && i == -1) i = 1;
		dz.y += i;
	}
}
int main(int argc, char const *argv[])
{

	return 0;
}