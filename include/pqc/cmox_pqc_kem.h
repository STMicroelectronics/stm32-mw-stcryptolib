/**
  ******************************************************************************
  * @file    cmox_pqc_kem.h
  * @brief   Define functions for PQC KEM functionalities
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef CMOX_PQC_KEM_H
#define CMOX_PQC_KEM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pqc/cmox_pqc_types.h"
#include "pqc/cmox_pqc_retvals.h"
#include "pqc/cmox_pqc_config.h"

/** @addtogroup CMOX_PQC
  * @{
  */

/**
  * @defgroup CMOX_PQC_KEM PQC ML-KEM algorithms
  * @{
  */

/**
  * @defgroup CMOX_PQC_KEM_PUBLIC_TYPES PQC ML-KEM public types
  * @{
  */

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 random seed for keygen.
  */
#define CMOX_PQC_ML_KEM_512_KEYGEN_SEED_LEN 64u

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 random seed for encapsulation.
  */
#define CMOX_PQC_ML_KEM_512_ENC_SEED_LEN 32u

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 private key.
  */
#define CMOX_PQC_ML_KEM_512_PRIVKEY_LEN 1632u

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 public key.
  */
#define CMOX_PQC_ML_KEM_512_PUBKEY_LEN  800u

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 ciphertext.
  */
#define CMOX_PQC_ML_KEM_512_CIPHERTEXT_LEN     768u

/**
  *  @brief Macro defining the byte size of a ML-KEM-512 shared secret.
  */
#define CMOX_PQC_ML_KEM_512_SHARED_LEN     32u

/**
  *  @brief Macro defining the byte size of a ML-KEM-768 random seed for keygen.
  */
#define CMOX_PQC_ML_KEM_768_KEYGEN_SEED_LEN 64u

/**
  *  @brief Macro defining the byte size of a ML-KEM-768 random seed for encapsulation.
  */
#define CMOX_PQC_ML_KEM_768_ENC_SEED_LEN 32u


/**
  *  @brief Macro defining the byte size of a ML-KEM-768 private key.
  */
#define CMOX_PQC_ML_KEM_768_PRIVKEY_LEN 2400u

/**
  *  @brief Macro defining the byte size of a ML-KEM-768 public key.
  */
#define CMOX_PQC_ML_KEM_768_PUBKEY_LEN  1184u

/**
  *  @brief Macro defining the byte size of a ML-KEM-768 ciphertext.
  */
#define CMOX_PQC_ML_KEM_768_CIPHERTEXT_LEN     1088u

/**
  *  @brief Macro defining the byte size of a ML-KEM-768 shared secret.
  */
#define CMOX_PQC_ML_KEM_768_SHARED_LEN     32u

/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 random seed for keygen.
  */
#define CMOX_PQC_ML_KEM_1024_KEYGEN_SEED_LEN 64u

/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 random seed for encapsulation.
  */
#define CMOX_PQC_ML_KEM_1024_ENC_SEED_LEN 32u


/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 private key.
  */
#define CMOX_PQC_ML_KEM_1024_PRIVKEY_LEN 3168u

/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 public key.
  */
#define CMOX_PQC_ML_KEM_1024_PUBKEY_LEN  1568u

/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 ciphertext.
  */
#define CMOX_PQC_ML_KEM_1024_CIPHERTEXT_LEN     1568u

/**
  *  @brief Macro defining the byte size of a ML-KEM-1024 shared secret.
  */
#define CMOX_PQC_ML_KEM_1024_SHARED_LEN     32u

/**
  * @brief PQC KEM algorithm type: Key Generation.
  *
  * This type specifies the algorithm to use with the PQC KEM module (e.g. ML-KEM-768).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally
  */
typedef const struct cmox_pqc_kem_keygen_algoStruct_st *cmox_pqc_kem_keygen_algo_t;

/**
  * @brief PQC KEM algorithm type: Key Encapsulation.
  *
  * This type specifies the algorithm to use with the PQC KEM module (e.g. ML-KEM-768).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally
  */
typedef const struct cmox_pqc_kem_enc_algoStruct_st *cmox_pqc_kem_enc_algo_t;

/**
  * @brief PQC KEM algorithm type: Key Decapsulation.
  *
  * This type specifies the algorithm to use with the PQC KEM module (e.g. ML-KEM-768).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally
  */
typedef const struct cmox_pqc_kem_dec_algoStruct_st *cmox_pqc_kem_dec_algo_t;

/**
  * @}
  */

/** @defgroup CMOX_PQC_KEM_ALGO PQC ML-KEM algorithms
  * @{
  */

/**
  * @brief Identifier of the ML-KEM--512 Key pair generation function.
  */
extern const cmox_pqc_kem_keygen_algo_t CMOX_PQC_ML_KEM_512_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML-KEM--768 Key pair generation function.
  */
extern const cmox_pqc_kem_keygen_algo_t CMOX_PQC_ML_KEM_768_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML-KEM--1024 Key pair generation function.
  */
extern const cmox_pqc_kem_keygen_algo_t CMOX_PQC_ML_KEM_1024_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML-KEM--512 Encapsulation generation function.
  */
extern const cmox_pqc_kem_enc_algo_t CMOX_PQC_ML_KEM_512_ENC_ALGO;

/**
  * @brief Identifier of the ML-KEM--768 Encapsulation generation function.
  */
extern const cmox_pqc_kem_enc_algo_t CMOX_PQC_ML_KEM_768_ENC_ALGO;

/**
  * @brief Identifier of the ML-KEM--1024 Encapsulation function.
  */
extern const cmox_pqc_kem_enc_algo_t CMOX_PQC_ML_KEM_1024_ENC_ALGO;

/**
  * @brief Identifier of the ML-KEM--512 Decapsulation generation function.
  */
extern const cmox_pqc_kem_dec_algo_t CMOX_PQC_ML_KEM_512_DEC_ALGO;

/**
  * @brief Identifier of the ML-KEM--768 Decapsulation generation function.
  */
extern const cmox_pqc_kem_dec_algo_t CMOX_PQC_ML_KEM_768_DEC_ALGO;

/**
  * @brief Identifier of the ML-KEM--1024 Decapsulation function.
  */
extern const cmox_pqc_kem_dec_algo_t CMOX_PQC_ML_KEM_1024_DEC_ALGO;

/**
  * @}
  */


/** @defgroup CMOX_PQC_PUBLIC_METHODS PQC public method prototypes
  * @{
  */

/**
  * @brief         Mandatory function to set preliminary settings for PQC KEM usage.
  * @param[in,out] P_pPqcCtx    PQC context to initialize
  * @param[in]     P_ImplParams Parameter defining the low-level optimizations (e.g., HASH HW engine usage)
  * @param[in]     P_pBuf       Buffer for internal usage (must be externally allocated by the user)
  * @param[in]     P_BufLen     Byte length of the buffer
  */
void cmox_pqc_kem_construct(cmox_pqc_handle_t    *P_pPqcCtx,
                            cmox_pqc_llengines_t P_ImplParams,
                            uint8_t              *P_pBuf,
                            size_t               P_BufLen);

/**
  * @brief         Clean the PQC KEM context and the internal temporary buffer.
  * @param[in,out] P_pPqcCtx  PQC context to clean
  */
void cmox_pqc_kem_cleanup(cmox_pqc_handle_t *P_pPqcCtx);

/**
  * @brief      Generate private and public keys to use for KEM.
  * @param[in]  P_pPqcCtx       Context for KEM operations
  * @param[in]  P_Algo          Chosen algorithm suite
  * @param[in]  P_pRandom       Buffer of random bytes
  * @param[in]  P_RandomLen     Byte length of the random buffer
  * @param[out] P_pPrivKey      Buffer with the private key
  * @param[out] P_pPrivKeyLen   Byte length of the private key
  * @param[out] P_pPubKey       Buffer with the public key
  * @param[out] P_pPubKeyLen    Byte length of the public key
  * @note If P_RandomLen is not enough, an error is returned and P_pPrivKeyLen
  *       contains the minimum number of bytes of random to provide, while
  *       P_pPubKeyLen contains the minimum length of P_pPubKey.
  * @note For ML-KEM, the P_pRandom buffer is read by the library as the concatenation of elements `d` and `z`, as
  *       named by the FIPS 203.
  * @retval     CMOX_PQC_SUCCESS                Everything OK
  * @retval     CMOX_PQC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_PQC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_PQC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_PQC_ERR_MATH_ALGO_MISMATCH Low-level engine set is not compatible with the functionality
  */
cmox_pqc_retval_t cmox_pqc_kem_keyGen(cmox_pqc_handle_t          *P_pPqcCtx,
                                      cmox_pqc_kem_keygen_algo_t P_Algo,
                                      const uint8_t              *P_pRandom,
                                      size_t                     P_RandomLen,
                                      uint8_t                    *P_pPrivKey,
                                      size_t                     *P_pPrivKeyLen,
                                      uint8_t                    *P_pPubKey,
                                      size_t                     *P_pPubKeyLen);

/**
  * @brief Encapsulate a shared secret key (generated by the function) with KEM public key.
  *
  * @param[in]  P_pPqcCtx            Context for KEM operations
  * @param[in]  P_Algo               Chosen algorithm suite
  * @param[in]  P_pRandom            Buffer of random bytes
  * @param[in]  P_RandomLen          Byte length of the random buffer
  * @param[in]  P_pPubKey            Buffer with the public key
  * @param[in]  P_PubKeyLen          Byte length of the public key
  * @param[out] P_pCiphertext        Buffer that will contain the encrypted shared secret
  * @param[out] P_pCiphertextLen     Byte length of the encrypted secret
  * @param[out] P_pSharedSecret      Buffer that will contain the generated shared secret
  * @param[out] P_pSharedSecretLen   Byte length of the shared secret
  * @return cmox_pqc_retval_t
  */
cmox_pqc_retval_t cmox_pqc_kem_encapsulate(cmox_pqc_handle_t       *P_pPqcCtx,
                                           cmox_pqc_kem_enc_algo_t P_Algo,
                                           const uint8_t           *P_pRandom,
                                           size_t                  P_RandomLen,
                                           const uint8_t           *P_pPubKey,
                                           size_t                  P_PubKeyLen,
                                           uint8_t                 *P_pCiphertext,
                                           size_t                  *P_pCiphertextLen,
                                           uint8_t                 *P_pSharedSecret,
                                           size_t                  *P_pSharedSecretLen);

/**
  * @brief Decapsulate a shared secret with KEM private key.
  *
  * @param[in]  P_pPqcCtx            Context for KEM operations
  * @param[in]  P_Algo               Chosen algorithm suite
  * @param[in]  P_pPrivKey           Buffer with the private key
  * @param[in]  P_PrivKeyLen         Byte length of the private key
  * @param[in]  P_pCiphertext        Buffer that contains the encrypted shared secret
  * @param[in]  P_CiphertextLen      Byte length of the encrypted secret
  * @param[out] P_pSharedSecret      Buffer that will contain the decapsulated shared secret
  * @param[out] P_pSharedSecretLen   Byte length of the shared secret
  * @return cmox_pqc_retval_t
  */
cmox_pqc_retval_t cmox_pqc_kem_decapsulate(cmox_pqc_handle_t       *P_pPqcCtx,
                                           cmox_pqc_kem_dec_algo_t P_Algo,
                                           const uint8_t           *P_pPrivKey,
                                           size_t                  P_PrivKeyLen,
                                           const uint8_t           *P_pCiphertext,
                                           size_t                  P_CiphertextLen,
                                           uint8_t                 *P_pSharedSecret,
                                           size_t                  *P_pSharedSecretLen);


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* CMOX_PQC_KEM_H */
