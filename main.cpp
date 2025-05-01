#include <iostream>
#include <string>
#include <vector>

// разбивает строку "s" по пробелам на вектор слов
static std::vector<std::string> splitWords(const std::string& s) {
    std::vector<std::string> words;
    size_t start = 0;
    while (start < s.size()) {
        size_t pos = s.find(' ', start);
        if (pos == std::string::npos) {
            words.push_back(s.substr(start));
            break;
        }
        words.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return words;
}

int main() {
    // чтение строки
    std::string s;
    std::getline(std::cin, s);

    // разобьем на слова
    auto words = splitWords(s);
    
    return 0;
}