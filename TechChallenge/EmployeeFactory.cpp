//
//  EmployeeFactory.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 9/2/25.
//

#include "EmployeeFactory.hpp"

#include "Employee.hpp"
#include "EngineeringEmployee.hpp"
#include "HREmployee.hpp"
#include "CEOEmployee.hpp"
#include "ArtistEmployee.hpp"
#include "DesignEmployee.hpp"
#include "PMEmployee.hpp"
#include "Constants.h"


EmployeeFactory* EmployeeFactory::_instance = 0;

EmployeeFactory* EmployeeFactory::GetInstance()
{
    if (_instance == 0)
    {
        _instance = new EmployeeFactory();
    }
    
    return _instance;
}

template<typename T> Employee CreateBasicInstance(std::string name, Employee::SeniorityE seniority, Employee::RoleE role)
{
    return T::create(name, seniority, role);
}

EmployeeFactory::EmployeeFactory()
{
    
}

std::unique_ptr<Employee> EmployeeFactory::CreateNewEmployee(std::string name, Employee::SeniorityE seniority, Employee::RoleE role)
{
    switch (role) {
        case Employee::RoleE::HR:
            {
                return std::make_unique<HREmployee>(name, seniority, role);
            }
            break;
        case Employee::RoleE::Design:
            {
                return std::make_unique<DesignEmployee>(name, seniority, role);
            }
            break;
        case Employee::RoleE::Artist:
            {
                return std::make_unique<ArtistEmployee>(name, seniority, role);
            }
            break;
        case Employee::RoleE::Engineering:
            {
                return std::make_unique<EngineeringEmployee>(name, seniority, role);
            }
            break;
        case Employee::RoleE::PM:
            {
                return std::make_unique<PMEmployee>(name, seniority, role);
            }
            break;
        case Employee::RoleE::CEO:
            {
                return std::make_unique<CEOEmployee>(name, seniority, role);
            }
            break;
            
        default:
            break;
    }

    return std::make_unique<Employee>(name, seniority, role);
}
