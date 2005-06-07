/**
*  SettingsStore.ccp
*  Copyright (C) 2004-2005 bear
*  Copyright (C) 2003  Shaun Faulds
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
*  bear can be reached on the forums at
*    http://forums.dvbowners.com/
*/


#include "SettingsStore.h"

CSettingsStore::CSettingsStore(void)
{
	lastUsed = time(NULL);
}

CSettingsStore::~CSettingsStore(void)
{

}

void CSettingsStore::setName(std::string newName)
{
	int index = newName.find("\\");

	while(index > 0)
	{
		newName.replace(index, 1, "/");
		index = newName.find("\\");
	}

	name = newName;
}

std::string CSettingsStore::getName()
{
	return name;
}

BOOL CSettingsStore::getAutoModeReg()
{
	return autoMode;
}

//*********************************************************************************************
//NP Control Additions

BOOL CSettingsStore::getNPControlReg()
{
	return nPControl;
}

//NP Slave Additions

BOOL CSettingsStore::getNPSlaveReg()
{
	return nPSlave;
}
//*********************************************************************************************

BOOL CSettingsStore::getMP2ModeReg()
{
	return mp2Mode;
}

BOOL CSettingsStore::getAC3ModeReg()
{
	return ac3Mode;
}

BOOL CSettingsStore::getCreateTSPinOnDemuxReg()
{
	return tsPinMode;
}

BOOL CSettingsStore::getDelayModeReg()
{
	return delayMode;
}

BOOL CSettingsStore::getRateControlModeReg()
{
	return rateMode;
}

BOOL CSettingsStore::getAudio2ModeReg()
{
	return audio2Mode;
}

int CSettingsStore::getProgramSIDReg()
{
	return programSID;
}

void CSettingsStore::setAutoModeReg(BOOL bAuto)
{
	autoMode = bAuto;
	return;
}

//*********************************************************************************************
//NP Control Additions

void CSettingsStore::setNPControlReg(BOOL bNPControl)
{
	nPControl = bNPControl;
	return;
}

//NP Slave Additions
void CSettingsStore::setNPSlaveReg(BOOL bNPSlave)
{
	nPSlave = bNPSlave;
	return;
}

//*********************************************************************************************

void CSettingsStore::setMP2ModeReg(BOOL bMP2)
{
	mp2Mode = bMP2;
	return;
}

void CSettingsStore::setAC3ModeReg(BOOL bAC3)
{
	ac3Mode = bAC3;
	return;
}

void CSettingsStore::setCreateTSPinOnDemuxReg(BOOL bTSPin)
{
	tsPinMode = bTSPin;
	return;
}

void CSettingsStore::setDelayModeReg(BOOL bDelay)
{
	delayMode = bDelay;
	return;
}

void CSettingsStore::setRateControlModeReg(BOOL bRate)
{
	rateMode = bRate;
	return;
}

void CSettingsStore::setAudio2ModeReg(BOOL bAudio2)
{
	audio2Mode = bAudio2;
	return;
}

void CSettingsStore::setProgramSIDReg(int bSID)
{
	programSID = bSID;
	return;
}