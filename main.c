#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCODE "encode"
#define DECODE "decode"

void cipher(unsigned char* string, int shift, unsigned char* type) {
	for (size_t i = 0; i < strlen(string); i++) {
		if(strcmp(type, ENCODE) == 0) {
			string[i] = (string[i] + shift) % 255;
		} else if(strcmp(type, DECODE) == 0) {
			string[i] = (string[i] - shift) % 255;
		}
	}
}

int main(int argc, char* argv[]) {
	char string[BUFSIZ];
	char option;
	int shift;

	printf("What do you want to do?\na.Encode\nb.Decode\nSelect: ");
	scanf("%c", &option);
	getchar();

	if(!(option == 'a' || option == 'b')) {
		printf("Entered invalid operation.\n");
		exit(1);
	}

	printf("Enter shift for %s: ", option == 'a' ? ENCODE:DECODE);
	scanf("%d", &shift);
	getchar();

	printf("Enter string to %s: ", option == 'a' ? ENCODE:DECODE);
	fgets(string, 100, stdin);

	cipher(string, 20, option == 'a' ? ENCODE:DECODE);

	printf("Your %sd string: %s\n", option == 'a' ? ENCODE:DECODE, string);

	return 0;
}