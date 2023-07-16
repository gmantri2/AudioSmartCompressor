#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "../includes/fileManagement.hpp"
#include "../includes/audioCompression.hpp"
#include "../includes/readWavFile.hpp"
#include "../config.h.in"

int main(){
    // std::vector<std::pair<double,double> > data = getData("sample-data.txt");
    // AudioCompression ac(data);
    // ac.getUserSpecs();
    // ac.compress(0,20);
    // exportData(ac.getAudio(),"sample-output-data.txt");

    // std::string file_path = SOURCE_DIR;
	// file_path.append("/M1F1-int12WE-AFsp.wav");

    std::string file_path = "sample wav audio files/Fallout.wav";

    int n = file_path.length();
    char p[n + 1];
    strcpy(p, file_path.c_str());

    vector<float> v0 = readWav(p);
    vector<pair<float,float> > v_pairs = convertToPairs(v0);

    // for(int x = 3000000;x<3000500;x++){std::cout << v_pairs[x].first << " " << v_pairs[x].second << std::endl;}
    // std::cout << "\n" << std::endl;

    AudioCompression ac(v_pairs, 0.7, 0.3, 0.5, 0.3, 4410, 0.02);
    ac.compress(v_pairs.size()/2,v_pairs.size()/2+100);
    vector<pair<float,float> > v_pairs_output = ac.getAudio();

    vector<float> v = convertBack(v_pairs_output); //convertBack(v_pairs_output)

    //for(int x = 3000000;x<3000500;x++){std::cout << v_pairs_output[x].first << " " << v_pairs_output[x].second << std::endl;}

    // float toMUl = 1.0;
    // for (size_t i = 0; i < v.size(); i++) {
    //     v[i] *= toMUl;
    // }

    std::string output = "sample wav audio files 2/Fallout_output.wav";
    int x = output.length();
    char p2[x + 1];
    strcpy(p2, output.c_str());
    vectToWav(v, p, p2);

    // int count = 0;
    // for(unsigned x = 0;x<v.size();x++){
    //     if(v[x] == 0){
    //         continue;
    //     }
    //     std::cout << v[x] << std::endl;
    //     if(count > 100){
    //         break;
    //     }
    //     count++;
    // }
    // std::cout << "Count: " << v.size() << std::endl;

    // vector<pair<float,float> > vv = convertToPairs(v);
    // for(unsigned x = vv.size()-100;x < vv.size();x++){
    //     std::cout << vv[x].first << " " << vv[x].second << std::endl;
    // }
    // std::cout << '\n';
    // vector<float> orig = convertBack(vv);
    // for(unsigned x = orig.size()-200;x < orig.size();x++){
    //     std::cout << orig[x] << std::endl;
    // }

    //vectToWav(orig,"/sample wav audio files/test.wav");
}
