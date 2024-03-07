/**
 * Copyright (c) 2018 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiswitchextensions.h
 *
 * @brief   This module defines switch extensions of the Switch Abstraction Interface (SAI)
 */

#ifndef __SAISWITCHEXTENSIONS_H_
#define __SAISWITCHEXTENSIONS_H_

#include <saiswitch.h>
#include <saitypes.h>

/**
 * @brief HA scope event type
 */
typedef enum _sai_ha_scope_event_t
{
    /** Moved to a new HA state. */
    SAI_HA_SCOPE_STATE_CHANGED,

} sai_ha_scope_event_t;

/**
 * @brief Notification data format received from SAI HA scope callback
 *
 * @count attr[attr_count]
 */
typedef struct _sai_ha_scope_event_data_t
{
    /** Event type */
    sai_ha_scope_event_t event_type;

    /** HA scope id */
    sai_object_id_t ha_scope_id;

    /** Attributes count */
    uint32_t attr_count;

    /**
     * @brief Attributes
     *
     * @objects SAI_OBJECT_TYPE_HA_SCOPE
     */
    sai_attribute_t *attr;

} sai_ha_scope_event_data_t;

/**
 * @brief HA scope event notification
 *
 * Passed as a parameter into sai_initialize_switch()
 *
 * @count data[count]
 *
 * @param[in] count Number of notifications
 * @param[in] data Array of HA scope events
 */
typedef void (*sai_ha_scope_event_notification_fn)(
        _In_ uint32_t count,
        _In_ const sai_ha_scope_event_data_t *ha_scope_event_data);

/**
 * @brief SAI switch attribute extensions.
 *
 * @flags free
 */
typedef enum _sai_switch_attr_extensions_t
{
    SAI_SWITCH_ATTR_EXTENSIONS_RANGE_START = SAI_SWITCH_ATTR_END,

    /**
     * @brief HA scope event notification callback function passed to the adapter.
     *
     * Use sai_ha_scope_event_notification_fn as notification function.
     *
     * @type sai_pointer_t sai_ha_scope_event_notification_fn
     * @flags CREATE_AND_SET
     * @default NULL
     */
    SAI_SWITCH_ATTR_HA_SCOPE_EVENT_NOTIFY = SAI_SWITCH_ATTR_EXTENSIONS_RANGE_START,

    SAI_SWITCH_ATTR_EXTENSIONS_RANGE_END

} sai_switch_attr_extensions_t;

#endif /* __SAISWITCHEXTENSIONS_H_ */
