/**
  ******************************************************************************
  * @file    Pre_Include_Global.h
  * @brief   Header to enable global STCryptoLib configuration file
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
#ifndef PRE_INCLUDE_GLOBAL_H_STMicroelectronics_stcryptolib
#define PRE_INCLUDE_GLOBAL_H_STMicroelectronics_stcryptolib

#ifdef __cplusplus
extern "C" {
#endif

/* origin-pack: STMicroelectronics::stcryptolib@2.3.0 */
/* file-format: 1.0.0 */

/* Device headers and defines */

/* RTE Content */
#if (CMSIS_USE_Security_STCryptoLib_CMOX_API_5_0_0)
/* Enabling global cmox configuration file */
#define CMOX_DEFAULT_FILE "mx_cmox_config.h"
#endif /* CMSIS_USE_Security_STCryptoLib_CMOX_API_5_0_0 */

#ifdef __cplusplus
}
#endif

#endif /* PRE_INCLUDE_GLOBAL_H_STMicroelectronics_stcryptolib */
