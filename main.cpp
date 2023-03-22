#include "PlacementSystem/placement_system.hpp"
#include "SchoolSystem/SchoolSystem.hpp"
#include "utils/utils.cpp"

std::vector<Student> template_students;
std::vector<RegistedSchool> template_schools;
std::unordered_map<std::string, std::string> template_grades;

int main() {
    // TODO
    // Make a global variable for registed courses for all candidates
    // Make a template generated list of students preferrably in a text file to
    // be read
    std::string path_to_student_database = "../students.txt";

    auto student_records = read_records_from_database(path_to_student_database);

    for (auto student_record : student_records) {
        auto caught = split_by(
            student_record,
            '-');  // separate names from grades by splitting with character
        for (auto item : caught) std::cout << item << "\n";
    }

    return 0;
}