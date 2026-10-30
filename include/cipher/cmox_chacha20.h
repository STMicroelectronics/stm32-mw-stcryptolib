/**
  ******************************************************************************
  * @file    cmox_chacha20.h
  * @brief   Header file for the ChaCha20 stream cipher
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
#ifndef CMOX_CHACHA20_H
#define CMOX_CHACHA20_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Include files -------------------------------------------------------------*/
#include "cmox_cipher.h"

/** @addtogroup CMOX_CIPHER
  * @{
  */

/** @defgroup CMOX_CHACHA ChaCha20 cipher
  * @{
  */

/* Public types --------------------------------------------------------------*/

/** @defgroup CMOX_CHACHA20_PUBLIC_TYPES ChaCha20 public types
  * @{
  */

/**
  * @brief ChaCha20 mode implementation
  *
  * This type specifies if the algorithm will be used for encryption or
  * decryption.
  * This type is defined as a pointer to a structure, that contains the
  * functions needed for the specific implementation, defined in the library
  * internally
  */
typedef const struct cmox_chacha20_implStruct_st *cmox_chacha20_impl_t;

/**
  * @brief  ChaCha20 handle structure definition
  */
typedef struct
{
  cmox_cipher_handle_t super; /*!< General cipher handle */
  size_t mAadLen;             /*!< Size of the processed AAD */
  size_t mCipherLen;          /*!< Size of the processed CipherText */
  uint32_t rValue[5];         /*!< Internal: value of r */
  uint32_t hValue[5];         /*!< Internal: value of h */
  uint32_t pad[4];            /*!< Internal: value of Poly nonce */
  uint32_t internalState[16]; /*!< Internal: ChaCha Internal State */
} cmox_chacha20_handle_t;

/**
  * @}
  */

/* Public constants ----------------------------------------------------------*/

/** @defgroup CMOX_CHACHA20_PUBLIC_CONSTANTS ChaCha20 public constants
  * @{
  */

/**
  * @brief Implementation of ChaCha20 encryption (Defined internally)
  */
extern const cmox_chacha20_impl_t CMOX_CHACHA20_ENC;

/**
  * @brief Implementation of ChaCha20 decryption (Defined internally)
  */
extern const cmox_chacha20_impl_t CMOX_CHACHA20_DEC;

/**
  * @}
  */

/**
  * @brief Identifier of the ChaCha20 encryption for single-call function
  *        (Defined internally)
  */
extern const cmox_cipher_algo_t CMOX_CHACHA20_ENC_ALGO;

/**
  * @brief Identifier of the ChaCha20 decryption for single-call function
  *        (Defined internally)
  */
extern const cmox_cipher_algo_t CMOX_CHACHA20_DEC_ALGO;

/* Public methods prototypes -------------------------------------------------*/

/** @defgroup CMOX_CHACHA20_PUBLIC_METHODS ChaCha20 public method prototypes
  * @{
  */

/**
  * @brief ChaCha20 constructor
  *
  * The function is used for specifying if the algorithm will be used for
  * encryption or decryption.
  *
  * @param P_pThis Pointer to the ChaCha20 handle to initialize
  * @param P_impl  Constant that specifies the implementation to use.
  *                This parameter can be one of the following values:
  *                @arg CMOX_CHACHA20_ENC
  *                @arg CMOX_CHACHA20_DEC
  * @return cmox_cipher_handle_t* Pointer to a general cipher handle. This will
  *                be used by the general purpose cipher functions in order to
  *                perform the algorithm
  */
cmox_cipher_handle_t *cmox_chacha20_construct(cmox_chacha20_handle_t *P_pThis,
                                              cmox_chacha20_impl_t P_impl);

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

#endif /* CMOX_CHACHA20_H */
