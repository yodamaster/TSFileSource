/**
*  StreamInfo.cpp
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

#include "StreamInfo.h"
#include <crtdbg.h>
//#include <streams.h>

StreamInfo::StreamInfo()
{
	Clear();
}

StreamInfo::~StreamInfo()
{
}

void StreamInfo::Clear()
{
	Vid   = false;
	Aud   = false;
	Aud2  = false;
	AC3   = false;
	Pid  = 0;
	ZeroMemory(&media, sizeof(media));
	flags   = 0;
	lcid  = 0;
	group   = 0;
	ZeroMemory(name, 256);
	object	= 0;
	unk   = 0;
}

void StreamInfo::CopyFrom(StreamInfo *StreamInfo)
{
	Vid   = StreamInfo->Vid;
	Aud   = StreamInfo->Aud;
	Aud2  = StreamInfo->Aud2;
	AC3   = StreamInfo->AC3;
	Pid   = StreamInfo->Pid;
	memcpy(&media, &StreamInfo->media, sizeof(media));
	flags   = StreamInfo->flags;
	lcid  = StreamInfo->lcid;
	group   = StreamInfo->group;
	memcpy(name, StreamInfo->name, 256);
	object	= StreamInfo->object;
	unk   = StreamInfo->unk;
}

void StreamInfo::CopyTo(StreamInfo *StreamInfo)
{
}

StreamInfoArray::StreamInfoArray()
{
}

StreamInfoArray::~StreamInfoArray()
{
	Clear();
}

void StreamInfoArray::Clear()
{
	std::vector<StreamInfo *>::iterator it = m_Array.begin();
	for ( ; it != m_Array.end() ; it++ )
	{
		delete *it;
	}
	m_Array.clear();
}

void StreamInfoArray::Add(StreamInfo *newStreamInfo)
{
	m_Array.push_back(newStreamInfo);
}

void StreamInfoArray::RemoveAt(int nPosition)
{
	if ((nPosition >= 0) && (nPosition < m_Array.size()))
	{
		m_Array.erase(m_Array.begin() + nPosition);
	}
}

StreamInfo &StreamInfoArray::operator[](int nPosition)
{
	int size = m_Array.size();
	_ASSERT(nPosition >= 0);
	_ASSERT(nPosition < size);

	return *m_Array.at(nPosition);
}

int StreamInfoArray::Count()
{
	return m_Array.size();
}
