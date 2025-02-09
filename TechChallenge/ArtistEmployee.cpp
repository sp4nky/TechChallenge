//
//  ArtistEmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#include "ArtistEmployee.hpp"

ArtistEmployee::ArtistEmployee(std::string name, SeniorityE seniority, RoleE role) : Employee::Employee(name, seniority, RoleE::Artist)
{
    SetSalaryData();
}

void ArtistEmployee::SetSalaryData()
{
    auto baseSalary = (_seniority == SeniorityE::Senior) ? ARTIST_SENIOR_SALARY : ARTIST_SEMI_SALARY;
    auto incrementPercentage = (_seniority == SeniorityE::Senior) ? ARTIST_SENIOR_INCREMENT : ARTIST_SEMI_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float ArtistEmployee::GetSalary()
{
    return Employee::GetSalary();
}
