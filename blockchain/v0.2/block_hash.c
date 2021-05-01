#include "blockchain.h"

/**
* block_hash - get the hash of a block
* @block: block to be hashed
* @hash_buf: resulted hash
* return: pointer to hash_buf, NULL upon failure
*/
uint8_t *block_hash(block_t const *block,
			uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	size_t len = sizeof(block->info) + block->data.len;
	sha256((int8_t const *)block, len, hash_buf);
	return (hash_buf);
}
