//
// Created by The Duke on 16/12/2022.
//

#include "builder.h"
#include <iostream>
#include <string>

CoffeeBuilder Coffee::create(std::string requestorName) {
    return CoffeeBuilder(requestorName);
}

CoffeeBuilder& CoffeeBuilder::makeHot() {
    coffee.isHot = true;
    return *this;
}

CoffeeBuilder& CoffeeBuilder::addSugar() {
    coffee.hasSugar = true;
    return *this;
}

CoffeeBuilder& CoffeeBuilder::addMilk() {
    coffee.hasMilk = true;
    return *this;
}

CoffeeBuilder& CoffeeBuilder::costs(double cost) {
    coffee.cost = cost;
    return *this;
}