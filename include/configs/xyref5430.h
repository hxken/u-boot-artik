/*
 * Copyright (C) 2012 Samsung Electronics
 *
 * Configuration settings for the SAMSUNG XYREF5430 (EXYNOS5430) board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */
#define CONFIG_SAMSUNG			/* in a SAMSUNG core */
#define CONFIG_S5P			/* S5P Family */
#define CONFIG_ARCH_EXYNOS		/* which is in a Exynos Family */
#define CONFIG_ARCH_EXYNOS5	        /* which is in a Exynos5 Family */
#define CONFIG_CPU_EXYNOS5430		/* which is in a Exynos5430 */
#define CONFIG_MACH_XYREF5430		/* which is in a XYREF5430 */

#define CONFIG_GPIO_DAT_MASK		/* opertation to mask dat register */

#include <asm/arch/cpu.h>		/* get chip and board defs */

#define CONFIG_ARCH_CPU_INIT
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_DISPLAY_CHIPID

/* TRUSTZONE */
#define CONFIG_TRUSTZONE_ENABLE
#ifdef CONFIG_TRUSTZONE_ENABLE
#undef CONFIG_TZPC
#define CONFIG_SMC_CMD
#define CONFIG_TRUSTZONE_RESERVED_DRAM  0x600000
#else
#define CONFIG_TZPC
#define CONFIG_TRUSTZONE_RESERVED_DRAM  0x0
#endif

/* Reserved memory for U-Boot */
#define CONFIG_UBOOT_RESERVED_DRAM  0x80000	/* Reserved 512Kbyte */
#define CONFIG_UBOOT_ATAG_RESERVED_DRAM  0x380000	/* Reserved 512Kbyte */

/* Configuration of bl1 partition size */
#define CONFIG_BL_MONITOR

/* Configuration of secure boot */
#undef CONFIG_UBOOT_SECURE_BOOT
#undef CONFIG_TZSW_SECURE_BOOT
#undef CONFIG_SECURE_BOOT

#ifdef CONFIG_SECURE_BOOT
#define CONFIG_UBOOT_SECURE_BOOT
#define CONFIG_TZSW_SECURE_BOOT
#define CONFIG_SECURE_ROOTFS
#define CONFIG_SECURE_CONTEXT_BASE      0x20003800
#define CONFIG_SECURE_KERNEL_BASE       0x20008000
#define CONFIG_SECURE_KERNEL_SIZE       PART_SIZE_KERNEL
#define CONFIG_SECURE_ROOTFS_BASE       0x21000000
#define CONFIG_SECURE_ROOTFS_SIZE       0x100000
#endif

/* Power Management is enabled */
#define CONFIG_PM
#define CONFIG_PM_VDD_MIF	        1025
#define CONFIG_PM_VDD_EGL	        900
#define CONFIG_PM_VDD_KFC	        950
#define CONFIG_PM_VDD_INT	        1050
#define CONFIG_PM_VDD_G3D	        875

/* Bootloader Recovery */
#define CONFIG_RECOVERY_MODE

/* RAMDUMP MODE */
#define CONFIG_RAMDUMP_MODE		0xD

/* Keep L2 Cache Disabled */
#define CONFIG_SYS_DCACHE_OFF

#define CONFIG_SYS_SDRAM_BASE		0x20000000
#if defined(CONFIG_TRUSTZONE_ENABLE)
#define CONFIG_SYS_TEXT_BASE		0x9F980000
#else
#define CONFIG_SYS_TEXT_BASE		0x9FF80000
#endif
#define CONFIG_SPL_TEXT_BASE		0x02026000

/* input clock of PLL: SMDK5430 has 24MHz input clock */
#define CONFIG_SYS_CLK_FREQ		24000000

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG
#define CONFIG_CMDLINE_EDITING

#define CONFIG_MACH_TYPE		MACH_TYPE_XYREF5430

/* iRAM information */
#define CONFIG_PHY_IRAM_BASE            (0x02020000)
#define CONFIG_PHY_IRAM_NS_BASE         (CONFIG_PHY_IRAM_BASE + 0x5F000)

/* BL1 version information */
#define CONFIG_BL1_VERSION_INFORM       (CONFIG_PHY_IRAM_NS_BASE + 0x810)

/* Power Down Modes */
#define S5P_CHECK_SLEEP			0x00000BAD
#define S5P_CHECK_DIDLE			0xBAD00000
#define S5P_CHECK_LPA			0xABAD0000

/* Offset for OM status registers */
#define OM_STATUS_OFFSET                0x0

/* Offset for inform registers */
#define INFORM0_OFFSET			0x800
#define INFORM1_OFFSET			0x804
#define INFORM2_OFFSET			0x808
#define INFORM3_OFFSET			0x80C

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + (1 << 20))

/* select serial console configuration */
#define CONFIG_SERIAL_MULTI
#define CONFIG_SERIAL2			/* use SERIAL 2 */
#define CONFIG_BAUDRATE			115200

#define TZPC_BASE_OFFSET		0x10000

/* SD/MMC configuration */
#define CONFIG_GENERIC_MMC
#define CONFIG_MMC
#define CONFIG_SDHCI
#define CONFIG_S5P_MSHC
#define CONFIG_S5P_SDHCI
#define CONFIG_MMC_64BIT_BUS

#if defined(CONFIG_S5P_MSHC)
#define CONFIG_MMC_SMU_INIT
#define CONFIG_MMC_EARLY_INIT
#define MMC_MAX_CHANNEL         4
#define USE_MMC0
#define USE_MMC2

#define PHASE_DEVIDER           4

#define SDR_CH0                 0x03020001
#define DDR_CH0                 0x03030002

#define SDR_CH2                 0x03020001
#define DDR_CH2                 0x03030002

#define SDR_CH4			0x00010001
#define DDR_CH4			0x00010001
#endif

/*
 * Boot configuration
 */
#define BOOT_ONENAND		0x1
#define BOOT_NAND		0x40000
#define BOOT_MMCSD		0x3
#define BOOT_NOR		0x4
#define BOOT_SEC_DEV		0x5
#define BOOT_EMMC		0x6
#define BOOT_EMMC_4_4		0x7
#define BOOT_USB                0x100

/*
 *  Boot device
 */
#define SDMMC_CH2               0x0
#define SDMMC_CH0               0x4
#define EMMC                    0x14
#define SATA                    0x18
#define SPI_SF                  0x28
#define SFMC                    0x34
#define USB                     0x40

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_PREP_BOARDCONFIG_FOR_KERNEL

/* CHIP ID */
#define CHIPID0_OFFSET		0x14
#define CHIPID1_OFFSET		0x18

/* PWM */
#define CONFIG_PWM

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/* Command definition*/
#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_MMC
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_CMD_NET
#define CONFIG_CMD_BOOTZ

/* FAT filesystem */
#define CONFIG_FAT_WRITE

#define CONFIG_BOOTDELAY		3
#define CONFIG_ZERO_BOOTDELAY_CHECK

/* USB */
#undef CONFIG_CMD_USB
/* EHCI : 2.0 Host */
#undef CONFIG_USB_EHCI
#undef CONFIG_USB_EHCI_EXYNOS
#undef CONFIG_USB_STORAGE

#define CONFIG_EXYNOS_USBD3
#undef CONFIG_S3C_USBD
#undef CONFIG_USB_CPUMODE

#define USBD_DOWN_ADDR                  0x40000000
#define EXYNOS_SYSREG_BASE              EXYNOS5430_SYSREG_BASE
#define EXYNOS_POWER_BASE               EXYNOS5430_POWER_BASE

/*
 * USBD 3.0 SFR
 */
#define USBDEVICE3_LINK_CH0_BASE	0x15400000
#define USBDEVICE3_PHYCTRL_CH0_BASE	0x15500000

#define CLK_MUX_SEL_FSYS2_OFFSET	0x0208
#define CLK_MUX_STATE_FSYS2_OFFSET	0x0408
#define USBDEVICE3_PHYCLK_SEL		(EXYNOS5430_CMU_FSYS_BASE+CLK_MUX_SEL_FSYS2_OFFSET)
#define USBDEVICE3_PHYCLK_STATE	(EXYNOS5430_CMU_FSYS_BASE+CLK_MUX_STATE_FSYS2_OFFSET)

/*
 * FASTBOOT
 */
#define CONFIG_FASTBOOT
#define CFG_FASTBOOT_SDMMCBSP
/* Fastboot multiple access */
#define CFG_FASTBOOT_MULTI_ACESS
/* Fastboot variables */
#define CFG_FASTBOOT_TRANSFER_BUFFER            (0x28000000)
#define CFG_FASTBOOT_TRANSFER_BUFFER_SIZE       (0x30000000)   /* 768MB */
#define CFG_FASTBOOT_ADDR_KERNEL                (0x20008000)
#define CFG_FASTBOOT_ADDR_RAMDISK               (0x21000000)
#define CFG_FASTBOOT_MMC_BUFFER                 (0x78000000)
#define CFG_FASTBOOT_PAGESIZE                   (2048)  // Page size of booting device
#define CFG_FASTBOOT_SDMMC_BLOCKSIZE            (512)   // Block size of sdmmc

/* MMC SPL */
#define CONFIG_SPL
#define CONFIG_SPL_15KB
#define IROM_FNPTR_BASE                         0x020200A0
#define SECCOND_BOOT_INFORM_OFFSET              0x00000028
#define SDMMC_DEV_OFFSET                        0x00000000
#define EMMC_DEV_OFFSET                         0x00000014
#define EMMC_ENDBOOTOP_OFFSET                   0x00000018

#ifdef CONFIG_SECURE_BOOT
#define CONFIG_BOOTCOMMAND	"emmc open 0;movi r z f 0 20000000;emmc close 0;"       \
                                "movi read kernel 0 20008000;movi read rootfs 0 21000000 100000;bootz 20008000 21000000"
#else
#define CONFIG_BOOTCOMMAND	"movi read kernel 0 20008000;movi read rootfs 0 21000000 100000;bootz 20008000 21000000"
#endif

#define CONFIG_RECOVERYCOMMAND	\
		"emmc partition 0 10 0;"	\
		"mmc erase user 0 1072 1;"	\
		"movi r f 1 40000000;emmc open 0;movi w z f 0 40000000;emmc close 0;"	\
		"movi r b 1 40000000;emmc open 0;movi w z b 0 40000000;emmc close 0;"	\
		"movi r u 1 40000000;emmc open 0;movi w z u 0 40000000;emmc close 0;"	\
		"movi r t 1 40000000;emmc open 0;movi w z t 0 40000000;emmc close 0;"	\
		"reset"

/* Configuration for factory reset mode */
#define CONFIG_FACTORY_RESET_MODE       0xf
#define CONFIG_FACTORY_RESET_BOOTCOMMAND        \
                "ext3format mmc 0:3;ext3format mmc 0:4;"		\
                "movi read kernel 0 20008000;"                          \
                "movi read rootfs 0 21000000 100000;"                   \
                "bootz 20008000 21000000"

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser	*/
#define CONFIG_SYS_PROMPT		"XYREF5430 # "
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE		384	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		16	/* max number of command args */
#define CONFIG_DEFAULT_CONSOLE		"console=ttySAC1,115200n8\0"
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x5E00000)
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_TEXT_BASE

#define CONFIG_SYS_HZ			1000

/* Stack sizes */
#define CONFIG_STACKSIZE		(256 << 10)	/* 256KB */

#define CONFIG_NR_DRAM_BANKS	12
#define SDRAM_BANK_SIZE		(256UL << 20UL)	/* 256 MB */
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE
#define PHYS_SDRAM_1_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_2		(CONFIG_SYS_SDRAM_BASE + SDRAM_BANK_SIZE)
#define PHYS_SDRAM_2_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_3		(CONFIG_SYS_SDRAM_BASE + (2 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_3_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_4		(CONFIG_SYS_SDRAM_BASE + (3 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_4_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_5		(CONFIG_SYS_SDRAM_BASE + (4 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_5_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_6		(CONFIG_SYS_SDRAM_BASE + (5 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_6_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_7		(CONFIG_SYS_SDRAM_BASE + (6 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_7_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_8		(CONFIG_SYS_SDRAM_BASE + (7 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_8_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_8_END_SIZE	(SDRAM_BANK_SIZE -                            \
                                               (CONFIG_TRUSTZONE_RESERVED_DRAM + \
						CONFIG_UBOOT_RESERVED_DRAM))
#define PHYS_SDRAM_9		(CONFIG_SYS_SDRAM_BASE + (8 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_9_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_10		(CONFIG_SYS_SDRAM_BASE + (9 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_10_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_11		(CONFIG_SYS_SDRAM_BASE + (10 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_11_SIZE	SDRAM_BANK_SIZE
#define PHYS_SDRAM_12		(CONFIG_SYS_SDRAM_BASE + (11 * SDRAM_BANK_SIZE))
#define PHYS_SDRAM_12_SIZE	(SDRAM_BANK_SIZE -                            \
                                               (CONFIG_TRUSTZONE_RESERVED_DRAM + \
						CONFIG_UBOOT_RESERVED_DRAM))

#define CONFIG_SYS_MONITOR_BASE	0x00000000

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH
#undef CONFIG_CMD_IMLS
#define CONFIG_IDENT_STRING		" for XYREF5430"

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0

/* Configuration of ENV size on mmc */
#define CONFIG_ENV_SIZE		(16 << 10)	/* 16 KB */
#include <asm/arch/movi_partition.h>

/* Configuration of ROOTFS_ATAGS */
#define CONFIG_ROOTFS_ATAGS
#ifdef CONFIG_ROOTFS_ATAGS
#define CONFIG_EXTRA_ENV_SETTINGS       "rootfslen= 100000"
#endif

/* Configuration for Partition */
#define CONFIG_DOS_PARTITION
#define CONFIG_NVDATA_PARTITION
#define CFG_PARTITION_START     0x6400000
#define CONFIG_IRAM_STACK	0x02080000

#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_LOAD_ADDR - 0x100000)

/* Ethernet Controllor Driver */
#ifdef CONFIG_CMD_NET
#define CONFIG_ENV_SROM_BANK		1
#endif /*CONFIG_CMD_NET*/

/* Disable devicetree support */
/* #define CONFIG_OF_LIBFDT */

/* secondary boot information */
#define CONFIG_SECOND_BOOT_INFORM_SIZE	(0x4)
#define CONFIG_SECOND_BOOT_INFORM_BASE	(CONFIG_PHY_IRAM_NS_BASE + \
						nscode_end - nscode_base)

/* image inforamtion base address for SMC */
#define CONFIG_SMC_IMAGE_INFORM_BASE	(CONFIG_PHY_IRAM_NS_BASE + \
						nscode_end - nscode_base + \
						CONFIG_SECOND_BOOT_INFORM_SIZE)
/* Offset for pmu reset status */
#define RST_STAT_OFFSET			0x404

/* RST_STAT */
#define SWRESET			(1 << 29)
#define WRESET			(1 << 28)
#define A5IS_WDTRESET		(1 << 27)
#define CORTEXA7_WDTRESET	(1 << 24)
#define CORTEXA15_WDTRESET	(1 << 23)
#define PINRESET		(1 << 16)
#define CORTEXA7_WRESET3	(1 << 7)
#define CORTEXA7_WRESET2	(1 << 6)
#define CORTEXA7_WRESET1	(1 << 5)
#define CORTEXA7_WRESET0	(1 << 4)
#define CORTEXA15_WRESET1	(1 << 1)
#define CORTEXA15_WRESET0	(1 << 0)

#endif	/* __CONFIG_H */
