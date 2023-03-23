#include <unordered_map>

#include "PlacementSystem/placement_system.cpp"
#include "PlacementSystem/placement_system.hpp"
#include "SchoolSystem/SchoolSystem.cpp"
#include "SchoolSystem/SchoolSystem.hpp"
#include "utils/utils.cpp"

std::vector<Student> TEMPLATE_STUDENTS;

std::vector<RegistedSchool> TEMPLATE_SCHOOLS;

std::vector<std::string> default_courses = {"Mathematics", "English Language",
                                            "Science", "Social Science"};

std::vector<std::string> &set_default_school_courses() {
    return default_courses;
}

RegistedSchool KNUST("KNUST", set_default_school_courses(), 17);
RegistedSchool Legon("UG-Legon", set_default_school_courses(), 15);
RegistedSchool Uenr("UENR", set_default_school_courses(), 12);

void preload_registedschools() {
    for (auto item : {KNUST, Legon, Uenr}) TEMPLATE_SCHOOLS.push_back(item);
}

void preload_student_data() {
    std::string path_to_student_database = "../students.txt";

    auto student_records =
        util::read_records_from_database(path_to_student_database);

    for (auto record : student_records) {
        std::unordered_map<std::string, std::string> student_grades;

        auto caught = util::split_by(record, '-');

        std::string student_name = caught[0];
        auto split_grades = util::split_by(caught[1], ',');

        for (auto item : split_grades) {
            auto course_and_grade = util::split_by(item, ':');
            student_grades.emplace(course_and_grade[0], course_and_grade[1]);
        }

        Student nwStudent(student_name, student_grades, TEMPLATE_SCHOOLS);

        TEMPLATE_STUDENTS.push_back(nwStudent);
    }
}

int main() {
    preload_registedschools();

    preload_student_data();

    for (int n = 0; n < 3; ++n) TEMPLATE_STUDENTS[n].display_profile();

    PlacementSystem WAEC(TEMPLATE_SCHOOLS, TEMPLATE_STUDENTS);

    WAEC.place_students();

    WAEC.display_placement_results("UENR");

    return 0;
}