/**
*  TSBuffer.h
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

#ifndef TSBUFFER_H
#define TSBUFFER_H

#include <vector>
#include "FileReader.h"
#include "TSFileSourceClock.h"

class CTSBuffer
{
public:


	CTSBuffer(CTSFileSourceClock *pClock);
	virtual ~CTSBuffer();

	void SetFileReader(FileReader *pFileReader);

	void Clear();
	long Count();
	HRESULT Require(long nBytes);

	HRESULT DequeFromBuffer(BYTE *pbData, long lDataLength);
	HRESULT ReadFromBuffer(BYTE *pbData, long lDataLength, long lOffset);

protected:
	FileReader *m_pFileReader;
	CTSFileSourceClock *m_pClock;
	std::vector<BYTE *> m_Array;
	long m_lItemOffset;

	long m_lTSBufferItemSize;
};

#endif
