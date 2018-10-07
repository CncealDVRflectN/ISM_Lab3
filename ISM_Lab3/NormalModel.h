#pragma once
#include "PRNG.h"


class NormalModel : public PRNG
{
private:
	const PRNG* prng;
	const double mean;
	const double variance;

	mutable double cachedValue;
	mutable bool isCached;
public:
	NormalModel(const PRNG* prng, double mean, double variance);
	NormalModel(const NormalModel* normalModel);
	~NormalModel();

	double next() const override;
	void reset() const override;

	NormalModel* clone() const override;
};

