#include "./SchoolSystem.hpp"

int SchoolSystem::RegistedSchool::get_cut_off() { return cut_off; }

std::vector<std::string> SchoolSystem::RegistedSchool::get_registed_courses() {
  return courses;
}

std::string SchoolSystem::RegistedSchool::get_name() { return name; }

std::string SchoolSystem::Student::get_name() { return name; }

std::unordered_map<std::string, std::string>
SchoolSystem::Student::get_grades() {
  return grades;
}

std::vector<SchoolSystem::RegistedSchool>
SchoolSystem::Student::get_school_choices() {
  return school_choices;
}

void SchoolSystem::Student::display_profile() {
  auto name = get_name();
  auto schools_chosen = get_school_choices();
  auto grades = get_grades();

  std::cout << "Student Name: " << name << '\n';

  std::cout << "Grades: \n";
  for (auto &grade : grades) {
    std::cout << grade.first << "-" << grade.second << "\n";
  }

  std::cout << "Schools picked\n";
  for (auto &school : schools_chosen) {
    std::cout << school.get_name() << "\n";
  }
}