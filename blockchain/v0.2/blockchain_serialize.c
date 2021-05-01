#include "blockchain.h"

/**
 * blockchain_serialize - serializes a Blockchain into a file
 *
 * @blockchain: points to the Blockchain to serialize
 * @path: path to a file to serialize the Blockchain into
 * Return: 0 on success or -1 on failure
 */
int blockchain_serialize(blockchain_t const *blockchain, char const *path)
{
	FILE *fp;
	int index = 0;
	int32_t hblk_blocks = 0;
	uint8_t hblk_magic[4];
	uint8_t	hblk_version[3];
	uint8_t hblk_endianness = _get_endianness();
	block_t *block =NULL;

	if (!blockchain || !blockchain->chain || !path)
		return (-1);
	hblk_blocks = llist_size(blockchain->chain);
	fp = fopen(path,"w");
	if (!fp)
		return(-1);
	memcpy(hblk_magic,"HBLK", 4);
	memcpy(hblk_version, "0.2", 3); 
	fwrite(&hblk_magic, sizeof(hblk_magic), 1, fp);
  	fwrite(&hblk_version, sizeof(hblk_version), 1, fp);
  	fwrite(&hblk_endianness, sizeof(hblk_endianness), 1, fp);
  	fwrite(&hblk_blocks, sizeof(hblk_blocks), 1, fp);
	while (index< hblk_blocks)
	{
		block = llist_get_node_at(blockchain->chain, index++);
		if (!block)
			return (-1);
		fwrite((void *)&block->info, sizeof(block->info), 1, fp);
  		fwrite((void *)&block->data.len, sizeof(block->data.len), 1, fp);
  		fwrite(block->data.buffer, block->data.len, 1, fp);
  		fwrite(block->hash, sizeof(block->hash), 1, fp);
	}
	fclose(fp);
	return (0);
}
	
