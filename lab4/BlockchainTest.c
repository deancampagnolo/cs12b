
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

  // I want the first block's data to be modifiable so use an array.
  // char* string literals are stored in immutable memory
/*
  char hackable[] = "one";
  printf("%d\n", append(chain, hackable));
  printf("%d\n", append(chain, "two"));
  printf("%d\n", append(chain, "three"));
  printf("valid = %d\n", valid(chain));
  // could use printBlockChain() here but want to explicitly test printBlock()
  for (int i = 0; i < size(chain); i++) {
    printBlock(stdout,get(chain, i));
  }
	*/
  /*removeLast(chain);
  printBlockchain(stdout, chain);

  // now break the chain
  Block b = get(chain, 0);
  char* value =  data(b);
  *value = (*value)+1; // change a value in the first block
  printf("valid = %d\n", valid(chain));
  // attempt to append to an invalid chain
  printf("%d\n", append(chain, "five"));

  freeBlockchain(&chain);
  */
return 0;
}