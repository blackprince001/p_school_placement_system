#pragma once

#include <string>
#include <vector>

namespace SchoolSystem {

class RegistedSchool {
 private:
  std::string name;
  std::vector<std::string> courses;
  int cut_off;

 public:
  RegistedSchool(std::string schoolName,
                 std::vector<std::string> registedCourses, int cut_off_grade)
      : name(schoolName), courses(registedCourses), cut_off(cut_off_grade) {}

  std::vector<std::string> get_registed_courses();
  int get_cut_off();
};

class Student {
 private:
  std::string name;
  std::vector<int> grades;
  std::vector<std::string> school_choices;

 public:
  Student(std::string refName, std::vector<int> refGrades,
          std::vector<std::string> refChoices)
      : name(refName), grades(refGrades), school_choices(refChoices) {}
  std::string get_name();
  std::vector<int> get_grades();
  std::vector<std::string> get_school_choices();
};
}  // namespace SchoolSystem