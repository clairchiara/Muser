//
//  msr-composition.cpp
//  Muser
//
//  Copyright (c) 2014 Clair Marchesani. All rights reserved.
//

#include <random>
#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include "msr-composition.h"
#include "successions.h"

typedef unsigned int uint;

msr::composition::composition() {
	_scale.note = NULL;
	_scale.type = '\0';
	tempo = NULL;
	signature.num = NULL;
	signature.den = NULL;
	signature.ticks = NULL;
	signature._32ndtoquarter = NULL;
	firstChannel = std::vector<msr::sound>();
	secondChannel = std::vector<msr::sound>();
	thirdChannel = std::vector<msr::sound>();
}

msr::composition::~composition() {
}

msr::scale msr::composition::getScale() {
	return _scale;
}

long msr::composition::getTempo() {
	return tempo;
}

msr::timesign msr::composition::getSignature() {
	return signature;
}

std::vector<msr::sound> msr::composition::getFirstChannel() {
	return firstChannel;
}

std::vector<msr::sound> msr::composition::getSecondChannel() {
	return secondChannel;
}

std::vector<msr::sound> msr::composition::getThirdChannel() {
	return thirdChannel;
}

void msr::composition::setScale(msr::scale s) {
	_scale = s;
}

void msr::composition::setTempo(long n) {
	tempo = n;
}

void msr::composition::setSignature(msr::timesign s) {
	signature = s;
}

void msr::composition::setFirstChannel(std::vector<msr::sound> channel) {
	firstChannel = channel;
}

void msr::composition::setSecondChannel(std::vector<msr::sound> channel) {
	secondChannel = channel;
}

void msr::composition::setThirdChannel(std::vector<msr::sound> channel) {
	thirdChannel = channel;
}

void msr::composition::compose() {
	
	msr::successions _successions;
	int octave = 0;
	bool scalechange1 = false;
	bool scalechange2 = false;
	int piece_length;
	const std::array<std::string, 12> notenames = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
	std::mt19937 gen;
	uint ms = (uint)std::chrono::duration_cast<std::chrono::milliseconds >(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	
	srandom(ms);
	
	uint seed = (uint)time(nullptr) + (uint)random();
	gen.seed(seed);
	
	std::uniform_int_distribution<> dis0_11(0, 11);
	std::uniform_int_distribution<> disbool(0, 1);
	std::uniform_int_distribution<> dis0_20(0, 20);
	std::uniform_int_distribution<> dis_major(0, (int)_successions.getMajorList().size() - 1);
	std::uniform_int_distribution<> dis_minor(0, (int)_successions.getMinorList().size() - 1);
	std::uniform_int_distribution<> dis0_5(0, 5);
	std::uniform_int_distribution<> dis0_4(0, 4);
	std::uniform_int_distribution<> dis0_120(0, 60);
	
	piece_length = 60 + dis0_120(gen);
	_scale.note = dis0_11(gen) + 60;
	_scale.type = disbool(gen) == 0 ? '+' : '-';
	signature.ticks = dis0_20(gen) + 20;
	signature.den = disbool(gen) == 0 ? 4 : 8;
	signature._32ndtoquarter = signature.den == 4 ? 8 : 12;
	
	
	std::uniform_int_distribution<> dis_sign(2, signature.den + 2);
	
	signature.num = dis_sign(gen);
	std::cout << "The time signature is " << signature.den << "/" << signature.num << "\n";
	std::cout << "The initial scale is " << notenames[_scale.note % 12] << _scale.type << "\n";
	for (int i = 0; i <= piece_length; i++) {
		
		int note = _scale.note + (octave * 12);
		
		if (_scale.type == '+') {
			
			int succession = dis_major(gen);
			
			for (uint j = 0; j < _successions.getMajorList()[succession].size(); j++) {
				
				float note_length = 1;
				
				switch (dis0_5(gen)) {
					case 0:
						note_length = 0.25;
						break;
					case 1:
					case 2:
					case 3:
						note_length = 0.5;
						break;
					case 4:
					case 5:
						note_length = 1;
						break;
				}
				if (j == 0) note_length = 2;
				if (j == _successions.getMajorList()[succession].size() -1) note_length = 2;
				if (i == piece_length && j == _successions.getMajorList()[succession].size() - 1) note_length = 3;
				if (i == piece_length) note_length *= 1.5;
				firstChannel.push_back(msr::sound() = {note + _successions.getMajorList()[succession][j].a, note_length});
				secondChannel.push_back(msr::sound() = {note + _successions.getMajorList()[succession][j].b, note_length});
				thirdChannel.push_back(msr::sound() = {note + _successions.getMajorList()[succession][j].c, note_length});
			}
		}
		else if (_scale.type == '-') {
			int succession = dis_minor(gen);
			for (uint j = 0; j < _successions.getMinorList()[succession].size(); j++) {
				
				float note_length = 1;
				
				switch (dis0_5(gen)) {
					case 0:
						note_length = 0.25;
						break;
					case 1:
					case 2:
					case 3:
						note_length = 0.5;
						break;
					case 4:
					case 5:
						note_length = 1;
						break;
				}
				if (i > piece_length / 3 && i < piece_length * 0.75) note_length *= 2;
				if (j == 0) note_length = 2;
				if (j == _successions.getMinorList()[succession].size() -1) note_length = 2;
				if (i == piece_length && j == _successions.getMinorList()[succession].size() - 1) note_length = 3;
				if (i == piece_length) note_length *= 1.5;
				firstChannel.push_back(msr::sound() = {note + _successions.getMinorList()[succession][j].a, note_length});
				secondChannel.push_back(msr::sound() = {note + _successions.getMinorList()[succession][j].b, note_length});
				thirdChannel.push_back(msr::sound() = {note + _successions.getMinorList()[succession][j].c, note_length});
			}
		}
		if ((dis0_11(gen) + i) > piece_length / 3 && scalechange1 == false) {
			if (_scale.type == '+') _scale = {_scale.note - 3, '-'};
			else if (_scale.type == '-') _scale = {_scale.note + 3, '+'};
			scalechange1 = true;
			std::cout << "The scale changes to " << notenames[_scale.note % 12] << _scale.type << " at "
				<< (int)(((float)i / (float)piece_length) * 100) << "%\n";
		}
		if ((dis0_11(gen) + i) > piece_length * 0.75 && scalechange2 == false) {
			if (_scale.type == '+') _scale = {_scale.note - 3, '-'};
			else if (_scale.type == '-') _scale = {_scale.note + 3, '+'};
			scalechange2 = true;
			std::cout << "The scale changes to " << notenames[_scale.note % 12] << _scale.type << " at "
				<< (int)(((float)i / (float)piece_length) * 100) << "%\n";
		}
		switch (dis0_5(gen)) {
			case 0:
				if (octave > -2) octave--;
				break;
			case 1:
			case 2:
			case 3:
				if (octave == 2) octave--;
				else if (octave == -2) octave++;
				break;
			case 4:
				if (octave < 2) octave++;
				break;
		}
	}
	for (uint i = 0; i < firstChannel.size(); i++) {
		
		int dist = firstChannel[i + 1].note - firstChannel[i].note;
		int startnote = firstChannel[i].note;
		float dur = firstChannel[i].length;
		float nlength = dur / dist >= 0 ? dur / dist : -dur / dist;
		
		if (i < firstChannel.size() / 3) {
			if (dist != 0 && (nlength * dis0_20(gen)) >= 0.75 && dis0_4(gen) == 0 && nlength >= 0.125) {
				firstChannel.erase(firstChannel.begin()+i);
				if (dist >= 0) for (int j = 0; j < dist; j++) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
				else if (dist < 0) for (int j = 0; j > dist; j--) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
			}
		}
		else if (i < firstChannel.size() * 0.75) {
			if (dist != 0 && (nlength * dis0_20(gen)) >= 1.25 && dis0_5(gen) == 0 && nlength >= 0.125) {
				firstChannel.erase(firstChannel.begin()+i);
				if (dist >= 0) for (int j = 0; j < dist; j++) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
				else if (dist < 0) for (int j = 0; j > dist; j--) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
			}
		}
		else {
			if (dist != 0 && (nlength * dis0_20(gen)) >= 0.5 && dis0_4(gen) == 0 && nlength >= 0.125) {
				firstChannel.erase(firstChannel.begin()+i);
				if (dist >= 0) for (int j = 0; j < dist; j++) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
				else if (dist < 0) for (int j = 0; j > dist; j--) firstChannel.insert(firstChannel.begin()+i, sound() = {startnote + j, nlength});
			}
		}
	}
}