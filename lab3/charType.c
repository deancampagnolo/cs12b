/*Dean campagno



*/
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
	char* a, d, p, w; // string holding blank space 


	in=fopen(argv[1], "r");
	out=fopen(argv[2], "w");
 	  // allocate strings line and alpha_num on the heap 
  	line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  	a = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
        d = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
        p = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
        w = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  	assert( line!=NULL && blank!=NULL );

  	// read each line in input file, extract alpha-numeric characters 
	int counter = 1;
  	while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
		extract_chars(line, a, d, p, w);

		printOutEverything(line, a, d, p, w, counter, out);
		counter++;
   	}

   	// free heap memory 
   	free(line);
   	free(blank);

	// close input and output files 
   	fclose(in);
   	fclose(out);

   	return EXIT_SUCCESS;
}
void extract_chars(char* s, char* a, char* d, char* p, char* w){
	extract_alphabet(s,a);
	extract_number(s,d);
	extract_punctuation(s,p);
	extract_whitespace(s,w);
}

void extract_alphabet(char* s, char* a){
   	int i=0, j=0;
   	while(s[i]!='\0' && i<MAX_STRING_LENGTH){
      		if( isalpha( s[i]) ) a[j++] = s[i];
      		i++;
   	}
   	a[j] = '\0';
}
void extract_number(char*s, char*a){
 	int i=0, j=0;
        while(s[i]!='\0' && i<MAX_STRING_LENGTH){
                if( isdigit( s[i]) ) a[j++] = s[i];
                i++;
        }
        a[j] = '\0';
}
void extract_punctuation(char*s, char*a){
        int i=0, j=0;
        while(s[i]!='\0' && i<MAX_STRING_LENGTH){
                if( ispunct( s[i]) ) a[j++] = s[i];
                i++;
        }
        a[j] = '\0';
}
void extract_whitespace(char*s, char*a){
        int i=0, j=0;
        while(s[i]!='\0' && i<MAX_STRING_LENGTH){
                if( isspace( s[i]) ) a[j++] = s[i];
                i++;
        }
        a[j] = '\0';
}
void printOutEverything(char* s, char* a, char* d, char* p, char* w, int counter, FILE* out){
	char z;
	if(strlen(a)>1){
		z = 's';
	} else{
		z = '\0';
	}
	fprintf(out,"%s%d%s","line ",counter," contains:\n");
	fprintf(out,"%d%s%c%s%s%s",strlen(a)," alphabetic character",z,": ",a, "\n"); 
        if(strlen(d)>1){
                z = 's';
        } else{
                z = '\0';
        }
        fprintf(out,"%d%s%c%s%s%s",strlen(d)," numeric character",z,": ",d, "\n");
        if(strlen(p)>1){
	
                z = 's';
        } else{
                z = '\0';
        }
        fprintf(out,"%d%s%c%s%s%s",strlen(p)," punctuation character",z,": ",p, "\n");
        if(strlen(w)>1){
                z = 's';
        } else{
                z = '\0';
        }
        fprintf(out,"%d%s%c%s%s%s",strlen(w)," whitespace character",z, ": ",w, "\n\n");
}
