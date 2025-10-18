#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string>m = {{2, "heyyy"}, {3, "selam"}};

    m.insert({5, "vay beeeee"});
    
    map<int, string>::iterator it = m.begin();
    m.erase(it);

    map<int, string>::iterator it2 = m.find(3);
    if (it2 != m.end())
        cout << it2->first << " " << it2->second << endl;

    m[2] = "tuceee";
    m[1] = "uiiyyyyyy";

    map<int, string>::iterator it3;

    // m.clear();
    // cout << "after clear" << endl;

    cout << "map size: " << m.size() << endl;
    for (it3 = m.begin(); it3 != m.end(); it3++)
        cout << it3->first << ":" << it3->second << endl;
     // m.clear();
    // cout << "after clear" << endl;
    
    return 0;
}

// #include <iostream>

// void chance(int &x) {
//     x = 100;
// }

// int main () {
//     int y = 42;
//     chance(y);
//     std::cout << y;
// }