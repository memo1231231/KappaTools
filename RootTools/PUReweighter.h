#ifndef PUREWEIGHTER_H
#define PUREWEIGHTER_H

#define WITH_KAPPA

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <assert.h>

#include "TFile.h"
#include "TH1F.h"


#ifdef WITH_KAPPA
#include <Kappa/DataFormats/interface/KMetadata.h>
#endif

class PUReweighter
{
private:
	void initTruthMatrix(std::vector<std::string> inputFilesData, std::vector<std::string> inputFilesMC);
	void initApproxMatrix(std::vector<std::string> inputFilesData, float scaleFactor = 1.);
	
	double weightsFall11[50];
    double weights3D[50][50][50];

	TH1F *puDistrData;
	TH1F *puDistrMC;	
public:
	PUReweighter(std::vector<std::string> inputFilesData, std::vector<std::string> inputFilesMC, float scaleFactor = 1.);

#ifdef WITH_KAPPA
	float getWeight(KGenEventMetadata * metadata);
	float getWeightTruth(KGenEventMetadata * metadata);
	float getWeightApprox(KGenEventMetadata * metadata);
#endif

	float getWeightTruth(float mean);
	float getWeightApprox(unsigned int bxM1, unsigned int bx0, unsigned int bxP1);
#
};
#endif