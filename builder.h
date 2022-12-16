//
// Created by The Duke on 16/12/2022.
//
#pragma once
#ifndef DESIGNPATTERNS_BUILDER_H
#define DESIGNPATTERNS_BUILDER_H
#include <iostream>
#include <string>

class CoffeeBuilder;

class Coffee {
    std::string requestorName;

public:
    bool isHot;
    bool hasMilk;
    bool hasSugar;
    bool cost;

    Coffee(std::string requestorName) : requestorName(requestorName) {}
    friend class CoffeeBuilder;
    static CoffeeBuilder create(std::string requestorName);

};

class CoffeeBuilder{
    Coffee coffee;

public:
    CoffeeBuilder(std::string requestorName) : coffee(Coffee(requestorName)) {}

    operator Coffee() const { return std::move(coffee); }

    CoffeeBuilder& makeHot();
    CoffeeBuilder& addMilk();
    CoffeeBuilder& addSugar();
    CoffeeBuilder& costs(double cost);
};

#endif //DESIGNPATTERNS_BUILDER_H
