#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/* A Model definition for Programme.
 *
 * attr: `_programme_name` will represent the name of the programme.
 *
 * attr: `_programme_cut_off_grade` will represent the grade for which an
 * applicant must have or less before being accepted.
 *
 * attr: `_cut_off` will represent the grade for which an applicant must have or
 * less before being accepted.
 */
class Programme {
   private:
    std::string _programme_name;
    int _programme_cut_off_grade;

   public:
    Programme(std::string name, int cut_off)
        : _programme_name(name), _programme_cut_off_grade(cut_off){};
    int get_programme_cut_off();
    std::string get_programme_name();
};

/* A Model definition for a placement system.
 *
 * attr: `_name` will represent the name of the School.
 *
 * attr: `_offered_programmes` will represent the majors it offers its
 * students.
 */
class RegistedSchool {
   private:
    // Declaring the private variables of the class
    std::string _name;
    std::vector<Programme> _offered_programmes;

   public:
    RegistedSchool(std::string schoolName,
                   std::vector<Programme> registedProgrammes)
        : _name(schoolName), _offered_programmes(registedProgrammes) {}

    // Declaring the public member functions
    std::vector<Programme> get_offered_programmes();
    std::string get_name();
};

/* A Model definition for a Student.
 *
 * attr: `_name` will represent the name of the student.
 *
 * attr: `_grades` will represent the course and grade obtained after exams.
 *
 * attr: `_school_choices` will represent the school the student applies to.
 *
 * attr: `_evaluated_grade` will constitute the evaluated grade from the grade
 * values from the `_grades` attribute.
 */
class Student {
   private:
    // Declaring the private variables of the class
    std::string _name;
    std::unordered_map<std::string, std::string> _grades;
    std::vector<RegistedSchool> _school_choices;
    std::vector<std::string> _selected_programmes;
    int _evaluated_grade = 0;

   public:
    Student(std::string refName,
            std::unordered_map<std::string, std::string> refGrades,
            std::vector<RegistedSchool> refChoices,
            std::vector<std::string> refprogrammes)
        : _name(refName),
          _grades(refGrades),
          _school_choices(refChoices),
          _selected_programmes(refprogrammes) {}

    // Declaring the public member functions
    std::string get_name();
    std::unordered_map<std::string, std::string> get_grades() const;
    std::vector<RegistedSchool> get_school_choices() const;
    std::vector<std::string> get_selected_programmes() const;
    void display_profile();
    int set_computed_evaluation();
};
