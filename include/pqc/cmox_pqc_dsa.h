/**
  ******************************************************************************
  * @file    cmox_pqc_dsa.h
  * @brief   Define functions for PQC signature functionalities
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

#ifndef CMOX_PQC_DSA_H
#define CMOX_PQC_DSA_H

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
  * @defgroup CMOX_PQC_SIG PQC Signature algorithms
  * @{
  */

/** @defgroup CMOX_PQC_PUBLIC_TYPES PQC public types
  * @{
  */

/**
  * @brief PQC Signature algorithm type: Key Generation.
  *
  * This type specifies the algorithm to use with the PQC SIG module (e.g. ML_DSA_44).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally.
  */
typedef const struct cmox_pqc_dsa_keygen_algoStruct_st *cmox_pqc_dsa_keygen_algo_t;

/**
  * @brief PQC Signature algorithm type: Signature Generation.
  *
  * This type specifies the algorithm to use with the PQC SIG module (e.g. ML_DSA_44).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally.
  */
typedef const struct cmox_pqc_dsa_sign_algoStruct_st   *cmox_pqc_dsa_sign_algo_t;

/**
  * @brief PQC Signature algorithm type: Signature Verification.
  *
  * This type specifies the algorithm to use with the PQC SIG module (e.g. ML_DSA_44).
  * The type is defined as a pointer to a structure, that contains the functions
  * for the specific algorithm, defined in the library internally.
  */
typedef const struct cmox_pqc_dsa_verify_algoStruct_st *cmox_pqc_dsa_verify_algo_t;

/**
  * @brief PQC Signature Prehash type.
  *
  * This type specifies the hash algorithm to use with PQC signature prehash.
  * Along with the types already defined by the library, the user can create additional structures, for hash functions
  * not defined here.
  * The OID (and its length) must be defined, accordingly to the standard.
  */
struct cmox_pqc_dsa_prehashStruct_t
{
  const uint8_t *oid;         /*!< OID */
  const size_t oid_len;       /*!< OID byte length */
  const uint8_t prehash_flag; /*!< is 0 for the standard version ONLY (for every prehashed structure MUST be 1) */
};
typedef const struct cmox_pqc_dsa_prehashStruct_t *cmox_pqc_dsa_prehash_t;

/**
  * @brief Max value possible for the header.
  * @warning For Prehash structures added by the user, that could have an
  *          oid_len higher than 11, this maximum value could be higher
  */
#define CMOX_PQC_DSA_HEADER_MAX_LENGTH (2u + 255u + 11u)

/**
  * @}
  */

/** @defgroup CMOX_PQC_ALGO PQC DSA algorithms
  * @{
  */

/**
  * @brief Identifier of the ML_DSA_44 key generation function.
  */
extern const cmox_pqc_dsa_keygen_algo_t CMOX_PQC_ML_DSA_44_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_44_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_44_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 deterministic signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_44_DET_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 deterministic signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_44_DET_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 signature verification function.
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_44_VERIFY_ALGO;

/**
  * @brief Identifier of the ML_DSA_44 signature verification function (low RAM).
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_44_VERIFY_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 key generation function.
  */
extern const cmox_pqc_dsa_keygen_algo_t CMOX_PQC_ML_DSA_65_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_65_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_65_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 deterministic signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_65_DET_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 deterministic signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_65_DET_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 signature verification function.
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_65_VERIFY_ALGO;

/**
  * @brief Identifier of the ML_DSA_65 signature verification function (low RAM).
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_65_VERIFY_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 key generation function.
  */
extern const cmox_pqc_dsa_keygen_algo_t CMOX_PQC_ML_DSA_87_KEYGEN_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_87_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_87_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 deterministic signature generation function.
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_87_DET_SIGN_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 deterministic signature generation function (low RAM).
  */
extern const cmox_pqc_dsa_sign_algo_t CMOX_PQC_ML_DSA_87_DET_SIGN_LOWRAM_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 signature verification function.
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_87_VERIFY_ALGO;

/**
  * @brief Identifier of the ML_DSA_87 signature verification function (low RAM).
  */
extern const cmox_pqc_dsa_verify_algo_t CMOX_PQC_ML_DSA_87_VERIFY_LOWRAM_ALGO;

/**
  * @}
  */

/** @defgroup CMOX_PQC_ALGO_CONF PQC DSA algorithm configurations
  * @{
  */
/**
  *  @brief Macro defining the byte size of a ML_DSA_44 seed (for keyGen process).
  */
#define CMOX_PQC_ML_DSA_44_KEYGEN_SEED_LEN 32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_44 seed (for sign process).
  */
#define CMOX_PQC_ML_DSA_44_SIGN_SEED_LEN   32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_44 private key.
  */
#define CMOX_PQC_ML_DSA_44_PRIVKEY_LEN 2560u

/**
  *  @brief Macro defining the byte size of a ML_DSA_44 public key.
  */
#define CMOX_PQC_ML_DSA_44_PUBKEY_LEN  1312u

/**
  *  @brief Macro defining the byte size of a ML_DSA_44 signature.
  */
#define CMOX_PQC_ML_DSA_44_SIG_LEN     2420u

/**
  *  @brief Macro defining the byte size of a ML_DSA_65 seed (for keyGen process).
  */
#define CMOX_PQC_ML_DSA_65_KEYGEN_SEED_LEN 32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_65 seed (for sign process).
  */
#define CMOX_PQC_ML_DSA_65_SIGN_SEED_LEN   32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_65 private key.
  */
#define CMOX_PQC_ML_DSA_65_PRIVKEY_LEN 4032u

/**
  *  @brief Macro defining the byte size of a ML_DSA_65 public key.
  */
#define CMOX_PQC_ML_DSA_65_PUBKEY_LEN  1952u

/**
  *  @brief Macro defining the byte size of a ML_DSA_65 signature.
  */
#define CMOX_PQC_ML_DSA_65_SIG_LEN     3309u

/**
  *  @brief Macro defining the byte size of a ML_DSA_87 seed (for keyGen process).
  */
#define CMOX_PQC_ML_DSA_87_KEYGEN_SEED_LEN 32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_87 seed (for sign process).
  */
#define CMOX_PQC_ML_DSA_87_SIGN_SEED_LEN   32u

/**
  *  @brief Macro defining the byte size of a ML_DSA_87 private key.
  */
#define CMOX_PQC_ML_DSA_87_PRIVKEY_LEN 4896u

/**
  *  @brief Macro defining the byte size of a ML_DSA_87 public key.
  */
#define CMOX_PQC_ML_DSA_87_PUBKEY_LEN  2592u

/**
  *  @brief Macro defining the byte size of a ML_DSA_87 signature.
  */
#define CMOX_PQC_ML_DSA_87_SIG_LEN     4627u


/**
  * @brief Identifier of the standard (not prehashed) version of DSA.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_STANDARD;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA1.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA1;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA224.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA224;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA256.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA256;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA384.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA384;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA512.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA512;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA512/224.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA512_224;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA512/256.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA512_256;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA3-224.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA3_224;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA3-256.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA3_256;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA3-384.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA3_384;
/**
  * @brief Identifier of the prehashed version of DSA, using SHA3-512.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHA3_512;
/**
  * @brief Identifier of the prehashed version of DSA, using SHAKE128.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHAKE128;
/**
  * @brief Identifier of the prehashed version of DSA, using SHAKE256.
  */
extern const cmox_pqc_dsa_prehash_t CMOX_PQC_DSA_PREHASH_SHAKE256;

/**
  * @}
  */

/** @defgroup CMOX_PQC_DSA_PUBLIC_METHODS PQC Signature public method prototypes
  * @{
  */

/**
  * @brief         Mandatory function to set preliminary settings for PQC signatures usage.
  * @param[in,out] P_pPqcCtx    PQC context to initialize
  * @param[in]     P_ImplParams Parameter defining the low-level optimizations (e.g., HASH HW engine usage)
  * @param[in]     P_pBuf       Buffer for internal usage (must be externally allocated by the user)
  * @param[in]     P_BufLen     Byte length of the buffer
  */
void cmox_pqc_dsa_construct(cmox_pqc_handle_t    *P_pPqcCtx,
                            cmox_pqc_llengines_t P_ImplParams,
                            uint8_t              *P_pBuf,
                            size_t               P_BufLen);

/**
  * @brief         Clean the PQC signature context and the internal temporary buffer.
  * @param[in,out] P_pPqcCtx  PQC context to clean
  */
void cmox_pqc_dsa_cleanup(cmox_pqc_handle_t *P_pPqcCtx);

/**
  * @brief      Generate private and public keys to use with PQC Signature functions.
  * @param[in]  P_pPqcCtx       Initialized PQC context
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
  * @retval     CMOX_PQC_SUCCESS                Everything OK
  * @retval     CMOX_PQC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_PQC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_PQC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_PQC_ERR_MATH_ALGO_MISMATCH Low-leven engine set is not compatible with the functionality
  */
cmox_pqc_retval_t cmox_pqc_dsa_keyGen(cmox_pqc_handle_t          *P_pPqcCtx,
                                      cmox_pqc_dsa_keygen_algo_t P_Algo,
                                      const uint8_t              *P_pRandom,
                                      size_t                     P_RandomLen,
                                      uint8_t                    *P_pPrivKey,
                                      size_t                     *P_pPrivKeyLen,
                                      uint8_t                    *P_pPubKey,
                                      size_t                     *P_pPubKeyLen);

/**
  * @brief      Prepare the header of the message, that composes, together with the message, the value M'
  *             (as specified by FIPS 204/205).
  * @param[in]  P_pPqcCtx       PQC context (currently not used, RFU)
  * @param[in]  P_pContext      Optional string for differentiation (by default, must be the empty string)
  * @param[in]  P_ContextLen    Byte length of the optional context (by default, must be 0. Max length = 255)
  * @param[in]  P_PreHashParam  Specifies if we are using the standard or prehashed version of the algorithm, and in the
  *                             last case also specifies which hash algorithm has been used to generate the digest that
  *                             will be signed/verified
  *                             Either the parameter could be one of the following:
  *                               @arg CMOX_PQC_DSA_STANDARD
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA1
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA224
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA256
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA384
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA512
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA512_224
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA512_256
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA3_224
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA3_256
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA3_384
  *                               @arg CMOX_PQC_DSA_PREHASH_SHA3_512
  *                               @arg CMOX_PQC_DSA_PREHASH_SHAKE128
  *                               @arg CMOX_PQC_DSA_PREHASH_SHAKE256
  *                             or the user could define its own.
  * @param[out] P_pHeader       Resulting header
  * @param[out] P_pHeaderLen    It will be filled with the byte length of the header (optional parameter)
  * @note       the length of the header will be: 2 + P_ContextLen [+ len(HASH_OID) if a prehashed version is used].
  *             The macro \ref CMOX_PQC_DSA_HEADER_MAX_LENGTH can be used to allocate a buffer.
  * @retval     CMOX_PQC_SUCCESS                Everything OK
  * @retval     CMOX_PQC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or context longer than 255 bytes
  */
cmox_pqc_retval_t cmox_pqc_dsa_prepareHeader(cmox_pqc_handle_t      *P_pPqcCtx,
                                             const uint8_t          *P_pContext,
                                             size_t                 P_ContextLen,
                                             cmox_pqc_dsa_prehash_t P_PreHashParam,
                                             uint8_t                *P_pHeader,
                                             size_t                 *P_pHeaderLen);

/**
  * @brief      Generate a PQC signature.
  * @param[in]  P_pPqcCtx       Initialized PQC context
  * @param[in]  P_Algo          Chosen algorithm suite
  * @param[in]  P_pRandom       Buffer of random bytes
  * @param[in]  P_RandomLen     Byte length of the random buffer
  * @param[in]  P_pPrivKey      Buffer with the private key
  * @param[in]  P_PrivKeyLen    Byte length of the private key
  * @param[in]  P_pHeader       Buffer with the optional header, that will be prepended to the message
  * @param[in]  P_HeaderLen     Byte length of the header
  * @param[in]  P_pMessage      Buffer with the message to sign
  * @param[in]  P_MessageLen    Byte length of the message
  * @param[out] P_pSignature    Buffer with the signature
  * @param[out] P_pSignatureLen Byte length of the signature
  * @note If P_RandomLen is provided, but not enough, an error is returned and
  *       P_pSignatureLen contains the minimum number of bytes of random
  *       to provide.
  * @retval     CMOX_PQC_SUCCESS                Everything OK
  * @retval     CMOX_PQC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_PQC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_PQC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_PQC_ERR_MATH_ALGO_MISMATCH Low-level engine set is not compatible with the functionality
  */
cmox_pqc_retval_t cmox_pqc_dsa_sign(cmox_pqc_handle_t        *P_pPqcCtx,
                                    cmox_pqc_dsa_sign_algo_t P_Algo,
                                    const uint8_t            *P_pRandom,
                                    size_t                   P_RandomLen,
                                    const uint8_t            *P_pPrivKey,
                                    size_t                   P_PrivKeyLen,
                                    const uint8_t            *P_pHeader,
                                    size_t                   P_HeaderLen,
                                    const uint8_t            *P_pMessage,
                                    size_t                   P_MessageLen,
                                    uint8_t                  *P_pSignature,
                                    size_t                   *P_pSignatureLen);

/**
  * @brief      Verify a PQC signature.
  * @param[in]  P_pPqcCtx       Initialized PQC context
  * @param[in]  P_Algo          Chosen algorithm suite
  * @param[in]  P_pPubKey       Buffer with the public key
  * @param[in]  P_PubKeyLen     Byte length of the public key
  * @param[in]  P_pHeader       Buffer with the optional header, that will be prepended to the message
  * @param[in]  P_HeaderLen     Byte length of the header
  * @param[in]  P_pMessage      Buffer with the message to sign
  * @param[in]  P_MessageLen    Byte length of the message
  * @param[in]  P_pSignature    Buffer with the signature
  * @param[in]  P_SignatureLen  Byte length of the signature
  * @param[out] P_pFaultCheck   Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_PQC_AUTH_SUCCESS           Signature verified
  * @retval     CMOX_PQC_AUTH_FAIL              Signature NOT verified
  * @retval     CMOX_PQC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_PQC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_PQC_ERR_INVALID_SIGNATURE  Input signature corrupted or not in the expected format
  * @retval     CMOX_PQC_ERR_INVALID_PUBKEY     Public key not in a valid format
  * @retval     CMOX_PQC_ERR_MATH_ALGO_MISMATCH Low-level engine set is not compatible with the functionality
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  *             This variable is not used/modified in case alternative implementation is used.
  */
cmox_pqc_retval_t cmox_pqc_dsa_verify(cmox_pqc_handle_t          *P_pPqcCtx,
                                      cmox_pqc_dsa_verify_algo_t P_Algo,
                                      const uint8_t              *P_pPubKey,
                                      size_t                     P_PubKeyLen,
                                      const uint8_t              *P_pHeader,
                                      size_t                     P_HeaderLen,
                                      const uint8_t              *P_pMessage,
                                      size_t                     P_MessageLen,
                                      const uint8_t              *P_pSignature,
                                      size_t                     P_SignatureLen,
                                      uint32_t                   *P_pFaultCheck);

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

#endif /* CMOX_PQC_DSA_H */
