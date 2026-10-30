/**
  ******************************************************************************
  * @file    cmox_hbs.h
  * @brief   Define functions for Hash-Based Signatures
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

#ifndef CMOX_HBS_H
#define CMOX_HBS_H

#include <stdint.h>
#include <stddef.h>
#include "cmox_hbs_retvals.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @defgroup HBS Hash-Based Signatures algorithms
  * @{
  */

/** @defgroup HBS_TYPES Hash-Based Signatures public types
  * @{
  */

/**
  * @brief Pointer type for the HBS algorithm suite.
  */
typedef const struct cmox_hbs_verify_algoStruct_st *cmox_hbs_verify_algo_t;

/**
  * @brief Pointer type for the hash algorithm.
  */
typedef const struct cmox_hbs_hashStruct_st *cmox_hbs_hash_t;

/**
  * @brief Structure for the HBS context.
  */
typedef struct
{
  cmox_hbs_verify_algo_t  suite;    /*!< HBS specific suite in use */
  cmox_hbs_hash_t  hash;            /*!< Hash algorithm to use */
  uint32_t         magic_num_check; /*!< Magic number for diagnostic checks */
  uint32_t         reserved;        /*!< Reserved for future use, do not set */
} cmox_hbs_handle_t;

/**
  * @}
  */

/** @defgroup HBS_HASH_PARAMS Hash Algorithms
  * @{
  */

extern const cmox_hbs_hash_t CMOX_HBS_SHA256;       /*!< SHA-256 */
extern const cmox_hbs_hash_t CMOX_HBS_SHAKE256;     /*!< SHAKE-256 */

/**
  * @}
  */

/** @defgroup HBS_SUITE_PARAMS HBS Suites
  * @{
  */

extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_10_192;      /*!< XMSS with H = 10 and hash_length = 192 bits */
extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_16_192;      /*!< XMSS with H = 16 and hash_length = 192 bits */
extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_20_192;      /*!< XMSS with H = 20 and hash_length = 192 bits */
extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_10_256;      /*!< XMSS with H = 10 and hash_length = 256 bits */
extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_16_256;      /*!< XMSS with H = 16 and hash_length = 256 bits */
extern const cmox_hbs_verify_algo_t CMOX_XMSS_VERIFY_20_256;      /*!< XMSS with H = 20 and hash_length = 256 bits */
extern const cmox_hbs_verify_algo_t CMOX_LMS_VERIFY_M24;          /*!< LMS with hash_length = 192 bits */
extern const cmox_hbs_verify_algo_t CMOX_LMS_VERIFY_M32;          /*!< LMS with hash_length = 256 bits */
/**
  * @}
  */

/** @defgroup HBS_PUBLIC_METHODS Hash-Based Signatures public method prototypes
  * @{
  */

/**
  * @brief      Mandatory function to initialize the HBS operations.
  * @param[in]  P_pHBSctx Context for HBS operations
  * @param[in]  P_Hash    Structure pointer with the hash algorithm and engine to use
  *                       This parameter can be one of the following:
  *                          @arg CMOX_HBS_SHA256;
  *                          @arg CMOX_HBS_SHAKE256;
  */
void cmox_hbs_construct(cmox_hbs_handle_t *P_pHBSctx,
                        cmox_hbs_hash_t   P_Hash);

/**
  * @brief      Verify a signature using an HBS suite.
  * @param[in]  P_pHBSctx       Context for HBS operations
  * @param[in]  P_Algo          Structure pointer with the suite parameters to use
  *                             This parameter can be one of the following:
  *                                @arg CMOX_XMSS_VERIFY_10_192
  *                                @arg CMOX_XMSS_VERIFY_16_192
  *                                @arg CMOX_XMSS_VERIFY_20_192
  *                                @arg CMOX_XMSS_VERIFY_10_256
  *                                @arg CMOX_XMSS_VERIFY_16_256
  *                                @arg CMOX_XMSS_VERIFY_20_256
  *                                @arg CMOX_LMS_VERIFY_M24
  *                                @arg CMOX_LMS_VERIFY_M32
  * @param[in]  P_pPubKey       Buffer with the public key
  * @param[in]  P_PubKeyLen     Byte length of the public key
  * @param[in]  P_pMessage      Buffer with the message to verify
  * @param[in]  P_MessageLen    Byte length of the message
  * @param[in]  P_pSignature    Buffer with the signature
  * @param[in]  P_SignatureLen  Byte length of the signature
  * @param[out] P_pFaultCheck   Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_HBS_AUTH_SUCCESS           Signature verified
  * @retval     CMOX_HBS_AUTH_FAIL              Signature NOT verified
  * @retval     CMOX_HBS_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_HBS_ERR_INVALID_SIGNATURE  Input signature corrupted or not in the expected format
  * @retval     CMOX_HBS_ERR_INVALID_PUBKEY     Public key not in a valid format
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  *             This variable is not used/modified in case alternative implementation is used.
  */
cmox_hbs_retval_t cmox_hbs_verify(cmox_hbs_handle_t       *P_pHBSctx,
                                  cmox_hbs_verify_algo_t  P_Algo,
                                  const uint8_t           *P_pPubKey,
                                  size_t                  P_PubKeyLen,
                                  const uint8_t           *P_pMessage,
                                  size_t                  P_MessageLen,
                                  const uint8_t           *P_pSignature,
                                  size_t                  P_SignatureLen,
                                  uint32_t                *P_pFaultCheck);

/**
  * @brief         Clean the HBS context.
  * @param[in,out] P_pHBSctx  Context for HBS operations
  */
void cmox_hbs_cleanup(cmox_hbs_handle_t *P_pHBSctx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* CMOX_HBS_H */

