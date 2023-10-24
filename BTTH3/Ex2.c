#include <stdio.h>
int main() {
	int x;
	scanf("%d", &x);
	if (x <= 0) {
		printf("INVALID");
	} else if ((x % 400 == 0 ) || (x % 4 == 0 && x % 100 != 0 )) {
		printf("YES");
	} else {
		printf("NO");
	}
	return 0;
}