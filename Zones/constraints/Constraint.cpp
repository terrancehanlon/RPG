#include "Constraint.h"
#include <regex>



Constraint::Constraint(){

}

void Constraint::setConstraintString(std::string statement){
    this->statementstring = statement;
}

bool Constraint::isConstrained(float playerX, float playerY){

    // (this->statementstring.begin(), this->statementstring.end(), 'X', std::to_string(playerX));
    std::string temp = std::regex_replace(statementstring, std::regex("X"), std::to_string(playerX));
    temp = std::regex_replace(statementstring, std::regex("Y"), std::to_string(playerY));
    return false;
}