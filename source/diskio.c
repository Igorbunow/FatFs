/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */

/* Definitions of physical drive number for each drive */
#define DEV_RAM		0	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat = STA_NOINIT;

	switch (pdrv) {
	case DEV_RAM :
		stat = RAM_disk_status();
		break;

	case DEV_MMC :
		stat = MMC_disk_status();
		break;
		
	case DEV_USB :
		stat = USB_disk_status();
		break;
		
	}
	return stat;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat = STA_NOINIT;

	switch (pdrv) {
	case DEV_RAM :
		stat = RAM_disk_initialize();
		break;

	case DEV_MMC :
		stat = MMC_disk_initialize();
		break;

	case DEV_USB :
		stat = USB_disk_initialize();
		DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 0 , "");
		break;
	}
	DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 64 , " status:%d", stat);
	return stat;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res = RES_PARERR;

	switch (pdrv) {
	case DEV_RAM :
		// translate the arguments here

		res = RAM_disk_read(buff, sector, count);

		// translate the reslut code here

		break;

	case DEV_MMC :
		// translate the arguments here

		res = MMC_disk_read(buff, sector, count);

		// translate the reslut code here

		break;

	case DEV_USB :
		// translate the arguments here

		res = USB_disk_read(buff, sector, count);

		// translate the reslut code here

		break;
	}

	return res;
}

disk_t u;

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res = RES_PARERR;

	switch (pdrv) {
	case DEV_RAM :
		// translate the arguments here

		res = RAM_disk_write(buff, sector, count);

		// translate the reslut code here

		break;

	case DEV_MMC :
		// translate the arguments here

		res = MMC_disk_write(buff, sector, count);

		// translate the reslut code here

		break;

	case DEV_USB :
		// translate the arguments here

		res = USB_disk_write(buff, sector, count);

		// translate the reslut code here

		break;
	}

	return res;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;
	int result;

	switch (pdrv) {
	case DEV_RAM :

		// Process of the command for the RAM drive

		return res;

	case DEV_MMC :

		// Process of the command for the MMC/SD card

		return res;

	case DEV_USB :

		switch (cmd) {
		case CTRL_SYNC:     /* Nothing to do */
			res = RES_OK;
			DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 64 , " CTRL_SYNC");
			break;

		case GET_SECTOR_COUNT:  /* Get number of sectors on the drive */
			//*(LBA_t*)buff = Stat[pdrv].n_sectors;
			*(LBA_t*)buff = USB_disk_ioctl_GET_SECTOR_COUNT();
			res = RES_OK;
			DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 64 , " GET_SECTOR_COUNT");
			break;

		case GET_SECTOR_SIZE: /* Get size of sector for generic read/write  */
			//*(WORD*)buff = Stat[pdrv].sz_sector;
			*(WORD*)buff = USB_disk_ioctl_GET_SECTOR_SIZE();
			res = RES_OK;
			DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 64 , " GET_SECTOR_SIZE");
			break;

		case GET_BLOCK_SIZE:  /* Retrieves erase block size of the flash memory media in unit of sector */
			*(DWORD*)buff = 1;
			res = RES_OK;
			DEBUG_PRINT_(LOG_LEVEL_MAX, "info", 64 , " GET_BLOCK_SIZE");
			break;
		}

		return res;
	}

	return RES_PARERR;
}

