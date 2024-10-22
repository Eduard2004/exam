#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {

	int left = 0;
	int right = strlen(str) - 1;

	while (left < right) {
		if (str[left] != str[right])
			return 0;
		left++;
		right--;

	}
	return 1;
}

int main() {
	char str[100];
	printf("Enter a string: ");
	scanf_s("%s", str);

	if (is_palindrome(str))
		printf("True\n");
	else
		printf("False\n");
	return 0;

}

