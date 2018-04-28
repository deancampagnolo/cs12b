#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Blockchain.h"
#include"Block.c"
#define ARRAYSIZE 100
typedef struct BlockchainObj{
	int BcSize;//Blockchain size
	Block* theChain[ARRAYSIZE];
} BlockchainObj;

Blockchain newBlockchain(){
	Blockchain B = malloc(sizeof(BlockchainObj));
	assert(B!=NULL);
	B->BcSize = 0;
	
}
/*
void freeBlockchain(Blockchain* pB){

}
*/
int append(Blockchain B, char* data){
	Block *theBlock = malloc(sizeof(Block));
	long theBlocksHash;
	if(size(B) == 0){
		theBlocksHash = 0;
	} else {
		theBlocksHash = hash(get(B,size(B)-1));
		//theBlocksHash = hash(get(B,size(B)-1));//Not sure if this works, or if we will have to make a new reference to a new Block.
		
	}
        B->theChain[size(B)] = newBlock(data,size(B),theBlocksHash);
	
	B->BcSize = size(B)+1;
}

int size(Blockchain B){
	return B->BcSize;
}

Block get(Blockchain B, int idx){
	return B->theChain[idx];
}

int valid(Blockchain B){
	//Block* C = B->theChain;
	for(int i = size(B)-1; i>0;i--){
		if(previousHash(get(B, i)) != hash(get(B,i-1))){
			return 0;
		}
	}
	return 1;
}

void removeLast(Blockchain B){
	B->BcSize = size(B) - 1;
}

void printBlockchain(FILE* out, Blockchain B){
	for(int i = 0; i<size(B); i++){
		//fprintf(out,"%s",B->theChain[i]->);
		printBlock(out, B->theChain[i]);
	}
}
