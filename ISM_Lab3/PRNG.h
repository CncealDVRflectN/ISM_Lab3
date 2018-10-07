#pragma once
#include "Cloneable.h"

class PRNG : public Cloneable
{
public:
	virtual double next() const = 0;
	virtual void reset() const = 0;
};

