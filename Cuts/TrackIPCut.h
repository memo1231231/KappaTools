#ifndef KTrackIPCut_h
#define KTrackIPCut_h

#include "TMath.h"
#include "BaseCut.h"
#include "DataFormats/interface/KBasic.h"
#include "DataFormats/interface/KTrack.h"

namespace KappaTools
{
	template <typename T>
	class TrackIPCut : public BaseCut
	{
		private:
			KDataVertex * pv;
			T * obj;
			double min, max;
			int type;
		public:
			/*
				mode:
					0 - dxy
					1 - dxy/error(track)
					2 - dxy/sqrt(error(track)**2 + error(vertex)**2)
			*/
			enum Type
			{
				DXY,
				DXY_ERRTRK,
				DXY_ERRTRK_ERRVTX
			};

			TrackIPCut();
			TrackIPCut(T * tmpObj);
			TrackIPCut(int type_);

			void setPV(KDataVertex * tmpObj);
			void setPointer(T * tmpObj);

			void setType(int type_);
			void setMinCut(double min_);
			void setMaxCut(double max_);

			virtual bool getInternalDecision();
			double getDecisionValue();
	};
}

#endif