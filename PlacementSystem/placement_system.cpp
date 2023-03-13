#include "./placement_system.hpp"

void PlacementSystem::add_school(RegistedSchool &registedSchool) {
  try {
    db_schools.push_back(registedSchool);
  } catch (...) {
    std::cout
        << "Registed School might not exist or has missing information!\n";
  }
}

void PlacementSystem::add_student(Student &registedStudent) {
  try {
    db_students.push_back(registedStudent);
  } catch (...) {
    std::cout
        << "Registed student might not exist or has missing information!\n";
  }
}

std::vector<RegistedSchool> PlacementSystem::get_registed_schools() {
  return db_schools;
}

std::vector<Student> PlacementSystem::get_students() { return db_students; }

void PlacementSystem::place_students() {
  for (auto &student : db_students) {
    auto student_school_choices = student.get_school_choices();
    bool placed = false;
    for (auto &student_choice_registedSchool : student_school_choices) {
      if (student.get_computed_evaluation() <=
          student_choice_registedSchool.get_cut_off()) {
        auto placed_student = std::make_pair(student, student_school_choices);
        // something happens here to add students placed into schools
      }
    }
  }
}