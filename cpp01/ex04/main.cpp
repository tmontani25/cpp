#include <iostream>
#include <fstream>
#include <sstream>

std::string replaceAll(const std::string& input, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found;

    if (s1.empty())
        return input; // éviter boucle infinie

    while ((found = input.find(s1, pos)) != std::string::npos) {
        result.append(input.substr(pos, found - pos));  // ajouter le contenu avant s1
        result.append(s2);  // remplacer s1 par s2
        pos = found + s1.length();  // avancer le curseur
    }

    result.append(input.substr(pos)); // ajouter la fin restante
    return result;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    // Lire le contenu du fichier
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: Cannot open file '" << filename << "' for reading." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string content = buffer.str();
    infile.close();

    // Remplacement
    std::string replaced = replaceAll(content, s1, s2);

    // Écriture dans le nouveau fichier
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error: Cannot open file '" << filename << ".replace' for writing." << std::endl;
        return 1;
    }

    outfile << replaced;
    outfile.close();

    return 0;
}