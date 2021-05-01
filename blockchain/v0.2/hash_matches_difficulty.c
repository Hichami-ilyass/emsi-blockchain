#include "blockchain.h"

/**
 * hash_matches_difficulty - checks whether a given hash matches
 *                           a given difficulty
 * @hash: hash to check
 * @difficulty: minimum difficulty the hash should match
 * Return: 1 if difficulty is respected or 0 otherwise
 */

int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
	uint32_t difficulty)
{
	uint8_t i = 0;
	uint8_t msb = difficulty & 7;
	
	difficulty -= difficulty & 7;
	difficulty /=8;

	for (i =0; i < difficulty; i++)
	{
		if (hash[i] != 0)
			return (0);
	}
	if (hash[difficulty] >> (8 - msb))
		return (0);
	return (1);
}

