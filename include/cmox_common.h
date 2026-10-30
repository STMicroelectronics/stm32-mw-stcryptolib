/**
  ******************************************************************************
  * @file    cmox_common.h
  * @brief   This file provides the types used within the RSA module.
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

#ifndef CMOX_COMMON_H
#define CMOX_COMMON_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/** @addtogroup CMOX_CRYPTO
  * @{
  */

/**
  * @defgroup CMOX_COMMON Common types and macros
  * @{
  */

/**
  * @defgroup CMOX_COMMON_TYPE Common types
  * @{
  */

/**
  * @brief Return value type for Initialization module
  */
typedef uint32_t cmox_init_retval_t;    /*!< Initialization return value type */

#define CMOX_INIT_SUCCESS       ((cmox_init_retval_t)0x5ba93f71) /*!< Init operation successfully performed */
#define CMOX_INIT_FAIL          ((cmox_init_retval_t)0xa7f5c827) /*!< Init operation failed */

/**
  * @}
  */

/**
  * @defgroup CMOX_COMMON_STRUCTS Common structures
  * @{
  */

/**
  *  @brief Structure to store information on the static memory.
  */
typedef struct
{
  uint8_t *MemBuf;    /*!< Pointer to the pre-allocated memory buffer */
  size_t  MemBufSize; /*!< Total size of the pre-allocated memory buffer */
  size_t  MemBufUsed; /*!< Currently used portion of the buffer */
  size_t  MaxMemUsed; /*!< Max memory used */
} cmox_membuf_handle_st;


/**
  * @}
  */

/**
  * @defgroup CMOX_COMMON_FUNCS Common function pointers and macros
  * @{
  */

/**
  * @brief Mathematical functions customizations for RSA and ECC.
  */
typedef const struct cmox_math_funcsStruct_st *cmox_math_funcs_t;

extern const cmox_math_funcs_t CMOX_MATH_FUNCS_SMALL;              /*!< Smaller footprint and slower performance.
                                                                        This is the default engine and is available for
                                                                        every target and functionality. */
extern const cmox_math_funcs_t CMOX_MATH_FUNCS_FAST;               /*!< Bigger footprint but faster performance. This
                                                                        engine is not compatible with every combination
                                                                        of platform and functionality (e.g., for RSA on
                                                                        architectures other than ARMv6m, can be used
                                                                        just with moduli whose length is multiple of 128
                                                                        bits). */
extern const cmox_math_funcs_t CMOX_MATH_FUNCS_SUPERFAST256;       /*!< Biggest footprint but fastest performance to
                                                                        speed-up those ECC curves whose length is close
                                                                        to (and less than) 256 bits, e.g., Curve25519,
                                                                        Secp256, Bpp256, Ed25519, Frp256, SM2. */


/**
  * @brief Modular exponentiation functions customizations for RSA.
  */
struct cmox_modexp_funcStruct_st;
typedef const struct cmox_modexp_funcStruct_st *cmox_modexp_func_t; /*!< Modexp implementation type definition */

extern const cmox_modexp_func_t CMOX_MODEXP_PUBLIC;               /*!< Suggested Modexp value for the target device public operations */

extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_LOWMEM;       /*!< Constant-time (for Private operations) using Low Memory (support both STD and CRT, higher code size) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_LOWMEM_STD;   /*!< Constant-time (for Private operations) using Low Memory (STD support only) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_LOWMEM_CRT;   /*!< Constant-time (for Private operations) using Low Memory (CRT support only) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_MIDMEM;       /*!< Constant-time (for Private operations) using Mid Memory (support both STD and CRT, higher code size) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_MIDMEM_STD;   /*!< Constant-time (for Private operations) using Mid Memory (STD support only) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_MIDMEM_CRT;   /*!< Constant-time (for Private operations) using Mid Memory (CRT support only) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_HIGHMEM;      /*!< Constant-time (for Private operations) using High Memory (support both STD and CRT, higher code size) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_HIGHMEM_STD;  /*!< Constant-time (for Private operations) using High Memory (STD support only) */
extern const cmox_modexp_func_t CMOX_MODEXP_PRIVATE_HIGHMEM_CRT;  /*!< Constant-time (for Private operations) using High Memory (CRT support only) */


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


#endif /* CMOX_COMMON_H */
