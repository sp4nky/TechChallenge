//
//  ArtistEmployee.hpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 7/2/25.
//

#ifndef ArtistEmployee_hpp
#define ArtistEmployee_hpp

#include <stdio.h>

#include "Employee.hpp"

class ArtistEmployee : public Employee
{
public:
    ArtistEmployee(std::string name, SeniorityE level, RoleE = RoleE::Artist);
    
    float GetSalary() override;

private:
    virtual void SetSalaryData() override;

};

#endif /* ArtistEmployee_hpp */
