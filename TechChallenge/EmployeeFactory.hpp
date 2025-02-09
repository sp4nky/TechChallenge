//
//  EmployeeFactory.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 9/2/25.
//

#ifndef EmployeeFactory_hpp
#define EmployeeFactory_hpp

#include "Employee.hpp"

#include <stdio.h>

class EmployeeFactory
{
public:
    static EmployeeFactory* GetInstance();
    
    std::unique_ptr<Employee> CreateNewEmployee(std::string name, Employee::SeniorityE seniority = Employee::SeniorityE::Senior, Employee::RoleE role = Employee::RoleE::CEO);
private:
    static EmployeeFactory* _instance;
    EmployeeFactory();
    
};

#endif /* EmployeeFactory_hpp */
