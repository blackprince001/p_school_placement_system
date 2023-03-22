#include <cstdio>
#include <fstream>

#include "PlacementSystem/placement_system.hpp"
#include "SchoolSystem/SchoolSystem.hpp"

std::vector<Student> template_students;
std::vector<RegistedSchool> template_schools;
std::unordered_map<std::string, std::string> template_grades;

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

int main() {
  // TODO
  // Make a global variable for registed courses for all candidates
  // Make a template generated list of students preferrably in a text file to be
  // read
  std::string path_to_student_database = "../students.txt";

  auto student_records = read_records_from_database(path_to_student_database);

  for (auto student_record : student_records) {
    auto caught = split_by(
        student_record,
        '-');  // separate names from grades by splitting with character
    for (auto item : caught) std::cout << item << "\n";
  }

  return 0;
}