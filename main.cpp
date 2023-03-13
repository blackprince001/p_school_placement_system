#include "SchoolSystem/SchoolSystem.cpp"

int main() { 
  RegistedSchool knust("KNUST", {"Physics"}, 16);
  Student kwame("kwame", {{"Physics", "A"}}, {knust});

  kwame.display_profile();
  return 0; }