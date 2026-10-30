/**
  ******************************************************************************
  * @file    cmox_hkdf.h
  * @brief   Header file for the HKDF algorithm
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CMOX_HKDF_H
#define CMOX_HKDF_H

/* Include files -------------------------------------------------------------*/
#include "cmox_kdf.h"
#include "mac/cmox_hmac.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** @addtogroup CMOX_KDF
  * @{
  */

/** @defgroup CMOX_HKDF HKDF
  * @{
  */

/* Public macros -------------------------------------------------------------*/

/* Public types --------------------------------------------------------------*/

/** @defgroup CMOX_HKDF_PUBLIC_TYPES HKDF public types
  * @{
  */

/**
  * @brief HKDF implementation.
  *
  * This type specifies the used hash function for the HKDF construct.
  * This type is defined as a pointer to a structure, that contains the
  * functions needed for the specific implementation, defined in the library
  * internally
  */
typedef const struct cmox_hkdf_implStruct_st *cmox_hkdf_impl_t;

/**
  * @brief HKDF internal support functions
  *
  * This type specifies some functions used internally by the HKDF in order to
  * correctly perform the KDF. The structure pointed by the type is defined
  * in the library internally
  */
typedef const struct cmox_hkdf_supportStruct_st *cmox_hkdf_support_t;

/**
  * @brief HKDF handle structure definition.
  */
typedef struct
{
  cmox_kdf_handle_t super;          /*!< General KDF handle */

  cmox_hmac_handle_t hmac_handle;   /*!< HMAC function handle */

  cmox_mac_handle_t *mac;           /*!< Pointer to general hash handle */
  cmox_hkdf_support_t support;      /*!< Support functions for HKDF computation */

  uint8_t prk[64];                  /*!< Buffer containing PRK */
  uint8_t temp[64];                 /*!< Buffer for storing temporary results */
  size_t temp_len;                  /*!< Number of bytes used in the temp buffer */
  const uint8_t *input_key;         /*!< Pointer to the input key */
  size_t input_key_len;             /*!< Length of the input key */
  const uint8_t *info;              /*!< Pointer to the shared info */
  size_t info_len;                  /*!< Length of the shared info */
  const uint8_t *salt;              /*!< Pointer to the salt */
  size_t salt_len;                  /*!< Length of the salt */
  size_t output_len;                /*!< Desired output length */
  uint8_t counter;                  /*!< Internal counter */
} cmox_hkdf_handle_t;

/**
  * @}
  */

/* Public constants ----------------------------------------------------------*/

/** @defgroup CMOX_HKDF_PUBLIC_CONSTANTS HKDF public constants
  * @{
  */

/** @defgroup CMOX_HKDF_IMPL HKDF implementations
  * @{
  */

/**
  * @brief Implementation of HKDF using SHA-1 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SHA1;

/**
  * @brief Implementation of HKDF using SHA-224 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SHA224;

/**
  * @brief Implementation of HKDF using SHA-256 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SHA256;

/**
  * @brief Implementation of HKDF using SHA-384 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SHA384;

/**
  * @brief Implementation of HKDF using SHA-512 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SHA512;

/**
  * @brief Implementation of HKDF using SM3 (Defined internally).
  */
extern const cmox_hkdf_impl_t CMOX_HKDF_SM3;

/**
  * @}
  */

/** @defgroup CMOX_HKDF_ALGO HKDF single-call algorithms
  * @{
  */
/**
  * @brief Identifier of the HKDF-SHA1 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SHA1_ALGO;

/**
  * @brief Identifier of the HKDF-SHA224 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SHA224_ALGO;

/**
  * @brief Identifier of the HKDF-SHA256 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SHA256_ALGO;

/**
  * @brief Identifier of the HKDF-SHA384 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SHA384_ALGO;

/**
  * @brief Identifier of the HKDF-SHA512 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SHA512_ALGO;

/**
  * @brief Identifier of the HKDF-SM3 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_HKDF_SM3_ALGO;

/**
  * @}
  */

/**
  * @}
  */

/* Public methods prototypes -------------------------------------------------*/

/** @defgroup CMOX_HKDF_PUBLIC_METHODS HKDF public method prototypes
  * @{
  */

/**
  * @brief HKDF constructor.
  *
  * The function is used for specifying which hash function to use in
  * order to implement the HKDF algorithm.
  *
  * @param P_pThis Pointer to the HKDF handle to initialize
  * @param P_impl  Constant that specifies the implementation to use.
  *                This parameter can be one of the following values:
  *                @arg CMOX_HKDF_SHA256
  *                @arg CMOX_HKDF_SM3
  * @return cmox_kdf_handle_t* Pointer to a general KDF handle. This will
  *                be used by the general purpose KDF functions in order to
  *                perform the algorithm
  */
cmox_kdf_handle_t *cmox_hkdf_construct(cmox_hkdf_handle_t *P_pThis,
                                       cmox_hkdf_impl_t P_impl);

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
#endif /* __cplusplus */

#endif /* CMOX_HKDF_H */

