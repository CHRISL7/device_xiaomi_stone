/*
 * Copyright (C) 2023 Paranoid Android
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

using android::base::GetProperty;
using std::string;

std::string hwname = GetProperty("ro.boot.hwname", "");

void property_override(string prop, string value)
{
    auto pi = (prop_info*) __system_property_find(prop.c_str());

    if (pi != nullptr)
        __system_property_update(pi, value.c_str(), value.size());
    else
        __system_property_add(prop.c_str(), prop.size(), value.c_str(), value.size());
}

void load_moonstone_p_global() {
    property_override("ro.product.mod_device", "moonstone_p_global");
}

void load_moonstone_in() {
    property_override("ro.product.device", "moonstone");
    property_override("ro.product.model", "POCO X5 5G");
    property_override("ro.product.name", "moonstone_in");
    property_override("ro.product.mod_device", "moonstone_in_global");
}

void load_sunstone_cn() {
    property_override("ro.product.brand", "Redmi");
    property_override("ro.product.device", "sunstone");
    property_override("ro.product.model", "Redmi Note 12 5G");
    property_override("ro.product.name", "sunstone_cn");
    property_override("ro.product.mod_device", "sunstone_cn_global");
}

void load_sunstone_global() {
    property_override("ro.product.brand", "Redmi");
    property_override("ro.product.device", "sunstone");
    property_override("ro.product.model", "Redmi Note 12 5G");
    property_override("ro.product.name", "sunstone_global");
    property_override("ro.product.mod_device", "sunstone_global");

}

void vendor_load_properties() {
    std::string hwname = GetProperty("ro.boot.hwname", "");
    if (access("/system/bin/recovery", F_OK) != 0) {
        if (hwname == "moonstone") {
            if (region.find("India") != std::string::npos) {
               load_moonstone_in();
            } else {
               load_moonstone_p_global();
             }
        if (hwname == "sunstone") {
            if (region.find("China") != std::string::npos) {
               load_sunstone_cn();
           } else {
               load_sunstone_global();
        }
      }
    }
  }

    // Set hardware revision
    property_override("ro.boot.hardware.revision", GetProperty("ro.boot.hwversion", "").c_str());

    // Set dalvik heap configuration
    std::string heapstartsize, heapgrowthlimit, heapsize, heapminfree,
			heapmaxfree, heaptargetutilization;

    struct sysinfo sys;
    sysinfo(&sys);

    if (sys.totalram > 5072ull * 1024 * 1024) {
        // from - phone-xhdpi-6144-dalvik-heap.mk
        heapstartsize = "16m";
        heapgrowthlimit = "256m";
        heapsize = "512m";
        heaptargetutilization = "0.5";
        heapminfree = "8m";
        heapmaxfree = "32m";
    } else if (sys.totalram > 3072ull * 1024 * 1024) {
        // from - phone-xhdpi-4096-dalvik-heap.mk
        heapstartsize = "8m";
        heapgrowthlimit = "192m";
        heapsize = "512m";
        heaptargetutilization = "0.6";
        heapminfree = "8m";
        heapmaxfree = "16m";
    } else {
        // from - phone-xhdpi-2048-dalvik-heap.mk
        heapstartsize = "8m";
        heapgrowthlimit = "192m";
        heapsize = "512m";
        heaptargetutilization = "0.75";
        heapminfree = "512k";
        heapmaxfree = "8m";
    }

    property_override("dalvik.vm.heapstartsize", heapstartsize);
    property_override("dalvik.vm.heapgrowthlimit", heapgrowthlimit);
    property_override("dalvik.vm.heapsize", heapsize);
    property_override("dalvik.vm.heaptargetutilization", heaptargetutilization);
    property_override("dalvik.vm.heapminfree", heapminfree);
    property_override("dalvik.vm.heapmaxfree", heapmaxfree);
}
