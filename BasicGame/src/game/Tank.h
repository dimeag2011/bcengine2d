//------------------------------------------------------------------------
#ifndef TANK_H
#define TANK_H
//------------------------------------------------------------------------
#include <vector>
#include <math.h>
#include "NeuralNet.h"
#include "utils.h"
#include "C2DMatrix.h"
#include "SVector2D.h"
#include "Parameters.h"
#include "Engine.h"
//------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------
class Tank
{

private:
	NeuralNet m_kBrain;

	SVector2D m_kPosition;
	SVector2D m_kLookAt;

	double m_dRotation;
	double m_dSpeed;
	double m_dLeftTrack, m_dRightTrack;

	double m_dFitness;

	double m_dScale;
	
	int m_iClosestMine;

	Box* m_kTankSprite;
  

public:
	Tank();
	
	bool Update(vector<Box*> &kMines);
	void WorldTransform();
	SVector2D GetClosestMine(vector<Box*> &kMines);
	int CheckForMine(vector<Box*> &kMines, double dSize);
	void Reset();
  
	SVector2D Position()
	{
		return m_kPosition;
	}

	void IncrementFitness()
	{
		++m_dFitness;
	}

	double Fitness()
	{
		return m_dFitness;
	}
  
	void PutWeights(vector<double> &kW)
	{
		m_kBrain.PutWeights(kW);
	}

	int GetNumberOfWeights()
	{
		return m_kBrain.GetNumberOfWeights();
	}
//------------------------------------------------------------------------
friend class Controller;
//------------------------------------------------------------------------
};
//------------------------------------------------------------------------
#endif //TANK_H
//------------------------------------------------------------------------

	
	