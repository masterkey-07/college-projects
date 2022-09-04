#include <stdio.h>
#include <stdlib.h>

int f(int number){
	if (number < 2)
		return number;
	else 
		return f(number - 1) + f(number - 2);
}


int main(){
	int number;

	scanf("%d", &number);


	printf("\n%d", f(number));

	return 0;
}
