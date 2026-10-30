/**
  ******************************************************************************
  * @file    cmox_utils_membuf.h
  * @brief   Define API for memory allocation.
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

#ifndef CMOX_UTILS_MEMBUF_H
#define CMOX_UTILS_MEMBUF_H

#include <stdint.h>
#include <stdlib.h>
#include "cmox_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CMOX_UTILS
  * @{
  */

/** @defgroup CMOX_UTILS_MEMBUF Memory buffer utilities
  * @brief    Utilities to manage preallocated memory buffers for cryptographic contexts.
  * @{
  */

/**
  * @brief Macro to retrieve the internal memory buffer context, to abstract from the specific context implementation.
  * @note  Example:
  *        \code{.c}
  *        cmox_ecc_handle_t ecc_ctx;
  *        size_t membuf_used;
  *
  *        membuf_used = cmox_membuf_getMaxUsed(CMOX_GET_MEMBUF(ecc_ctx));
  *        \endcode
  */
#define CMOX_GET_MEMBUF(context_struct) (&((context_struct).membuf_str))

/**
  * @brief          Returns the maximum size (Bytes) of data used inside the preallocated static buffer.
  * @param[in]      P_pMembufCtx  Pointer to the memory buffer structure
  * @return         Maximum number of used Bytes since the construct function has been called
  * @note           The user, after having declared a higher level context and having called the relative construct
  *                 function in the following way:
  *                 \code{.c}
  *                 cmox_ecc_handle_t ecc_ctx;
  *                 size_t membuf_used;
  *
  *                 cmox_ecc_construct(&ecc_ctx, ... );
  *                 \endcode
  *                 this function can be called in the following way:
  *                 \code{.c}
  *                 membuf_used = cmox_membuf_getMaxUsed(CMOX_GET_MEMBUF(ecc_ctx));
  *                 \endcode
  *                 in order to retrieve the needed size for the temporary memory buffer to allocate.
  * @note           This function can be useful for all the cryptographic functionalities needing a preallocated
  *                 memory buffer, like ECC, RSA and PQC modules.
  */
size_t cmox_membuf_getMaxUsed(const cmox_membuf_handle_st *P_pMembufCtx);

/**
  * @brief          Reset maximum used memory (Bytes).
  * @param[in]      P_pMembufCtx  Pointer to the memory buffer structure
  */
void cmox_membuf_resetMaxUsed(cmox_membuf_handle_st *P_pMembufCtx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* CMOX_UTILS_MEMBUF_H */
