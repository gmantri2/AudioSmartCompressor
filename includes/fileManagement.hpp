#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include "config.h"

std::vector<std::pair<double,double> > _getData(const std::string& filename);
void exportData(std::vector<std::pair<double,double> > newdata, const std::string& filename);

// from https://gist.github.com/csukuangfj/c1d1d769606260d436f8674c30662450
bool writeWAV(std::vector<std::pair<double, double> > data, std::string file_path);

struct WAV_HEADER {
	/* Riff Chunk Descriptor */
	uint8_t RIFF[4] = { 'R', 'I', 'F', 'F' }; // RIFF Header Magic header
	uint32_t ChunkSize;                     // RIFF Chunk Size
	uint8_t WAVE[4] = { 'W', 'A', 'V', 'E' }; // WAVE Header
	/* "fmt" sub-chunk */
	uint8_t fmt[4] = { 'f', 'm', 't', ' ' }; // FMT header
	uint32_t Subchunk1Size = 16;           // Size of the fmt chunk
	uint16_t AudioFormat = 1; // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM
							  // Mu-Law, 258=IBM A-Law, 259=ADPCM
	uint16_t NumOfChan = 1;   // Number of channels 1=Mono 2=Sterio
	uint32_t SamplesPerSec = 44100;   // Sampling Frequency in Hz
	uint32_t bytesPerSec = 44100 * 2; // bytes per second
	uint16_t blockAlign = 2;          // 2=16-bit mono, 4=16-bit stereo
	uint16_t bitsPerSample = 16;      // Number of bits per sample
	/* "data" sub-chunk */
	uint8_t Subchunk2ID[4] = { 'd', 'a', 't', 'a' }; // "data"  string
	uint32_t Subchunk2Size;                        // Sampled data length
};