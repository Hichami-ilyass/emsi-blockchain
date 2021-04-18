#include "blockchain.h"

/**
 * blockchain_destroy - deletes an existing Blockchain
 * @blockchain: Blockchain structure to delete
 *
 * Return: void
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	if (!blockchain)
		return;
	
	if (llist_destroy(blockchain->chain, 1, NULL) != 0)
	{
		return;
	}
	free(blockchain);
}

