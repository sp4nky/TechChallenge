//
//  DesignEmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#include "DesignEmployee.hpp"

DesignEmployee::DesignEmployee(std::string name, SeniorityE seniority, RoleE role) : Employee::Employee(name, seniority, RoleE::Design)
{
    SetSalaryData();
}

void DesignEmployee::SetSalaryData()
{
    auto baseSalary = (_seniority == SeniorityE::Senior) ? DESIGN_SENIOR_SALARY : DESIGN_JUNIOR_SALARY;
    auto incrementPercentage = (_seniority == SeniorityE::Senior) ? DESIGN_SENIOR_INCREMENT : DESIGN_JUNIOR_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float DesignEmployee::GetSalary()
{
    return Employee::GetSalary();
}
