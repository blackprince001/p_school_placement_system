#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "../SchoolSystem/SchoolSystem.hpp"

/* A Model definition for a placement system.
 *
 * attr: `db_schools` will represent the schools that are going to be assigned
 * students.
 *
 * attr: `db_students` will represent the students thar are going to
 * be assigned schools.
 *
 * attr: `placed_students` will represent who have been
 * successfully assigned a school.
 *
 * attr: `rejected_students` will represent
 * who have not been successfully assigned a school.
 */
class PlacementSystem {
   private:
    // Declaring the private variables of the class.
    std::vector<RegistedSchool> _db_schools;
    std::vector<Student> _db_students;
    std::vector<std::tuple<Student, RegistedSchool, Programme>>
        _placed_students;
    std::vector<std::tuple<Student, RegistedSchool, Programme>>
        _rejected_students;

   public:
    PlacementSystem() : _db_schools({}), _db_students({}){};
    PlacementSystem(std::vector<RegistedSchool> schoolList,
                    std::vector<Student> studentList)
        : _db_schools(schoolList), _db_students(studentList){};

    // Declaring public member functions
    std::vector<Student> get_students();
    void add_school(RegistedSchool &);
    void add_student(Student &);
    std::vector<RegistedSchool> get_registed_schools();
    void place_students();
    std::vector<std::tuple<Student, RegistedSchool, Programme>>
    get_placed_students();
    std::vector<std::tuple<Student, RegistedSchool, Programme>>
    get_rejected_students();
    void display_placement_results(std::string schoolName);
};
