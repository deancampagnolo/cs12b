/*Dean Campagnolo
dcampagn (1599389)
12M
This file contains the code to reverse files
*/


#include <stdio.h> /* library with print fnc*/
#include <stdlib.h> /*lib with EXIT_SUCCESS*/
#include <string.h> /*lib with strlen*/

void stringReverse(char* s){


}
main(int argc, char* argv[]){
	FILE* in;//declares file input
	FILE* out;//declares file output
	char word[256]; //to store words from the input file
	in = fopen(argv[1], "r");
	
	while( fscanf(in, "%s", word) != EOF){
		printf("%s\n", word);
	}	
	printf("Hello World");
	return EXIT_SUCCESS;
}


