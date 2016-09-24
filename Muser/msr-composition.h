//
//  msr-composition.h
//  Muser
//
//  Copyright (c) 2014 Clair Marchesani. All rights reserved.
//

#ifndef __Muser__msr_composition__
#define __Muser__msr_composition__

#include <array>
#include <vector>

namespace msr {
			
	struct timesign {
		int num;
		int den;
		int ticks;
		int _32ndtoquarter;
	};
	
	struct sound {
		int note;
		float length;
	};
	
	struct scale {
		int note;
		char type;
	};
	
	class composition {
	private:
		msr::scale _scale;
		long tempo;
		msr::timesign signature;
		std::vector<msr::sound> firstChannel;
		std::vector<msr::sound> secondChannel;
		std::vector<msr::sound> thirdChannel;
	public:
		composition();
		~composition();
		msr::scale getScale();
		long getTempo();
		msr::timesign getSignature();
		std::vector<msr::sound> getFirstChannel();
		std::vector<msr::sound> getSecondChannel();
		std::vector<msr::sound> getThirdChannel();
		void setScale(msr::scale);
		void setTempo(long);
		void setSignature(msr::timesign);
		void setFirstChannel(std::vector<msr::sound>);
		void setSecondChannel(std::vector<msr::sound>);
		void setThirdChannel(std::vector<msr::sound>);
		void compose();
	};
	
}

#endif /* defined(__Muser__msr_composition__) */