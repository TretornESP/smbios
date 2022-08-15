# SMBIOS (Almost) Standalone Implementation

Use this library to parse SMBIOS data.
Reference spec: [link](https://www.dmtf.org/sites/default/files/standards/documents/DSP0134_3.6.0.pdf)

## Current support

We currently support `SMBIOS 2` tables:

| Index  | Name      | Version | Support |
| ------ | --------- | ------- | ------- |
| 0      | BIOS      | 30+     | Partial |
| 1      | System    | 24+     | Full    |
| 2      | Processor | 26-29   | Partial |

## How to use?

First modify the file `smbios.c` in order to include
headers containing the functions defined in `stub.h`.

Simply copy the folder smbios to your project, modify
the file `smbios.c` in order to include headers 
containing the functions defined in `stub.h`.

Then you can call the startup function
`init_smbios_interface(smbios32_address, smbios64_address)`.

Pass it the address of your SMBIOS header. The pointer that doesn't belong 
to your system must be `0` (ignored). If you specify both, the 64-bit version 
will be used.

After this call, you can use every function defined in `smbios_interface.h`

## Available functions:

```c
    char *      get_smbios_bios_vendor();
    char *      get_smbios_bios_version();
    char *      get_smbios_bios_release_date();
        
    uint8_t *   get_smbios_bios_major_release();
    uint8_t *   get_smbios_bios_minor_release();
    uint8_t *   get_smbios_bios_embedded_controller_major_release();
    uint8_t *   get_smbios_bios_embedded_controller_minor_release();
    
    uint8_t     get_smbios_bios_not_supports_characteristics();
    uint8_t     get_smbios_bios_supports_isa();
    uint8_t     get_smbios_bios_supports_mca();
    uint8_t     get_smbios_bios_supports_pci();
    uint8_t     get_smbios_bios_supports_pnp();
    uint8_t     get_smbios_bios_supports_apm();
    uint8_t     get_smbios_bios_supports_edd();
    uint8_t     get_smbios_bios_supports_escd();
    uint8_t     get_smbios_bios_supports_eisa();
    uint8_t     get_smbios_bios_supports_vl_vesa();
    uint8_t     get_smbios_bios_supports_boot_from_cd();
    uint8_t     get_smbios_bios_supports_selectable_boot();
    uint8_t     get_smbios_bios_supports_acpi();
    uint8_t     get_smbios_bios_supports_usb_legacy();
    uint8_t     get_smbios_bios_supports_agp();
    uint8_t     get_smbios_bios_supports_bios_boot();
    uint8_t     get_smbios_bios_supports_uefi();
    uint8_t     get_smbios_bios_is_virtual_machine();
    
    char *      get_smbios_system_manufacturer();
    char *      get_smbios_system_product_name();
    char *      get_smbios_system_version();
    char *      get_smbios_system_serial_number();
    char *      get_smbios_system_sku_number();
    char *      get_smbios_system_family();
    uint8_t *   get_smbios_system_uuid();
    uint8_t *   get_smbios_system_wake_up_type();
    
    char *      get_smbios_cpu_socket_designation();
    uint8_t *   get_smbios_cpu_processor_type();
    uint8_t *   get_smbios_cpu_processor_family();
    char *      get_smbios_cpu_processor_manufacturer();
    uint64_t *  get_smbios_cpu_processor_id();
    char *      get_smbios_cpu_processor_version();
    
    uint8_t     get_smbios_cpu_voltage_legacy();
    uint8_t     get_smbios_cpu_voltage_5V();
    uint8_t     get_smbios_cpu_voltage_3_3V();
    uint8_t     get_smbios_cpu_voltage_2_9V();
    
    uint16_t *  get_smbios_cpu_external_clock();
    uint16_t *  get_smbios_cpu_max_speed();
    uint16_t *  get_smbios_cpu_current_speed();
    
    uint8_t     get_smbios_cpu_socket_populated();
    uint8_t     get_smbios_cpu_enabled();
    uint8_t     get_smbios_cpu_disabled_by_user();
    uint8_t     get_smbios_cpu_disabled_by_bios();
    uint8_t     get_smbios_cpu_idle();
    
    uint8_t *   get_smbios_cpu_processor_upgrade();
    char *      get_smbios_cpu_serial_number();
    char *      get_smbios_cpu_asset_tag();
    char *      get_smbios_cpu_part_number();
    uint8_t *   get_smbios_cpu_core_count();
    uint8_t *   get_smbios_cpu_core_enabled();
    uint8_t *   get_smbios_cpu_thread_count();
    
    uint8_t     get_smbios_cpu_supports_64_bits();
    uint8_t     get_smbios_cpu_supports_multicore();
    uint8_t     get_smbios_cpu_supports_hardware_thread();
    uint8_t     get_smbios_cpu_supports_execute_protection();
    uint8_t     get_smbios_cpu_supports_enhanced_virtualization();
    uint8_t     get_smbios_cpu_supports_power_management();
    uint8_t     get_smbios_cpu_supports_128_bits();
    uint8_t     get_smbios_cpu_is_arm_soc();
    uint16_t *  get_smbios_cpu_processor_family2(); 
    uint16_t *  get_smbios_cpu_core_count2();
    uint16_t *  get_smbios_cpu_core_enabled2();
    uint16_t *  get_smbios_cpu_thread_count2();
    uint16_t *  get_smbios_cpu_thread_enabled();
```

## Request to improve

The interface is really easy to expand, simply:

### To add a new table: 

- Add the table structure in `smbios.h` (one table for each version)

This structure must be packed and aligned with the specification.

- Add the table index to `smbios.c@process_smbios_table`

- Add the interface structure in `smbios_interface.h`

This structure contains every useful field that the table can provide us.
It contains items of two kinds of data: bitfields and pointers. 

- Create the processing function `process_<tablename>_information`

The function discriminates between versions and populates the interface
structure with the real smbios data.

- Create the access functions in `smbios_interface.c` and `smbios_interface.h`

Thoose are simple getters for the interface structure. 
You can use the `EXTRACT` macro for the bitfields.

### To add a new field:

- Add the field in the respective `smbios.h` and `smbios_interface.h` structures
- Modify the `process_<tablename>_information` function to populate the interface structure
- Create the access functions in `smbios_interface.c` and `smbios_interface.h`

### To support a new version:

Simply define the new version's structure and create a new case
in the `process_<tablename>_information` function in order to use
the right structure. This specially easy in case you want to define
an older version of an already supported table.