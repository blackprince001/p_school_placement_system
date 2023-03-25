#include "./placement_system.hpp"

/**
 * It adds a school to the database
 *
 * @param registedSchool The school to be added to the database.
 */
void PlacementSystem::add_school(RegistedSchool &registedSchool) {
    try {
        _db_schools.push_back(registedSchool);
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
        _db_students.push_back(registedStudent);
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
    return _db_schools;
}

/**
 * It returns the placed students.
 *
 * @return A vector of pairs of Student and RegistedSchool objects.
 */
std::vector<std::tuple<Student, RegistedSchool, Programme>>
PlacementSystem::get_placed_students() {
    if (_db_students.size() > 1 && _placed_students.size() <= 1)
        return _placed_students;
    return {};
}

/**
 * It returns the rejected students.
 *
 * @return A vector of pairs of Student and RegistedSchool.
 */
std::vector<std::tuple<Student, RegistedSchool, Programme>>
PlacementSystem::get_rejected_students() {
    if (_db_students.size() > 1 && _rejected_students.size() <= 1)
        return _rejected_students;
    return {};
}

/**
 * It returns the vector of students.
 *
 * @return A vector of Student objects.
 */
std::vector<Student> PlacementSystem::get_students() { return _db_students; }

/**
 * > The function iterates through the list of students, and for each student,
 * it iterates through the list of schools the student has chosen, and for each
 * school, it iterates through the list of programmes the school offers, and for
 * each programme, it iterates through the list of programmes the student has
 * chosen, and if the programme the student has chosen is the same as the
 * programme the school offers, it checks if the student's computed evaluation
 * is less than or equal to the programme's cut off, and if it is, it places the
 * student in the programme, otherwise, it rejects the student.

 *This is an
 * O(N^4) Monstrosity but this was the first solution i could come up with!
 */
void PlacementSystem::place_students() {
    // Rewrite the placement algo to fit selection by programmes not only
    // schools.
    for (auto &student : _db_students) {
        auto student_school_choices = student.get_school_choices();

        for (auto &student_chosen_registedSchool : student_school_choices) {
            // check if the student chosen programme is in the University
            // offered courses
            for (auto student_selected_programme :
                 student.get_selected_programmes()) {
                auto school_offered_programmes =
                    student_chosen_registedSchool.get_offered_programmes();
                int N = school_offered_programmes.size();
                for (int i = 0; i < N; ++i) {
                    auto current_programme = school_offered_programmes[i];
                    if (student_selected_programme ==
                        current_programme.get_programme_name()) {
                        // perform placement logic here
                        if (student.set_computed_evaluation() <=
                            current_programme.get_programme_cut_off()) {
                            _placed_students.emplace_back(
                                student, student_chosen_registedSchool,
                                current_programme);
                            break;
                        } else {
                            _rejected_students.emplace_back(
                                student, student_chosen_registedSchool,
                                current_programme);
                        }
                    }
                }
            }
        }
    }
}

/**
 * It displays the list of students who have been placed in a particular school
 * and the list of students who have been rejected by a particular school
 *
 * @param schoolName The name of the school whose placement results are to be
 * displayed.
 */
void PlacementSystem::display_placement_results(std::string schoolName) {
    std::cout << "LIST OF STUDENTS WHO HAVE BEEN PLACED IN " << schoolName
              << "\n";
    for (auto &placed_student : _placed_students) {
        auto student_name = std::get<0>(placed_student).get_name();
        auto student_school = std::get<1>(placed_student).get_name();
        auto student_programme =
            std::get<2>(placed_student).get_programme_name();
        if (student_school == schoolName) {
            std::cout << student_name << ": " << student_school << ": "
                      << student_programme << "\n";
        }
    }
    std::cout << "LIST OF STUDENTS WHO HAVE BEEN REJECTED BY " << schoolName
              << "\n";
    for (auto &rejected_student : _rejected_students) {
        auto student_name = std::get<0>(rejected_student).get_name();
        auto student_school = std::get<1>(rejected_student).get_name();
        auto student_programme =
            std::get<2>(rejected_student).get_programme_name();
        if (student_school == schoolName) {
            std::cout << student_name << ": " << student_school << ": "
                      << student_programme << "\n";
        }
    }
}