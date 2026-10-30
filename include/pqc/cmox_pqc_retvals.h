/**
  ******************************************************************************
  * @file    cmox_pqc_retvals.h
  * @brief   This file provides the error types and code for the PQC module
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

#ifndef CMOX_PQC_RETVALS_H
#define CMOX_PQC_RETVALS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
  * @addtogroup CMOX_PQC
  * @{
  */

/**
  * @defgroup CMOX_PQC_RETVALS PQC return values
  * @{
  */

/**
  * @brief Return value type for PQC module.
  */
typedef uint32_t cmox_pqc_retval_t;

#define CMOX_PQC_SUCCESS                ((cmox_pqc_retval_t)0x00090000) /*!< Success */
#define CMOX_PQC_ERR_INTERNAL           ((cmox_pqc_retval_t)0x00090001) /*!< Internal computat. error (e.g. hash) */
#define CMOX_PQC_ERR_BAD_PARAMETERS     ((cmox_pqc_retval_t)0x00090003) /*!< Bad input parameters */
#define CMOX_PQC_ERR_BAD_OPERATION      ((cmox_pqc_retval_t)0x00090004) /*!< Bad/unsupported operation */
#define CMOX_PQC_ERR_INVALID_PUBKEY     ((cmox_pqc_retval_t)0x00090008) /*!< Invalid Public Key value */
#define CMOX_PQC_ERR_INVALID_SIGNATURE  ((cmox_pqc_retval_t)0x00090009) /*!< Invalid Signature value */
#define CMOX_PQC_ERR_WRONG_RANDOM       ((cmox_pqc_retval_t)0x0009000B) /*!< Random not compliant with the API (Recall with other random material) */
#define CMOX_PQC_ERR_MEMORY_FAIL        ((cmox_pqc_retval_t)0x0009000C) /*!< Not enough memory */
#define CMOX_PQC_ERR_NO_ALT_IMPL        ((cmox_pqc_retval_t)0x0009000D) /*!< alternative implementation function not implemented */
#define CMOX_PQC_ERR_MATH_ALGO_MISMATCH ((cmox_pqc_retval_t)0x00090010) /*!< Low-level engine not supported by current functionality */
#define CMOX_PQC_AUTH_SUCCESS           ((cmox_pqc_retval_t)0x0009C726) /*!< PQC signature successful verification */
#define CMOX_PQC_AUTH_FAIL              ((cmox_pqc_retval_t)0x00096E93) /*!< PQC signature not verified */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_PQC_RETVALS_H */
