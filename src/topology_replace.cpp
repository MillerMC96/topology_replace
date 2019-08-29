#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cout << "Usage: ./topology_replace input.top output.top" << std::endl;

        return -1;
    }

    std::ofstream top_output;
    std::ifstream top_input;
    std::string line;
    std::string nr, type, resnr, residue, atom, cgnr, charge, mass;

    top_input.open(argv[1]);
    top_output.open(argv[2]);

    while (std::getline(top_input, line)) {
        std::istringstream iss(line);
        if (line[0] == ';' || line[0] == '[') {
            top_output << line << std::endl;
        } else {
            if (!(iss >> nr >> type >> resnr >> residue >> atom >> cgnr >> charge >> mass)) {
                top_output << line << std::endl;
            } else {
                top_output << nr << ' ' << type << ' ' << resnr << ' ' <<
                residue << ' ' << atom << ' ' << cgnr << ' ' << '0' << ' ' 
                << '0' << std::endl;
            }
        }
    }

    top_input.close();
    top_output.close();
}
