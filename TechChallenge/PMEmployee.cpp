//
//  PMEmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 8/2/25.
//

#include "PMEmployee.hpp"

PMEmployee::PMEmployee(std::string name, SeniorityE seniority, RoleE role) : Employee::Employee(name, seniority, RoleE::PM)
{
    SetSalaryData();
}

void PMEmployee::SetSalaryData()
{
    auto baseSalary = (_seniority == SeniorityE::Senior) ? PM_SENIOR_SALARY : PM_SEMI_SALARY;
    auto incrementPercentage = (_seniority == SeniorityE::Senior) ? PM_SENIOR_INCREMENT : PM_SEMI_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float PMEmployee::GetSalary()
{
    return Employee::GetSalary();
}
