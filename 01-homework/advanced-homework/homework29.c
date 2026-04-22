#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[101], output[101];
	int count = 1, k = 0;
	gets(input);
	for (int i = 0; i < strlen(input); i++) {
		for (int j = 0; j < i; j++) {
			if (input[i] == input[j])
				count = 2;
		}
		if (count == 1) output[k++] = input[i];
		count = 1;
	}
	output[k] = '\0';
	puts(output);

	return 0;
}