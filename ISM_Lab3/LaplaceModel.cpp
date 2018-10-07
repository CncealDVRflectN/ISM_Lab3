#include "pch.h"
#include "LaplaceModel.h"
#include <algorithm>

LaplaceModel::LaplaceModel(const PRNG* prng, double lambda) : prng((PRNG*)(prng->clone())), lambda(lambda) {}

LaplaceModel::LaplaceModel(const LaplaceModel* source) : prng((PRNG*)(source->prng->clone())), lambda(source->lambda) {}

LaplaceModel::~LaplaceModel()
{
	delete prng;
}


double LaplaceModel::next() const
{
	double randomValue = prng->next();
	return (randomValue < 0.5) ? log(2.0 * randomValue) / lambda : -log(2.0 * (1.0 - randomValue)) / lambda;
}

void LaplaceModel::reset() const
{
	prng->reset();
}


LaplaceModel* LaplaceModel::clone() const
{
	return new LaplaceModel(this);
}
