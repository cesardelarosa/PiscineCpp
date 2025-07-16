#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

void    ft_error(const std::string& str, int status)
{
    std::cerr << "Error: " << str << std::endl;
    std::exit(status % 256);
}

std::string replaceLine(std::string line, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return line;
    
    std::string result;
    size_t  pos = 0;
    size_t  lastPos = 0;

    while ((pos = line.find(s1, lastPos)) != std::string::npos)
    {
        result.append(line, lastPos, pos - lastPos);
        result.append(s2);
        lastPos = pos + s1.length();
    }
    result.append(line, lastPos, line.length() - lastPos);

    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
        ft_error("Invalid number of parameters (must be 3)", 1);
    
    const std::string   filename = argv[1];
    const std::string   s1 = argv[2];
    const std::string   s2 = argv[3];

    if (filename.empty())
        ft_error("Invalid first argument (filename is empty)", 1);

    std::ifstream   inputFile(filename.c_str());
    if (!inputFile.is_open())
        ft_error("Could not open input file '" + filename + "'", 3);
    
    const std::string   outputFilename = filename + ".replace";
    std::ofstream   outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
        ft_error("Could not create output file '" + outputFilename + "'", 3);

    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceLine(line, s1, s2);
        if (!inputFile.eof())
            outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}