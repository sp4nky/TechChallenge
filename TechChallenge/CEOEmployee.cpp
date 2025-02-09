//
//  CEOEmployee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#include "CEOEmployee.hpp"

CEOEmployee::CEOEmployee(std::string name, SeniorityE senority, RoleE role) : Employee::Employee(name, SeniorityE::Senior, RoleE::CEO)
{
    SetSalaryData();
}

void CEOEmployee::SetSalaryData()
{
    auto baseSalary = CEO_SALARY;
    auto incrementPercentage = CEO_INCREMENT;
    _salaryData = SalaryData(baseSalary, incrementPercentage);
}

float CEOEmployee::GetSalary()
{
    return Employee::GetSalary();
}
