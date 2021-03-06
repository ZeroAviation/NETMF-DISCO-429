////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Implementation for MX29: Copyright (c) Oberon microsystems, Inc.
//
//  *** MX29 Flash Driver ***
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>

//--//
#ifndef _DRIVERS_BS_MX29_
#define _DRIVERS_BS_MX29_ 1

//--//

typedef UINT16 CHIP_WORD;


struct MX29_Flash_Driver
{

    static BOOL ChipInitialize( void* context );

    static BOOL ChipUnInitialize( void* context );

    static const BlockDeviceInfo* GetDeviceInfo( void* context );

    static BOOL Read( void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff );

    static BOOL Write( void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff, BOOL ReadModifyWrite );

    static BOOL Memset( void* context, ByteAddress Address, UINT8 Data, UINT32 NumBytes );

    static BOOL GetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata);

    static BOOL SetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata);

    static BOOL IsBlockErased( void* context, ByteAddress BlockStart, UINT32 BlockLength );

    static BOOL EraseBlock( void* context, ByteAddress Address );

    static void SetPowerState( void* context, UINT32 State );

    static UINT32 MaxSectorWrite_uSec( void* context );

    static UINT32 MaxBlockErase_uSec( void* context );

private:
    static BOOL WriteX( void* context, ByteAddress StartSector, UINT32 NumSectors,BYTE * pSectorBuff, BOOL ReadModifyWrite, BOOL fIncrementDataPtr );
    static BOOL Action_EraseSector( void* context, volatile CHIP_WORD* SectorStart                      );
    static void Action_WriteWord  ( void* context, volatile CHIP_WORD* Sector, CHIP_WORD Data           );

};

//--//

#endif // _DRIVERS_BS_MX29_

