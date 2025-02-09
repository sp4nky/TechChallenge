//
//  HREmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#include "HREmployee.hpp"

HREmployee::HREmployee(std::string name, SeniorityE seniority, RoleE role) : Employee::Employee(name, seniority, RoleE::HR)
{
    SetSalaryData();
}

void HREmployee::SetSalaryData()
{
    auto baseSalary = (_seniority == SeniorityE::Senior) ? HR_SENIOR_SALARY : (_seniority == SeniorityE::SemiSenior) ? HR_SEMI_SALARY : HR_JUNIOR_SALARY;
    auto incrementPercentage = (_seniority == SeniorityE::Senior) ? HR_SENIOR_INCREMENT : (_seniority == SeniorityE::SemiSenior) ? HR_SEMI_INCREMENT : HR_JUNIOR_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float HREmployee::GetSalary()
{
    return Employee::GetSalary();
}
