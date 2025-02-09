//
//  EngineeringEmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#include "EngineeringEmployee.hpp"

EngineeringEmployee::EngineeringEmployee(std::string name, SeniorityE seniority, RoleE role) : Employee::Employee(name, seniority, RoleE::Engineering)
{
    SetSalaryData();
}

void EngineeringEmployee::SetSalaryData()
{
    auto baseSalary = (_seniority == SeniorityE::Senior) ? ENGINEERING_SENIOR_SALARY : (_seniority == SeniorityE::SemiSenior) ? ENGINEERING_SEMI_SALARY : ENGINEERING_JUNIOR_SALARY;
    auto incrementPercentage = (_seniority == SeniorityE::Senior) ? ENGINEERING_SENIOR_INCREMENT : (_seniority == SeniorityE::SemiSenior) ? ENGINEERING_SEMI_INCREMENT : ENGINEERING_JUNIOR_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float EngineeringEmployee::GetSalary()
{
    return Employee::GetSalary();
}
