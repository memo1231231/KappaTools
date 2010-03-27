#ifndef KZmumuObjects_h
#define KZmumuObjects_h

#include "DataFormats/interface/KMuon.h"
#include "DataFormats/interface/KBasic.h"
#include "DataFormats/interface/KLorentzVector.h"
#include <stdlib.h>

namespace KappaTools
{
	template <typename JetType>
	class ZmumuObjects
	{
		private:
			void printMuonInformation(KDataMuon * muon);
			KDataMuon * muon1, * muon2;
			JetType * rjet;	// recoil jet
			//MTAPFMET * met;
			//MTATrigger * trigger;
			KDataVertex * primaryvertex;
			void recalcP4();
		public:
			void printInformation();
			RMLV p4;
			RMLV getDiMuP4();
			RMLV getDiMu() { return getDiMuP4(); };
			
			void setMuons(KDataMuon * muon1, KDataMuon * muon2);
			void setRJet(JetType * rjet);
			//void setMET(MTAPFMET * met);
			//void setTrigger(MTATrigger * trigger);
			void setPV(KDataVertex * primaryvertex);
			
			KDataMuon * getMuon1();
			KDataMuon * getMuon2();
			JetType * getRJet();
			KDataVertex * getPV();
			
			//ZmumuObjects() : muon1(0), muon2(0), rjet(0), met(0), trigger(0), primaryvertex(0) {};
			ZmumuObjects() : muon1(0), muon2(0), rjet(0), primaryvertex(0) {};
	};
}

#endif
