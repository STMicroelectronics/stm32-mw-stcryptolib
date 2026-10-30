/**
  ******************************************************************************
  * @file    cmox_ecc.h
  * @brief   This file provides common function for ECC module.
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

#ifndef CMOX_ECC_H
#define CMOX_ECC_H

#include <stdint.h>
#include <stdlib.h>

#include "ecc/cmox_ecc_retvals.h"
#if !defined(CMOX_DEFAULT_FILE)
#include "cmox_default_config.h"
#else
#include CMOX_DEFAULT_FILE
#endif /* CMOX_DEFAULT_FILE */
#include "ecc/cmox_ecc_types.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/** @addtogroup CMOX_ECC
  * @{
  */

/**
  * @defgroup CMOX_ECC_CURVES Supported curves implementations
  * @{
  */
extern const cmox_ecc_impl_t CMOX_ECC_CURVE25519;                   /*!< Suggested Curve25519 implementation (for X25519) for the target device */
extern const cmox_ecc_impl_t CMOX_ECC_CURVE448;                     /*!< Suggested Curve448 implementation (for X448) for the target device */

extern const cmox_ecc_impl_t CMOX_ECC_ED25519_LOWMEM;               /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_LOWMEM_KEYGEN;        /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_LOWMEM_SIGN;          /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_LOWMEM_VERIFY;        /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_HIGHMEM;              /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_HIGHMEM_KEYGEN;       /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_HIGHMEM_SIGN;         /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_HIGHMEM_VERIFY;       /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_LOWMEM;           /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_LOWMEM_KEYGEN;    /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_LOWMEM_SIGN;      /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_LOWMEM_VERIFY;    /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_HIGHMEM;          /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_HIGHMEM_KEYGEN;   /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_HIGHMEM_SIGN;     /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519_OPT_HIGHMEM_VERIFY;   /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_LOWMEM;             /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_LOWMEM_KEYGEN;      /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_LOWMEM_SIGN;        /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_LOWMEM_VERIFY;      /*!< EDWARDS Ed25519 with general Edwards functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_HIGHMEM;            /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_HIGHMEM_KEYGEN;     /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_HIGHMEM_SIGN;       /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_HIGHMEM_VERIFY;     /*!< EDWARDS Ed25519 with general Edwards functions, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_LOWMEM;         /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_LOWMEM_KEYGEN;  /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_LOWMEM_SIGN;    /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_LOWMEM_VERIFY;  /*!< EDWARDS Ed25519 with Edwards optimized functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_HIGHMEM;        /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_HIGHMEM_KEYGEN; /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_HIGHMEM_SIGN;   /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED25519PH_OPT_HIGHMEM_VERIFY; /*!< EDWARDS Ed25519 with Edwards optimized functions, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_LOWMEM;                 /*!< EDWARDS Ed448 with general Edwards functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_LOWMEM_KEYGEN;          /*!< EDWARDS Ed448 with general Edwards functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_LOWMEM_SIGN;            /*!< EDWARDS Ed448 with general Edwards functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_LOWMEM_VERIFY;          /*!< EDWARDS Ed448 with general Edwards functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_HIGHMEM;                /*!< EDWARDS Ed448 with general Edwards functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_HIGHMEM_KEYGEN;         /*!< EDWARDS Ed448 with general Edwards functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_HIGHMEM_SIGN;           /*!< EDWARDS Ed448 with general Edwards functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448_HIGHMEM_VERIFY;         /*!< EDWARDS Ed448 with general Edwards functions, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_LOWMEM;               /*!< EDWARDS Ed448ph with general Edwards functions, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_LOWMEM_KEYGEN;        /*!< EDWARDS Ed448ph with general Edwards functions, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_LOWMEM_SIGN;          /*!< EDWARDS Ed448ph with general Edwards functions, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_LOWMEM_VERIFY;        /*!< EDWARDS Ed448ph with general Edwards functions, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_HIGHMEM;              /*!< EDWARDS Ed448ph with general Edwards functions, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_HIGHMEM_KEYGEN;       /*!< EDWARDS Ed448ph with general Edwards functions, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_HIGHMEM_SIGN;         /*!< EDWARDS Ed448ph with general Edwards functions, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_ED448PH_HIGHMEM_VERIFY;       /*!< EDWARDS Ed448ph with general Edwards functions, high RAM usage, for signature verification only */

extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_LOWMEM;             /*!< NIST-R P-224, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_LOWMEM_KEYGEN;      /*!< NIST-R P-224, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_LOWMEM_SIGN;        /*!< NIST-R P-224, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_LOWMEM_VERIFY;      /*!< NIST-R P-224, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_LOWMEM_ECDH;        /*!< NIST-R P-224, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_HIGHMEM;            /*!< NIST-R P-224, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_HIGHMEM_KEYGEN;     /*!< NIST-R P-224, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_HIGHMEM_SIGN;       /*!< NIST-R P-224, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_HIGHMEM_VERIFY;     /*!< NIST-R P-224, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP224R1_HIGHMEM_ECDH;       /*!< NIST-R P-224, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_LOWMEM;             /*!< NIST-R P-256, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_LOWMEM_KEYGEN;      /*!< NIST-R P-256, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_LOWMEM_SIGN;        /*!< NIST-R P-256, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_LOWMEM_VERIFY;      /*!< NIST-R P-256, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_LOWMEM_ECDH;        /*!< NIST-R P-256, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_HIGHMEM;            /*!< NIST-R P-256, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_HIGHMEM_KEYGEN;     /*!< NIST-R P-256, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_HIGHMEM_SIGN;       /*!< NIST-R P-256, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_HIGHMEM_VERIFY;     /*!< NIST-R P-256, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256R1_HIGHMEM_ECDH;       /*!< NIST-R P-256, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_LOWMEM;             /*!< NIST-R P-384, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_LOWMEM_KEYGEN;      /*!< NIST-R P-384, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_LOWMEM_SIGN;        /*!< NIST-R P-384, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_LOWMEM_VERIFY;      /*!< NIST-R P-384, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_LOWMEM_ECDH;        /*!< NIST-R P-384, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_HIGHMEM;            /*!< NIST-R P-384, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_HIGHMEM_KEYGEN;     /*!< NIST-R P-384, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_HIGHMEM_SIGN;       /*!< NIST-R P-384, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_HIGHMEM_VERIFY;     /*!< NIST-R P-384, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP384R1_HIGHMEM_ECDH;       /*!< NIST-R P-384, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_LOWMEM;             /*!< NIST-R P-521, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_LOWMEM_KEYGEN;      /*!< NIST-R P-521, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_LOWMEM_SIGN;        /*!< NIST-R P-521, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_LOWMEM_VERIFY;      /*!< NIST-R P-521, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_LOWMEM_ECDH;        /*!< NIST-R P-521, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_HIGHMEM;            /*!< NIST-R P-521, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_HIGHMEM_KEYGEN;     /*!< NIST-R P-521, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_HIGHMEM_SIGN;       /*!< NIST-R P-521, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_HIGHMEM_VERIFY;     /*!< NIST-R P-521, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP521R1_HIGHMEM_ECDH;       /*!< NIST-R P-521, high RAM usage, for ECDH only */

extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_LOWMEM;             /*!< NIST-K P-256, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_LOWMEM_KEYGEN;      /*!< NIST-K P-256, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_LOWMEM_SIGN;        /*!< NIST-K P-256, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_LOWMEM_VERIFY;      /*!< NIST-K P-256, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_LOWMEM_ECDH;        /*!< NIST-K P-256, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_HIGHMEM;            /*!< NIST-K P-256, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_HIGHMEM_KEYGEN;     /*!< NIST-K P-256, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_HIGHMEM_SIGN;       /*!< NIST-K P-256, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_HIGHMEM_VERIFY;     /*!< NIST-K P-256, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SECP256K1_HIGHMEM_ECDH;       /*!< NIST-K P-256, high RAM usage, for ECDH only */

extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_LOWMEM;              /*!< BRAINPOOL-R P-160, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-160, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-160, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-160, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-160, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_HIGHMEM;             /*!< BRAINPOOL-R P-160, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-160, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-160, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-160, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-160, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_LOWMEM;              /*!< BRAINPOOL-R P-192, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-192, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-192, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-192, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-192, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_HIGHMEM;             /*!< BRAINPOOL-R P-192, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-192, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-192, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-192, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-192, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_LOWMEM;              /*!< BRAINPOOL-R P-224, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-224, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-224, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-224, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-224, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_HIGHMEM;             /*!< BRAINPOOL-R P-224, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-224, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-224, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-224, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-224, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_LOWMEM;              /*!< BRAINPOOL-R P-256, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-256, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-256, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-256, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-256, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_HIGHMEM;             /*!< BRAINPOOL-R P-256, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-256, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-256, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-256, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-256, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_LOWMEM;              /*!< BRAINPOOL-R P-320, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-320, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-320, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-320, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-320, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_HIGHMEM;             /*!< BRAINPOOL-R P-320, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-320, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-320, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-320, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-320, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_LOWMEM;              /*!< BRAINPOOL-R P-384, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-384, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-384, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-384, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-384, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_HIGHMEM;             /*!< BRAINPOOL-R P-384, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-384, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-384, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-384, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-384, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_LOWMEM;              /*!< BRAINPOOL-R P-512, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-R P-512, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_LOWMEM_SIGN;         /*!< BRAINPOOL-R P-512, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_LOWMEM_VERIFY;       /*!< BRAINPOOL-R P-512, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_LOWMEM_ECDH;         /*!< BRAINPOOL-R P-512, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_HIGHMEM;             /*!< BRAINPOOL-R P-512, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-R P-512, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_HIGHMEM_SIGN;        /*!< BRAINPOOL-R P-512, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-R P-512, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512R1_HIGHMEM_ECDH;        /*!< BRAINPOOL-R P-512, high RAM usage, for ECDH only */

extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_LOWMEM;              /*!< BRAINPOOL-T P-160, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-160, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-160, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-160, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-160, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_HIGHMEM;             /*!< BRAINPOOL-T P-160, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-160, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-160, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-160, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP160T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-160, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_LOWMEM;              /*!< BRAINPOOL-T P-192, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-192, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-192, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-192, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-192, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_HIGHMEM;             /*!< BRAINPOOL-T P-192, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-192, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-192, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-192, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP192T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-192, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_LOWMEM;              /*!< BRAINPOOL-T P-224, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-224, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-224, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-224, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-224, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_HIGHMEM;             /*!< BRAINPOOL-T P-224, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-224, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-224, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-224, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP224T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-224, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_LOWMEM;              /*!< BRAINPOOL-T P-256, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-256, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-256, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-256, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-256, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_HIGHMEM;             /*!< BRAINPOOL-T P-256, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-256, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-256, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-256, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP256T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-256, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_LOWMEM;              /*!< BRAINPOOL-T P-320, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-320, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-320, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-320, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-320, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_HIGHMEM;             /*!< BRAINPOOL-T P-320, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-320, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-320, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-320, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP320T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-320, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_LOWMEM;              /*!< BRAINPOOL-T P-384, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-384, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-384, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-384, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-384, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_HIGHMEM;             /*!< BRAINPOOL-T P-384, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-384, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-384, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-384, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP384T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-384, high RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_LOWMEM;              /*!< BRAINPOOL-T P-512, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_LOWMEM_KEYGEN;       /*!< BRAINPOOL-T P-512, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_LOWMEM_SIGN;         /*!< BRAINPOOL-T P-512, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_LOWMEM_VERIFY;       /*!< BRAINPOOL-T P-512, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_LOWMEM_ECDH;         /*!< BRAINPOOL-T P-512, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_HIGHMEM;             /*!< BRAINPOOL-T P-512, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_HIGHMEM_KEYGEN;      /*!< BRAINPOOL-T P-512, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_HIGHMEM_SIGN;        /*!< BRAINPOOL-T P-512, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_HIGHMEM_VERIFY;      /*!< BRAINPOOL-T P-512, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_BPP512T1_HIGHMEM_ECDH;        /*!< BRAINPOOL-T P-512, high RAM usage, for ECDH only */

extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_LOWMEM;              /*!< ANSSI P-256, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_LOWMEM_KEYGEN;       /*!< ANSSI P-256, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_LOWMEM_SIGN;         /*!< ANSSI P-256, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_LOWMEM_VERIFY;       /*!< ANSSI P-256, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_LOWMEM_ECDH;         /*!< ANSSI P-256, low RAM usage, for ECDH only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_HIGHMEM;             /*!< ANSSI P-256, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_HIGHMEM_KEYGEN;      /*!< ANSSI P-256, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_HIGHMEM_SIGN;        /*!< ANSSI P-256, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_HIGHMEM_VERIFY;      /*!< ANSSI P-256, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_FRP256V1_HIGHMEM_ECDH;        /*!< ANSSI P-256, high RAM usage, for ECDH only */

extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM;                   /*!< OSCCA 256 bit curve, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_KEYGEN;            /*!< OSCCA 256 bit curve, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_SIGN;              /*!< OSCCA 256 bit curve, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_VERIFY;            /*!< OSCCA 256 bit curve, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_ENC;               /*!< OSCCA 256 bit curve, low RAM usage, for encryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_DEC;               /*!< OSCCA 256 bit curve, low RAM usage, for decryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_LOWMEM_KEX;               /*!< OSCCA 256 bit curve, low RAM usage, for key exchange only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM;                  /*!< OSCCA 256 bit curve, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_KEYGEN;           /*!< OSCCA 256 bit curve, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_SIGN;             /*!< OSCCA 256 bit curve, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_VERIFY;           /*!< OSCCA 256 bit curve, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_ENC;              /*!< OSCCA 256 bit curve, high RAM usage, for encryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_DEC;              /*!< OSCCA 256 bit curve, high RAM usage, for decryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2_HIGHMEM_KEX;              /*!< OSCCA 256 bit curve, high RAM usage, for key exchange only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM;               /*!< OSCCA 256 bit test curve, low RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_KEYGEN;        /*!< OSCCA 256 bit test curve, low RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_SIGN;          /*!< OSCCA 256 bit test curve, low RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_VERIFY;        /*!< OSCCA 256 bit test curve, low RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_ENC;           /*!< OSCCA 256 bit test curve, low RAM usage, for encryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_DEC;           /*!< OSCCA 256 bit test curve, low RAM usage, for decryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_LOWMEM_KEX;           /*!< OSCCA 256 bit test curve, low RAM usage, for key exchange only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM;              /*!< OSCCA 256 bit test curve, high RAM usage */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_KEYGEN;       /*!< OSCCA 256 bit test curve, high RAM usage, for key generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_SIGN;         /*!< OSCCA 256 bit test curve, high RAM usage, for signature generation only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_VERIFY;       /*!< OSCCA 256 bit test curve, high RAM usage, for signature verification only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_ENC;          /*!< OSCCA 256 bit test curve, high RAM usage, for encryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_DEC;          /*!< OSCCA 256 bit test curve, high RAM usage, for decryption only */
extern const cmox_ecc_impl_t CMOX_ECC_SM2TEST_HIGHMEM_KEX;          /*!< OSCCA 256 bit test curve, high RAM usage, for key exchange only */
/**
  * @}
  */

/**
  * @defgroup CMOX_ECC_OUTPUT_LENGTHS Macros for output buffers definitions
  * @{
  */
#define CMOX_ECC_CURVE25519_PRIVKEY_LEN   32u /*!< Byte length for a byte buffer containing a CURVE25519 private key */
#define CMOX_ECC_CURVE25519_PUBKEY_LEN    32u /*!< Byte length for a byte buffer containing a CURVE25519 public key */
#define CMOX_ECC_CURVE25519_SECRET_LEN    32u /*!< Byte length for a byte buffer containing a CURVE25519 ECDH secret */
#define CMOX_ECC_CURVE448_PRIVKEY_LEN     56u /*!< Byte length for a byte buffer containing a CURVE448 private key */
#define CMOX_ECC_CURVE448_PUBKEY_LEN      56u /*!< Byte length for a byte buffer containing a CURVE448 public key */
#define CMOX_ECC_CURVE448_SECRET_LEN      56u /*!< Byte length for a byte buffer containing a CURVE448 ECDH secret */
#define CMOX_ECC_ED25519_SIG_LEN          64u /*!< Byte length for a byte buffer containing a ED25519 signature */
#define CMOX_ECC_ED25519_PRIVKEY_LEN      64u /*!< Byte length for a byte buffer containing a ED25519 private key */
#define CMOX_ECC_ED25519_PUBKEY_LEN       32u /*!< Byte length for a byte buffer containing a ED25519 public key */
#define CMOX_ECC_ED448_SIG_LEN           114u /*!< Byte length for a byte buffer containing a ED448 signature */
#define CMOX_ECC_ED448_PRIVKEY_LEN       114u /*!< Byte length for a byte buffer containing a ED448 private key */
#define CMOX_ECC_ED448_PUBKEY_LEN         57u /*!< Byte length for a byte buffer containing a ED448 public key */
#define CMOX_ECC_SECP224R1_SIG_LEN        56u /*!< Byte length for a byte buffer containing a SECP224R1 signature */
#define CMOX_ECC_SECP224R1_PRIVKEY_LEN    28u /*!< Byte length for a byte buffer containing a SECP224R1 private key */
#define CMOX_ECC_SECP224R1_PUBKEY_LEN     56u /*!< Byte length for a byte buffer containing a SECP224R1 public key */
#define CMOX_ECC_SECP224R1_SECRET_LEN     56u /*!< Byte length for a byte buffer containing a SECP224R1 ECDH secret */
#define CMOX_ECC_SECP256R1_SIG_LEN        64u /*!< Byte length for a byte buffer containing a SECP256R1 signature */
#define CMOX_ECC_SECP256R1_PRIVKEY_LEN    32u /*!< Byte length for a byte buffer containing a SECP256R1 private key */
#define CMOX_ECC_SECP256R1_PUBKEY_LEN     64u /*!< Byte length for a byte buffer containing a SECP256R1 public key */
#define CMOX_ECC_SECP256R1_SECRET_LEN     64u /*!< Byte length for a byte buffer containing a SECP256R1 ECDH secret */
#define CMOX_ECC_SECP384R1_SIG_LEN        96u /*!< Byte length for a byte buffer containing a SECP384R1 signature */
#define CMOX_ECC_SECP384R1_PRIVKEY_LEN    48u /*!< Byte length for a byte buffer containing a SECP384R1 private key */
#define CMOX_ECC_SECP384R1_PUBKEY_LEN     96u /*!< Byte length for a byte buffer containing a SECP384R1 public key */
#define CMOX_ECC_SECP384R1_SECRET_LEN     96u /*!< Byte length for a byte buffer containing a SECP384R1 ECDH secret */
#define CMOX_ECC_SECP521R1_SIG_LEN       132u /*!< Byte length for a byte buffer containing a SECP521R1 signature */
#define CMOX_ECC_SECP521R1_PRIVKEY_LEN    66u /*!< Byte length for a byte buffer containing a SECP521R1 private key */
#define CMOX_ECC_SECP521R1_PUBKEY_LEN    132u /*!< Byte length for a byte buffer containing a SECP521R1 public key */
#define CMOX_ECC_SECP521R1_SECRET_LEN    132u /*!< Byte length for a byte buffer containing a SECP521R1 ECDH secret */
#define CMOX_ECC_SECP256K1_SIG_LEN        64u /*!< Byte length for a byte buffer containing a SECP256K1 signature */
#define CMOX_ECC_SECP256K1_PRIVKEY_LEN    32u /*!< Byte length for a byte buffer containing a SECP256K1 private key */
#define CMOX_ECC_SECP256K1_PUBKEY_LEN     64u /*!< Byte length for a byte buffer containing a SECP256K1 public key */
#define CMOX_ECC_SECP256K1_SECRET_LEN     64u /*!< Byte length for a byte buffer containing a SECP256K1 ECDH secret */
#define CMOX_ECC_BPP160R1_SIG_LEN         40u /*!< Byte length for a byte buffer containing a BPP160R1 signature */
#define CMOX_ECC_BPP160R1_PRIVKEY_LEN     20u /*!< Byte length for a byte buffer containing a BPP160R1 private key */
#define CMOX_ECC_BPP160R1_PUBKEY_LEN      40u /*!< Byte length for a byte buffer containing a BPP160R1 public key */
#define CMOX_ECC_BPP160R1_SECRET_LEN      40u /*!< Byte length for a byte buffer containing a BPP160R1 ECDH secret */
#define CMOX_ECC_BPP192R1_SIG_LEN         48u /*!< Byte length for a byte buffer containing a BPP192R1 signature */
#define CMOX_ECC_BPP192R1_PRIVKEY_LEN     24u /*!< Byte length for a byte buffer containing a BPP192R1 private key */
#define CMOX_ECC_BPP192R1_PUBKEY_LEN      48u /*!< Byte length for a byte buffer containing a BPP192R1 public key */
#define CMOX_ECC_BPP192R1_SECRET_LEN      48u /*!< Byte length for a byte buffer containing a BPP192R1 ECDH secret */
#define CMOX_ECC_BPP224R1_SIG_LEN         56u /*!< Byte length for a byte buffer containing a BPP224R1 signature */
#define CMOX_ECC_BPP224R1_PRIVKEY_LEN     28u /*!< Byte length for a byte buffer containing a BPP224R1 private key */
#define CMOX_ECC_BPP224R1_PUBKEY_LEN      56u /*!< Byte length for a byte buffer containing a BPP224R1 public key */
#define CMOX_ECC_BPP224R1_SECRET_LEN      56u /*!< Byte length for a byte buffer containing a BPP224R1 ECDH secret */
#define CMOX_ECC_BPP256R1_SIG_LEN         64u /*!< Byte length for a byte buffer containing a BPP256R1 signature */
#define CMOX_ECC_BPP256R1_PRIVKEY_LEN     32u /*!< Byte length for a byte buffer containing a BPP256R1 private key */
#define CMOX_ECC_BPP256R1_PUBKEY_LEN      64u /*!< Byte length for a byte buffer containing a BPP256R1 public key */
#define CMOX_ECC_BPP256R1_SECRET_LEN      64u /*!< Byte length for a byte buffer containing a BPP256R1 ECDH secret */
#define CMOX_ECC_BPP320R1_SIG_LEN         80u /*!< Byte length for a byte buffer containing a BPP320R1 signature */
#define CMOX_ECC_BPP320R1_PRIVKEY_LEN     40u /*!< Byte length for a byte buffer containing a BPP320R1 private key */
#define CMOX_ECC_BPP320R1_PUBKEY_LEN      80u /*!< Byte length for a byte buffer containing a BPP320R1 public key */
#define CMOX_ECC_BPP320R1_SECRET_LEN      80u /*!< Byte length for a byte buffer containing a BPP320R1 ECDH secret */
#define CMOX_ECC_BPP384R1_SIG_LEN         96u /*!< Byte length for a byte buffer containing a BPP384R1 signature */
#define CMOX_ECC_BPP384R1_PRIVKEY_LEN     48u /*!< Byte length for a byte buffer containing a BPP384R1 private key */
#define CMOX_ECC_BPP384R1_PUBKEY_LEN      96u /*!< Byte length for a byte buffer containing a BPP384R1 public key */
#define CMOX_ECC_BPP384R1_SECRET_LEN      96u /*!< Byte length for a byte buffer containing a BPP384R1 ECDH secret */
#define CMOX_ECC_BPP512R1_SIG_LEN        128u /*!< Byte length for a byte buffer containing a BPP512R1 signature */
#define CMOX_ECC_BPP512R1_PRIVKEY_LEN     64u /*!< Byte length for a byte buffer containing a BPP512R1 private key */
#define CMOX_ECC_BPP512R1_PUBKEY_LEN     128u /*!< Byte length for a byte buffer containing a BPP512R1 public key */
#define CMOX_ECC_BPP512R1_SECRET_LEN     128u /*!< Byte length for a byte buffer containing a BPP512R1 ECDH secret */
#define CMOX_ECC_BPP160T1_SIG_LEN         40u /*!< Byte length for a byte buffer containing a BPP160T1 signature */
#define CMOX_ECC_BPP160T1_PRIVKEY_LEN     20u /*!< Byte length for a byte buffer containing a BPP160T1 private key */
#define CMOX_ECC_BPP160T1_PUBKEY_LEN      40u /*!< Byte length for a byte buffer containing a BPP160T1 public key */
#define CMOX_ECC_BPP160T1_SECRET_LEN      40u /*!< Byte length for a byte buffer containing a BPP160T1 ECDH secret */
#define CMOX_ECC_BPP192T1_SIG_LEN         48u /*!< Byte length for a byte buffer containing a BPP192T1 signature */
#define CMOX_ECC_BPP192T1_PRIVKEY_LEN     24u /*!< Byte length for a byte buffer containing a BPP192T1 private key */
#define CMOX_ECC_BPP192T1_PUBKEY_LEN      48u /*!< Byte length for a byte buffer containing a BPP192T1 public key */
#define CMOX_ECC_BPP192T1_SECRET_LEN      48u /*!< Byte length for a byte buffer containing a BPP192T1 ECDH secret */
#define CMOX_ECC_BPP224T1_SIG_LEN         56u /*!< Byte length for a byte buffer containing a BPP224T1 signature */
#define CMOX_ECC_BPP224T1_PRIVKEY_LEN     28u /*!< Byte length for a byte buffer containing a BPP224T1 private key */
#define CMOX_ECC_BPP224T1_PUBKEY_LEN      56u /*!< Byte length for a byte buffer containing a BPP224T1 public key */
#define CMOX_ECC_BPP224T1_SECRET_LEN      56u /*!< Byte length for a byte buffer containing a BPP224T1 ECDH secret */
#define CMOX_ECC_BPP256T1_SIG_LEN         64u /*!< Byte length for a byte buffer containing a BPP256T1 signature */
#define CMOX_ECC_BPP256T1_PRIVKEY_LEN     32u /*!< Byte length for a byte buffer containing a BPP256T1 private key */
#define CMOX_ECC_BPP256T1_PUBKEY_LEN      64u /*!< Byte length for a byte buffer containing a BPP256T1 public key */
#define CMOX_ECC_BPP256T1_SECRET_LEN      64u /*!< Byte length for a byte buffer containing a BPP256T1 ECDH secret */
#define CMOX_ECC_BPP320T1_SIG_LEN         80u /*!< Byte length for a byte buffer containing a BPP320T1 signature */
#define CMOX_ECC_BPP320T1_PRIVKEY_LEN     40u /*!< Byte length for a byte buffer containing a BPP320T1 private key */
#define CMOX_ECC_BPP320T1_PUBKEY_LEN      80u /*!< Byte length for a byte buffer containing a BPP320T1 public key */
#define CMOX_ECC_BPP320T1_SECRET_LEN      80u /*!< Byte length for a byte buffer containing a BPP320T1 ECDH secret */
#define CMOX_ECC_BPP384T1_SIG_LEN         96u /*!< Byte length for a byte buffer containing a BPP384T1 signature */
#define CMOX_ECC_BPP384T1_PRIVKEY_LEN     48u /*!< Byte length for a byte buffer containing a BPP384T1 private key */
#define CMOX_ECC_BPP384T1_PUBKEY_LEN      96u /*!< Byte length for a byte buffer containing a BPP384T1 public key */
#define CMOX_ECC_BPP384T1_SECRET_LEN      96u /*!< Byte length for a byte buffer containing a BPP384T1 ECDH secret */
#define CMOX_ECC_BPP512T1_SIG_LEN        128u /*!< Byte length for a byte buffer containing a BPP512T1 signature */
#define CMOX_ECC_BPP512T1_PRIVKEY_LEN     64u /*!< Byte length for a byte buffer containing a BPP512T1 private key */
#define CMOX_ECC_BPP512T1_PUBKEY_LEN     128u /*!< Byte length for a byte buffer containing a BPP512T1 public key */
#define CMOX_ECC_BPP512T1_SECRET_LEN     128u /*!< Byte length for a byte buffer containing a BPP512T1 ECDH secret */
#define CMOX_ECC_FRP256V1_SIG_LEN         64u /*!< Byte length for a byte buffer containing a FRP256V1 signature */
#define CMOX_ECC_FRP256V1_PRIVKEY_LEN     32u /*!< Byte length for a byte buffer containing a FRP256V1 private key */
#define CMOX_ECC_FRP256V1_PUBKEY_LEN      64u /*!< Byte length for a byte buffer containing a FRP256V1 public key */
#define CMOX_ECC_FRP256V1_SECRET_LEN      64u /*!< Byte length for a byte buffer containing a FRP256V1 ECDH secret */
#define CMOX_ECC_SM2_SIG_LEN              64u /*!< Byte length for a byte buffer containing a SM2 signature */
#define CMOX_ECC_SM2_PRIVKEY_LEN          32u /*!< Byte length for a byte buffer containing a SM2 private key */
#define CMOX_ECC_SM2_PUBKEY_LEN           64u /*!< Byte length for a byte buffer containing a SM2 public key */
#define CMOX_ECC_SM2_SECRET_LEN           64u /*!< Byte length for a byte buffer containing a SM2 ECDH secret */
#define CMOX_ECC_SM2_KEX_HASH_S1_LEN      32u /*!< Byte length for just the first hash of the key exchange */
#define CMOX_ECC_SM2_KEX_HASH_S1S2_LEN    64u /*!< Byte length for both hashes of the key exchange */
#define CMOX_ECC_SM2TEST_SIG_LEN          64u /*!< Byte length for a byte buffer containing a SM2TEST signature */
#define CMOX_ECC_SM2TEST_PRIVKEY_LEN      32u /*!< Byte length for a byte buffer containing a SM2TEST private key */
#define CMOX_ECC_SM2TEST_PUBKEY_LEN       64u /*!< Byte length for a byte buffer containing a SM2TEST public key */
#define CMOX_ECC_SM2TEST_SECRET_LEN       64u /*!< Byte length for a byte buffer containing a SM2TEST ECDH secret */
#define CMOX_ECC_SM2TEST_KEX_HASH_S1_LEN  32u /*!< Byte length for just the first hash of the key exchange */
#define CMOX_ECC_SM2TEST_KEX_HASH_S1S2_LEN 64u /*!< Byte length for both hashes of the key exchange */
/**
  * @}
  */

/**
  * @defgroup CMOX_ECC_PUBLIC_METHODS ECC public method prototypes
  * @{
  */

/**
  * @brief         Mandatory function to set Low Level Mathematical Functions, and working memory buffer, for ECC.
  * @param[in,out] P_pEccCtx  Context for ECC operations
  * @param[in]     P_Math     Structure pointer with the Low-level Mathematical functions
  *                           This parameter can be one of the following:
  *                              @arg CMOX_MATH_FUNCS_SMALL
  *                              @arg CMOX_MATH_FUNCS_FAST
  *                              @arg CMOX_MATH_FUNCS_SUPERFAST256
  * @param[in]     P_pBuf     The preallocated static buffer that will be used
  * @param[in]     P_BufLen   The size in bytes of the P_pBuf buffer
  */
void cmox_ecc_construct(cmox_ecc_handle_t        *P_pEccCtx,
                        const cmox_math_funcs_t  P_Math,
                        uint8_t                  *P_pBuf,
                        size_t                   P_BufLen);

/**
  * @brief         Clean the ECC context and the internal temporary buffer.
  * @param[in,out] P_pEccCtx  Context for ECC operations
  */
void cmox_ecc_cleanup(cmox_ecc_handle_t *P_pEccCtx);

/**
  * @brief         Create a random value by using extra bits (see NIST FIPS 186-4,
  *                paragraph B.4.1 "Key Pair Generation Using Extra Random Bits"),
  *                without the final '+1' increment (that will be done by subsequent
  *                cryptographic functions).
  *                The output of this function must be used as input for the higher
  *                level algorithms function calls where a random seed is requested
  *                (e.g. ECDSA KeyGen or SigGen), and will never let those functions
  *                returning the error CMOX_ECC_ERR_WRONG_RANDOM.
  * @param[in,out] P_pEccCtx      Context for ECC operations
  * @param[in]     P_CurveParams  Curve Parameters and point functions
  * @param[in]     P_pInput       Input random buffer (needs to be longer than
  *                               the curve parameter N by at least 64 bit, and
  *                               cannot be more than twice longer)
  * @param[in]     P_InputLen     Length (in bytes) of the input random buffer
  * @param[out]    P_pOutput      Output buffer, containing the random value in
  *                               the range [0; N). It must be at least long as
  *                               CMOX_ECC_xxxxxx_PRIVKEY_LEN.
  * @param[out]    P_pOutputLen   Length (in bytes) of the output random buffer.
  *                               It will be the same length of the parameter N
  *                               of the curve
  * @retval CMOX_ECC_SUCCESS                Everything OK
  * @retval CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval CMOX_ECC_ERR_ALGOCURVE_MISMATCH Curve is not compatible with current functionality
  * @retval CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval CMOX_ECC_ERR_WRONG_RANDOM       Random material too short (< bitlen(N) + 64) or too long (> 2 * bitlen(N))
  * @retval CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  * @note   P_pInput and P_pOutput can be the same buffer
  */
cmox_ecc_retval_t cmox_ecc_extraBitRndGen(cmox_ecc_handle_t     *P_pEccCtx,
                                          const cmox_ecc_impl_t P_CurveParams,
                                          const uint8_t         *P_pInput,
                                          size_t                P_InputLen,
                                          uint8_t               *P_pOutput,
                                          size_t                *P_pOutputLen);

/**
  * @brief      Compress an ECC public key (point) to a single coordinate plus the leading compression byte.
  * @param[in]  P_pEccCtx           Context for ECC operations
  * @param[in]  P_CurveParams       Curve Parameters
  * @param[in]  P_pUncomprPubKey    Uncompressed public key (X concatenated with Y),
  *                                 with or without the leading compression byte `04`
  * @param[in]  P_UncomprPubKeyLen  Byte length of the uncompressed public key
  * @param[out] P_pComprPubKey      Buffer with the compressed public key,
  *                                 with the leading compression byte (`02` or `03`)
  * @param[out] P_pComprPubKeyLen   Byte length of the compressed public key
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY     Wrong public key leading compression byte (if present)
  * @retval     CMOX_ECC_ERR_BAD_OPERATION      Provided curve does not support this functionality
  *                                             (only Short-Weierstrass curves do)
  */
cmox_ecc_retval_t cmox_ecc_compressPubKey(cmox_ecc_handle_t     *P_pEccCtx,
                                          const cmox_ecc_impl_t P_CurveParams,
                                          const uint8_t         *P_pUncomprPubKey,
                                          size_t                P_UncomprPubKeyLen,
                                          uint8_t               *P_pComprPubKey,
                                          size_t                *P_pComprPubKeyLen);

/**
  * @brief      Decompress an ECC public key (point), recovering the missing coordinate.
  * @param[in]  P_pEccCtx           Context for ECC operations
  * @param[in]  P_CurveParams       Curve Parameters
  * @param[in]  P_pComprPubKey      Buffer with the compressed public key,
  *                                 with the leading compression byte (`02` or `03`)
  * @param[in]  P_ComprPubKeyLen    Byte length of the compressed public key
  * @param[out] P_pUncomprPubKey    Uncompressed public key (X concatenated with Y),
  *                                 without the leading compression byte `04`
  * @param[out] P_pUncomprPubKeyLen Byte length of the uncompressed public key
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Provided curve parameter is for alternative implementation, and not for
  *                                             standard software impl.
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called or wrong
  *                                             public key leading compression byte
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_ECC_ERR_BAD_OPERATION      Provided curve does not support this functionality (only
  *                                             Short-Weierstrass curves do) or it was not possible to retrieve the
  *                                             missing coordinate for this input value
  * @warning    Actually does NOT support Alternative Implementations
  */
cmox_ecc_retval_t cmox_ecc_decompressPubKey(cmox_ecc_handle_t     *P_pEccCtx,
                                            const cmox_ecc_impl_t P_CurveParams,
                                            const uint8_t         *P_pComprPubKey,
                                            size_t                P_ComprPubKeyLen,
                                            uint8_t               *P_pUncomprPubKey,
                                            size_t                *P_pUncomprPubKeyLen);

/**
  * @brief      validate an ECC public key (point), for Short-Weierstrass or Edwards curves.
  * @param[in]  P_pEccCtx      Context for ECC operations
  * @param[in]  P_CurveParams  Curve Parameters
  * @param[in]  P_pPubKey      Buffer with the uncompressed public key (raw format: no leading compression byte)
  * @param[in]  P_PubKeyLen    Byte length of the public key buffer
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_ALGOCURVE_MISMATCH Provided curve parameter is for alternative implementation, and not for
  *                                             standard software impl.
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called or wrong
  *                                             public key leading compression byte
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  * @warning    The curve parameter, if for Edwards curves, MUST support Verification Functionalities
  * @warning    Actually does NOT support Alternative Implementations
  */
cmox_ecc_retval_t cmox_ecc_validatePubKey(cmox_ecc_handle_t     *P_pEccCtx,
                                          const cmox_ecc_impl_t P_CurveParams,
                                          const uint8_t         *P_pPubKey,
                                          size_t                P_PubKeyLen);

/**
  * @brief      Generate private and public keys to use with ECDSA, SM2 or EdDSA, depending on the chosen curve.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters
  * @param[in]  P_pRandom       Buffer of random bytes
  * @param[in]  P_RandomLen     Byte length of the random buffer
  * @param[out] P_pPrivKey      Buffer with the private key
  * @param[out] P_pPrivKeyLen   Byte length of the private key
  * @param[out] P_pPubKey       Buffer with the public key
  * @param[out] P_pPubKeyLen    Byte length of the public key
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  */
cmox_ecc_retval_t cmox_ecc_keyGen(cmox_ecc_handle_t     *P_pEccCtx,
                                  const cmox_ecc_impl_t P_CurveParams,
                                  const uint8_t         *P_pRandom,
                                  size_t                P_RandomLen,
                                  uint8_t               *P_pPrivKey,
                                  size_t                *P_pPrivKeyLen,
                                  uint8_t               *P_pPubKey,
                                  size_t                *P_pPubKeyLen);

/**
  * @brief      Generate a signature, using ECDSA, SM2 or EdDSA, depending on the chosen curve.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters
  * @param[in]  P_pRandom       Buffer of random bytes (not required nor used for some algorithms, e.g. EdDSA)
  * @param[in]  P_RandomLen     Byte length of the random buffer (not required nor used for some algorithms, e.g. EdDSA)
  * @param[in]  P_pPrivKey      Buffer with the private key
  * @param[in]  P_PrivKeyLen    Byte length of the private key
  * @param[in]  P_pDigest       Buffer with the digest to sign
  * @param[in]  P_DigestLen     Byte length of the digest
  * @param[out] P_pSignature    Buffer with the signature (concatenation of R and S)
  * @param[out] P_pSignatureLen Byte length of the signature
  * @retval     CMOX_ECC_SUCCESS                Everything OK
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_WRONG_RANDOM       Random material too short or not valid for the functionality
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  */
cmox_ecc_retval_t cmox_ecc_sign(cmox_ecc_handle_t     *P_pEccCtx,
                                const cmox_ecc_impl_t P_CurveParams,
                                const uint8_t         *P_pRandom,
                                size_t                P_RandomLen,
                                const uint8_t         *P_pPrivKey,
                                size_t                P_PrivKeyLen,
                                const uint8_t         *P_pDigest,
                                size_t                P_DigestLen,
                                uint8_t               *P_pSignature,
                                size_t                *P_pSignatureLen);

/**
  * @brief      Verify a signature, using ECDSA, SM2 or EdDSA, depending on the chosen curve.
  * @param[in]  P_pEccCtx       Context for ECC operations
  * @param[in]  P_CurveParams   Curve Parameters
  * @param[in]  P_pPubKey       Buffer with the public key
  * @param[in]  P_PubKeyLen     Byte length of the public key
  * @param[in]  P_pDigest       Buffer with the digest to verify
  * @param[in]  P_DigestLen     Byte length of the digest
  * @param[in]  P_pSignature    Buffer with the signature (concatenation of R and S)
  * @param[in]  P_SignatureLen  Byte length of the signature
  * @param[out] P_pFaultCheck   Optional value to check, together with the retval, to verify if some fault happened
  * @retval     CMOX_ECC_AUTH_SUCCESS           Signature verified
  * @retval     CMOX_ECC_AUTH_FAIL              Signature NOT verified
  * @retval     CMOX_ECC_ERR_MATHCURVE_MISMATCH Mathematical function set is not compatible with current ECC curve
  * @retval     CMOX_ECC_ERR_BAD_PARAMETERS     Some NULL/wrong/empty parameter or Construct API not called
  * @retval     CMOX_ECC_ERR_MEMORY_FAIL        Not enough memory
  * @retval     CMOX_ECC_ERR_INVALID_SIGNATURE  Input signature corrupted or not in the expected format
  * @retval     CMOX_ECC_ERR_INVALID_PUBKEY     Public key not in a valid format
  * @note       P_pFaultCheck value, if the parameter is provided, MUST be checked to
  *             be equal to the retval, and both MUST be equal to the successful value.
  *             P_pFaultCheck MUST be checked only if the main result is successful,
  *             and has no relevance if the main result is not successful.
  *             Every comparison (both for the return value and for P_pFaultCheck) must be done against
  *             the success value, and not comparing the value with the failure value. Indeed, in presence of faults,
  *             especially P_pFaultCheck, could be a dirty value.
  *             This variable is not used/modified in case ECDSA alternative implementation is used.
  */
cmox_ecc_retval_t cmox_ecc_verify(cmox_ecc_handle_t     *P_pEccCtx,
                                  const cmox_ecc_impl_t P_CurveParams,
                                  const uint8_t         *P_pPubKey,
                                  size_t                P_PubKeyLen,
                                  const uint8_t         *P_pDigest,
                                  size_t                P_DigestLen,
                                  const uint8_t         *P_pSignature,
                                  size_t                P_SignatureLen,
                                  uint32_t              *P_pFaultCheck);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CMOX_ECC_H */
