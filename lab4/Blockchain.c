#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Blockchain.h"
#include"Block.c"
#define ARRAYSIZE = 100
typedef struct BlockchainObj{
	int BcSize;//Blockchain size
	Block* theChain[ARRAYSIZE]
} BlockchainObj;

Blockchain newBlockchain(){
	Blockchain B = malloc(sizeof(BlockchainObj));
	assert(B!=NULL);
	B->BcSize = 0;
	theChain = new
	
}

void freeBlockchain(Blockchain* pB){

}

int append(Blockchain B, char* data){
	Block *theBlock = malloc(sizeof(Block));
	long theBlocksHash;
	int BlockchainSize
	if(B->BcSize == 0){
		theBlocksHash = 0;
	} else {
		B-> --BcSize;//so that we can get previous block's Hash Value
		theBlocksHash = get(B,BcSize)->hash;//Not sure if this works, or if we will have to make a new reference to a new Block.
		
		B-> ++BcSize; //to not screw with the actual size
	}
        theBlock = newBlock(data,BcSize,theBlocksHash);
        printBlock(stdout,theBlock);	
	
	BcSize ++;
}

int size(Blockchain B){

}

Block get(Blockchain B, int idx){

}

int valid(Blockchain B){

}

void removeLast(Blockchain B){

}

void printBlockchain(FILE* out, Blockchain B){

}
