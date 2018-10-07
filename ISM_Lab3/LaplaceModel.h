#pragma once
#include "PRNG.h"


class LaplaceModel : public PRNG
{
private:
	const PRNG* prng;
	const double lambda;
public:
	LaplaceModel(const PRNG* prng, double lambda);
	LaplaceModel(const LaplaceModel* source);
	~LaplaceModel();

	double next() const override;
	void reset() const override;

	LaplaceModel* clone() const override;
};

