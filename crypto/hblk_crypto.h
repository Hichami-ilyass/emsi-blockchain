# include <openssl/sha.h>
# include <stdint.h>

# define EC_CURVE   NID_secp256k1


# define EC_PUB_LEN 65

# define SIG_MAX_LEN    72

# define PRI_FILENAME   "key.pem"
# define PUB_FILENAME   "key_pub.pem"

typedef struct sig_s
{
    uint8_t     sig[SIG_MAX_LEN];
    uint8_t     len;
} sig_t;

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);

