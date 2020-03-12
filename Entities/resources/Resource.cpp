#include "./Resource.h"

Resource::~Resource(){}

Resource::Resource(){
    this->blood = new Blood();
    this->blood->sprite.setPosition(this->blood_x, this->blood_y);
}