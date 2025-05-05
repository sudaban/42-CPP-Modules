#include <fstream>
#include <iostream>
#include <string>

int replace(const char *filename, const std::string &to_find, const std::string &to_replace, const std::string &content) {
	std::ofstream outfile((std::string(filename) + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error: Could not create output file.\n";
		return 1;
	}

	for (std::size_t i = 0; i < content.length(); ++i) {
		if (content.find(to_find, i) == i) {
			outfile << to_replace;
			i += to_find.length() - 1;
		} else {
			outfile << content[i];
		}
	}

	outfile.close();
	return 0;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "usage: replace <file> <old_word> <new_word>\n";
		return 1;
	}

	const char *filename = argv[1];
	std::string to_find = argv[2];
	std::string to_replace = argv[3];

	if (to_find.empty()) {
		std::cerr << "Error: <old_word> cannot be empty.\n";
		return 1;
	}

	std::ifstream infile(filename);
	if (!infile) {
		std::cerr << "Error: " << filename << ": no such file or directory\n";
		return 1;
	}

	std::string content;
	char c;
	while (infile.get(c))
		content += c;

	infile.close();
	return replace(filename, to_find, to_replace, content);
}
