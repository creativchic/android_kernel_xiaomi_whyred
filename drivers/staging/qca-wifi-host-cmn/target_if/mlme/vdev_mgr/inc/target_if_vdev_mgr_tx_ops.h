/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: target_if_vdev_mgmt_tx_ops.h
 *
 * This file provides declaration for APIs to send WMI commands
 */

#ifndef __TARGET_IF_VDEV_MGR_TX_OPS_H__
#define __TARGET_IF_VDEV_MGR_TX_OPS_H__

#ifdef CMN_VDEV_MGR_TGT_IF_ENABLE
#include <wlan_vdev_mgr_tgt_if_tx_defs.h>
#include <wlan_objmgr_vdev_obj.h>
#include <wlan_objmgr_psoc_obj.h>
#include <wlan_lmac_if_def.h>

/**
 * target_if_vdev_mgr_wmi_handle_get() - API to get wmi handle from vdev
 * @vdev: pointer to vdev
 *
 * Return: pointer to wmi_unified handle or NULL
 */
struct wmi_unified *target_if_vdev_mgr_wmi_handle_get(
					struct wlan_objmgr_vdev *vdev);

/**
 * target_if_vdev_mgr_get_tx_ops() - get tx ops
 * @psoc: pointer to psoc obj
 *
 * Return: pointer to tx ops
 */
static inline struct wlan_lmac_if_mlme_tx_ops *
target_if_vdev_mgr_get_tx_ops(struct wlan_objmgr_psoc *psoc)
{
	return &psoc->soc_cb.tx_ops.mops;
}

/**
 * target_if_vdev_mgr_vdev_mlme_register_tx_ops() - define mlme lmac
 * tx ops functions
 * @tx_ops: pointer to lmac tx ops
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS
target_if_vdev_mgr_register_tx_ops(struct wlan_lmac_if_tx_ops *tx_ops);

#else

static inline QDF_STATUS
target_if_vdev_mgr_register_tx_ops(struct wlan_lmac_if_tx_ops *tx_ops)
{
	return QDF_STATUS_SUCCESS;
}

#endif /* CMN_VDEV_MGR_TGT_IF_ENABLE */
#endif /* __TARGET_IF_VDEV_MGR_TX_OPS_H__ */
