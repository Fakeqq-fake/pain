#include <iostream>
#include <string>
#include <vector>
#include <map>

class Singleton {
private:
    Singleton() = default;
    static Singleton instance;
public:
    static Singleton& getInstance() {
        return instance;
    }
    void print() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};
Singleton Singleton::instance;

class Counter {
private:
    Counter() = default;
    int count = 0;
    static Counter instance;
public:
    static Counter& getInstance() {
        return instance;
    }
    void increment() {
        ++count;
    }
    int getCount() const {
        return count;
    }
};
Counter Counter::instance;

class App {
private:
    App() = default;
    std::string appName;
    static App instance;
public:
    static App& getInstance() {
        return instance;
    }
    void setAppName(const std::string& name) {
        appName = name;
    }
    void printAppName() const {
        std::cout << appName << std::endl;
    }
};
App App::instance;

class Config {
private:
    Config() = default;
    int volume = 50;
    static Config instance;
public:
    static Config& getInstance() {
        return instance;
    }
    void setVolume(int vol) {
        volume = vol;
    }
    int getVolume() const {
        return volume;
    }
};
Config Config::instance;

class Logger {
private:
    Logger() = default;
    static Logger instance;
public:
    static Logger& getInstance() {
        return instance;
    }
    void log(const std::string& message) {
        std::cout << message << std::endl;
    }
};
Logger Logger::instance;

class DataManager {
private:
    DataManager() = default;
    std::map<std::string, int> data;
    static DataManager instance;
public:
    static DataManager& getInstance() {
        return instance;
    }
    void addValue(const std::string& key, int value) {
        data[key] = value;
    }
    int getValue(const std::string& key) const {
        auto it = data.find(key);
        return it != data.end() ? it->second : -1;
    }
};
DataManager DataManager::instance;

class ProtectedSingleton {
private:
    ProtectedSingleton() = default;
    ProtectedSingleton(const ProtectedSingleton&) = delete;
    ProtectedSingleton& operator=(const ProtectedSingleton&) = delete;
    static ProtectedSingleton instance;
public:
    static ProtectedSingleton& getInstance() {
        return instance;
    }
};
ProtectedSingleton ProtectedSingleton::instance;

class UserManager {
private:
    UserManager() = default;
    UserManager(const UserManager&) = delete;
    UserManager& operator=(const UserManager&) = delete;
    std::vector<std::string> users;
    static UserManager instance;
public:
    static UserManager& getInstance() {
        return instance;
    }
    void addUser(const std::string& user) {
        users.push_back(user);
    }
    void printUsers() const {
        for (const auto& user : users) {
            std::cout << user << std::endl;
        }
    }
};
UserManager UserManager::instance;

class ObjectCounter {
private:
    ObjectCounter() = default;
    ObjectCounter(const ObjectCounter&) = delete;
    ObjectCounter& operator=(const ObjectCounter&) = delete;
    int objectCount = 0;
    static ObjectCounter instance;
public:
    static ObjectCounter& getInstance() {
        return instance;
    }
    void createObject() {
        ++objectCount;
    }
    int getObjectCount() const {
        return objectCount;
    }
};
ObjectCounter ObjectCounter::instance;

void func1() {
    Config::getInstance().setVolume(75);
}

void func2() {
    std::cout << Config::getInstance().getVolume() << std::endl;
}

void logError() {
    Logger::getInstance().log("Error occurred!");
}

void logInfo() {
    Logger::getInstance().log("Info: Process started");
}

int main() {
    Singleton& obj1 = Singleton::getInstance();
    Singleton& obj2 = Singleton::getInstance();
    std::cout << (&obj1 == &obj2) << std::endl;

    Singleton::getInstance().print();
    Singleton::getInstance().print();

    Counter::getInstance().increment();
    Counter::getInstance().increment();
    std::cout << Counter::getInstance().getCount() << std::endl;

    App::getInstance().setAppName("MyApp");
    App::getInstance().printAppName();

    func1();
    func2();

    logError();
    logInfo();

    DataManager::getInstance().addValue("score", 100);
    std::cout << DataManager::getInstance().getValue("score") << std::endl;

    UserManager::getInstance().addUser("Alice");
    UserManager::getInstance().addUser("Bob");
    UserManager::getInstance().printUsers();

    ObjectCounter::getInstance().createObject();
    ObjectCounter::getInstance().createObject();
    std::cout << ObjectCounter::getInstance().getObjectCount() << std::endl; 

    return 0;
}
