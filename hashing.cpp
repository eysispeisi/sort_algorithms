#include <cstddef>
using namespace std;

class SimpleHash {
private:
    size_t hash = 0x4ff016ae;
    size_t multiplier = 0x11a8e410;
public:
    SimpleHash();
    SimpleHash(const char *ch);
    void update(const char *ch);
    size_t digest();
};

SimpleHash::SimpleHash(const char *ch) {
    update(ch);
};

void SimpleHash::update(const char *ch) {
    while (*ch) {
        hash ^= (unsigned char) *ch++;
        hash *= multiplier;
    }
};

size_t SimpleHash::digest() {
    return hash;
};
