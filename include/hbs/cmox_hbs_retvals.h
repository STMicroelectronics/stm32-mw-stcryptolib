/**
  ******************************************************************************
  * @file    cmox_hbs_retvals.h
  * @brief   This file provides the error types and code for the HBS module
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

#ifndef CMOX_HBS_RETVALS_H
#define CMOX_HBS_RETVALS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
  * @addtogroup HBS
  * @{
  */

/**
  * @defgroup HBS_RETVALS ECC return values
  * @{
  */

/**
  * @brief Return value type for HBS module.
  */
typedef uint32_t cmox_hbs_retval_t;

#define CMOX_HBS_SUCCESS                ((cmox_hbs_retval_t)0x00100000) /*!< Success */
#define CMOX_HBS_ERR_INTERNAL           ((cmox_hbs_retval_t)0x00100001) /*!< Internal computat. error (e.g. hash) */
#define CMOX_HBS_ERR_BAD_PARAMETERS     ((cmox_hbs_retval_t)0x00100003) /*!< Bad input parameters */
#define CMOX_HBS_ERR_BAD_OPERATION      ((cmox_hbs_retval_t)0x00100004) /*!< Bad/unsupported operation */
#define CMOX_HBS_ERR_INVALID_PUBKEY     ((cmox_hbs_retval_t)0x00100008) /*!< Invalid Public Key value */
#define CMOX_HBS_ERR_INVALID_SIGNATURE  ((cmox_hbs_retval_t)0x00100009) /*!< Invalid Signature value */
#define CMOX_HBS_ERR_NO_ALT_IMPL        ((cmox_hbs_retval_t)0x0010000D) /*!< alternative implementation function not implemented */
#define CMOX_HBS_AUTH_SUCCESS           ((cmox_hbs_retval_t)0x0010C726) /*!< signature successful verification */
#define CMOX_HBS_AUTH_FAIL              ((cmox_hbs_retval_t)0x00106E93) /*!< signature not verified */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_HBS_RETVALS_H */

