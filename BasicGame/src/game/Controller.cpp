//-----------------------------------------------------------------------
#include "Controller.h"
//-----------------------------------------------------------------------
Controller::Controller(Importer* pkImporter, Scene* pkScene)
:
m_pkScene(pkScene),
m_iNumTanks(def_iNumTanks), 
m_pkGA(NULL),
m_iTicks(0),
m_iNumMines(def_iNumMines),
m_iGenerations(0)
{
	cout << "Generation number: 0" << endl;

	pkImporter->importResources("../../res/sprite.xml");

	for (int i=0; i<m_iNumTanks; ++i)
	{
		m_kVecTanks.push_back(Tank());
		/*
		pkImporter->createSprite("Tank", &m_kVecTanks[i].m_kTankSprite);
		stringstream kName;
		kName.str("");
		kName << "Tank " << i;
		m_kVecTanks[i].m_kTankSprite.setName(kName.str());
		*/
		pkScene->addEntity(m_kVecTanks[i].m_kTankSprite);
	}

	m_iNumWeightsInNN = m_kVecTanks[0].GetNumberOfWeights();

	m_pkGA = new GeneticAlg(m_iNumTanks, def_dMutationRate, def_dCrossoverRate, m_iNumWeightsInNN);

	m_kVecPopulation = m_pkGA->GetChromos();

	for (int i=0; i<m_iNumTanks; i++)
	{
		m_kVecTanks[i].PutWeights(m_kVecPopulation[i].kVecWeights);
	}

	for (int i=0; i<m_iNumMines; ++i)
	{
		Box* pkBox = new Box();
		pkBox->setPos(RandFloat() * def_WindowWidth, RandFloat() * def_WindowHeight);
		pkBox->setColor(0,0,0);
		pkBox->setDim(def_dMineScale,def_dMineScale);
		pkScene->addEntity(pkBox);
		m_kVecMines.push_back(pkBox);
	}
}
//--------------------------------------------------------------------------------------
Controller::~Controller()
{
	if(m_pkGA)
	{
		delete m_pkGA;
	}

	while (m_kVecMines.size() > 0)
	{
		delete m_kVecMines[m_kVecMines.size() - 1];
		m_kVecMines.pop_back();
	}
}
//-------------------------------------------------------------------
bool Controller::Update()
{
	if (m_iTicks++ < def_iNumTicks)
	{
		for (int i=0; i<m_iNumTanks; ++i)
		{
			if (!m_kVecTanks[i].Update(m_kVecMines))
			{
				return false;
			}
				
			int iGrabHit = m_kVecTanks[i].CheckForMine(m_kVecMines, def_dMineScale);

			if (iGrabHit >= 0)
			{
				m_kVecTanks[i].IncrementFitness();
				m_kVecMines[iGrabHit]->setPos(RandFloat() * def_WindowWidth, RandFloat() * def_WindowHeight);
			}

			m_kVecPopulation[i].dFitness = m_kVecTanks[i].Fitness();
		}
	}
	else
	{
		m_kVecAvFitness.push_back(m_pkGA->AverageFitness());
		m_kVecBestFitness.push_back(m_pkGA->BestFitness());

		++m_iGenerations;
		cout << "Generation number: " << m_iGenerations << endl;
		m_iTicks = 0;
		m_kVecPopulation = m_pkGA->Epoch(m_kVecPopulation);
			
	    for (int i=0; i<m_iNumTanks; ++i)
		{
			m_kVecTanks[i].PutWeights(m_kVecPopulation[i].kVecWeights);
			m_kVecTanks[i].Reset();
		}
	}

	return true;
}
//-------------------------------------------------------------------------
