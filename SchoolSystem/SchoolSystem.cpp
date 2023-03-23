#include "./SchoolSystem.hpp"

/**
 * *|MARCADOR_CURSOR|*
 *
 * @return The cut_off value of the RegistedSchool object.
 */
int RegistedSchool::get_cut_off() { return cut_off; }

/**
 * It returns the courses vector.
 *
 * @return A vector of strings.
 */
std::vector<std::string> RegistedSchool::get_registed_courses() {
    return courses;
}

/**
 * It returns the name of the school.
 *
 * @return The name of the school.
 */
std::string RegistedSchool::get_name() { return name; }

/**
 * It returns the name of the student.
 *
 * @return The name of the student.
 */
std::string Student::get_name() { return name; }

/**
 * This function returns a copy of the grades map.
 *
 * @return A copy of the grades map.
 */
std::unordered_map<std::string, std::string> Student::get_grades() const {
    return grades;
}

/**
 * This function returns the school choices of a student.
 *
 * @return A vector of RegistedSchool objects.
 */
std::vector<RegistedSchool> Student::get_school_choices() const {
    return school_choices;
}

/**
 * It takes the grades of a student and converts them to a numerical value
 *
 * @return The evaluated grade of the student.
 */
int Student::set_computed_evaluation() {
    for (auto [_, grade] : grades) {
        if (grade == "A")
            evaluated_grade += 1;
        else if (grade == "B")
            evaluated_grade += 2;
        else if (grade == "C")
            evaluated_grade += 3;
        else if (grade == "D")
            evaluated_grade += 4;
        else if (grade == "E")
            evaluated_grade += 5;
        else if (grade == "F")
            evaluated_grade += 6;
    }
    return evaluated_grade;
}

/**
 * The function `display_profile` prints the name of the student, the grades of
 * the student, and the schools the student has chosen
 */
void Student::display_profile() {
    auto name = get_name();
    auto schools_chosen = get_school_choices();
    auto grades = get_grades();

    std::cout << "Student Name: " << name << '\n';

    std::cout << "Grades: \n";
    for (auto &grade : grades) {
        std::cout << grade.first << "-" << grade.second << "\n";
    }

    evaluated_grade = set_computed_evaluation();
    std::cout << "Overall Grade: " << evaluated_grade << "\n";

    std::cout << "Schools picked\n";
    for (auto &school : schools_chosen) {
        std::cout << school.get_name() << "\n";
    }
}