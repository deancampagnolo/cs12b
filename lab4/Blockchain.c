/* 
 * Aaron Swoiskin
 * aswoiski
 * Dean Campagnolo
 * dcampagn
 *
 * Blockchain.c
 *This is the file that contains the Blockchain class and its methods
 * */
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
	return(B);	
}
void freeBlockchain(Blockchain* pB){
	if(pB != NULL && *pB != NULL){
		while(size(*pB)>0){//While there are still Blocks
			removeLast(*pB);	
		}
		free(*pB);
		*pB = NULL;
	}
}

int append(Blockchain B, char* data){
   if(valid(B) == 1){
	long theBlocksHash;
	if(size(B) == 0){
		theBlocksHash = 0;
	} else {
		theBlocksHash = hash(get(B,size(B)-1));//hash of previous block
	}

        B->theChain[size(B)] = newBlock(data,size(B),theBlocksHash);
	
	B->BcSize = size(B)+1;
	return size(B);
   } else{
      	return 0;
   }
}

int size(Blockchain B){
	return B->BcSize;
}

Block get(Blockchain B, int idx){
	return B->theChain[idx];
}

int valid(Blockchain B){
	//Block* C = B->theChain;
	if(size(B) <=1){
		return 1; //Since there is nothing to validate
	}
	for(int i = size(B)-1; i>0;i--){
		if(previousHash(get(B, i)) != hash(get(B,i-1))){
			return 0;
		}
	}
	return 1;
}

void removeLast(Blockchain B){
	B->BcSize = size(B) - 1;
	Block C = get(B,size(B));
	freeBlock(&C);//removes block at the last index
}

void printBlockchain(FILE* out, Blockchain B){
	for(int i = 0; i<size(B); i++){
		//fprintf(out,"%s",B->theChain[i]->);
		printBlock(out, B->theChain[i]);
	}
}
