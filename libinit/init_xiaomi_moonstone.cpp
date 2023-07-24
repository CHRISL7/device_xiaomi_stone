/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>

#include "vendor_init.h"

static const variant_info_t moonstone_global_info = {
    .hwc_value = "Global",
    .model_value = "",

    .brand = "POCO",
    .device = "moonstone",
    .marketname = "POCO X5 5G",
    .model = "22111317PI",
    .name = "moonstone_global",
    .build_fingerprint = "POCO/moonstone/moonstone:11/TKQ1.221114.001/V14.0.4.0.TMPMIXM:user/release-keys",

    .nfc = false,
};

static const variant_info_t moonstone_p_global_info = {
    .hwc_value = "Global",
    .model_value = "",

    .brand = "POCO",
    .device = "moonstone",
    .marketname = "POCO X5 5G",
    .model = "22111317PG",
    .name = "moonstone_p_global",
    .build_fingerprint = "POCO/moonstone_p_global/moonstone:13/TKQ1.221114.001/V14.0.4.0.TMPMIXM:user/release-keys",

    .nfc = true,
};

static const variant_info_t sunstone_info = {
    .hwc_value = "Global",
    .model_value = "",

    .brand = "Redmi",
    .device = "sunstone",
    .marketname = "Redmi Note 12 5G",
    .model = "22101317C",
    .name = "sunstone",
    .build_fingerprint = "Redmi/sunstone/sunstone:11/TKQ1.221013.002/V14.0.4.0.TMQMIXM:user/release-keys",

    .nfc = false,
};

static const variant_info_t sunstone_global_info = {
    .hwc_value = "Global",
    .model_value = "",

    .brand = "Redmi",
    .device = "sunstone",
    .marketname = "Redmi Note 12 5G",
    .model = "22111317G",
    .name = "sunstone_global",
    .build_fingerprint = "Redmi/sunstone_global/sunstone:13/TKQ1.221013.002/V14.0.4.0.TMQMIXM:user/release-keys",

    .nfc = true,
};

static const std::vector<variant_info_t> variants = {
    moonstone_global_info,
    moonstone_p_global_info,
    sunstone_info,
    sunstone_global_info,
};

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();
}
