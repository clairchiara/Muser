//
//  successions.h
//  Muser
//
//  Copyright (c) 2014 Clair Marchesani. All rights reserved.
//

#ifndef __Muser__successions__
#define __Muser__successions__

#include <vector>

namespace msr {
	
	struct chord {
		int a;
		int b;
		int c;
		chord();
		chord(int, int, int);
		~chord();
	};
	
	class successions {
	private:
		std::vector<std::vector<msr::chord>> majorList;
		std::vector<std::vector<msr::chord>> minorList;
	public:
		successions();
		~successions();
		std::vector<std::vector<msr::chord>> getMajorList();
		std::vector<std::vector<msr::chord>> getMinorList();
		void setMajorList(std::vector<std::vector<msr::chord>>);
		void setMinorList(std::vector<std::vector<msr::chord>>);
	};
	
}

#endif /* defined(__Muser__successions__) */