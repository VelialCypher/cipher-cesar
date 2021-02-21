#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCODE "ENCODE"
#define DECODE "DECODE"

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
	return 0;
}