from random import choice
from defaults import student_names, grades, courses

with open("./assets/students.txt", 'w') as file:
  grouped_students = []
  for name in student_names:
    student_courses = []
    for course in courses:
      student_courses.append(f"{course}:{choice(grades)}")
    
    new_student = name + ", {" + ", ".join(student_courses) + "}" + "\n"
    grouped_students.append(new_student)

  for data in grouped_students:
    file.write(data)
  
