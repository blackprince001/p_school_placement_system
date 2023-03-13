#include "./SchoolSystem.hpp"

int RegistedSchool::get_cut_off() { return cut_off; }

std::vector<std::string> RegistedSchool::get_registed_courses() {
  return courses;
}

std::string RegistedSchool::get_name() { return name; }

std::string Student::get_name() { return name; }

std::unordered_map<std::string, std::string> Student::get_grades() const {
  return grades;
}

std::vector<RegistedSchool> Student::get_school_choices() const {
  return school_choices;
}

int Student::get_computed_evaluation() {
  for (auto &[_, grade] : grades) {
    if (grade == "A") evaluated_grade += 1;
    if (grade == "B") evaluated_grade += 2;
    if (grade == "C") evaluated_grade += 3;
    if (grade == "D") evaluated_grade += 4;
    if (grade == "E") evaluated_grade += 5;
    if (grade == "F") evaluated_grade += 6;
  }
  return evaluated_grade;
}

void Student::display_profile() {
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