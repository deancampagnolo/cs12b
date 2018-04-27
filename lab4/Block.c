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
	assert(B!=null);
	B->id = id;
	B->hash = hash;	
	 
}

void freeBlock(Block* pB){

}

char* data(Block B){

}

long previousHash(Block B){

}

long hash(Block B){

}

void printBlock(FILE* out, Block B){
	fprintf(out,"%s","hello world");
}
