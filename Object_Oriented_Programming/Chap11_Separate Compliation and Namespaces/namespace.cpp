#include <iostream>
using namespace std;

namespace Space1 {
    void greeting() {
        cout << "Hello from namespace Space1!\n";
    }
} // end namespace Space1

namespace Space2 {
    void greeting() {
        cout << "Greetings from namespace Space2!\n";
    }
} // end namespace Space2

void bigGreeting() {
    cout << "A Big Global Hello!\n";
}

int main() {
    {
        using namespace Space1;
        greeting();
    }

    {
        using namespace Space2;
        greeting();
    }

    bigGreeting();

    return 0;
}