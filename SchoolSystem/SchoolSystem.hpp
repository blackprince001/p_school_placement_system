#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class RegistedSchool {
   private:
    std::string name;
    std::vector<std::string> courses;
    int cut_off;

   public:
    RegistedSchool(std::string schoolName,
                   std::vector<std::string> registedCourses, int cut_off_grade)
        : name(schoolName), courses(registedCourses), cut_off(cut_off_grade) {}

    std::vector<std::string> get_registed_courses();
    int get_cut_off();
    std::string get_name();
};

class Student {
   private:
    std::string name;
    std::unordered_map<std::string, std::string> grades;
    std::vector<RegistedSchool> school_choices;
    int evaluated_grade = 0;

   public:
    Student(std::string refName,
            std::unordered_map<std::string, std::string> refGrades,
            std::vector<RegistedSchool> refChoices)
        : name(refName), grades(refGrades), school_choices(refChoices) {}
    std::string get_name();
    std::unordered_map<std::string, std::string> get_grades() const;
    std::vector<RegistedSchool> get_school_choices() const;
    void display_profile();
    int set_computed_evaluation();
};
