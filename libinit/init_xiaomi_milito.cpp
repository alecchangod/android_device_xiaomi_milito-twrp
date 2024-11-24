/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_lmk.h>
#include <libinit_utils.h>

#include <libinit_variant.h>

#include "vendor_init.h"

static const variant_info_t monet_info = {
    .hwc_value = "GLOBAL",
    .sku_value = "",
    .hwversion = "",

    .brand = "Xiaomi",
    .device = "monet",
    .marketname = "Mi 10 Lite 5G",
    .model = "M2002J9G",
    .build_fingerprint = "Xiaomi/monet_eea/monet:12/SKQ1.211006.001/V13.0.2.0.SJIEUXM:user/release-keys",

    .nfc = true,
    .battery_size = "4160mah",
};

static const variant_info_t vangogh_info = {
    .hwc_value = "CN",
    .sku_value = "",
    .hwversion = "2.9.0",

    .brand = "Xiaomi",
    .device = "vangogh",
    .marketname = "Mi 10 Lite Zoom",
    .model = "M2002J9E",
    .build_fingerprint = "Xiaomi/vangogh/vangogh:12/SKQ1.211006.001/V13.0.9.0.SJVCNXM:user/release-keys",

    .nfc = true,
    .battery_size = "4160mah",
};

static const variant_info_t picasso_info = {
    .hwc_value = "CN",
    .sku_value = "",
    .hwversion = "3.9.0",

    .brand = "Redmi",
    .device = "picasso",
    .marketname = "Redmi K30 5G",
    .model = "M1912G7BC",
    .build_fingerprint = "Redmi/picasso/picasso:12/SKQ1.211006.001/V13.0.5.0.SGICNXM:user/release-keys",

    .nfc = true,
    .battery_size = "4500mah",
};

static const variant_info_t picasso_48m_info = {
    .hwc_value = "",
    .sku_value = "",
    .hwversion = "",

    .brand = "Redmi",
    .device = "picasso",
    .marketname = "Redmi K30i 5G",
    .model = "M1912G7BC",
    .build_fingerprint = "Redmi/picasso/picasso:12/SKQ1.211006.001/V13.0.4.0.SGICMXM:user/release-keys",

    .nfc = true,
    .battery_size = "4500mah",
};

static const std::vector<variant_info_t> variants = {
    monet_info,
    vangogh_info,
    picasso_info,
    picasso_48m_info,
};

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();
    set_lmk();

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
    property_override("ro.oem_unlock_supported", "0");
}
