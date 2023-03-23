#include <fstream>
#include <iostream>
#include <vector>

namespace util {
/**
 * It reads a file and returns a vector of strings
 *
 * @param path The path to the file to read from.
 *
 * @return A vector of strings.
 */
std::vector<std::string> read_records_from_database(std::string &path) {
    std::ifstream file(path);
    std::vector<std::string> parsed_records;

    if (!file.is_open()) {
        return {};  // return an empty vector instead
    }
    std::string line;
    while (std::getline(file, line)) {
        parsed_records.push_back(line);
    }
    file.close();
    return parsed_records;
}

/**
 * It splits a string by a character
 *
 * @param text The text to split
 * @param ch The character to split by
 *
 * @return A vector of strings
 */
std::vector<std::string> split_by(std::string &text, char ch) {
    std::vector<std::string> texts;
    std::string buf;
    for (auto s : text) {
        if (s == ch) {
            texts.push_back(buf);
            buf = "";
            continue;
        }
        buf += s;
    }
    if (buf.length() > 0) texts.push_back(buf);
    return texts;
}
}  // namespace util
