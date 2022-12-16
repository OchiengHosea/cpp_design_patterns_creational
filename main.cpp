#include <iostream>
#include <map>
#include <string>
#include "builder.h"

class GlobalCoffeeConfig {
    std::map<std::string, std::string> coffeeState;

    /// Private constructor
    GlobalCoffeeConfig() {}

public:
    // Remove ability to use the copy constructor
    GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;

    // Remove the ability to use the copy assignment operator
    GlobalCoffeeConfig &operator=(GlobalCoffeeConfig const&) = delete;

    // provide a single, static method for retrieving the singleton instance
    static GlobalCoffeeConfig &get() {
        static GlobalCoffeeConfig config;
        return config;
    }

    void setState(const std::string &key, const std::string &value) {
        coffeeState.insert({key, value});
    }

    std::string getState(const std::string key) {
        auto iterator = coffeeState.find(key);
        return iterator->second;
    }
};

int main() {
    std::cout << "Hello, Singletons!" << std::endl;
    GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();
    configObj.setState("COFFEE_STATUS", "ON");
    configObj.setState("COFFEE_HEALTH_URL", "./heath");
    printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
    printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());

    // Builder pattern example
    Coffee coffee = Coffee::create("Zachary")
            .makeHot()
            .addSugar()
            .addMilk()
            .costs(6.4);

    Coffee coffee1 = Coffee::create("Jenifer")
            .makeHot()
            .costs(3.44);

    std::cout << coffee.cost << std::endl;
    std::cout << coffee1.cost << std::endl;
    return EXIT_SUCCESS;
}
