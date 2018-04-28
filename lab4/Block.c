#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Block.h"


typedef struct BlockObj{
	char* data;
	int id;
	long hash;

} BlockObj;


Block newBlock(char* data, int id, long hash){
	Block B = malloc(sizeof(BlockObj));
	assert(B!=NULL);
	B->id = id;
	B->hash = hash;	
	B->data = data; 
}

void freeBlock(Block* pB){
	if( pB!=NULL && *pB!=NULL){
		free(*pB);
		*pB = NULL;		
	}
}

char* data(Block B){
	return B->data;
}

long previousHash(Block B){
	return B->hash;
}
long hash(Block B){
	long sum = 0;
	char* k;
	k = data(B);
          for(int i = 0; i<strlen(k); i++){
                sum += k[i];
                  //printf("sum: %d",sum);
          }
	sum = sum + B->id + previousHash(B);
          return sum;
  }

void printBlock(FILE* out, Block B){
	fprintf(out,"Id:%d\nPreviousHash:%ld\n",B->id,B->hash);
}
