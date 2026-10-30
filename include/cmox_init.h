/**
  ******************************************************************************
  * @file    cmox_init.h
  * @brief   This file exports symbols needed to use init module.
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

#ifndef CMOX_INIT_H
#define CMOX_INIT_H

#include <stdint.h>
#include <stdlib.h>
#include "cmox_common.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


/** @addtogroup CMOX_CRYPTO
  * @{
  */

/** @addtogroup CMOX_INIT Initialization module
    @brief The cmox initialization is only needed for backward compatibility with STM32 Crypographic V4
  * @{
  */

/**
  * @brief Initialization target type.
  */
typedef uint32_t cmox_init_target_t;

/* STM32 target Series are provided only for compatibility with STM32 Cryptographic library V4.x.x */
/* the STM32 target Series will not be longer updated */

#define CMOX_INIT_TARGET_AUTO       ((cmox_init_target_t)0x00000000)  /*!< Let the cryptographic library auto-detect running STM32 target Series */
#define CMOX_INIT_TARGET_F0         ((cmox_init_target_t)0x46300000)  /*!< Select a STM32F0 Series target */
#define CMOX_INIT_TARGET_F1         ((cmox_init_target_t)0x46310000)  /*!< Select a STM32F1 Series target */
#define CMOX_INIT_TARGET_F2         ((cmox_init_target_t)0x46320000)  /*!< Select a STM32F2 Series target */
#define CMOX_INIT_TARGET_F3         ((cmox_init_target_t)0x46330000)  /*!< Select a STM32F3 Series target */
#define CMOX_INIT_TARGET_F4         ((cmox_init_target_t)0x46340000)  /*!< Select a STM32F4 Series target */
#define CMOX_INIT_TARGET_F7         ((cmox_init_target_t)0x46370000)  /*!< Select a STM32F7 Series target */
#define CMOX_INIT_TARGET_H5         ((cmox_init_target_t)0x48350000)  /*!< Select a STM32H5 Series target */
#define CMOX_INIT_TARGET_H7         ((cmox_init_target_t)0x48370000)  /*!< Select a STM32H72x/STM32H73x/STM32H74x/STM32H75x Series target */
#define CMOX_INIT_TARGET_H7AB       ((cmox_init_target_t)0x48378000)  /*!< Select a STM32H7Ax/STM32H7Bx Series target */
#define CMOX_INIT_TARGET_H7RS       ((cmox_init_target_t)0x48370000)  /*!< Select a STM32H7Rx/STM32H7Sx Series target */
#define CMOX_INIT_TARGET_G0         ((cmox_init_target_t)0x47300000)  /*!< Select a STM32G0 Series target */
#define CMOX_INIT_TARGET_G4         ((cmox_init_target_t)0x47340000)  /*!< Select a STM32G4 Series target */
#define CMOX_INIT_TARGET_L0         ((cmox_init_target_t)0x4C300000)  /*!< Select a STM32L0 Series target */
#define CMOX_INIT_TARGET_L1         ((cmox_init_target_t)0x4C310000)  /*!< Select a STM32L1 Series target */
#define CMOX_INIT_TARGET_L4         ((cmox_init_target_t)0x4C340000)  /*!< Select a STM32L4/4+ Series target */
#define CMOX_INIT_TARGET_L5         ((cmox_init_target_t)0x4C350000)  /*!< Select a STM32L5 Series target */
#define CMOX_INIT_TARGET_N6         ((cmox_init_target_t)0x4E360000)  /*!< Select a STM32N6 Series target */
#define CMOX_INIT_TARGET_U0         ((cmox_init_target_t)0x55300000)  /*!< Select a STM32U0 Series target */
#define CMOX_INIT_TARGET_U3         ((cmox_init_target_t)0x55330000)  /*!< Select a STM32U3 Series target */
#define CMOX_INIT_TARGET_U5         ((cmox_init_target_t)0x55350000)  /*!< Select a STM32U5 Series target */
#define CMOX_INIT_TARGET_WB         ((cmox_init_target_t)0x57420000)  /*!< Select a STM32WB Series target */
#define CMOX_INIT_TARGET_WBA        ((cmox_init_target_t)0x57424100)  /*!< Select a STM32WBA Series target */
#define CMOX_INIT_TARGET_WL         ((cmox_init_target_t)0x574C0000)  /*!< Select a STM32WL Series target */

/** @brief    Initialization structure.
  */
typedef struct
{
  cmox_init_target_t  target;     /*!< User target specification */
  void *pArg;                     /*!< User defined parameter that is transmitted to Low Level services */
} cmox_init_arg_t;


extern cmox_init_retval_t cmox_ll_init(void *pArg);
extern cmox_init_retval_t cmox_ll_deInit(void *pArg);

/**
  * @brief          Initialize CMOX library.
  * @param          pInitArg Initialization parameter see @ref cmox_init_arg_t
  * @note           pInitArg User defined parameter that is transmitted to Low Level services
  * @retval         Initialization status: @ref CMOX_INIT_SUCCESS / @ref CMOX_INIT_FAIL
  */
static inline cmox_init_retval_t cmox_initialize(cmox_init_arg_t *pInitArg) { return CMOX_INIT_SUCCESS; }

/**
  * @brief          Finalize CMOX library.
  * @param          pArg User defined parameter that is transmitted to Low Level services
  * @retval         Finalization status: @ref CMOX_INIT_SUCCESS / @ref CMOX_INIT_FAIL
  */
static inline cmox_init_retval_t cmox_finalize(void *pArg) { return CMOX_INIT_SUCCESS; }

/**
  * @}
  */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_INIT_H */
