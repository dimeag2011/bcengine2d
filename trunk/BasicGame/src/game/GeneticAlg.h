//------------------------------------------------------------------------
#ifndef GENETICALG_H
#define GENETICALG_H
//------------------------------------------------------------------------
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "utils.h"
#include "Parameters.h"
//------------------------------------------------------------------------
using namespace std;
//-----------------------------------------------------------------------
struct Genome
{
	vector <double>	kVecWeights;
	double          dFitness;

	Genome()
	:
	dFitness(0)
	{
		/***/
	}

	Genome( vector<double> kW, double dF )
	:
	kVecWeights(kW),
	dFitness(dF)
	{
		/***/
	}

	friend bool operator < (const Genome& kLhs, const Genome& kRhs)
	{
		return (kLhs.dFitness < kRhs.dFitness);
	}
};

//-----------------------------------------------------------------------
class GeneticAlg
{
private:
	
	vector<Genome> m_kVecPop;
	int m_iPopSize;
	int m_iChromoLength;
	double m_dTotalFitness;
	double m_dBestFitness;
	double m_dAverageFitness;
	double m_dWorstFitness;
	int	m_iFittestGenome;
	double m_dMutationRate;
	double m_dCrossoverRate;
	int m_iGeneration;

	void Crossover(const vector<double> &kMum, const vector<double> &kDad, vector<double> &kBaby1, vector<double> &kBaby2);
	void Mutate(vector<double> &kChromo);	
	Genome GetChromoRoulette();
	void GrabNBest(int iNBest, int iNumCopies, vector<Genome> &kVecPop);
	void CalculateBestWorstAvTot();
	void Reset();

public:

	GeneticAlg(int iPopsize, double	dMutRat, double dCrossRat, int iNumWeights);
	vector<Genome> Epoch(vector<Genome> &kOldPop);

	vector<Genome> GetChromos()
	{
		return m_kVecPop;
	}

	double AverageFitness()
	{
		return m_dTotalFitness / m_iPopSize;
	}

	double BestFitness()
	{
		return m_dBestFitness;
	}	
};
//-----------------------------------------------------------------------
#endif //GENETICALG_H
//-----------------------------------------------------------------------

