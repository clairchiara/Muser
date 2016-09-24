//
//  main.cpp
//  Muser
//
//  Copyright (c) 2014 Clair Marchesani. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
//#include <MidiFile.cpp>
//#include <FileIO.cpp>
#include "successions.h"
#include "msr-composition.h"

int main(int argc, const char * argv[]) {
	
	msr::composition music;
	
	music.compose();
	
	std::ofstream midifile ("music.mid", std::ios::out | std::ios::binary);
	
	int header[8] = {0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06};
	
	for (uint i = 0; i < 8; i++) midifile.write((char*)&header[i], 1);
	
	int singleTrack[2] = {0x00, 0x01};
	
	for (uint i = 0; i < 2; i++) midifile.write((char*)&singleTrack[i], 1);
	
	int numberOfTracks[2] = {0x00, 0x03};
	
	for (uint i = 0; i < 2; i++) midifile.write((char*)&numberOfTracks[i], 1);
		
	long trackHeader[8] = {0x4D, 0x54, 0x72, 0x6B};
	long bytes = ((music.getFirstChannel().size() + music.getSecondChannel().size() + music.getThirdChannel().size()) * 4);
	
	for (uint i = 4; i < 8; i++) {
		trackHeader[i] = i != 7 ? (bytes - (bytes % (long)pow(2, 8 * (7 - i)))) / 256 : bytes;
		bytes -= trackHeader[i] * (long)pow(2, 8 * (7 - i));
	}
	
	for (uint i = 0; i < 8; i++) midifile.write((char *)&trackHeader[i], 1);
	
	//	for (int i = 0; i < m1.size(); i++) {
	//		midievent[2] = actiontime % (music.getSignature().den * ticks) == 0 ? 90 : 60;
	//		midievent[0] = 0x90;
	//		midievent[1] = m1[i];
	//		outputfile.addEvent(1, actiontime, midievent);
	//		actiontime += r1[i];
	//		midievent[0] = 0x80;
	//		outputfile.addEvent(1, actiontime, midievent);
	//	}

	int timeSignature[5] = {0xFF, music.getSignature().num, music.getSignature().den, music.getSignature().ticks, music.getSignature()._32ndtoquarter};
	
	for (uint i = 0; i < 5; i++) midifile.write((char*)&timeSignature[i], 1);
	
	int noteOn0 = 0x90;
	int noteOn1 = 0x91;
	int noteOn2 = 0x92;
	int noteOff0 = 0x80;
	int noteOff1 = 0x81;
	int noteOff2 = 0x82;
	int actiontime = 0;
	
	for (uint i = 0; i < music.getFirstChannel().size(); i++) {
		midifile.write((char *)&actiontime, 1);
		midifile.write((char *)&noteOn0, 1);
		
		int note = music.getFirstChannel()[i].note;
		int velocity = 60;
		
		midifile.write((char *)&note, 1);
		midifile.write((char *)&velocity, 1);
		actiontime += music.getFirstChannel()[i].length * music.getSignature().ticks;
	} actiontime = 0;
	for (uint i = 0; i < music.getSecondChannel().size(); i++) {
		midifile.write((char *)&actiontime, 1);
		midifile.write((char *)&noteOn1, 1);
		
		int note = music.getSecondChannel()[i].note;
		int velocity = 60;
		
		midifile.write((char *)&note, 1);
		midifile.write((char *)&velocity, 1);
		actiontime += music.getSecondChannel()[i].length * music.getSignature().ticks;
	} actiontime = 0;
	for (uint i = 0; i < music.getThirdChannel().size(); i++) {
		midifile.write((char *)&actiontime, 1);
		midifile.write((char *)&noteOn2, 1);
		
		int note = music.getThirdChannel()[i].note;
		int velocity = 60;
		
		midifile.write((char *)&note, 1);
		midifile.write((char *)&velocity, 1);
		actiontime += music.getThirdChannel()[i].length * music.getSignature().ticks;
	} actiontime = 0;
	
	int endoftrack[3] = {0xFF, 0x2F, 0x00};
	
	for (uint i = 0; i < 3; i++) midifile.write((char *)&endoftrack[i], 1);
	
//	MidiFile outputfile;
//	Array<unsigned char> midievent;
//	int ticks = music.getSignature().ticks;
//	std::vector<int> m1, m2, m3;
//	std::vector<int> r1, r2, r3;
//
//	outputfile.absoluteTime();
//	outputfile.addTrack(3);
//	midievent.setSize(3);
//	outputfile.setTicksPerQuarterNote(ticks);
//	for (int i = 0; i < music.getFirstChannel().size(); i++) m1.push_back(music.getFirstChannel()[i].note);
//	for (int i = 0; i < music.getFirstChannel().size(); i++) r1.push_back(music.getFirstChannel()[i].length * ticks);
//	
//	int actiontime = 0;
//	
//	for (int i = 0; i < m1.size(); i++) {
//		midievent[2] = actiontime % (music.getSignature().den * ticks) == 0 ? 90 : 60;
//		midievent[0] = 0x90;
//		midievent[1] = m1[i];
//		outputfile.addEvent(1, actiontime, midievent);
//		actiontime += r1[i];
//		midievent[0] = 0x80;
//		outputfile.addEvent(1, actiontime, midievent);
//	}
//	for (int i = 0; i < music.getSecondChannel().size(); i++) m2.push_back(music.getSecondChannel()[i].note);
//	for (int i = 0; i < music.getSecondChannel().size(); i++) r2.push_back(music.getSecondChannel()[i].length * ticks);
//	actiontime = 0;
//	for (int i = 0; i < m2.size(); i++) {
//		midievent[2] = actiontime % (music.getSignature().den * ticks) == 0 ? 90 : 60;
//		midievent[0] = 0x90;
//		midievent[1] = m2[i];
//		outputfile.addEvent(2, actiontime, midievent);
//		actiontime += r2[i];
//		midievent[0] = 0x80;
//		outputfile.addEvent(2, actiontime, midievent);
//	}
//	for (int i = 0; i < music.getThirdChannel().size(); i++) m3.push_back(music.getThirdChannel()[i].note);
//	for (int i = 0; i < music.getThirdChannel().size(); i++) r3.push_back(music.getThirdChannel()[i].length * ticks);
//	actiontime = 0;
//	for (int i = 0; i < m3.size(); i++) {
//		midievent[2] = actiontime % (music.getSignature().den * ticks) == 0 ? 90 : 60;
//		midievent[0] = 0x90;
//		midievent[1] = m3[i];
//		outputfile.addEvent(3, actiontime, midievent);
//		actiontime += r3[i];
//		midievent[0] = 0x80;
//		outputfile.addEvent(3, actiontime, midievent);
//	}
//	outputfile.sortTracks();
//	outputfile.write("music.mid");
    return 0;
}