/**
*  PidParser.h
*  Copyright (C) 2003      bisswanger
*  Copyright (C) 2004-2005 bear
*  Copyright (C) 2005      nate
*
*  This file is part of TSFileSource, a directshow push source filter that
*  provides an MPEG transport stream output.
*
*  TSFileSource is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  TSFileSource is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with TSFileSource; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*  bisswanger can be reached at WinSTB@hotmail.com
*    Homepage: http://www.winstb.de
*
*  bear and nate can be reached on the forums at
*    http://forums.dvbowners.com/
*/

#ifndef PIDPARSER_H
#define PIDPARSER_H

#include "PidInfo.h"
#include "FileReader.h"

class PidParser
{
public:

PidParser(FileReader *pFileReader);

	virtual ~PidParser();

//***********************************************************************************************
//Refresh additions

	HRESULT ParseFromFile(__int64 fileStartPointer);

//Removed	HRESULT ParseFromFile();

//***********************************************************************************************

	HRESULT RefreshPids();
//***********************************************************************************************
//Refresh additions

	HRESULT RefreshDuration(BOOL bStoreInArray, FileReader *pFileReader);

//Removed	HRESULT RefreshDuration(BOOL bStoreInArray = TRUE);

//***********************************************************************************************

//***********************************************************************************************
//NID Additions

	void get_ChannelNumber(BYTE *pointer);
	void get_NetworkName(BYTE *pointer);

//ONID Additions

	void get_ONetworkName(BYTE *pointer);
	void get_ChannelName(BYTE *pointer);

//Descriptor Fix

	HRESULT get_EPGFromFile();
	void get_ShortNextDescr(BYTE *pointer);
	void get_ExtendedNextDescr(BYTE *pointer);

//***********************************************************************************************

	void get_ShortDescr(BYTE *pointer);
	void get_ExtendedDescr(BYTE *pointer);
	void get_CurrentTSArray(ULONG *pPidArray);

	WORD get_ProgramNumber();
	void set_ProgramNumber(WORD programNumber);

	PidInfo pids;
	PidInfoArray pidArray;	//Currently selected pids

	static HRESULT FindSyncByte(PBYTE pbData, ULONG ulDataLength, ULONG* a, int step);

	static HRESULT FindFirstPCR(PBYTE pData, ULONG ulDataLength, PidInfo *pPids, REFERENCE_TIME* pcrtime, ULONG* pulPos);
	static HRESULT FindLastPCR(PBYTE pData, ULONG ulDataLength, PidInfo *pPids, REFERENCE_TIME* pcrtime, ULONG* pulPos);
	static HRESULT FindNextPCR(PBYTE pData, ULONG ulDataLength, PidInfo *pPids, REFERENCE_TIME* pcrtime, ULONG* pulPos, int step);

//***********************************************************************************************
//NID Additions

	BOOL m_ATSCFlag;
	int m_NetworkID;
	unsigned char m_NetworkName[128];

//ONID Additions

	int m_ONetworkID;

//TSID Additions

	int m_TStreamID;

//Program Registry Additions

	int m_ProgramSID;

	void set_SIDPid(BOOL bProgramSID);
	HRESULT set_ProgramSID();

//***********************************************************************************************


protected:
	static HRESULT CheckForPCR(PBYTE pData, ULONG ulDataLength, PidInfo *pPids, int pos, REFERENCE_TIME* pcrtime);

protected:
	HRESULT ParsePAT(PBYTE pData, ULONG ulDataLength, long pos);
	HRESULT ParsePMT(PBYTE pData, ULONG ulDataLength, long pos);
	BOOL CheckEsDescriptorForAC3(PBYTE pData, ULONG ulDataLength, int pos, int lastpos);
	BOOL CheckEsDescriptorForTeletext(PBYTE pData, ULONG ulDataLength, int pos, int lastpos);

	HRESULT IsValidPMT(PBYTE pData, ULONG ulDataLength);

	REFERENCE_TIME GetPCRFromFile(int step);

	HRESULT ACheckVAPids(PBYTE pData, ULONG ulDataLength);

	HRESULT CheckEPGFromFile();
//***********************************************************************************************
//Descriptor Fix

	bool CheckForEPG(PBYTE pData, int pos, bool *extpacket, int *sectlen, int *sidcount, int *event);

//Removed	bool CheckForEPG(PBYTE pData, ULONG ulDataLength, int pos);

//***********************************************************************************************

//***********************************************************************************************
//NID Additions

	bool CheckForNID(PBYTE pData, int pos, bool *extPacket, int *sectlen);
	HRESULT CheckNIDInFile(FileReader *pFileReader);

//ONID Additions

	bool CheckForONID(PBYTE pData, int pos, bool *extpacket, int *sectlen);
	HRESULT CheckONIDInFile(FileReader *pFileReader);

//***********************************************************************************************

	HRESULT ParseEISection (ULONG ulDataLength);
	HRESULT ParseShortEvent(int start, ULONG ulDataLength);
	HRESULT ParseExtendedEvent(int start, ULONG ulDataLength);

//***********************************************************************************************
//Refresh Additions

	REFERENCE_TIME GetFileDuration(PidInfo *pPids, FileReader *pFileReader);
	HRESULT GetPCRduration(
		PBYTE pData,
		long lDataLength,
		PidInfo *pPids,
		__int64 filelength,
		__int64* pStartFilePos,
		__int64* pEndFilePos,
		FileReader *pFileReader);

//Removed	REFERENCE_TIME GetFileDuration(PidInfo *pPids);
//Removed	HRESULT GetPCRduration(PBYTE pData, long lDataLength, PidInfo *pPids, __int64 filelength, __int64* pStartFilePos, __int64* pEndFilePos);

//FileWriter additions

void  AddBitRateForAverage(__int64 bitratesample);

//***********************************************************************************************


	void AddPidArray();
	void SetPidArray(int n);
	void AddTsPid(PidInfo *pidInfo, WORD pid);

protected:
	FileReader *m_pFileReader;

	int		m_buflen;
	//PBYTE	m_pData;
//***********************************************************************************************
//Descriptor Fix

	BYTE	m_pDummy[0x4000];

//removed	BYTE	m_pDummy[1000];

//***********************************************************************************************
//Descriptor Fix
	BYTE	m_shortdescr[128];
	BYTE	m_extenddescr[600];

	__int64	filepos;
	WORD	m_pgmnumb;

	__int64 m_fileLenOffset;
	__int64	m_fileEndOffset;
	__int64	m_fileStartOffset;

//***********************************************************************************************
//Refreash pids additions

	__int64 m_FileStartPointer;

//***********************************************************************************************

};

#endif
