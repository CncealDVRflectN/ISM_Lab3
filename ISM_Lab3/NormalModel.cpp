#include "pch.h"
#include "NormalModel.h"
#include <algorithm>
#include <cmath>


NormalModel::NormalModel(const PRNG* prng, double mean, double variance) : prng((PRNG*)(prng->clone())), mean(mean), variance(variance)
{
	cachedValue = 0.0;
	isCached = false;
}

NormalModel::NormalModel(const NormalModel* source) : prng((PRNG*)(source->prng->clone())), mean(source->mean), variance(source->variance)
{
	this->cachedValue = source->cachedValue;
	this->isCached = source->isCached;
}

NormalModel::~NormalModel()
{
	delete prng;
}


double NormalModel::next() const
{
	double result;

	if(!isCached)
	{
		double mul = sqrt(-2.0 * log(prng->next()));
		double ang = 2.0 * M_PI * prng->next();
		double deviation = sqrt(variance);

		result = mean + deviation * (mul * cos(ang));
		cachedValue = mean + deviation * (mul * sin(ang));
		isCached = true;
	}
	else
	{
		result = cachedValue;
		isCached = false;
	}

	return result;
}

void NormalModel::reset() const
{
	prng->reset();
	isCached = false;
}


NormalModel* NormalModel::clone() const
{
	return new NormalModel(this);
}
