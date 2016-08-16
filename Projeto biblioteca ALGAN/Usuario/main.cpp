#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    double a;
    
    a = 54*53*52*51*50*49;
    printf("%.20lf", (1/(a/720)) * 100);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
