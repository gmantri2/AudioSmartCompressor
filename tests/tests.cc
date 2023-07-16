#include "../catch/catch.hpp"
#include "fileManagement.hpp"
#include "audioCompression.hpp"
#include "readWavFile.hpp"
#include "config.h"

#include <iostream>
/*
AudioCompression createBasicCompressor() {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample-data.txt");
	vector<float> vec = readWav(file_path.c_str());
	vector<std::pair<float, float>> c = convertToPairs(vec);
	return AudioCompression(c, 1.0, 0.0, 0.5, 0.5, 6, 0.005);
}

TEST_CASE("File Reading") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample-data.txt");
	std::vector<std::pair<double, double>> vec = getData(file_path);
	REQUIRE(vec[0].first == -0.00348);
	REQUIRE(vec[99].first == 0.00116);
}

TEST_CASE("Read WAV file") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample wav audio files/BabyElephantWalk60.wav");
	vector<float> v = readWav(const_cast<char*>(file_path.c_str()));
    REQUIRE(v.size() != 0);
}

TEST_CASE("File Writing") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample-data.txt");
	std::vector<std::pair<double, double>> empty;
	exportData(empty, "sample-output-data.txt");
	// do something 
	std::vector<std::pair<double, double>> vec = getData(file_path);
	exportData(vec, "sample-output-data.txt");
}

TEST_CASE("File Writing To Wav") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample wav audio files/BabyElephantWalk60.wav");
	vector<float> v = readWav(const_cast<char*>(file_path.c_str()));

	std::cout << "Successfully Read File" << std::endl;
	std::string output_path = SOURCE_DIR;
	output_path.append("/ElephantTest.wav");
	//vectToWav(v, const_cast<char*>(output_path.c_str()));
	std::cout << "Successfully Written File" << std::endl;
	
}

TEST_CASE("AudioCompression Constructor", "[AudioCompression]") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample-data.txt");
	vector<float> vec = readWav(file_path.c_str());
	vector<pair<float, float>> c = convertToPairs(vec);
	AudioCompression au = createBasicCompressor();
	REQUIRE(au.getAudio()[0].first == vec[0]);
	REQUIRE(au.getAudio().size() == c.size());
	vector<pair<float, float>> empty;
	AudioCompression au2 = AudioCompression(empty, 0, 0, 0, 0, 0, 0);
	REQUIRE(!au.getAudio().empty());
}

TEST_CASE("Amplify single point correctly", "[AudioCompression]") {
	std::string file_path = SOURCE_DIR;
	file_path.append("/sample-data.txt");
	vector<float> vec = readWav(file_path.c_str());
	vector<pair<float, float>> c = convertToPairs(vec);
	AudioCompression au = AudioCompression(c, 100, 0, 50, 50, 14, 12);
	REQUIRE(au.amplify(0, 2));
	REQUIRE(au.getAudio()[0].second == c[0].second * 2);
	REQUIRE_FALSE(au.amplify(0, 1000));
	REQUIRE(au.getAudio()[0].second == c[0].second * 2);
	REQUIRE_FALSE(au.amplify(0, -1));
	REQUIRE(au.getAudio()[0].second == c[0].second * 2);
}

TEST_CASE("Detect peaks", "[AudioCompression]") {
	AudioCompression au = createBasicCompressor();
	REQUIRE_FALSE(au.isPeak(96));
	REQUIRE_FALSE(au.isPeak(93));
	REQUIRE(au.isPeak(97));
}

TEST_CASE("Detect silence", "[AudioCompression]") {
	AudioCompression au = createBasicCompressor();
	REQUIRE(au.silence(46));
	REQUIRE_FALSE(au.silence(35));
	REQUIRE_FALSE(au.silence(2));
}

TEST_CASE("Compressed audio stays within bounds", "[AudioCompression]") {
	AudioCompression au = createBasicCompressor();
	bool bound = true;
	for (std::pair<float, float> point : au.getAudio()) {
		if (point.first > 1 || point.second > 1 || point.first < -1 || point.second < -1) {
			bound = false;
		}
	}
	REQUIRE(bound);
}
*/