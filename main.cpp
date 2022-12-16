#include <vector>
#include <iostream>
class CoffeeMachine {
public:
    virtual CoffeeMachine* clone() = 0;
    virtual void brew() = 0;
};

class SimpleCoffeeMachine : public CoffeeMachine {
public:
    CoffeeMachine* clone() {
        return new SimpleCoffeeMachine;
    }

    void brew() {
        std::cout << "Brewing simple coffee\n";
    }
};

class ComplexCoffeeMachine : public CoffeeMachine {
public:
    CoffeeMachine* clone() {
        return new ComplexCoffeeMachine;
    }

    void brew() {
        std::cout << "brewing complex coffee \n";
    }
};

class ExpressMachine: public CoffeeMachine {
public:
    CoffeeMachine* clone() {
        return new ExpressMachine;
    }

    void brew() {
        std::cout << "Brewing Express coffee \n";
    }
};

class CoffeeMachineManager {
public:
    static CoffeeMachine* createMachine(int machineType);
    ~CoffeeMachineManager(){};

private:
    static CoffeeMachine* machines[3];
};

CoffeeMachine* CoffeeMachineManager::machines[] = {
        new SimpleCoffeeMachine, new ComplexCoffeeMachine, new ExpressMachine
};

CoffeeMachine* CoffeeMachineManager::createMachine(int machineType){
    return machines[machineType]->clone();
}

int main() {
    std::vector<CoffeeMachine*> myMachines[7];
    CoffeeMachine* simpleMachine = CoffeeMachineManager::createMachine(0);
    CoffeeMachine* complexMachine = CoffeeMachineManager::createMachine(1);
    CoffeeMachine* expressMachine = CoffeeMachineManager::createMachine(2);

    myMachines->push_back(simpleMachine);
    myMachines->push_back(complexMachine);
    myMachines->push_back(expressMachine);

    std::cout << myMachines->size();

    for (int i = 0; i < myMachines->size(); i++) {
        myMachines->at(i)->brew();
    }

    CoffeeMachine* clonedMachine = simpleMachine->clone();
    clonedMachine->brew();

    // clean up
    for (int i = 0; i < myMachines->size(); ++i) {
        delete myMachines->at(i);
    }

    delete clonedMachine;
    return EXIT_SUCCESS;
}
