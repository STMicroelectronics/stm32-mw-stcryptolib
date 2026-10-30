/**
  ******************************************************************************
  * @file    cmox_pqc_types.h
  * @brief   This file provides the types used within the PQC module
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

#ifndef CMOX_PQC_TYPES_H
#define CMOX_PQC_TYPES_H

#include "cmox_common.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/**
  * @addtogroup CMOX_PQC PQC module
  * @{
  */

/** @defgroup CMOX_PQC_PUBLIC_TYPES PQC public types
  * @{
  */

/**
  * @brief Parameter specifying low-level engines.
  *        For example, this parameter could define the usage of a HASH HW engine,
  *        instead of the SW implementation.
  */
typedef const struct cmox_pqc_llenginesStruct_t *cmox_pqc_llengines_t;

/**
  * @brief Structure for the PQC context.
  */
typedef struct
{
  cmox_membuf_handle_st   membuf_str;       /*!< Memory buffer structure */
  cmox_pqc_llengines_t    ll_opt;           /*!< Low-level engines */
  uint32_t                magic_num_check;  /*!< Magic number for diagnostic checks */
} cmox_pqc_handle_t;


/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_PQC_TYPES_H */
