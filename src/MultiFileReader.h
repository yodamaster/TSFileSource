/**
*  MultiFileReader.h
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
*  nate can be reached on the forums at
*    http://forums.dvbowners.com/
*/

#ifndef MULTIFILEREADER
#define MULTIFILEREADER

#include "FileReader.h"
#include <vector>

class MultiFileReaderFile
{
public:
	LPWSTR filename;
	__int64 startPosition;
	__int64 length;
	long filePositionId;
};

class MultiFileReader : FileReader
{
public:

	MultiFileReader();
	virtual ~MultiFileReader();

	virtual FileReader* CreateFileReader();

	virtual HRESULT GetFileName(LPOLESTR *lpszFileName);
	virtual HRESULT SetFileName(LPCOLESTR pszFileName);
	virtual HRESULT OpenFile();
	virtual HRESULT CloseFile();
	virtual HRESULT Read(PBYTE pbData, ULONG lDataLength, ULONG *dwReadBytes);
	virtual HRESULT Read(PBYTE pbData, ULONG lDataLength, ULONG *dwReadBytes, __int64 llDistanceToMove, DWORD dwMoveMethod);
	virtual HRESULT get_ReadOnly(WORD *ReadOnly);
	//virtual HRESULT get_DelayMode(WORD *DelayMode);
	//virtual HRESULT set_DelayMode(WORD DelayMode);

	//TODO: GetFileSize should go since get_FileSize should do the same thing.
	virtual HRESULT GetFileSize(__int64 *pStartPosition, __int64 *pEndPosition);

	virtual BOOL IsFileInvalid();

	virtual DWORD SetFilePointer(__int64 llDistanceToMove, DWORD dwMoveMethod);
	virtual __int64 GetFilePointer();

protected:
	HRESULT RefreshTSBufferFile();
	HRESULT GetFileLength(LPWSTR pFilename, __int64 &length);

	FileReader m_TSBufferFile;
	__int64 m_startPosition;
	__int64 m_endPosition;
	__int64 m_currentPosition;
	long m_filesAdded;
	long m_filesRemoved;

	std::vector<MultiFileReaderFile *> m_tsFiles;

	FileReader m_TSFile;
	long m_TSFileId;

};

#endif