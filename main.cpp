#include "PlacementSystem/placement_system.cpp"
#include "PlacementSystem/placement_system.hpp"
#include "SchoolSystem/SchoolSystem.cpp"
#include "SchoolSystem/SchoolSystem.hpp"
#include "utils/utils.cpp"

/* Declaring two global vectors of type `Student` and `RegistedSchool`
 * respectively. */
std::vector<Student> template_students;
std::vector<RegistedSchool> template_schools;

/* A global variable that is used to store the default courses that
are offered by the schools. */
std::vector<Programme> default_programmes;

std::vector<std::string> default_programme_names = {
    "Computer Engineering", "Electrical Engineering", "Computer Science",
    "Mechanical Engineering"};

/**
 * It returns a reference to the vector of strings that is the default school
 * courses
 *
 * @return A reference to the vector of strings.
 */
std::vector<Programme> &set_default_school_programmes() {
    for (auto programme_name : default_programme_names) {
        Programme nwProgramme(programme_name, 15);
        default_programmes.push_back(nwProgramme);
    }
    return default_programmes;
}

/* Creating three objects of the class `RegistedSchool` and assigning them to
the variables `KNUST`, `Legon` and `Uenr` respectively. */
RegistedSchool KNUST("KNUST", set_default_school_programmes());
RegistedSchool Legon("UG-Legon", set_default_school_programmes());
RegistedSchool Uenr("UENR", set_default_school_programmes());

/**
 * It takes a list of schools and pushes them into a vector
 */
void preload_registedschools() {
    for (auto item : {KNUST, Legon, Uenr}) template_schools.push_back(item);
}

/**
 * It reads the student database,
 * creates a student object for each student, and adds the student to the global
 * vector of students
 */
void preload_student_data() {
    std::string fp = "../students.txt";
    auto student_records = util::read_records_from_database(fp);

    for (auto record : student_records) {
        std::unordered_map<std::string, std::string> student_grades;

        // Split the name of the student from the grades obtained
        auto split_name_from_grades = util::split_by(record, '-');

        // Assign the student name and grades to string and pair objects
        std::string student_name = split_name_from_grades[0];
        auto split_grades = util::split_by(split_name_from_grades[1], ',');

        // Iterate over the pair iterable `split_grades`, append them to
        // student_grades
        for (auto item : split_grades) {
            auto course_and_grade = util::split_by(item, ':');
            student_grades.emplace(course_and_grade[0], course_and_grade[1]);
        }
        // create student objects and add them to a collection of present
        // students.
        Student nwStudent(student_name, student_grades, template_schools,
                          {"Computer Engineering", "Computer Science"});
        template_students.push_back(nwStudent);
    }
}

int main() {
    preload_registedschools();

    preload_student_data();

    for (int n = 0; n < 3; ++n) template_students[n].display_profile();

    // Create a PlacementSystem object called WAEC
    PlacementSystem WAEC(template_schools, template_students);
    // Place students using system member functions
    WAEC.place_students();
    // Display the student who have been placed in a particular University by
    // name Default University can be inferenced from the global variables at
    // the top of this source. {KNUST, UG-Legon, UENR}.
    WAEC.display_placement_results("KNUST");

    return 0;
}