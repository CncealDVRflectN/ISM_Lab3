#pragma once
#include "PRNG.h"


class ExponentialModel : public PRNG
{
private:
	const PRNG* prng;
	const double lambda;
public:
	ExponentialModel(const PRNG* prng, double lambda);
	ExponentialModel(const ExponentialModel* source);
	~ExponentialModel();

	double next() const override;
	void reset() const override;

	ExponentialModel* clone() const override;
};

