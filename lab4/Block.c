/* 
 * Aaron Swoiskin
 * aswoiski
 * Dean Campagnolo
 * dcampagn
 *
 * Block.c
 * this file contains the class Block and its methods
 * */

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
	return(B);
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
long hash(Block B){//data + id + hash
	long sum = 0;
	char* k;
	k = data(B);
          for(int i = 0; i<strlen(k); i++){
                sum += k[i];
          }
	sum = sum + B->id + previousHash(B);
          return sum;
  }

void printBlock(FILE* out, Block B){
	fprintf(out,"%d:%s\n",B->id,B->data);
}
