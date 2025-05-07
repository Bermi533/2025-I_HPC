#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <unordered_set> 

void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    const std::string FNAME = argv[1];
    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname)
{
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;

    static const std::unordered_set<std::string> prohibidas = {  // Conjunto de palabras a filtrar dadas por chatgpt.
    // Artículos y determinantes                                  // Igual es ineficiente, son muchas palabras
    "a","an","the","this","that","these","those",                 // y aún así hacen falta más.          
    // Pronombres                                            
    "i","me","my","mine","myself",
    "you","your","yours","yourself","yourselves",
    "he","him","his","himself",
    "she","her","hers","herself",
    "it","its","itself",
    "we","us","our","ours","ourselves",
    "they","them","their","theirs","themselves",
    "who","whom","whose","which","what","where","when","why","how",
    // Verbos auxiliares y modales 
    "am","is","are","was","were","be","been","being",
    "have","has","had","do","does","did",
    "will","would","shall","should","can","could","may","might","must",
    "im","ive","ill","id","lets"
    // Preposiciones
    "of","to","in","for","on", "if","with","at","by","from","about","as","into","like",
    "through","after","over","between","against","during","without","before",
    "under","around","among","across","behind","beyond","near","inside","outside",
    // Conjunciones
    "and","but","or","nor","so","yet","for",
    // Adverbios 
    "not","no","only", "any","just","also","even","still","very","too","once","ever","never", "much",
    "here","there","now","then","thus","so","such","more","most","few","many","both","all"
    // Negaciones y contracciones sin apóstrofe
    "dont","didnt","doesnt","cant","couldnt","shouldnt","mustnt","wasnt","werent","wont","wouldnt",
    "havent","hasnt","hadnt","arent","isnt","shant","lets","theres","whos","whats","whens","wheres","whys","hows"
    };

        while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c){ return std::tolower(c); });

    
        word.erase(std::remove_if(word.begin(), word.end(),
                                  [](unsigned char c){return std::ispunct(c) || c > 127; }),
                   word.end());

        // Quita las vacías y lsa que no queremos (prohibidas)
        if (word.empty() || prohibidas.count(word))
            continue;
        word_count[word]++;
    }


    std::vector<std::pair<std::string, int>> freq_vec(word_count.begin(), word_count.end());
    std::sort(freq_vec.begin(), freq_vec.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second;
              });

    std::cout << "\nTop 20 most frequent words:\n";
    int count = 0;
    for (const auto& [w, freq] : freq_vec) {
        std::cout << w << ": " << freq << std::endl;
        if (++count >= 20) break;
    }
}
