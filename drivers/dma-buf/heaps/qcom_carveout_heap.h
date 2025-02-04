/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 */

#ifndef _QCOM_CARVEOUT_HEAP_H
#define _QCOM_CARVEOUT_HEAP_H

#include "qcom_dt_parser.h"

#ifdef CONFIG_QCOM_DMABUF_HEAPS_CARVEOUT
int qcom_secure_carveout_heap_create(struct platform_heap *heap_data);
int qcom_carveout_heap_create(struct platform_heap *heap_data);
int qcom_secure_carveout_freeze(void);
int qcom_secure_carveout_restore(void);
#else
static int qcom_secure_carveout_heap_create(struct platform_heap *heap_data)
{
	return 1;
}
static int qcom_carveout_heap_create(struct platform_heap *heap_data)
{
	return 1;
}
static inline int qcom_secure_carveout_freeze(void) { return 0; }
static inline int qcom_secure_carveout_restore(void) { return 0; }
#endif

#endif /* _QCOM_CARVEOUT_HEAP_H */
