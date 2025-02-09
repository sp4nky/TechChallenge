//
//  Employee.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 4/2/25.
//

#include "Employee.hpp"

Employee::Employee(std::string name, SeniorityE seniority, RoleE role) : _salaryData(0,0)
{
    this->_name =  name;
    this->_seniority = seniority;
    this->_role = role;
}

float Employee::GetSalary()
{
    return _salaryData.baseSalary * (1 + _salaryData.incrementPercentage / 100);
}

void Employee::SetSalaryData()
{
    
}

Employee::SeniorityE Employee::GetSeniority()
{
    return this->_seniority;
}

