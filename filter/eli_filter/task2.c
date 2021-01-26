#include <stdio.h>
#include <string.h>

char oppositeCase (char c) {
	char ans = c;
	/*A-Z 65-90 a-z 97-122*/
	if(c >= 'a' && c <= 'z') {
		ans = c - 32;
	}
	else if (c >= 'A' && c<= 'Z') {
		ans = c + 32;
	}
	return ans ;
}

/* 0 - true
   1 - false */
int contains (char* characters, char c) {
	int i ;
	for (i=0; i<strlen(characters); ++i) {
		if (characters[i] == c || characters[i] == oppositeCase(c))
			return 0 ;
	}
	return 1 ;
}

/*
 * outputStream - stream write to
 * characters - what characters to filter
 */
void filter (char* characters, FILE* outputStream) {
	char input ;
	while ((input = fgetc(stdin)) != EOF) {
		if (contains (characters, input) == 0)  /* meaning that we need to print the character */
			fputc(input, outputStream) ;
	}
} 

int main(int argc, char** argv){
	char *param = "h" ; /* default case */
	FILE* readFrom = stdin ;
	FILE* writeTo = stdout ;
	char buffer[30] ; /* to read from the input file */ 
	buffer[0] = 0 ;
	int i ;

	if (argc > 1) { /* if arguments provided */
		for (i=1; i<argc; ++i) {
			if (strcmp (argv[i], "-o") == 0) {
				printf ("Enter output file: \n") ;
				char out[30] ;
				fgets (out,30,stdin) ;
				out[strlen(out)-1] = '\0' ; /* instead of \n in the end */
				writeTo = fopen (out, "w") ;
			}

			else if (strcmp (argv[i], "-i") == 0) {
				readFrom = fopen(argv[i+1], "r") ;
				if (readFrom == NULL) {
					perror ("FILE cannot be opened for reading") ;
					return 1 ;
				}
			}
			else
				param = argv[i] ;
		}
	}

	printf ("Start writing your string, Ctrl+D for exit: \n") ;

	if (readFrom != stdin) {
		fgets (buffer,30,readFrom) ;
		fclose(readFrom) ;
	}

	if (buffer[0] != 0) /* if I read something*/
		filter (buffer, writeTo) ;
	else
		filter (param, writeTo) ;

	return 0 ;

}

