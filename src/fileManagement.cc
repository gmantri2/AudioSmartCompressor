#include "fileManagement.hpp"

std::vector<std::pair<double,double> > _getData(const std::string& filename){
    std::ifstream ifs(filename);
    std::vector<std::pair<double,double> > data;
    std::string line;
    if (ifs.is_open()) {
        while (std::getline(ifs, line)) {
                std::pair<double, double> nums;
                std::istringstream iss(line);
                std::string temp;

                std::getline(iss, temp, '\t');
                if (temp.compare("[inf]") == 0 || temp.compare("[-inf]") == 0) {
                    temp = "0.0";
                }
                std::string::size_type sz;
                double num1 = std::stod(temp, &sz);
                nums.first = num1;

                std::getline(iss, temp, '\t');
                if (temp.compare("[inf]") == 0 || temp.compare("[-inf]") == 0) {
                    temp = "0.0";
                }
                double num2 = std::stod(temp, &sz);
                nums.second = num2;
                data.push_back(nums);
        }
        return data;
    }
    else {
        throw std::runtime_error("File did not open correctly");
    }
    ifs.close();
}

void exportData(std::vector<std::pair<double,double> > newdata, const std::string& filename){
    std::ofstream ofs(filename);
    for(unsigned x = 0;x<newdata.size();x++){
        std::pair<double,double> point = newdata[x];
        ofs << point.first << '\t';
        ofs << point.second << '\n';
    }
}
/*
bool writeWAV(std::vector<std::pair<double, double> > data, std::string file_path) {
    WAV_HEADER wav;
    wav.ChunkSize = sizeof(WAV_HEADER) - 8;
    wav.Subchunk2Size = sizeof(WAV_HEADER) - 44;

    std::ofstream out(file_path, std::ios::binary);
    if (out.is_open()) {
        out.write(reinterpret_cast<const char*>(&wav), sizeof(wav));

        for (size_t i = 0; i < data.size(); ++i) {
            // TODO: read/write in blocks
            double d = data.at(i).first;
            double d1 = data.at(i).second;
            char arr[sizeof(d)];
            memcpy(arr, &d, sizeof(d));
            //char arr1[sizeof(d1)];
            memcpy(arr, &d1, sizeof(d1));
            out.write(reinterpret_cast<const char*> (&d), sizeof(char*));
            out.write(reinterpret_cast<const char*> (&d1), sizeof(char*));
        }
    }
    else {
        throw std::runtime_error("Output wav file is not opened");
    }

    out.close();

    return 1;
}
*/