#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "../SchoolSystem/SchoolSystem.hpp"

class PlacementSystem {
 private:
  std::vector<RegistedSchool> db_schools;
  std::vector<Student> db_students;
  std::vector<std::pair<Student, RegistedSchool>> placed_students;
  // TODO add attributes for student analytics and review

 public:
  PlacementSystem() : db_schools({}), db_students({}){};
  PlacementSystem(std::vector<RegistedSchool> &schoolList,
                  std::vector<Student> &studentList)
      : db_schools(schoolList), db_students(studentList){};
  std::vector<Student> get_students();
  void add_school(RegistedSchool &);
  void add_student(Student &);
  std::vector<RegistedSchool> get_registed_schools();
  void place_students();
  std::vector<std::pair<Student, RegistedSchool>> get_placed_students() {
    return placed_students;
  }
};
