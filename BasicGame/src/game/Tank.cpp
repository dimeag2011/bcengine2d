//-----------------------------------------------------------------------
#include "Tank.h"
//-----------------------------------------------------------------------
Tank::Tank()
:
m_dRotation(RandFloat() * def_dTwoPi),
m_dLeftTrack(0.16),
m_dRightTrack(0.16),
m_dFitness(0),
m_dScale(def_iTankScale),
m_iClosestMine(0)			 
{
	m_kPosition = SVector2D( ( RandFloat() * def_WindowWidth ), ( RandFloat() * def_WindowHeight ) );
	m_kTankSprite = new Box();
	m_kTankSprite->setDim(10,10);
	m_kTankSprite->setColor(255,255,255);
}
//----------------------------------------------------------------------
void Tank::Reset()
{
	m_kPosition = SVector2D( ( RandFloat() * def_WindowWidth ), ( RandFloat() * def_WindowHeight ) );
	m_dFitness = 0;
	m_dRotation = RandFloat() * def_dTwoPi;
}
//-------------------------------------------------------------------
void Tank::WorldTransform()
{
	/*
	setDim(m_dScale, m_dScale);
	setRotation(m_dRotation);
	setPos(m_kPosition.x, m_kPosition.y);
	*/
}
//-----------------------------------------------------------------------
bool Tank::Update(vector<Box*> &kMines)
{
	vector<double> kInputs;	

	SVector2D kClosestMine = GetClosestMine(kMines);
	
	Vec2DNormalize(kClosestMine);
  
	kInputs.push_back(kClosestMine.x);
	kInputs.push_back(kClosestMine.y);

	kInputs.push_back(m_kLookAt.x);
	kInputs.push_back(m_kLookAt.y);

	vector<double> kOutput = m_kBrain.Update(kInputs);

	if (kOutput.size() < def_iNumOutputs) 
	{
		return false;
	}

	m_dLeftTrack = kOutput[0];
	m_dRightTrack = kOutput[1];

	double dRotForce = m_dLeftTrack - m_dRightTrack;

	Clamp(dRotForce, -def_dMaxTurnRate, def_dMaxTurnRate);

	m_dRotation += dRotForce;
	
	m_dSpeed = (m_dLeftTrack + m_dRightTrack);	

	m_kLookAt.x = -sin(m_dRotation);
	m_kLookAt.y = cos(m_dRotation);

	m_kPosition += (m_kLookAt * m_dSpeed);

	if (m_kPosition.x > def_WindowWidth)
		m_kPosition.x = 0;
	if (m_kPosition.x < 0)
		m_kPosition.x = def_WindowWidth;
	if (m_kPosition.y > def_WindowHeight)
		m_kPosition.y = 0;
	if (m_kPosition.y < 0)
		m_kPosition.y = def_WindowHeight;

	m_kTankSprite->setDim(m_dScale, m_dScale);
	m_kTankSprite->setRotation(m_dRotation);
	m_kTankSprite->setPos(m_kPosition.x, m_kPosition.y);

	return true;
}
//-----------------------------------------------------------------------
SVector2D Tank::GetClosestMine(vector<Box*> &kMines)
{
	double dClosestSoFar = 99999;

	SVector2D kClosestObject(0, 0);

	for (int i=0; i<kMines.size(); i++)
	{
		SVector2D kMinePos;
		kMinePos.x = kMines[i]->getPosX();
		kMinePos.y = kMines[i]->getPosY();

		double dLenToObj = Vec2DLength(kMinePos - m_kPosition);

		if (dLenToObj < dClosestSoFar)
		{
			dClosestSoFar	= dLenToObj;
			kClosestObject	= m_kPosition - kMinePos;
			m_iClosestMine = i;
		}
	}

	return kClosestObject;
}
//-----------------------------------------------------------------------
int Tank::CheckForMine(vector<Box*> &kMines, double size)
{
	SVector2D kMinePos;
	kMinePos.x = kMines[m_iClosestMine]->getPosX();
	kMinePos.y = kMines[m_iClosestMine]->getPosY();

	SVector2D kDistToObject = m_kPosition - kMinePos;

	if (Vec2DLength(kDistToObject) < (size + 5))
	{
		return m_iClosestMine;
	}

	return -1;
}
