/**
  ******************************************************************************
  * @file    cmox_kdf_retvals.h
  * @brief   Header file containing the return values for the kdf module
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
#ifndef CMOX_KDF_RETVALS_H
#define CMOX_KDF_RETVALS_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Include files -------------------------------------------------------------*/
#include <stdint.h>

/** @addtogroup CMOX_KDF
  * @{
  */

/** @defgroup CMOX_KDF_RETVALS KDF return values
  * @{
  */

/* Macros --------------------------------------------------------------------*/

/**
  * @brief KDF operation successfully performed.
  */
#define CMOX_KDF_SUCCESS                      ((cmox_kdf_retval_t)0x00080000U)

/**
  * @brief Some error happens internally in the kdf module.
  */
#define CMOX_KDF_ERR_INTERNAL                 ((cmox_kdf_retval_t)0x00080001U)

/**
  * @brief One or more parameter has been wrongly passed to the function.
  *        (e.g. pointer to NULL)
  */
#define CMOX_KDF_ERR_BAD_PARAMETER            ((cmox_kdf_retval_t)0x00080003U)

/**
  * @brief Error on performing the operation.
  *        (e.g. an operation has been called before initializing the handle)
  */
#define CMOX_KDF_ERR_BAD_OPERATION            ((cmox_kdf_retval_t)0x00080004U)

/* Public types --------------------------------------------------------------*/

/**
  * @brief KDF module return value type.
  */
typedef uint32_t cmox_kdf_retval_t;

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CMOX_KDF_RETVALS_H */

