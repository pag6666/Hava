#include <iostream>
#include <string>
#include <sstream>
#include <functional>

namespace System {
class Object {
private:
    std::string value = "";
public:
    
    virtual std::string ToString() const {
        return "Object: " + value;
    }
    Object operator =(std::string out) {
        value = out;
        return *this;
    }
    virtual size_t GetHashCode() const {
        return std::hash<std::string>()(ToString());
    }

    virtual bool Equals(const Object& other) const {
        return this->GetHashCode() == other.GetHashCode();
    }

    virtual ~Object() {}
};
}
