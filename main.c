#include "smbios/smbios_interface.h"
#include "printf.h" // CHANGE THIS TO YOUR IMPLEMENTATION OF PRINTF

void dump_smbios() {
    if (get_smbios_bios_loaded()) {
        printf("[BIOS]\n");
        printf("get_smbios_bios_vendor: %s\n", get_smbios_bios_vendor());
        printf("get_smbios_bios_version: %s\n", get_smbios_bios_version());
        printf("get_smbios_bios_release_date: %s\n", get_smbios_bios_release_date());
        printf("get_smbios_bios_major_release: %d\n", *get_smbios_bios_major_release());
        printf("get_smbios_bios_minor_release: %d\n", *get_smbios_bios_minor_release());
        printf("get_smbios_bios_embedded_controller_major_release: %d\n", *get_smbios_bios_embedded_controller_major_release());
        printf("get_smbios_bios_embedded_controller_minor_release: %d\n", *get_smbios_bios_embedded_controller_minor_release());
        printf("get_smbios_bios_not_supports_characteristics: %d\n", get_smbios_bios_not_supports_characteristics());
        printf("get_smbios_bios_supports_isa: %d\n", get_smbios_bios_supports_isa());
        printf("get_smbios_bios_supports_mca: %d\n", get_smbios_bios_supports_mca());
        printf("get_smbios_bios_supports_pci: %d\n", get_smbios_bios_supports_pci());
        printf("get_smbios_bios_supports_pnp: %d\n", get_smbios_bios_supports_pnp());
        printf("get_smbios_bios_supports_apm: %d\n", get_smbios_bios_supports_apm());
        printf("get_smbios_bios_supports_edd: %d\n", get_smbios_bios_supports_edd());
        printf("get_smbios_bios_supports_escd: %d\n", get_smbios_bios_supports_escd());
        printf("get_smbios_bios_supports_eisa: %d\n", get_smbios_bios_supports_eisa());
        printf("get_smbios_bios_supports_vl_vesa: %d\n", get_smbios_bios_supports_vl_vesa());
        printf("get_smbios_bios_supports_boot_from_cd: %d\n", get_smbios_bios_supports_boot_from_cd());
        printf("get_smbios_bios_supports_selectable_boot: %d\n", get_smbios_bios_supports_selectable_boot());
        printf("get_smbios_bios_supports_acpi: %d\n", get_smbios_bios_supports_acpi());
        printf("get_smbios_bios_supports_usb_legacy: %d\n", get_smbios_bios_supports_usb_legacy()); 
        printf("get_smbios_bios_supports_agp: %d\n", get_smbios_bios_supports_agp());
        printf("get_smbios_bios_supports_bios_boot: %d\n", get_smbios_bios_supports_bios_boot());
        printf("get_smbios_bios_supports_uefi: %d\n", get_smbios_bios_supports_uefi());
        printf("get_smbios_bios_is_virtual_machine: %d\n", get_smbios_bios_is_virtual_machine());
    }

    if (get_smbios_system_loaded()) {
        printf("[System]\n");
        printf("get_smbios_system_manufacturer: %s\n", get_smbios_system_manufacturer());
        printf("get_smbios_system_product_name: %s\n", get_smbios_system_product_name());
        printf("get_smbios_system_version: %s\n", get_smbios_system_version());
        printf("get_smbios_system_serial_number: %s\n", get_smbios_system_serial_number());
        printf("get_smbios_system_sku_number: %s\n", get_smbios_system_sku_number());
        printf("get_smbios_system_family(): %s\n", get_smbios_system_family());
        printf("get_smbios_system_uuid: ");
        for (int i = 0; i < 16; i++)
            printf("%x:", get_smbios_system_uuid()[i]);
        printf("\n");
        printf("get_smbios_system_wake_up_type: %d\n", *get_smbios_system_wake_up_type());
    }

    if (get_smbios_cpu_loaded()) {
        printf("[CPU]\n");
        printf("get_smbios_cpu_socket_designation: %s\n", get_smbios_cpu_socket_designation());
        printf("get_smbios_cpu_processor_type: %d\n", *get_smbios_cpu_processor_type());         
        printf("get_smbios_cpu_processor_family: %d\n", *get_smbios_cpu_processor_family());
        printf("get_smbios_cpu_processor_manufacturer: %s\n", get_smbios_cpu_processor_manufacturer());       
        printf("get_smbios_cpu_processor_id: %llx\n", *get_smbios_cpu_processor_id());
        printf("get_smbios_cpu_processor_version: %s\n", get_smbios_cpu_processor_version());
        printf("get_smbios_cpu_voltage_legacy: %d\n", get_smbios_cpu_voltage_legacy());
        printf("get_smbios_cpu_voltage_5V: %d\n", get_smbios_cpu_voltage_5V());
        printf("get_smbios_cpu_voltage_3_3V: %d\n", get_smbios_cpu_voltage_3_3V());
        printf("get_smbios_cpu_voltage_2_9V: %d\n", get_smbios_cpu_voltage_2_9V());
        printf("get_smbios_cpu_external_clock: %d\n", *get_smbios_cpu_external_clock());
        printf("get_smbios_cpu_max_speed: %d\n", *get_smbios_cpu_max_speed());
        printf("get_smbios_cpu_current_speed: %d\n", *get_smbios_cpu_current_speed());
        printf("get_smbios_cpu_socket_populated: %d\n", get_smbios_cpu_socket_populated());
        printf("get_smbios_cpu_enabled: %d\n", get_smbios_cpu_enabled());
        printf("get_smbios_cpu_disabled_by_user: %d\n", get_smbios_cpu_disabled_by_user());
        printf("get_smbios_cpu_disabled_by_bios: %d\n", get_smbios_cpu_disabled_by_bios());
        printf("get_smbios_cpu_idle: %d\n", get_smbios_cpu_idle());
        printf("get_smbios_cpu_processor_upgrade: %d\n", *get_smbios_cpu_processor_upgrade());
        printf("get_smbios_cpu_serial_number: %s\n", get_smbios_cpu_serial_number());
        printf("get_smbios_cpu_asset_tag: %s\n", get_smbios_cpu_asset_tag());
        printf("get_smbios_cpu_part_number: %s\n", get_smbios_cpu_part_number());     
        printf("get_smbios_cpu_core_count: %d\n", *get_smbios_cpu_core_count());
        printf("get_smbios_cpu_core_enabled: %d\n", *get_smbios_cpu_core_enabled());
        printf("get_smbios_cpu_thread_count: %d\n", *get_smbios_cpu_thread_count());
        printf("get_smbios_cpu_supports_64_bits: %d\n", get_smbios_cpu_supports_64_bits());
        printf("get_smbios_cpu_supports_multicore: %d\n", get_smbios_cpu_supports_multicore());
        printf("get_smbios_cpu_supports_hardware_thread: %d\n", get_smbios_cpu_supports_hardware_thread());
        printf("get_smbios_cpu_supports_execute_protection: %d\n", get_smbios_cpu_supports_execute_protection());
        printf("get_smbios_cpu_supports_enhanced_virtualization: %d\n", get_smbios_cpu_supports_enhanced_virtualization());
        printf("get_smbios_cpu_supports_power_management: %d\n", get_smbios_cpu_supports_power_management());
        printf("get_smbios_cpu_supports_128_bits: %d\n", get_smbios_cpu_supports_128_bits());
        printf("get_smbios_cpu_is_arm_soc: %d\n", get_smbios_cpu_is_arm_soc());
        printf("get_smbios_cpu_processor_family2: %d\n", *get_smbios_cpu_processor_family2());
    }
}

void _start() {
    void * smbios32_address = 0xdeadbeef; //Change this
    void * smbios64_address = 0xcafebabe; //And this

    init_smbios_interface(smbios32_address, smbios64_address);
    dump_smbios();

    while(1);
}