//
//  EngineeringEmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#ifndef EngineeringEmployee_hpp
#define EngineeringEmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class EngineeringEmployee : public Employee
{
public:
    
    ~EngineeringEmployee(){}
    EngineeringEmployee(std::string name, SeniorityE level, RoleE = RoleE::Engineering);
    
    float GetSalary() override;

private:
    virtual void SetSalaryData() override;

};

#endif /* EngineeringEmployee_hpp */
