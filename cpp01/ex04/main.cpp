#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>\n";
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream infile(filename.c_str());
    std::ofstream outfile((filename + ".replace").c_str());
    std::string line;

    if (!infile)
    {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    if (!outfile)
    {
        std::cerr << "Error: Cannot create output file\n";
        return 1;
    }
    
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << "\n";
    }
    return 0;
}
