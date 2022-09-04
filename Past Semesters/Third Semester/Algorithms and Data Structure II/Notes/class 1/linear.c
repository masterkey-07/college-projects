#include <stdio.h>
#include <stdlib.h>

int main(){
	int number;

	scanf("%d", &number);

	int a  =0, b =0 , c=1, i;

	for (i = 0; i <= number; i++){
		a = b + c;
		c = b;
		b = a;
	}

	printf("\n%d", c);

	return 0;
}
