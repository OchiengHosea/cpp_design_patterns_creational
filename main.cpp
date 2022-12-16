#include <iostream>
#include <map>
#include <string>

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

    return EXIT_SUCCESS;
}
