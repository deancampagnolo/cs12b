/* 
 * Aaron Swoiskin
 * aswoiski
 * Dean Campagnolo
 * dcampagn
 *
 * BlockchainTest.c
 * this file contains the tests that we did on the lab
 * */
#include<stdio.h>
#include<stdlib.h>
#include "Blockchain.h"
//#include "Block.c"

int main(int argc, char* argv[]){
/*		
	char* str = "dean";
	int id = 0;
	int khash = 0;
	Block *BB = malloc(sizeof(Block));
	BB = newBlock(str,id,khash);
	printBlock(stdout,BB);
	
	printf("%ld",previousHash(BB));
*/
	//long k = hash(BB);
	//printf("%ld", k);
	
	Blockchain *Blocky = malloc(sizeof(Blockchain));
	Blocky = newBlockchain();
	append(Blocky, "hello");
	append(Blocky, "bingbong");
	append(Blocky, "hehexd");
	append(Blocky, "");
	append(Blocky, "juajuajua");
	printBlockchain(stdout,Blocky);
	printf("%d",valid(Blocky));
	removeLast(Blocky);
	printBlockchain(stdout,Blocky);
	//freeBlock(Blocky);

return 0;
}
