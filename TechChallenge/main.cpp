//
//  main.cpp
//  TechChallenge
//
//  Created by Jonathan Cabrera on 8/2/25.
//

#include <iostream>


#include "EmployeeController.hpp"

int main(int argc, const char * argv[]) {

    auto controller = EmployeeController();
    return controller.StartTest(argc, argv);
}
