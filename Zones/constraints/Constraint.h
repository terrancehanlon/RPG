#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#pragma once

#include <string>
#include <vector>

class Constraint {

    private:
        bool le = false; //less than or equal to
        bool ge = false; //greater than or equal to
        bool l = false; //less than
        bool g = false; //greater than
        
        bool x = false;
        bool y = false;
        std::vector<float> coords;

    public:
        Constraint(std::string equality, std::vector<float> coords);
        


};

#endif