/**
  ******************************************************************************
  * @file    cmox_sm2.h
  * @brief   Header file for SM2 signature creation and verification functions.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021-2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef CMOX_SM2_H
#define CMOX_SM2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ecc/cmox_ecc.h"
#include "hash/cmox_sm3.h"
#include "kdf/cmox_x963_kdf.h"

/** @addtogroup CMOX_ECC
  * @{
  */

/**
  * @defgroup CMOX_ECC_SM2 SM2 algorithm
  * @{
  */

/**
  * @defgroup CMOX_ECC_SM2_STRUCTS SM2 public structures
  * @{
  */

/**
  * @brief Structure for the SM2 ECIES handle
  */
typedef struct
{
  cmox_ecc_handle_t      *ecc_ctx;      /*!< ECC context */
  cmox_ecc_impl_t        curve;         /*!< curve implementation parameter */
  uint8_t                *secret;       /*!< computed shared secret */
  size_t                 secret_len;    /*!< shared secret length */
  cmox_sm3_handle_t      hash_ctx;      /*!< hash context */
  cmox_hash_handle_t     *hash_handle;  /*!< hash handle */
  cmox_x963_kdf_handle_t kdf_ctx;       /*!< KDF context */
  cmox_kdf_handle_t      *kdf_handle;   /*!< KDF handle */
  uint32_t               t_0_check;     /*!< mask to check if T=0 */
}
cmox_ecies_handle_t;

/**
  * @}
  */

/**
  * @defgroup CMOX_ECC_SM2_FLAGS SM2 public flags
  * @{
  */

/**
  * @brief Flag for the SM2 Key Exchange Roles
  */
typedef uint32_t cmox_sm2_kex_role_flag_t;
#define CMOX_SM2_KEX_ROLE_INITIATOR  ((cmox_sm2_kex_role_flag_t) 0u) /*!< Initiator */
#define CMOX_SM2_KEX_ROLE_RESPONDER  ((cmox_sm2_kex_role_flag_t) 1u) /*!< Responder */

/**
  * @brief Flag for the SM2 Key Exchange Output hash selection
  */
typedef uint32_t cmox_sm2_kex_hash_flag_t;
#define CMOX_SM2_KEX_HASH_NONE  ((cmox_sm2_kex_hash_flag_t) 0u) /*!< No hashes have to be returned */
#define CMOX_SM2_KEX_HASH_S1    ((cmox_sm2_kex_hash_flag_t) 1u) /*!< Just Hash S1 is returned */
#define CMOX_SM2_KEX_HASH_S1S2  ((cmox_sm2_kex_hash_flag_t) 2u) /*!< Both Hashes S1 and S2 are returned */

/**
  * @}
  */

/** @defgroup CMOX_ECC_SM2_PUBLIC_METHODS SM2 public method prototypes
  * @{
  */

/**
  * @brief      Generate private and public keys to use with ECDSA.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters and point functions
  *                             This parameter can be one of the following:
  *                                @arg CMOX_ECC_SM2_LOWMEM
  *                                @arg CMOX_ECC_SM2_HIGHMEM
  *                                @arg CMOX_ECC_SM2TEST_LOWMEM
  *                                @arg CMOX_ECC_SM2TEST_HIGHMEM
  * @param[in]  P_pRandom       Buffer of random bytes
  * @param[in]  P_RandomLen     Byte length of the random buffer
  * @param[out] P_pPrivKey      Buffer with the private key (in range [1; N - 2])
  * @param[out] P_pPrivKeyLen   Byte length of the private key
  * @param[out] P_pPubKey       Buffer with the public key
  * @param[out] P_pPubKeyLen    Byte length of the public key
  * @note the private key is derived from the random in the
  *       following way: \verbatim privkey = (random >> ((WORD_NBIT - N_MSW_NBIT) & 7)) + 1 \endverbatim,
  *       where: random is the input random buffer (interpreted as a big-endian integer),
  *              WORD_NBIT is the bitsize of a cpu word,
  *              N_MSW_NBIT is the bitlength of the most significant word of the parameter N of the curve.
  * @note If P_RandomLen is not enough, an error is returned and P_pPrivKeyLen
  *       contains the minimum number of bytes of random to provide (and is also
  *       the minimum length of P_pPrivKey), while P_pPubKeyLen contains the
  *       minimum length of P_pPubKey.
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Curve is not compatible with current functionality
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  */
cmox_ecc_retval_t cmox_sm2_keyGen(cmox_ecc_handle_t     *P_pEccCtx,
                                  const cmox_ecc_impl_t P_CurveParams,
                                  const uint8_t         *P_pRandom,
                                  size_t                P_RandomLen,
                                  uint8_t               *P_pPrivKey,
                                  size_t                *P_pPrivKeyLen,
                                  uint8_t               *P_pPubKey,
                                  size_t                *P_pPubKeyLen);

/**
  * @brief      Compute ZA = HASH(ENTLA || IDA || a || b || xG || yG || xA || yA), that is the value to hash, together
  *             with the message, to obtain the digest to provide to \ref cmox_sm2_sign and \ref cmox_sm2_verify.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters and point functions
  *                             This parameter can be one of the following:
  *                                @arg CMOX_ECC_SM2_LOWMEM
  *                                @arg CMOX_ECC_SM2_HIGHMEM
  *                                @arg CMOX_ECC_SM2TEST_LOWMEM
  *                                @arg CMOX_ECC_SM2TEST_HIGHMEM
  * @param[in]  P_pIDA          Buffer with ID (e.g. email "user@domain.com") of the user
  * @param[in]  P_ENTLA         Bit length of the user ID (usually, multiple of 8)
  * @param[in]  P_pPubKey       Buffer with the public key (both X and Y)
  * @param[in]  P_PubKeyLen     Byte length of the public key
  * @param[out] P_pZA           Buffer with ZA
  * @param[out] P_pZALen        Byte length of ZA (optional parameter)
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_INTERNAL           Something went wrong during internal computations (e.g. hash)
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Curve is not compatible with current functionality
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  */
cmox_ecc_retval_t cmox_sm2_computeZA(cmox_ecc_handle_t     *P_pEccCtx,
                                     const cmox_ecc_impl_t P_CurveParams,
                                     const uint8_t         *P_pIDA,
                                     uint16_t              P_ENTLA,
                                     const uint8_t         *P_pPubKey,
                                     size_t                P_PubKeyLen,
                                     uint8_t               *P_pZA,
                                     size_t                *P_pZALen);

/**
  * @brief      Generate a signature, using ECDSA.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters and point functions
  *                             This parameter can be one of the following:
  *                                @arg CMOX_ECC_SM2_LOWMEM
  *                                @arg CMOX_ECC_SM2_HIGHMEM
  *                                @arg CMOX_ECC_SM2TEST_LOWMEM
  *                                @arg CMOX_ECC_SM2TEST_HIGHMEM
  * @param[in]  P_pRandom       Buffer of random bytes
  * @param[in]  P_RandomLen     Byte length of the random buffer
  * @param[in]  P_pPrivKey      Buffer with the private key
  * @param[in]  P_PrivKeyLen    Byte length of the private key
  * @param[in]  P_pDigest       Buffer with the digest to sign
  * @param[in]  P_DigestLen     Byte length of the digest
  * @param[out] P_pSignature    Buffer with the signature (concatenation of R and S)
  * @param[out] P_pSignatureLen Byte length of the signature
  * @note the internal value k, used as scalar and multiplied by the base point, is derived from the random in the
  *       following way: \verbatim k = (random >> ((WORD_NBIT - N_MSW_NBIT) & 7)) + 1 \endverbatim,
  *       where: random is the input random buffer (interpreted as a big-endian integer),
  *              WORD_NBIT is the bitsize of a cpu word,
  *              N_MSW_NBIT is the bitlength of the most significant word of the parameter N of the curve.
  * @note If P_RandomLen is not enough, an error is returned and
  *       P_pSignatureLen contains the minimum number of bytes of random
  *       to provide (and is also the minimum length of P_pPrivKey, and
  *       half the length of P_pSignature).
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Curve is not compatible with current functionality
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  */
cmox_ecc_retval_t cmox_sm2_sign(cmox_ecc_handle_t     *P_pEccCtx,
                                const cmox_ecc_impl_t P_CurveParams,
                                const uint8_t         *P_pRandom,
                                size_t                P_RandomLen,
                                const uint8_t         *P_pPrivKey,
                                size_t                P_PrivKeyLen,
                                const uint8_t         *P_pDigest,
                                size_t                P_DigestLen,
                                uint8_t               *P_pSignature,
                                size_t                *P_pSignatureLen);

/**
  * @brief      Verify a signature, using ECDSA.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters and point functions
  *                             This parameter can be one of the following:
  *                                @arg CMOX_ECC_SM2_LOWMEM
  *                                @arg CMOX_ECC_SM2_HIGHMEM
  *                                @arg CMOX_ECC_SM2TEST_LOWMEM
  *                                @arg CMOX_ECC_SM2TEST_HIGHMEM
  * @param[in]  P_pPubKey       Buffer with the public key
  * @param[in]  P_PubKeyLen     Byte length of the public key
  * @param[in]  P_pDigest       Buffer with the digest to sign
  * @param[in]  P_DigestLen     Byte length of the digest
  * @param[in]  P_pSignature    Buffer with the signature (concatenation of R and S)
  * @param[in]  P_SignatureLen  Byte length of the signature
  * @param[out] P_pFaultCheck   Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_ECC_AUTH_SUCCESS           Signature verified
  * @retval     CMOX_ECC_AUTH_FAIL              Signature NOT verified
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Curve is not compatible with current functionality
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_ECC_ERR_INVALID_SIGNATURE  Input signature corrupted or not in the expected format
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY     Public key not in a valid format
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  */
cmox_ecc_retval_t cmox_sm2_verify(cmox_ecc_handle_t     *P_pEccCtx,
                                  const cmox_ecc_impl_t P_CurveParams,
                                  const uint8_t         *P_pPubKey,
                                  size_t                P_PubKeyLen,
                                  const uint8_t         *P_pDigest,
                                  size_t                P_DigestLen,
                                  const uint8_t         *P_pSignature,
                                  size_t                P_SignatureLen,
                                  uint32_t              *P_pFaultCheck);

/**
  * @brief Encrypt and authenticate a plaintext with SM2 (single call).
  * @param[in]  P_pEccCtx         Context for ECC operations
  * @param[in]  P_CurveParams     Curve Parameters and point functions
  * @param[in]  P_pRecPubKey      Public key of the receiver
  * @param[in]  P_RecPubKeyLen    Byte length of the public key
  * @param[in]  P_pRandom         Random bytes, at least as long as the curve order
  * @param[in]  P_RandomLen       Byte length of the random data
  * @param[in]  P_pInput          Plaintext to encrypt
  * @param[in]  P_InputLen        Byte length of the plaintext
  * @param[out] P_pOutput         Whole encrypted payload, composed by sender public key, ciphertext and auth. tag
  * @param[out] P_pOutputLen      Byte length of the encrypted payload
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM   Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY Input public key not valid
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with kdf/encryption/authentication process
  * @note       P_pRecPubKey is a 'big-endian' vector (most significant byte first)
  * @note       P_pOutput is a buffer containing:
  *             @arg the sender ephemeral public key (uncompressed form: 04 || X || Y), therefore with length 2*L+1,
  *                  where L is the byte length of the P parameter of the curve
  *             @arg the ciphertext, with the same byte length of the input plaintext
  *             @arg the authentication tag, as long as an SM3 hash digest
  */
cmox_ecc_retval_t cmox_sm2_encrypt(cmox_ecc_handle_t     *P_pEccCtx,
                                   const cmox_ecc_impl_t P_CurveParams,
                                   const uint8_t         *P_pRecPubKey,
                                   size_t                P_RecPubKeyLen,
                                   const uint8_t         *P_pRandom,
                                   size_t                P_RandomLen,
                                   const uint8_t         *P_pInput,
                                   size_t                P_InputLen,
                                   uint8_t               *P_pOutput,
                                   size_t                *P_pOutputLen);

/**
  * @brief Authenticate and decrypt a ciphertext with SM2 (single call).
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters and point functions
  * @param[in]  P_pRecPrivKey   Receiver private key
  * @param[in]  P_RecPrivKeyLen Byte length of the receiver private key
  * @param[in]  P_pInput        Whole encrypted payload, composed by sender public key, ciphertext and auth. tag
  * @param[in]  P_InputLen      Byte length of the encrypted payload
  * @param[out] P_pOutput       Decrypted plaintext
  * @param[out] P_pOutputLen    Byte length of the decrypted plaintext
  * @param[out] P_pFaultCheck   Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_ECC_AUTH_SUCCESS       Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY Input public key not valid
  * @retval     CMOX_ECC_AUTH_FAIL          Authentication Tag NOT verified
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with kdf/encryption/authentication process
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM   Random material used for the encryption was not suitable for the encryption
  * @note       P_pRecPrivKey is a 'big-endian' vector (most significant byte first)
  * @note       P_pInput is a buffer containing:
  *             @arg the sender ephemeral public key (uncompressed form: 04 || X || Y), therefore with length 2*L+1,
  *                  where L is the byte length of the P parameter of the curve
  *             @arg the ciphertext, with the same byte length of the input plaintext
  *             @arg the authentication tag, as long as an SM3 hash digest
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  * @note       In case the internal tag verification fails, the output plaintext is erased and its length is set to 0.
  */
cmox_ecc_retval_t cmox_sm2_decrypt(cmox_ecc_handle_t     *P_pEccCtx,
                                   const cmox_ecc_impl_t P_CurveParams,
                                   const uint8_t         *P_pRecPrivKey,
                                   size_t                P_RecPrivKeyLen,
                                   const uint8_t         *P_pInput,
                                   size_t                P_InputLen,
                                   uint8_t               *P_pOutput,
                                   size_t                *P_pOutputLen,
                                   uint32_t              *P_pFaultCheck);

/**
  * @brief Initialize the SM2 context for a multi-call encryption session.
  * @param[in]  P_pEciesCtx       Context to initialize
  * @param[in]  P_pEccCtx         Context for ECC operations
  * @param[in]  P_CurveParams     Curve Parameters and point functions
  * @param[in]  P_pRecPubKey      Public key of the receiver
  * @param[in]  P_RecPubKeyLen    Byte length of the public key
  * @param[in]  P_pRandom         Random bytes, at least as long as the curve order
  * @param[in]  P_RandomLen       Byte length of the random data
  * @param[out] P_pSendPubKey     Sender ephemeral public key
  * @param[out] P_pSendPubKeyLen  Byte length of the sender ephemeral public key
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM   Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY Input public key not valid
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with kdf/encryption/authentication process
  * @note       P_pRecPubKey and P_pSendPubKey are 'big-endian' vectors (most significant byte first)
  * @note       P_pSendPubKey (the sender ephemeral public key) will be in uncompressed format, with leading compression
  *             byte (04 || X || Y), therefore with length 2*L+1, where L is the byte length of the P parameter of the
  *             curve. This format is requested by the SM2 encryption standard.
  */
cmox_ecc_retval_t cmox_sm2_encrypt_init(cmox_ecies_handle_t   *P_pEciesCtx,
                                        cmox_ecc_handle_t     *P_pEccCtx,
                                        const cmox_ecc_impl_t P_CurveParams,
                                        const uint8_t         *P_pRecPubKey,
                                        size_t                P_RecPubKeyLen,
                                        const uint8_t         *P_pRandom,
                                        size_t                P_RandomLen,
                                        uint8_t               *P_pSendPubKey,
                                        size_t                *P_pSendPubKeyLen);

/**
  * @brief Append additional plaintext to the SM2 context, both for encryption and authentication.
  * @param[in]  P_pEciesCtx   Initialized context
  * @param[in]  P_pInput      Plaintext to encrypt
  * @param[in]  P_InputLen    Byte length of the plaintext
  * @param[out] P_pOutput     Encrypted ciphertext
  * @param[out] P_pOutputLen  Byte length of the encrypted ciphertext
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with encryption/authentication process
  * @warning    if P_InputLen is not a multiple of CMOX_SM3_SIZE, this is the last possible append call: only the last
  *             cmox_sm2_encrypt_append can have an input length not multiple of CMOX_SM3_SIZE.
  */
cmox_ecc_retval_t cmox_sm2_encrypt_append(cmox_ecies_handle_t *P_pEciesCtx,
                                          const uint8_t       *P_pInput,
                                          size_t              P_InputLen,
                                          uint8_t             *P_pOutput,
                                          size_t              *P_pOutputLen);

/**
  * @brief Generate the final SM2 authentication tag, and clean the context.
  * @param[in]  P_pEciesCtx   Initialized context, that will be cleaned
  * @param[out] P_pAuthTag    Authentication tag
  * @param[out] P_pAuthTagLen Byte length of the generated authentication tag
  * @retval     CMOX_ECC_SUCCESS          Everything OK
  * @retval     CMOX_ECC_ERR_INTERNAL     Something went wrong with authentication process
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM Random material used during the init was not suitable for the encryption
  */
cmox_ecc_retval_t cmox_sm2_encrypt_generateTag(cmox_ecies_handle_t *P_pEciesCtx,
                                               uint8_t             *P_pAuthTag,
                                               size_t              *P_pAuthTagLen);

/**
  * @brief Initialize the SM2 context for a multi-call decryption session.
  * @param[in]  P_pEciesCtx       Context to initialize
  * @param[in]  P_pEccCtx         Context for ECC operations
  * @param[in]  P_CurveParams     Curve Parameters and point functions
  * @param[in]  P_pRecPrivKey     Receiver private key
  * @param[in]  P_RecPrivKeyLen   Byte length of the receiver private key
  * @param[in]  P_pSendPubKey     Ephemeral public key of the sender
  * @param[in]  P_SendPubKeyLen   Byte length of the ephemeral public key
  * @param[out] P_pProcessedBytes Number of bytes processed by the function
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY Input public key not valid
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with kdf/encryption/authentication process
  * @note       P_pSendPubKey and P_pRecPrivKey are 'big-endian' vectors (most significant byte first)
  * @note       P_pProcessedBytes returns the number of bytes processed by the function. Indeed, the user could not know
  *             how long the sender public key is, therefore could provide a longer buffer (or even the whole buffer
  *             transmitted by the sender) and the routine will process only the needed bytes, returning their number
  *             to the user. The user, then, will use that offset as starting point during the append function call.
  * @note       P_pSendPubKey (the sender ephemeral public key) must be in uncompressed format, with leading compression
  *             byte (04 || X || Y), therefore with length 2*L+1, where L is the byte length of the P parameter of the
  *             curve. This format is requested by the SM2 encryption standard.
  */
cmox_ecc_retval_t cmox_sm2_decrypt_init(cmox_ecies_handle_t   *P_pEciesCtx,
                                        cmox_ecc_handle_t     *P_pEccCtx,
                                        const cmox_ecc_impl_t P_CurveParams,
                                        const uint8_t         *P_pRecPrivKey,
                                        size_t                P_RecPrivKeyLen,
                                        const uint8_t         *P_pSendPubKey,
                                        size_t                P_SendPubKeyLen,
                                        size_t                *P_pProcessedBytes);

/**
  * @brief Append additional ciphertext to the SM2 context, both for decryption and authentication.
  * @param[in]  P_pEciesCtx   Initialized context
  * @param[in]  P_pInput      Ciphertext to decrypt
  * @param[in]  P_InputLen    Byte length of the ciphertext
  * @param[out] P_pOutput     Decrypted plaintext
  * @param[out] P_pOutputLen  Byte length of the decrypted plaintext
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_INTERNAL       Something went wrong with encryption/authentication process
  * @warning    if P_InputLen is not a multiple of CMOX_SM3_SIZE, this is the last possible append call: only the last
  *             cmox_sm2_encrypt_append can have an input length not multiple of CMOX_SM3_SIZE.
  */
cmox_ecc_retval_t cmox_sm2_decrypt_append(cmox_ecies_handle_t *P_pEciesCtx,
                                          const uint8_t       *P_pInput,
                                          size_t              P_InputLen,
                                          uint8_t             *P_pOutput,
                                          size_t              *P_pOutputLen);

/**
  * @brief Verify the final SM2 authentication tag, and clean the context.
  * @param[in]  P_pEciesCtx   Initialized context, that will be cleaned
  * @param[in]  P_pAuthTag    Authentication tag to verify against
  * @param[in]  P_AuthTagLen  Byte length of the authentication tag
  * @param[out] P_pFaultCheck Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_ECC_AUTH_SUCCESS     Everything OK
  * @retval     CMOX_ECC_AUTH_FAIL        Everything OK
  * @retval     CMOX_ECC_ERR_INTERNAL     Something went wrong with authentication process
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM Random material used for the encryption was not suitable for the encryption
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  */
cmox_ecc_retval_t cmox_sm2_decrypt_verifyTag(cmox_ecies_handle_t *P_pEciesCtx,
                                             const uint8_t       *P_pAuthTag,
                                             size_t              P_AuthTagLen,
                                             uint32_t            *P_pFaultCheck);

/**
  * @brief Perform the key exchange as expressed by the OSCCA standard.
  *        Only the first optional hash described in the standard can be computed, not the second one.
  * @param[in]  P_pEccCtx           Initialized context
  * @param[in]  P_CurveParams       Curve Parameters and point functions
  *                                 This parameter can be one of the following:
  *                                   @arg CMOX_ECC_SM2_LOWMEM
  *                                   @arg CMOX_ECC_SM2_HIGHMEM
  *                                   @arg CMOX_ECC_SM2TEST_LOWMEM
  *                                   @arg CMOX_ECC_SM2TEST_HIGHMEM
  * @param[in]  P_pEphPrivKey       Buffer with the ephemeral private key
  * @param[in]  P_EphPrivKeyLen     Byte length of the ephemeral private key
  * @param[in]  P_pEphPubKey        Buffer with the ephemeral public key
  * @param[in]  P_EphPubKeyLen      Byte length of the ephemeral public key
  * @param[in]  P_pPrivKey          Buffer with the static private key
  * @param[in]  P_PrivKeyLen        Byte length of the static private key
  * @param[in]  P_pOtherPubKey      Buffer with the other party's static public key
  * @param[in]  P_OtherPubKeyLen    Byte length of the other party's static public key
  * @param[in]  P_pOtherEphPubKey   Buffer with the other party's ephemeral public key
  * @param[in]  P_OtherEphPubKeyLen Byte length of the other party's ephemeral public key
  * @param[in]  P_pZ                Buffer with the own Z parameter
  * @param[in]  P_ZLen              Byte length of the own Z parameter
  * @param[in]  P_pOtherZ           Buffer with the other party's Z parameter
  * @param[in]  P_OtherZLen         Byte length of the other party's Z parameter
  * @param[in]  p_KexRoleFlag       Flag indicating if this is the Initiator or the Responder
  *                                 This parameter can be one of the following:
  *                                   @arg CMOX_SM2_KEX_ROLE_INITIATOR
  *                                   @arg CMOX_SM2_KEX_ROLE_RESPONDER
  * @param[out] P_pSharedKey        Output shared secret key
  * @param[in]  P_SharedKeyLen      Desired byte length for the shared secret key
  * @param[in]  P_KexHashFlag       Flag indicating if and which hashes must be returned by the function
  *                                 This parameter can be one of the following:
  *                                   @arg CMOX_SM2_KEX_HASH_NONE
  *                                   @arg CMOX_SM2_KEX_HASH_S1
  *                                   @arg CMOX_SM2_KEX_HASH_S1S2
  *                                 In case both the hashes are returned, the output buffer contains both of them,
  *                                 with S1 concatenated to S2 (S1 || S2)
  * @param[out] P_pOptHash          (Optional) Hash to be sure of the correct generation of the shared secret key
  * @param[out] P_pOptHashLen       (Optional) Output byte length of the hash value
  * @retval     CMOX_ECC_SUCCESS            Everything OK
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS Wrong input parameters
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY One of the input public keys was not valid
  */
cmox_ecc_retval_t cmox_sm2_keyExchange(cmox_ecc_handle_t        *P_pEccCtx,
                                       const cmox_ecc_impl_t    P_CurveParams,
                                       const uint8_t            *P_pEphPrivKey,
                                       size_t                   P_EphPrivKeyLen,
                                       const uint8_t            *P_pEphPubKey,
                                       size_t                   P_EphPubKeyLen,
                                       const uint8_t            *P_pPrivKey,
                                       size_t                   P_PrivKeyLen,
                                       const uint8_t            *P_pOtherPubKey,
                                       size_t                   P_OtherPubKeyLen,
                                       const uint8_t            *P_pOtherEphPubKey,
                                       size_t                   P_OtherEphPubKeyLen,
                                       const uint8_t            *P_pZ,
                                       size_t                   P_ZLen,
                                       const uint8_t            *P_pOtherZ,
                                       size_t                   P_OtherZLen,
                                       cmox_sm2_kex_role_flag_t p_KexRoleFlag,
                                       uint8_t                  *P_pSharedKey,
                                       size_t                   P_SharedKeyLen,
                                       cmox_sm2_kex_hash_flag_t P_KexHashFlag,
                                       uint8_t                  *P_pOptHash,
                                       size_t                   *P_pOptHashLen);

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

#endif /* CMOX_SM2_H */
