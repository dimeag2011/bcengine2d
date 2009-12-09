//------------------------------------------------------------------------
#ifndef CONTROLLER_H
#define CONTROLLER_H
//------------------------------------------------------------------------
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Tank.h"
#include "GeneticAlg.h"
#include "utils.h"
#include "C2DMatrix.h"
#include "SVector2D.h"
#include "Parameters.h"
#include "Engine.h"
//------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------
class Controller
{

private:
	vector<Genome> m_kVecPopulation;
	vector<Tank> m_kVecTanks;
	vector<Box*> m_kVecMines;

	GeneticAlg* m_pkGA;

	int m_iNumTanks;
	int m_iNumMines;
	int m_iNumWeightsInNN;

	Scene* m_pkScene;

	vector<double> m_kVecAvFitness;
	vector<double> m_kVecBestFitness;
	int m_iTicks;
	int m_iGenerations;

public:
	Controller(Importer* pkImporter, Scene* pkScene);
	~Controller();

	bool Update();
};
//------------------------------------------------------------------------
#endif //CONTROLLER_H
//------------------------------------------------------------------------
	
