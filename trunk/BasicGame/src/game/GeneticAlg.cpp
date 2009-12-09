//-----------------------------------------------------------------------
#include "GeneticAlg.h"
//-----------------------------------------------------------------------
GeneticAlg::GeneticAlg(int iPopsize, double dMutRat, double dCrossRat, int iNumWeights)
:
m_iPopSize(iPopsize),
m_dMutationRate(dMutRat),
m_dCrossoverRate(dCrossRat),
m_iChromoLength(iNumWeights),
m_dTotalFitness(0),
m_iGeneration(0),
m_iFittestGenome(0),
m_dBestFitness(0),
m_dWorstFitness(99999999),
m_dAverageFitness(0)
{
	for (int i=0; i<m_iPopSize; ++i)
	{
		m_kVecPop.push_back(Genome());
		for (int j=0; j < m_iChromoLength; ++j)
		{
			m_kVecPop[i].kVecWeights.push_back(RandomClamped());
		}
	}
}
//-----------------------------------------------------------------------
void GeneticAlg::Mutate(vector<double> &dChromo)
{
	for (unsigned int i=0; i < dChromo.size(); ++i)
	{
		if (RandFloat() < m_dMutationRate)
		{
			dChromo[i] += (RandomClamped() * def_dMaxPerturbation);
		}
	}
}
//-----------------------------------------------------------------------
Genome GeneticAlg::GetChromoRoulette()
{
	double dSlice = (double)(RandFloat() * m_dTotalFitness);

	Genome kTheChosenOne;
	
	double dFitnessSoFar = 0;
	
	for (int i=0; i<m_iPopSize; ++i)
	{
		dFitnessSoFar += m_kVecPop[i].dFitness;
		
		if (dFitnessSoFar >= dSlice)
		{
			kTheChosenOne = m_kVecPop[i];
			break;
		}
		
	}

	return kTheChosenOne;
}
//-----------------------------------------------------------------------
void GeneticAlg::Crossover(const vector<double> &kMum, const vector<double> &kDad, vector<double> &kBaby1, vector<double> &kBaby2)
{
	if ( (RandFloat() > m_dCrossoverRate) || (kMum == kDad)) 
	{
		kBaby1 = kMum;
		kBaby2 = kDad;

		return;
	}

	int iCrossPoint = RandInt(0, m_iChromoLength - 1);

	for (int i=0; i<iCrossPoint; ++i)
	{
		kBaby1.push_back(kMum[i]);
		kBaby2.push_back(kDad[i]);
	}

	for (unsigned int i=iCrossPoint; i<kMum.size(); ++i)
	{
		kBaby1.push_back(kDad[i]);
		kBaby2.push_back(kMum[i]);
	}
}
//-----------------------------------------------------------------------
vector<Genome> GeneticAlg::Epoch(vector<Genome> &kOldPop)
{
	m_kVecPop = kOldPop;

	Reset();

	sort(m_kVecPop.begin(), m_kVecPop.end());

	CalculateBestWorstAvTot();
  
	vector <Genome> kVecNewPop;

	if (!(def_iNumCopiesElite * def_iNumElite % 2))
	{
		GrabNBest(def_iNumElite, def_iNumCopiesElite, kVecNewPop);
	}

	while (kVecNewPop.size() < m_iPopSize)
	{
		Genome kMum = GetChromoRoulette();
		Genome kDad = GetChromoRoulette();

		vector<double> kBaby1, kBaby2;

		Crossover(kMum.kVecWeights, kDad.kVecWeights, kBaby1, kBaby2);

		Mutate(kBaby1);
		Mutate(kBaby2);

		kVecNewPop.push_back(Genome(kBaby1, 0));
		kVecNewPop.push_back(Genome(kBaby2, 0));
	}

	m_kVecPop = kVecNewPop;

	return m_kVecPop;
}
//--------------------------------------------------------------------
void GeneticAlg::GrabNBest(int iNBest, int iNumCopies, vector<Genome> &kVecPop)
{
	while(iNBest--)
	{
		for (int i=0; i < iNumCopies; ++i)
		{
			kVecPop.push_back(m_kVecPop[(m_iPopSize - 1) - iNBest]);
		}
	}
}
//---------------------------------------------------------------------
void GeneticAlg::CalculateBestWorstAvTot()
{
	m_dTotalFitness = 0;
	
	double dHighestSoFar = 0;
	double dLowestSoFar  = 9999999;
	
	for (int i=0; i<m_iPopSize; ++i)
	{
		if (m_kVecPop[i].dFitness > dHighestSoFar)
		{
			dHighestSoFar	 = m_kVecPop[i].dFitness;
			m_iFittestGenome = i;
			m_dBestFitness	 = dHighestSoFar;
		}
		
		if (m_kVecPop[i].dFitness < dLowestSoFar)
		{
			dLowestSoFar = m_kVecPop[i].dFitness;
			m_dWorstFitness = dLowestSoFar;
		}
		
		m_dTotalFitness	+= m_kVecPop[i].dFitness;
	}
	
	m_dAverageFitness = m_dTotalFitness / m_iPopSize;
}
//--------------------------------------------------------------
void GeneticAlg::Reset()
{
	m_dTotalFitness		= 0;
	m_dBestFitness		= 0;
	m_dWorstFitness		= 9999999;
	m_dAverageFitness	= 0;
}
//--------------------------------------------------------------
