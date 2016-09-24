//
//  successions.cpp
//  Muser
//
//  Copyright (c) 2014 Clair Marchesani. All rights reserved.
//

#include "successions.h"

using namespace msr;

chord::chord() {
	a = NULL;
	b = NULL;
	c = NULL;
}

chord::chord(int A, int B, int C) {
	a = A;
	b = B;
	c = C;
}

chord::~chord() {
}

successions::successions() {
	
	/* Major scales */
	
	majorList = std::vector<std::vector<chord>>();
	
	// Alternative
	
	std::vector<chord> major1;
	major1.push_back(chord() = {-3, 0, 4});
	major1.push_back(chord() = {-7, -3, 0});
	major1.push_back(chord() = {0, 4, 7});
	major1.push_back(chord() = {-5, -1, 2});
	majorList.push_back(major1);
	
	std::vector<chord> major2;
	major2.push_back(chord() = {-7, -3, 0});
	major2.push_back(chord() = {2, 5, 9});
	major2.push_back(chord() = {-3, 0, 4});
	major2.push_back(chord() = {-8, -5, -1});
	majorList.push_back(major2);
	
	std::vector<chord> major3;
	major3.push_back(chord() = {-8, -5, -1});
	major3.push_back(chord() = {0, 4, 7});
	major3.push_back(chord() = {-5, -1, 2});
	major3.push_back(chord() = {2, 5, 9});
	majorList.push_back(major3);
	
	std::vector<chord> major4;
	major4.push_back(chord() = {2, 5, 9});
	major4.push_back(chord() = {-2, 2, 5});
	major4.push_back(chord() = {-6, 3, 0});
	major4.push_back(chord() = {0, 4, 7});
	majorList.push_back(major4);
	
	// Canon
	
	std::vector<chord> major5;
	major5.push_back(chord() = {0, 4, 7});
	major5.push_back(chord() = {-5, -1, 2});
	major5.push_back(chord() = {-3, 0, 4});
	major5.push_back(chord() = {-8, -5, -1});
	major5.push_back(chord() = {-7, -3, 0});
	major5.push_back(chord() = {0, 4, 7});
	major5.push_back(chord() = {5, 9, 12});
	major5.push_back(chord() = {7, 11, 14});
	majorList.push_back(major5);
	
	std::vector<chord> major6;
	major6.push_back(chord() = {-3, 0, 4});
	major6.push_back(chord() = {4, 7, 11});
	major6.push_back(chord() = {5, 9, 12});
	major6.push_back(chord() = {0, 4, 7});
	major6.push_back(chord() = {2, 5, 9});
	major6.push_back(chord() = {-3, 0, 4});
	major6.push_back(chord() = {2, 5, 9});
	major6.push_back(chord() = {4, 7, 11});
	majorList.push_back(major6);
	
	std::vector<chord> major7;
	major7.push_back(chord() = {-5, -1, 2});
	major7.push_back(chord() = {2, 5, 9});
	major7.push_back(chord() = {4, 7, 11});
	major7.push_back(chord() = {-1, 2, 5});
	major7.push_back(chord() = {0, 5, 7});
	major7.push_back(chord() = {-5, -1, 2});
	major7.push_back(chord() = {0, 4, 7});
	major7.push_back(chord() = {2, 5, 9});
	majorList.push_back(major7);
	
	std::vector<chord> major8;
	major8.push_back(chord() = {-7, -3, 0});
	major8.push_back(chord() = {0, 4, 7});
	major8.push_back(chord() = {2, 5, 9});
	major8.push_back(chord() = {-3, 0, 4});
	major8.push_back(chord() = {-2, 2, 5});
	major8.push_back(chord() = {-7, -3, 0});
	major8.push_back(chord() = {-2, 2, 5});
	major8.push_back(chord() = {0, 4, 7});
	majorList.push_back(major8);
	
	// Cliché
	
	std::vector<chord> major9;
	major9.push_back(chord() = {0, 4, 7});
	major9.push_back(chord() = {-5, -1, 2});
	major9.push_back(chord() = {-3, 0, 4});
	major9.push_back(chord() = {-7, -3, 0});
	majorList.push_back(major9);
	
	std::vector<chord> major10;
	major10.push_back(chord() = {-3, 0, 4});
	major10.push_back(chord() = {-8, 5, 1});
	major10.push_back(chord() = {-7, -3, 0});
	major10.push_back(chord() = {-10, -7, -3});
	majorList.push_back(major10);
	
	std::vector<chord> major11;
	major11.push_back(chord() = {-5, -1, 2});
	major11.push_back(chord() = {2, 5, 9});
	major11.push_back(chord() = {4, -7, 11});
	major11.push_back(chord() = {0, 4, 7});
	majorList.push_back(major11);
	
	std::vector<chord> major12;
	major12.push_back(chord() = {-7, -3, 0});
	major12.push_back(chord() = {0, 4, 7});
	major12.push_back(chord() = {2, 5, 9});
	major12.push_back(chord() = {-2, 2, 5});
	majorList.push_back(major12);
	
	// Cliché 2
	
	std::vector<chord> major13;
	major13.push_back(chord() = {0, 4, 7});
	major13.push_back(chord() = {-3, 0, 4});
	major13.push_back(chord() = {-8, -5, -1});
	major13.push_back(chord() = {-1, 2, 5});
	majorList.push_back(major13);
	
	std::vector<chord> major14;
	major14.push_back(chord() = {-3, 0, 4});
	major14.push_back(chord() = {-7, -3, 0});
	major14.push_back(chord() = {0, 4, 7});
	major14.push_back(chord() = {-5, -1, 2});
	majorList.push_back(major14);
	
	std::vector<chord> major15;
	major15.push_back(chord() = {-5, -1, 2});
	major15.push_back(chord() = {-8, -5, -1});
	major15.push_back(chord() = {-1, 2, 5});
	major15.push_back(chord() = {-6, -3, 0});
	majorList.push_back(major15);
	
	std::vector<chord> major16;
	major16.push_back(chord() = {5, 9, 12});
	major16.push_back(chord() = {2, 5, 9});
	major16.push_back(chord() = {-3, 0, 4});
	major16.push_back(chord() = {-8, -5, -1});
	majorList.push_back(major16);
	
	// Creepy
	
	std::vector<chord> major17;
	major17.push_back(chord() = {0, 4, 7});
	major17.push_back(chord() = {-3, 0, 4});
	major17.push_back(chord() = {-7, -3, 0});
	major17.push_back(chord() = {-5, -1, 2});
	majorList.push_back(major17);
	
	std::vector<chord> major18;
	major18.push_back(chord() = {-3, 0, 4});
	major18.push_back(chord() = {5, 9, 12});
	major18.push_back(chord() = {2, 5, 9});
	major18.push_back(chord() = {4, 7, 11});
	majorList.push_back(major18);
	
	std::vector<chord> major19;
	major19.push_back(chord() = {-5, -1, 2});
	major19.push_back(chord() = {-8, -5, -1});
	major19.push_back(chord() = {0, 4, 7});
	major19.push_back(chord() = {2, 5, 9});
	majorList.push_back(major19);

	std::vector<chord> major20;
	major20.push_back(chord() = {5, 9, 12});
	major20.push_back(chord() = {2, 5, 9});
	major20.push_back(chord() = {-2, 2, 5});
	major20.push_back(chord() = {0, 4, 7});
	majorList.push_back(major20);
	
	// Creepy 2
	
	std::vector<chord> major21;
	major21.push_back(chord() = {0, 4, 7});
	major21.push_back(chord() = {-3, 0, 4});
	major21.push_back(chord() = {2, 5, 9});
	major21.push_back(chord() = {-5, -1, 2});
	majorList.push_back(major21);
	
	std::vector<chord> major22;
	major22.push_back(chord() = {-3, 0, 4});
	major22.push_back(chord() = {-7, -3, 0});
	major22.push_back(chord() = {-1, 2, 5});
	major22.push_back(chord() = {-8, -5, -1});
	majorList.push_back(major22);
	
	std::vector<chord> major23;
	major23.push_back(chord() = {-5, -1, 2});
	major23.push_back(chord() = {-8, -5, -1});
	major23.push_back(chord() = {-3, 0, 4});
	major23.push_back(chord() = {2, 5, 9});
	majorList.push_back(major23);
	
	std::vector<chord> major24;
	major24.push_back(chord() = {5, 9, 12});
	major24.push_back(chord() = {2, 5, 9});
	major24.push_back(chord() = {-5, -1, 2});
	major24.push_back(chord() = {0, 4, 7});
	majorList.push_back(major24);
	
	// Endless
	
	std::vector<chord> major25;
	major25.push_back(chord() = {0, 4, 7});
	major25.push_back(chord() = {-3, 0, 4});
	major25.push_back(chord() = {2, 5, 9});
	major25.push_back(chord() = {-7, -3, 0});
	majorList.push_back(major25);
	
	std::vector<chord> major26;
	major26.push_back(chord() = {-3, 0, 4});
	major26.push_back(chord() = {-7, -3, 0});
	major26.push_back(chord() = {-1, 2, 5});
	major26.push_back(chord() = {2, 5, 9});
	majorList.push_back(major26);
	
	std::vector<chord> major27;
	major27.push_back(chord() = {-5, -1, 2});
	major27.push_back(chord() = {-8, -5, -1});
	major27.push_back(chord() = {-3, 0, 4});
	major27.push_back(chord() = {0, 4, 7});
	majorList.push_back(major27);
	
	std::vector<chord> major28;
	major28.push_back(chord() = {-7, -3, 0});
	major28.push_back(chord() = {2, 5, 9});
	major28.push_back(chord() = {-5, -1, 2});
	major28.push_back(chord() = {-2, 2, 5});
	majorList.push_back(major28);
	
	// Energetic
	
	std::vector<chord> major29;
	major29.push_back(chord() = {0, 4, 7});
	major29.push_back(chord() = {-8, -5, -1});
	major29.push_back(chord() = {-7, -3, 0});
	major29.push_back(chord() = {-3, 0, 4});
	majorList.push_back(major29);
	
	std::vector<chord> major30;
	major30.push_back(chord() = {-3, 0, 4});
	major30.push_back(chord() = {0, 4, 7});
	major30.push_back(chord() = {2, 5, 9});
	major30.push_back(chord() = {5, 9, 12});
	majorList.push_back(major30);
	
	std::vector<chord> major31;
	major31.push_back(chord() = {-5, -1, 2});
	major31.push_back(chord() = {-1, 2, 5});
	major31.push_back(chord() = {0, 4, 7});
	major31.push_back(chord() = {4, 7, 11});
	majorList.push_back(major31);
	
	std::vector<chord> major32;
	major32.push_back(chord() = {-7, -3, 0});
	major32.push_back(chord() = {-3, 0, 4});
	major32.push_back(chord() = {-2, 2, 5});
	major32.push_back(chord() = {2, 5, 9});
	majorList.push_back(major32);
	
	// Grungy
	
	std::vector<chord> major33;
	major33.push_back(chord() = {0, 4, 7});
	major33.push_back(chord() = {-7, -3, 0});
	major33.push_back(chord() = {-8, -5, -1});
	major33.push_back(chord() = {-3, 0, 4});
	majorList.push_back(major33);
	
	std::vector<chord> major34;
	major34.push_back(chord() = {-3, 0, 4});
	major34.push_back(chord() = {2, 5, 9});
	major34.push_back(chord() = {0, 4, 7});
	major34.push_back(chord() = {-7, -3, 0});
	majorList.push_back(major34);
	
	std::vector<chord> major35;
	major35.push_back(chord() = {-5, -1, 2});
	major35.push_back(chord() = {0, 4, 7});
	major35.push_back(chord() = {-1, 2, 5});
	major35.push_back(chord() = {-8, -5, -1});
	majorList.push_back(major35);
	
	std::vector<chord> major36;
	major36.push_back(chord() = {-7, -3, 0});
	major36.push_back(chord() = {-2, 2, 5});
	major36.push_back(chord() = {-3, 0, 4});
	major36.push_back(chord() = {2, 5, 9});
	majorList.push_back(major36);
	
	// Memories
	
	std::vector<chord> major37;
	major37.push_back(chord() = {0, 4, 7});
	major37.push_back(chord() = {-7, -3, 0});
	major37.push_back(chord() = {0, 4, 7});
	major37.push_back(chord() = {-5, -1, 2});
	majorList.push_back(major37);
	
	std::vector<chord> major38;
	major38.push_back(chord() = {-3, 0, 4});
	major38.push_back(chord() = {2, 5, 9});
	major38.push_back(chord() = {-3, 0, 4});
	major38.push_back(chord() = {-8, -5, -1});
	majorList.push_back(major38);
	
	std::vector<chord> major39;
	major39.push_back(chord() = {-5, -2, 2});
	major39.push_back(chord() = {0, 4, 7});
	major39.push_back(chord() = {-5, -2, 2});
	major39.push_back(chord() = {2, 5, 9});
	majorList.push_back(major39);
	
	std::vector<chord> major40;
	major40.push_back(chord() = {-7, -3, 0});
	major40.push_back(chord() = {-2, 2, 5});
	major40.push_back(chord() = {-7, -3, 0});
	major40.push_back(chord() = {0, 4, 7});
	majorList.push_back(major40);
	
	// Rebellious
	
	
	
	/* ~~~~~ Minor scales~~~~~ */
		
	
	// Alternative
	
	std::vector<chord> minor1;
	minor1.push_back(chord() = {-4, 0, 3});
	minor1.push_back(chord() = {-7, -4, 0});
	minor1.push_back(chord() = {0, 3, 7});
	minor1.push_back(chord() = {-5, -2, 2});
	minorList.push_back(minor1);
	
	std::vector<chord> minor2;
	minor2.push_back(chord() = {0, 3, 7});
	minor2.push_back(chord() = {-4, 0, 3});
	minor2.push_back(chord() = {3, 7, 10});
	minor2.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor2);
	
	std::vector<chord> minor3;
	minor3.push_back(chord() = {3, 7, 10});
	minor3.push_back(chord() = {0, 3, 7});
	minor3.push_back(chord() = {-5, -2, 2});
	minor3.push_back(chord() = {2, 5, 8});
	minorList.push_back(minor3);
	
	std::vector<chord> minor4;
	minor4.push_back(chord() = {1, 5, 8});
	minor4.push_back(chord() = {-2, 1, 5});
	minor4.push_back(chord() = {-7, -4, 0});
	minor4.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor4);
	
	// Canon
	
	std::vector<chord> minor5;
	minor5.push_back(chord() = {0, 3, 7});
	minor5.push_back(chord() = {-5, -2, 2});
	minor5.push_back(chord() = {-4, 0, 3});
	minor5.push_back(chord() = {3, 7, 10});
	minor5.push_back(chord() = {5, 8, 12});
	minor5.push_back(chord() = {0, 3, 7});
	minor5.push_back(chord() = {5, 8, 12});
	minor5.push_back(chord() = {-5, -2, 2});
	minorList.push_back(minor5);
	
	std::vector<chord> minor6;
	minor6.push_back(chord() = {-9, -5, -2});
	minor6.push_back(chord() = {-2, 2, 5});
	minor6.push_back(chord() = {0, 3, 7});
	minor6.push_back(chord() = {-5, -2, 2});
	minor6.push_back(chord() = {-4, 0, 3});
	minor6.push_back(chord() = {-9, -5, -2});
	minor6.push_back(chord() = {-4, 0, 3});
	minor6.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor6);
	
	std::vector<chord> minor7;
	minor7.push_back(chord() = {-5, -2, 2});
	minor7.push_back(chord() = {2, 5, 8});
	minor7.push_back(chord() = {3, 7, 10});
	minor7.push_back(chord() = {-2, 2, 5});
	minor7.push_back(chord() = {0, 3, 7});
	minor7.push_back(chord() = {-5, -2, 2});
	minor7.push_back(chord() = {0, 3, 7});
	minor7.push_back(chord() = {2, 5, 8});
	minorList.push_back(minor7);
	
	std::vector<chord> minor8;
	minor8.push_back(chord() = {-7, -4, 0});
	minor8.push_back(chord() = {0, 3, 7});
	minor8.push_back(chord() = {1, 5, 8});
	minor8.push_back(chord() = {-4, 0, 3});
	minor8.push_back(chord() = {-2, 1, 5});
	minor8.push_back(chord() = {-7, -4, 0});
	minor8.push_back(chord() = {-2, 1, 5});
	minor8.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor8);
	
	// Cliché
	
	std::vector<chord> minor9;
	minor9.push_back(chord() = {4, 3, 7});
	minor9.push_back(chord() = {-5, -2, 2});
	minor9.push_back(chord() = {-4, 0, 3});
	minor9.push_back(chord() = {-7, -4, 0});
	minorList.push_back(minor9);
	
	std::vector<chord> minor10;
	minor10.push_back(chord() = {3, 7, 10});
	minor10.push_back(chord() = {-2, 2, 5});
	minor10.push_back(chord() = {0, 3, 7});
	minor10.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor10);

	std::vector<chord> minor11;
	minor11.push_back(chord() = {-5, -2, 2});
	minor11.push_back(chord() = {2, 5, 8});
	minor11.push_back(chord() = {3, 7, 10});
	minor11.push_back(chord() = {4, 3, 7});
	minorList.push_back(minor11);

	std::vector<chord> minor12;
	minor12.push_back(chord() = {5, 8, 12});
	minor12.push_back(chord() = {4, 3, 7});
	minor12.push_back(chord() = {1, 5, 8});
	minor12.push_back(chord() = {-2, 1, 5});
	minorList.push_back(minor12);

	// Cliché 2
	
	std::vector<chord> minor13;
	minor13.push_back(chord() = {0, 3, 7});
	minor13.push_back(chord() = {-4, 0, 3});
	minor13.push_back(chord() = {-9, -5, -2});
	minor13.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor13);
	
	std::vector<chord> minor14;
	minor14.push_back(chord() = {-9, -5, -2});
	minor14.push_back(chord() = {0, 3, 7});
	minor14.push_back(chord() = {-5, -2, 2});
	minor14.push_back(chord() = {2, 5, 8});
	minorList.push_back(minor14);
	
	std::vector<chord> minor15;
	minor15.push_back(chord() = {-5, -2, 2});
	minor15.push_back(chord() = {-9, -5, -2});
	minor15.push_back(chord() = {-2, 2, 5});
	minor15.push_back(chord() = {-7, -4, 0});
	minorList.push_back(minor15);

	std::vector<chord> minor16;
	minor16.push_back(chord() = {-7, -4, 0});
	minor16.push_back(chord() = {1, 5, 8});
	minor16.push_back(chord() = {-4, 0, 3});
	minor16.push_back(chord() = {-9, -5, -2});
	minorList.push_back(minor16);
	
	// Creepy
	
	std::vector<chord> minor17;
	minor17.push_back(chord() = {0, 3, 7});
	minor17.push_back(chord() = {-4, 0, 3});
	minor17.push_back(chord() = {-7, -4, 0});
	minor17.push_back(chord() = {-5, -2, 2});
	minorList.push_back(minor17);
	
	std::vector<chord> minor18;
	minor18.push_back(chord() = {3, 7, 10});
	minor18.push_back(chord() = {0, 3, 7});
	minor18.push_back(chord() = {-4, 0, 3});
	minor18.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor18);

	std::vector<chord> minor19;
	minor19.push_back(chord() = {-5, -2, 2});
	minor19.push_back(chord() = {-9, -5, -2});
	minor19.push_back(chord() = {0, 3, 7});
	minor19.push_back(chord() = {2, 5, 8});
	minorList.push_back(minor19);
	
	std::vector<chord> minor20;
	minor20.push_back(chord() = {5, 8, 12});
	minor20.push_back(chord() = {1, 5, 8});
	minor20.push_back(chord() = {-2, 1, 5});
	minor20.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor20);
	
	// Creepy 2
	
	std::vector<chord> minor21;
	minor21.push_back(chord() = {0, 3, 7});
	minor21.push_back(chord() = {-4, 0, 3});
	minor21.push_back(chord() = {-7, -4, 0});
	minor21.push_back(chord() = {-5, -2, 2});
	minorList.push_back(minor21);

	std::vector<chord> minor22;
	minor22.push_back(chord() = {3, 7, 10});
	minor22.push_back(chord() = {0, 3, 7});
	minor22.push_back(chord() = {2, 5, 8});
	minor22.push_back(chord() = {-2, 2, 5});
	minorList.push_back(minor22);
	
	std::vector<chord> minor23;
	minor23.push_back(chord() = {-5, -2, 2});
	minor23.push_back(chord() = {-9, -5, -2});
	minor23.push_back(chord() = {-4, -1, 2});
	minor23.push_back(chord() = {2, 5, 8});
	minorList.push_back(minor23);
	
	std::vector<chord> minor24;
	minor24.push_back(chord() = {-7, -4, 0});
	minor24.push_back(chord() = {1, 5, 8});
	minor24.push_back(chord() = {-5, -2, 2});
	minor24.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor24);
	
	// Endless
	
	std::vector<chord> minor25;
	minor25.push_back(chord() = {0, 3, 7});
	minor25.push_back(chord() = {-4, 0, 3});
	minor25.push_back(chord() = {2, -5, 8});
	minor25.push_back(chord() = {-7, -4, 0});
	minorList.push_back(minor25);

	std::vector<chord> minor26;
	minor26.push_back(chord() = {3, 7, 10});
	minor26.push_back(chord() = {0, 3, 7});
	minor26.push_back(chord() = {-7, -4, 0});
	minor26.push_back(chord() = {-4, 0, 3});
	minorList.push_back(minor26);
	
	std::vector<chord> minor27;
	minor27.push_back(chord() = {-5, -2, 2});
	minor27.push_back(chord() = {-9, -5, -2});
	minor27.push_back(chord() = {-3, 0, 3});
	minor27.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor27);
	
	std::vector<chord> minor28;
	minor28.push_back(chord() = {-7, -4, 0});
	minor28.push_back(chord() = {1, 5, 8});
	minor28.push_back(chord() = {-5, -2, 2});
	minor28.push_back(chord() = {-2, 1, 5});
	minorList.push_back(minor28);
	
	// Energetic
	
	std::vector<chord> minor29;
	minor29.push_back(chord() = {0, 3, 7});
	minor29.push_back(chord() = {3, 7, 10});
	minor29.push_back(chord() = {-7, -4, 0});
	minor29.push_back(chord() = {-4, 0, 3});
	minorList.push_back(minor29);
	
	std::vector<chord> minor30;
	minor30.push_back(chord() = {3, 7, 10});
	minor30.push_back(chord() = {-5, -2, 2});
	minor30.push_back(chord() = {-4, 0, 3});
	minor30.push_back(chord() = {0, 3, 7});
	minorList.push_back(minor30);
	
	std::vector<chord> minor31;
	minor31.push_back(chord() = {-5, -2, 2});
	minor31.push_back(chord() = {-2, 2, 5});
	minor31.push_back(chord() = {0, 3, 7});
	minor31.push_back(chord() = {3, 7, 10});
	minorList.push_back(minor31);
	
	std::vector<chord> minor32;
	minor32.push_back(chord() = {-7, -4, 0});
	minor32.push_back(chord() = {-4, 0, 3});
	minor32.push_back(chord() = {-2, 1, 5});
	minor32.push_back(chord() = {1, 5, 8});
	minorList.push_back(minor32);
	
	// Grungy
	
	std::vector<chord> minor33;
	minor33.push_back(chord() = {0, 3, 7});
	minor33.push_back(chord() = {-7, -4, 0});
	minor33.push_back(chord() = {-9, -5, -2});
	minor33.push_back(chord() = {-4, 0, 3});
	minorList.push_back(minor33);
	
}

successions::~successions() {
}

std::vector<std::vector<chord>> successions::getMajorList() {
	return majorList;
}

std::vector<std::vector<chord>> successions::getMinorList() {
	return minorList;
}

void successions::setMajorList(std::vector<std::vector<chord>> cl) {
	majorList = cl;
}

void successions::setMinorList(std::vector<std::vector<chord>> cl) {
	minorList = cl;
}