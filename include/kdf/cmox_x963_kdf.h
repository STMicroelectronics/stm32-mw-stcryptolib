/**
  ******************************************************************************
  * @file    cmox_x963_kdf.h
  * @brief   Header file for the X963_KDF algorithm
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
#ifndef CMOX_X963_KDF_H
#define CMOX_X963_KDF_H

/* Include files -------------------------------------------------------------*/
#include "cmox_kdf.h"
#include "hash/cmox_md.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** @addtogroup CMOX_MAC
  * @{
  */

/** @defgroup CMOX_X963_KDF X963_KDF
  * @{
  */

/* Public macros -------------------------------------------------------------*/

/* Public types --------------------------------------------------------------*/

/** @defgroup CMOX_X963_KDF_PUBLIC_TYPES X963_KDF public types
  * @{
  */

/**
  * @brief X963_KDF implementation.
  *
  * This type specifies the used hash function for the X963_KDF construct.
  * This type is defined as a pointer to a structure, that contains the
  * functions needed for the specific implementation, defined in the library
  * internally
  */
typedef const struct cmox_x963_kdf_implStruct_st *cmox_x963_kdf_impl_t;

/**
  * @brief X963_KDF internal support functions.
  *
  * This type specifies some functions used internally by the X963_KDF in order to
  * correctly perform the KDF. The structure pointed by the type is defined
  * in the library internally
  */
typedef const struct cmox_x963_kdf_supportStruct_st *cmox_x963_kdf_support_t;

/**
  * @brief X963_KDF handle structure definition.
  */
typedef struct
{
  cmox_kdf_handle_t super; /*!< General MAC handle */

  /**
    * @brief Hash function handle
    *
    * Depending on the chosen hash function, one of the two fields of the union
    * will be used.
    */
  union
  {
    cmox_mdSmall_handle_t md_small;     /*!< Handle for SHA-224, SHA-256, SM3 */
    cmox_mdLarge_handle_t md_large;     /*!< Handle for SHA-384, SHA-512 */
  } hash_context;

  cmox_hash_handle_t *hash;     /*!< Pointer to general hash handle */
  cmox_x963_kdf_support_t support;  /*!< Support functions for X.963 KDF computation */

  uint8_t counter[4];           /*!< Internal counter */
  const uint8_t *input_key;     /*!< Pointer to the input key */
  size_t input_key_len;         /*!< Length of the input key */
  const uint8_t *info;          /*!< Pointer to the shared info */
  size_t info_len;              /*!< Length of the shared info */
  size_t output_len;            /*!< Desired output length */
} cmox_x963_kdf_handle_t;

/**
  * @}
  */

/* Public constants ----------------------------------------------------------*/

/** @defgroup CMOX_X963_KDF_PUBLIC_CONSTANTS X963_KDF public constants
  * @{
  */

/** @defgroup CMOX_X963_KDF_IMPL X963_KDF implementations
  * @{
  */

/**
  * @brief Implementation of X963_KDF using SHA-1 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SHA1;

/**
  * @brief Implementation of X963_KDF using SHA-224 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SHA224;

/**
  * @brief Implementation of X963_KDF using SHA-256 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SHA256;

/**
  * @brief Implementation of X963_KDF using SHA-384 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SHA384;

/**
  * @brief Implementation of X963_KDF using SHA-512 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SHA512;

/**
  * @brief Implementation of X963_KDF using SM3 (Defined internally).
  */
extern const cmox_x963_kdf_impl_t CMOX_X963_KDF_SM3;

/**
  * @}
  */

/** @defgroup CMOX_X963_KDF_ALGO X963_KDF single-call algorithms
  * @{
  */

/**
  * @brief Identifier of the X963_KDF-SHA1 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SHA1_ALGO;

/**
  * @brief Identifier of the X963_KDF-SHA224 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SHA224_ALGO;

/**
  * @brief Identifier of the X963_KDF-SHA256 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SHA256_ALGO;

/**
  * @brief Identifier of the X963_KDF-SHA384 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SHA384_ALGO;

/**
  * @brief Identifier of the X963_KDF-SHA512 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SHA512_ALGO;

/**
  * @brief Identifier of the X963_KDF-SM3 algorithm for single-call function.
  *   (Defined internally)
  */
extern const cmox_kdf_algo_t CMOX_X963_KDF_SM3_ALGO;

/**
  * @}
  */

/**
  * @}
  */

/* Public methods prototypes -------------------------------------------------*/

/** @defgroup CMOX_X963_KDF_PUBLIC_METHODS X963_KDF public method prototypes
  * @{
  */

/**
  * @brief X963_KDF constructor.
  *
  * The function is used for specifying which hash function to use in
  * order to implement the X963_KDF algorithm.
  *
  * @param P_pThis Pointer to the X963_KDF handle to initialize
  * @param P_impl  Constant that specifies the implementation to use.
  *                This parameter can be one of the following values:
  *                @arg CMOX_X963_KDF_SHA256
  *                @arg CMOX_X963_KDF_SM3
  * @return cmox_kdf_handle_t* Pointer to a general KDF handle. This will
  *                be used by the general purpose KDF functions in order to
  *                perform the algorithm
  */
cmox_kdf_handle_t *cmox_x963_kdf_construct(cmox_x963_kdf_handle_t *P_pThis,
                                           cmox_x963_kdf_impl_t P_impl);

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

#endif /* CMOX_X963_KDF_H */

