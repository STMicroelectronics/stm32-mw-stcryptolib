/**
  ******************************************************************************
  * @file    cmox_pqc_config.h
  * @brief   This file provides object and macros for PQC configuration
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

#ifndef CMOX_PQC_CONFIG_H
#define CMOX_PQC_CONFIG_H

#include "pqc/cmox_pqc_types.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** @addtogroup CMOX_PQC
  * @{
  */

/**
  * @defgroup CMOX_PQC_LLENGINES Low-level engines for PQC algorithms acceleration
  * @{
  */
extern const cmox_pqc_llengines_t CMOX_PQC_LLENGINES_DEFAULT;        /*!< Default full-SW implementation */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_PQC_CONFIG_H */

