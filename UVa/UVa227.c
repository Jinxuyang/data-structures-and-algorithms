#include <stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	int count = 0;
	while (1) {
		char f[5][5], temp;
		/*for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
			f[i][j] = 0;
			}
		}*/
		count++;
		int x, y;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if ((temp = getchar()) != '\n') {
					if (temp == 'Z') return 0;;
					f[i][j] = temp;
					if (f[i][j] == ' ') {
						x = i;
						y = j;
					}
				}
				else j--;
			}
		}
		char op = '0';
		int ok = 1;
		while ((op = getchar()) != '0') {
			switch (op) {
			case 'A':
				if (x - 1 >= 0 ) {f[x][y] = f[x - 1][y]; f[x - 1][y] = ' '; x = x - 1;}
				else ok = 0;
				break;

			case 'B':
				if (x + 1 < 5 ) {f[x][y] = f[x + 1][y]; f[x + 1][y] = ' '; x = x + 1;}
				else ok = 0;
				break;

			case 'L':
				if (y - 1 >= 0) {f[x][y] = f[x][y - 1]; f[x][y - 1] = ' '; y = y - 1;}
				else ok = 0;
				break;
			case 'R':
				if (y + 1 < 5) {f[x][y] = f[x][y + 1]; f[x][y + 1] = ' '; y = y + 1;}
				else ok = 0;
				break;
			default: break;
			}
		}
		printf("Puzzle #%d:\n", count);
		int isfil = 1, isfic = 1;
		if (ok) {
			for (int i = 0; i < 5; i++) {
				if (!isfil) {
					isfic = 1;
				}
				else isfil = 0;
				for (int j = 0; j < 5; j++) {
					if (isfic) {
						printf("%c", f[i][j]);
						isfic = 0;
					}
					else printf(" %c", f[i][j]);
				}
				printf("\n");
			}
		}
		else printf("This puzzle has no final configuration.\n");
	}
	return 0;
}