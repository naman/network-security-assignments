#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/hmac.h>

#ifndef ALLOWED_CHAR_LENGTH
#define ALLOWED_CHAR_LENGTH 4096
#endif

#ifndef KEY_LEN
#define KEY_LEN 32 //BYTES
#endif

#ifndef BYTES_READ
#define BYTES_READ 512
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 20000
#endif

/* A 128 bit IV */
unsigned char *iv = (unsigned char *)"01234567890123456";

int decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* plaintext) {

	EVP_CIPHER_CTX* ctx;

	int len;
	int plaintext_len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		ERR_print_errors_fp(stderr);

	// EVP_CIPHER_CTX_set_padding(&ctx, 0);

	/* Initialise the encryption operation.	AES encryption in CBC mode key length == 256 bit*/
	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) //iv = ""
		ERR_print_errors_fp(stderr);

	/* Provide the encrypted message, and obtain the decrypted output.
	* EVP_DecryptUpdate can be called multiple times if necessary */
	if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
		ERR_print_errors_fp(stderr);

	plaintext_len = len;

	if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
		ERR_print_errors_fp(stderr);

	plaintext_len += len;

	// BIO_dump_fp (stdout, (const char *)plaintext, plaintext_len);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	/* Clean up */
	EVP_cleanup();
	ERR_free_strings();

	return plaintext_len;
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char* key, unsigned char* ciphertext) {

	EVP_CIPHER_CTX *ctx;

	int len;
	int ciphertext_len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		ERR_print_errors_fp(stderr);

	// EVP_CIPHER_CTX_set_padding(&ctx, 0);

	/*
		* Initialise the encryption operation. IMPORTANT - ensure you use a key
		* and IV size appropriate for your cipher
		* In this example we are using 256 bit AES (i.e. a 256 bit key). The
		* IV size for *most* modes is the same as the block size.
		* For AES this * is 128 bits
	*/

	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) //iv = ""
		ERR_print_errors_fp(stderr);

	/* Provide the message to be encrypted, and obtain the encrypted output. * EVP_EncryptUpdate can be
	called multiple times if necessary */

	if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
		ERR_print_errors_fp(stderr);

	ciphertext_len = len;

	if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
		ERR_print_errors_fp(stderr);

	ciphertext_len += len;

	// BIO_dump_fp (stdout, (const char *)ciphertext, ciphertext_len);

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
	/* Clean up */
	EVP_cleanup();
	ERR_free_strings();

	return ciphertext_len;
}