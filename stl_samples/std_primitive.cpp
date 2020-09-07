#include <limits>
#include <cstddef>
#include <iostream>
 
int main()
{
        int  min = std::numeric_limits<int>::min();
        int  max = std::numeric_limits<int>::max();
        << "short: " << std::dec << std::numeric_limits<short>::min()
        << " or " << std::hex << std::showbase 
        << std::numeric_limits<short>::min() << '\n'
 
        << "int: " << std::dec <<  << std::showbase
        << " or " << std::hex << std::numeric_limits<int>::min() << '\n' << std::dec 
 
        << "ptrdiff_t: " << std::numeric_limits<std::ptrdiff_t>::min() << std::showbase
        << " or " << std::hex << std::numeric_limits<std::ptrdiff_t>::min() << '\n'
 
        << "float: " << std::numeric_limits<float>::min()
        << " or " << std::hexfloat << std::numeric_limits<float>::min() << '\n'
 
        << "double: " << std::defaultfloat << std::numeric_limits<double>::min()
        << " or " << std::hexfloat << std::numeric_limits<double>::min() << '\n';
}

#include <cstdlib>
#include <iostream>
#include <ctime>
 
int main() 
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll 6-sided dice 20 times
    for (int n=0; n != 20; ++n) {
        int x = 7;
        while(x > 6) 
            x = 1 + std::rand()/((RAND_MAX + 1u)/6);  // Note: 1+rand()%6 is biased
        std::cout << x << ' ';
    }
}

#include <iostream>
// Primitive type stl libs
#include <limits>
#include <random>
using std::numeric_limits;
using std::abs;
using std::fabs;
using std::cout;
using std::pow;
using std::endl;
using std::log;
using std::sqrt;
using std::ceil;
using std::floor;
using std::uniform_int_distribution;
int main() {
    int min =  numeric_limits<int>::min();
    long int minLongInt = numeric_limits<long int>::min();
    cout<<"\nAbs value of -50:" << fabs(-50.50)<<endl;
    cout<<"\n3rd power of 2:"<<pow(2,3);
    cout<<"\nLog2 of 4:"<<log2(4);
    cout<<"\nLog10 of 4:"<<log10(4);
    cout<<"\nLog10 of 4:"<<log(4);
    cout<<"\nLog of :"<<logb(10);
    return 0;
}
