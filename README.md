# FatFs
FatFs - Generic FAT Filesystem Module
This is a copy of FatFs, a "generic FAT file system module for small embedded
systems", by ChaN. See http://elm-chan.org/fsw/ff/00index_e.html.

This repository contains extendend functions, uses in some of my projects.

Please submit bug reports to the http://elm-chan.org/fsw/ff/bd/[FatFs User Forum] 
in case of original functions and in case of extendend functions, please report here

# Extended functions

1) Copy files beetween different volumes

functions:
```css
f_copy(	const TCHAR *old_file, const TCHAR *new_file, void *buffer, UINT buff_size); 
// Copy file beetwin partishions in into
```

2) Work with extended partishions

functions:
```css
f_getextended_count(const TCHAR* path, UINT* count); - Get extended partishions count
```
config consts:
```css
#define FF_EXTENDED_PARTISHIONS 9 
// This option avalible to use extended MBR partishions and sets max of avaliable it's quantity
```

global variables:
```css
// Sample drive map: MBR
// Physical drive number 2
// 3 master parts (1, 2, 3) and master 4 contains 7 logic parts (1..7)
PARTITION VolToPart[FF_VOLUMES] = { /* {drive, logic drive, extended} */
	{2, 1, 0},		/* "0:" ==> 1st partition on the phys drive 2 logic drive 1 extended 0(no) */
	{2, 2, 0},		/* "1:" ==> 2nd partition on the phys drive 2 logic drive 2 extended 0(no) */
	{2, 3, 0},		/* "2:" ==> 3rd partition on the phys drive 2 logic drive 3 extended 0(no) */
	{2, 4, 1},		/* "3:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 0(no) */
	{2, 4, 2},		/* "4:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 1 */
	{2, 4, 3},		/* "5:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 2 */
	{2, 4, 4},		/* "6:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 3 */
	{2, 4, 5},		/* "7:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 4 */
	{2, 4, 6},		/* "8:" ==> 4rd partition on the phys drive 2 logic drive 4 extended 5 */
	{2, 4, 7}		/* "9:" ==> 4rd partition on the pd#0 */
};
```
3) Aditional volume creationg congig

functions:
```css
f_fdisk (BYTE pdrv, const LBA_t ptbl[], void* work, BYTE n_sec_track); 
// add aditional argument n_sec_track
```

config consts:
```css
#define FF_FAT_RESERVE_SECTORS	1
/* Reserved sectors for crc for fat12/fat16 */

#define FF_FAT_RESERVE_EQUAL_TABLE 0
/* Reserved sectors for crc for fat12/fat16  equal fat table. Enable 1, disable 0*/

#define N_SEC_TRACK 63
/* Sectors per track for determination of drive CHS. Default 63 */
```




# License

BSD-2-Clause License 
