/*
** FamiTracker - NES/Famicom sound tracker
** Copyright (C) 2005-2014  Jonathan Liss
**
** SnevenTracker is (C) HertzDevil 2016
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful, 
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
** Library General Public License for more details.  To obtain a 
** copy of the GNU Library General Public License, write to the Free 
** Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
**
** Any permitted reproduction of these routines, in whole or in part,
** must bear this legend.
*/

#include "Base.h"

CVGMWriterBase::CVGMWriterBase(CVGMLogger &logger) : m_Logger(logger)
{
	m_Logger.RegisterWriter(*this);
}

CVGMWriterBase::~CVGMWriterBase()
{
	m_Logger.UnregisterWriter(*this);
}

void CVGMWriterBase::WriteReg(uint32_t adr, uint32_t val, uint32_t port) const
{
	m_Logger.InsertByte(Command(adr, val, port));
}
