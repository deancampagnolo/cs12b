#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include<stdio.h>
#define MAX_STRING_LENGTH 100

// function prototype 

// function main which takes command line arguments 
int main(int argc, char* argv[]){
   	FILE* in;        // handle for input file                  
  	FILE* out;       // handle for output file                 
  	char* line;      // string holding input line              
	char* alpha_num; // string holding all alpha-numeric chars 

	in=fopen(argv[1], "r");
	out=fopen(argv[2], "w");
 	  // allocate strings line and alpha_num on the heap 
  	line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  	alpha_num = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  	assert( line!=NULL && alpha_num!=NULL );

  	// read each line in input file, extract alpha-numeric characters 
	int counter = 1;
  	while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
     		//extract_alpha_num(line, alpha_num,out, 1);
		printOutEverything(line, alpha_num, out, 1);
     		fprintf(out, "%s\n", alpha_num);
		counter++;
   	}

   	// free heap memory 
   	free(line);
   	free(alpha_num);

   // close input and output files 
   	fclose(in);
   	fclose(out);

   	return EXIT_SUCCESS;
}

// function definition 
void extract_alpha_num(char* s, char* a){
   	int i=0, j=0;
   	while(s[i]!='\0' && i<MAX_STRING_LENGTH){
      		if( isalnum( s[i]) ) a[j++] = s[i];
      		i++;
   	}
   	a[j] = '\0';
}
void printOutEverything(char*s, char* a, FILE* out, int counter){
	fprintf(out,"%s%d%s","line ",counter," contains:");
	printf("hif");
//	while(s[i]!='\0' && i<MAX_STRING_LENGTH){
		
//	}

}
