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

// меняет в векторе "words" первое слово с последним, второе — с предпоследним и т.д.
static void swapWords(std::vector<std::string>& words) {
    size_t n = words.size();
    for (size_t i = 0; i < n/2; ++i) {
        std::string tmp = words[i];
        words[i] = words[n - 1 - i];
        words[n - 1 - i] = tmp;
    }
}

// собирает слова обратно в одну строку, разделяя их пробелом
static std::string joinWords(const std::vector<std::string>& words) {
    std::string res;
    for (size_t i = 0; i < words.size(); ++i) {
        res += words[i];
        if (i + 1 < words.size())
        res += ' ';
    }
    return res;
}

int main() {
    // ввод текста
    std::cout << "Введите сообщение (на английском, слова разделены пробелами, в конце — точка):\n";

    // чтение строки
    std::string s;
    std::getline(std::cin, s);

    // разобьем на слова
    auto words = splitWords(s);

    // поменяем пары
    swapWords(words);

    // собираем обратно
    std::string result = joinWords(words);

    // выводим результат
    std::cout << result << std::endl;

    return 0;
}