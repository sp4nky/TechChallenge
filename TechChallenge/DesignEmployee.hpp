//
//  DesignEmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#ifndef DesignEmployee_hpp
#define DesignEmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class DesignEmployee : public Employee
{
public:
    DesignEmployee(std::string name, SeniorityE level, RoleE = RoleE::Design);
    
    float GetSalary() override;

private:
    virtual void SetSalaryData() override;

};

#endif /* DesignEmployee_hpp */
