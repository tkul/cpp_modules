#include <iostream>
#include <fstream>
#include <string>

void	replace_in_file(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
		throw std::runtime_error("Could not open input file: " + filename);

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		inFile.close();
		throw std::runtime_error("Could not create output file: " + outFilename);
	}

	std::string line;
	std::string result;
	while (std::getline(inFile, line)) {
		size_t pos = 0;
		result.clear();
		
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			result.append(line.substr(0, pos));
			result.append(s2);
			line = line.substr(pos + s1.length());
			pos = 0;
		}
		result.append(line);
		outFile << result;
		if (!inFile.eof())
			outFile << std::endl;
	}

	inFile.close();
	outFile.close();
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string_to_find> <string_to_replace>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: search string cannot be empty" << std::endl;
		return 1;
	}

	try
	{
		replace_in_file(filename, s1, s2);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}