#include "blockchain.h"

/**
 * blockchain_create - creates a Blockchain structure, and initializes it.
 *
 * Return: A blockchain_t structure, NULL upon failure
 */

blockchain_t *blockchain_create(void)
{
	blockchain_t *blockchain;
	block_t *block;
	block_t const genesis = GENESIS_BLOCK;
	block= (block_t *) malloc(sizeof(block_t));
	
	memcpy(block,(block_t *)&genesis,sizeof(block_t));
 	
	blockchain = (blockchain_t *) malloc(sizeof(blockchain_t));
	blockchain->chain = llist_create(MT_SUPPORT_TRUE);

	if (llist_add_node(blockchain->chain, block, ADD_NODE_FRONT) !=0)
		return (NULL);

	return (blockchain);
}

