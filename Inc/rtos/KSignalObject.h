#pragma once

#include "KObject.h"

class KSignalObject : public KObject
{
public:
	KSignalObject(const KObjectType type) : KObject(type)
	{

	}

	virtual bool IsSignalled() const = 0;
};