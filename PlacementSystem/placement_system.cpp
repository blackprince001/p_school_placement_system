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

std::vector<std::pair<Student, RegistedSchool>>
PlacementSystem::get_placed_students() {
  if (db_students.size() > 1 && placed_students.size() <= 1)
    return placed_students;
  return {};
}

std::vector<std::pair<Student, RegistedSchool>>
PlacementSystem::get_rejected_students() {
  if (db_students.size() > 1 && rejected_students.size() <= 1)
    return rejected_students;
  return {};
}

std::vector<Student> PlacementSystem::get_students() { return db_students; }

void PlacementSystem::place_students() {
  for (auto &student : db_students) {
    auto student_school_choices = student.get_school_choices();
    bool placed = false;

    for (auto &student_chosen_registedSchool : student_school_choices) {
      if (student.get_computed_evaluation() <=
          student_chosen_registedSchool.get_cut_off()) {
        placed_students.emplace_back(student, student_chosen_registedSchool);
      } else {
        rejected_students.emplace_back(student, student_chosen_registedSchool);
      }
    }
  }
}

void PlacementSystem::display_placement_results(std::string schoolName) {
  std::cout << "LIST OF STUDENTS WHO HAVE BEEN PLACED IN " << schoolName
            << "\n";
  for (auto &placed_student : placed_students) {
    if (placed_student.second.get_name() == schoolName) {
      std::cout << placed_student.first.get_name() << ":"
                << placed_student.second.get_name() << "\n";
    }
  }
  std::cout << "LIST OF STUDENTS WHO HAVE BEEN REJECTED BY " << schoolName
            << "\n";
  for (auto &rejected_student : rejected_students) {
    if (rejected_student.second.get_name() == schoolName) {
      std::cout << rejected_student.first.get_name() << ":"
                << rejected_student.second.get_name() << "\n";
    }
  }
}