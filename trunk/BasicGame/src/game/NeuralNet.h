//------------------------------------------------------------------------
#ifndef NEURALNET_H
#define NEURALNET_H
//------------------------------------------------------------------------
#include <vector>
#include <fstream>
#include <math.h>
#include "utils.h"
#include "Parameters.h"
//-------------------------------------------------------------------
using namespace std;
//-------------------------------------------------------------------
struct Neuron
{
	int m_iNumInputs;
	vector<double> m_kVecWeight;
	Neuron(int iNumInputs);
};
//---------------------------------------------------------------------
struct Layer
{
	int m_iNumNeurons;
	vector<Neuron> m_kVecNeurons;
	Layer(int iNumNeurons, int iNumInputsPerNeuron);
};
//----------------------------------------------------------------------
class NeuralNet
{
private:
	int m_iNumInputs;
	int m_iNumOutputs;
	int m_iNumHiddenLayers;
	int m_iNeuronsPerHiddenLyr;

	vector<Layer>	m_kVecLayers;

public:

	NeuralNet();
	~NeuralNet();

	void CreateNet();
	vector<double> GetWeights();
	int GetNumberOfWeights();
	void PutWeights( vector<double> &kWeights );
	vector<double> Update( vector<double> &kInputs );
	double Sigmoid(double dActivation, double dResponse);

};
//-------------------------------------------------------------------
#endif //NEURALNET_H
//-------------------------------------------------------------------
