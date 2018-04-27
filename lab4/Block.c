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
	 
}

/*
void freeBlock(Block* pB){
	if( pB!=NULL && *pB!=NULL){
		

	}

}
*/

char* data(Block B){
	return B->data;
}

long previousHash(Block B){
	return B->hash;
}

long hash(Block B){//construct a new hash value save then return?
	int sum = 0;
	for(int i = 0; i<strlen(data); i++){
		sum += B->data[i];
	}
	return B->hash;
}

void printBlock(FILE* out, Block B){
	fprintf(out,"%s","hello world");
	fprintf(out,"Id:%d\nPreviousHash:%ld",B->id,B->hash);
}
