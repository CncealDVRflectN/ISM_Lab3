#include "pch.h"
#include "ExponentialModel.h"
#include <algorithm>


ExponentialModel::ExponentialModel(const PRNG* prng, double lambda) : prng((PRNG*)(prng->clone())), lambda(lambda) {}

ExponentialModel::ExponentialModel(const ExponentialModel* source) : prng((PRNG*)(source->prng->clone())), lambda(source->lambda) {}

ExponentialModel::~ExponentialModel()
{
	delete prng;
}


double ExponentialModel::next() const
{
	return -log(prng->next()) / lambda;
}

void ExponentialModel::reset() const
{
	prng->reset();
}


ExponentialModel* ExponentialModel::clone() const
{
	return new ExponentialModel(this);
}
