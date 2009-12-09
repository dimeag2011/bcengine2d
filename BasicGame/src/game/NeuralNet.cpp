//---------------------------------------------------------------------
#include "NeuralNet.h"
//---------------------------------------------------------------------
Neuron::Neuron(int iNumInputs)
:
m_iNumInputs( iNumInputs + 1 )											
{
	for (int i = 0; i < iNumInputs + 1; ++i)
	{
		m_kVecWeight.push_back(RandomClamped());
	}
}
//-----------------------------------------------------------------------
Layer::Layer(int iNumNeurons, int iNumInputsPerNeuron)
:
m_iNumNeurons(iNumNeurons)
{
	for (int i = 0; i < iNumNeurons; ++i)
		m_kVecNeurons.push_back(Neuron(iNumInputsPerNeuron));
}
//-----------------------------------------------------------------------
NeuralNet::NeuralNet() 
{
	m_iNumInputs = def_iNumInputs;
	m_iNumOutputs = def_iNumOutputs;
	m_iNumHiddenLayers = def_iNumHidden;
	m_iNeuronsPerHiddenLyr = def_iNeuronsPerHiddenLayer;

	CreateNet();
}
//------------------------------------------------------------------------
NeuralNet::~NeuralNet() 
{
	/***/
}
//------------------------------------------------------------------------
void NeuralNet::CreateNet()
{
	if (m_iNumHiddenLayers > 0)
	{
		m_kVecLayers.push_back(Layer(m_iNeuronsPerHiddenLyr, m_iNumInputs));

		for (int i = 0; i < m_iNumHiddenLayers - 1; ++i)
		{
			m_kVecLayers.push_back( Layer( m_iNeuronsPerHiddenLyr, m_iNeuronsPerHiddenLyr ) );
		}

		m_kVecLayers.push_back( Layer( m_iNumOutputs, m_iNeuronsPerHiddenLyr ) );
	}
	else
	{
		m_kVecLayers.push_back(Layer(m_iNumOutputs, m_iNumInputs));
	}
}
//------------------------------------------------------------------------
vector<double> NeuralNet::GetWeights()
{
	vector<double> dWeights;
	
	for (int i = 0; i < m_iNumHiddenLayers + 1; ++i)
	{
		for (int j = 0; j < m_kVecLayers[i].m_iNumNeurons; ++j)
		{
			for (int k = 0; k < m_kVecLayers[i].m_kVecNeurons[j].m_iNumInputs; ++k)
			{
				dWeights.push_back(m_kVecLayers[i].m_kVecNeurons[j].m_kVecWeight[k]);
			}
		}
	}

	return dWeights;
}
//------------------------------------------------------------------------
void NeuralNet::PutWeights(vector<double> &kWeights)
{
	int iWeight = 0;
	
	for (int i = 0; i < m_iNumHiddenLayers + 1; ++i)
	{
		for (int j = 0; j < m_kVecLayers[i].m_iNumNeurons; ++j)
		{
			for (int k = 0; k < m_kVecLayers[i].m_kVecNeurons[j].m_iNumInputs; ++k)
			{
				m_kVecLayers[i].m_kVecNeurons[j].m_kVecWeight[k] = kWeights[iWeight++];
			}
		}
	}
}
//------------------------------------------------------------------------
int NeuralNet::GetNumberOfWeights()
{
	int iWeights = 0;
	
	for (int i = 0; i < m_iNumHiddenLayers + 1; ++i)
	{
		for (int j = 0; j < m_kVecLayers[i].m_iNumNeurons; ++j)
		{
			for (int k = 0; k < m_kVecLayers[i].m_kVecNeurons[j].m_iNumInputs; ++k)
				iWeights++;
		}
	}

	return iWeights;
}
//------------------------------------------------------------------------
vector<double> NeuralNet::Update(vector<double> &kInputs)
{
	vector<double> kOutputs;

	int iWeight = 0;
	
	if (kInputs.size() != m_iNumInputs)
	{
		return kOutputs;
	}
	
	for (int i = 0; i < m_iNumHiddenLayers + 1; ++i)
	{		
		if ( i > 0 )
		{
			kInputs = kOutputs;
		}

		kOutputs.clear();
		
		iWeight = 0;

		for (int j = 0; j < m_kVecLayers[i].m_iNumNeurons; ++j)
		{
			double dNetInput = 0;

			int	iNumInputs = m_kVecLayers[i].m_kVecNeurons[j].m_iNumInputs;
			
			for (int k = 0; k < iNumInputs - 1; ++k)
			{
				dNetInput += m_kVecLayers[i].m_kVecNeurons[j].m_kVecWeight[k] * kInputs[iWeight++];
			}

			dNetInput += m_kVecLayers[i].m_kVecNeurons[j].m_kVecWeight[iNumInputs - 1] * def_dBias;

			kOutputs.push_back(Sigmoid(dNetInput, def_dActivationResponse));

			iWeight = 0;
		}
	}

	return kOutputs;
}
//------------------------------------------------------------------------
double NeuralNet::Sigmoid(double dNetInput, double dResponse)
{
	return ( 1 / ( 1 + exp( -dNetInput / dResponse ) ) );
}
//------------------------------------------------------------------------
