#include "./placement_system.hpp"

/**
 * It adds a school to the database
 * 
 * @param registedSchool The school to be added to the database.
 */
void PlacementSystem::add_school(RegistedSchool &registedSchool) {
    try {
        db_schools.push_back(registedSchool);
    } catch (...) {
        std::cout
            << "Registed School might not exist or has missing information!\n";
    }
}

/**
 * It adds a student to the database
 * 
 * @param registedStudent The student to be added to the database.
 */
void PlacementSystem::add_student(Student &registedStudent) {
    try {
        db_students.push_back(registedStudent);
    } catch (...) {
        std::cout
            << "Registed student might not exist or has missing information!\n";
    }
}

/**
 * It returns the vector of all the schools that are registered in the system.
 * 
 * @return A vector of RegistedSchool objects.
 */
std::vector<RegistedSchool> PlacementSystem::get_registed_schools() {
    return db_schools;
}

/**
 * It returns the placed students.
 * 
 * @return A vector of pairs of Student and RegistedSchool objects.
 */
std::vector<std::pair<Student, RegistedSchool>>
PlacementSystem::get_placed_students() {
    if (db_students.size() > 1 && placed_students.size() <= 1)
        return placed_students;
    return {};
}

/**
 * It returns the rejected students.
 * 
 * @return A vector of pairs of Student and RegistedSchool.
 */
std::vector<std::pair<Student, RegistedSchool>>
PlacementSystem::get_rejected_students() {
    if (db_students.size() > 1 && rejected_students.size() <= 1)
        return rejected_students;
    return {};
}

/**
 * It returns the vector of students.
 * 
 * @return A vector of Student objects.
 */
std::vector<Student> PlacementSystem::get_students() { return db_students; }

/**
 * > The function iterates through the list of students and checks if the student's computed evaluation
 * is less than or equal to the school's cut off. If it is, the student is placed in the school, else
 * the student is rejected
 */
void PlacementSystem::place_students() {
    for (auto &student : db_students) {
        auto student_school_choices = student.get_school_choices();
        bool placed = false;

        for (auto &student_chosen_registedSchool : student_school_choices) {
            if (student.get_computed_evaluation() <=
                student_chosen_registedSchool.get_cut_off()) {
                placed_students.emplace_back(student,
                                             student_chosen_registedSchool);
            } else {
                rejected_students.emplace_back(student,
                                               student_chosen_registedSchool);
            }
        }
    }
}

/**
 * It displays the list of students who have been placed in a particular school and the list of
 * students who have been rejected by a particular school
 * 
 * @param schoolName The name of the school whose placement results are to be displayed.
 */

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