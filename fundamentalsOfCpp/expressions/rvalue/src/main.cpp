#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Fraction
{
  private:
    int m_numerator;
    int m_denominator;
   
  public:
    Fraction(int numerator = 0, int denominator = 1) :
      m_numerator(numerator), m_denominator(denominator)
    {
    }
   
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
    {
      out << f1.m_numerator << "/" << f1.m_denominator;
      return out;
    }
};

int
main (int argc, char *argv[])
{
  /*
   *  Literal (except string-literal)
   */

  /*
   *  Function-Call expression with return type Lvalue
   */

  /*
   *  Overloaded Operator expression with return type Lvalue
   */

  /*  
   *  Built-in Arithmetic expression (like x+y)
   */

  /*
   *  Built-in Logical expression (like expr1 && expr2)
   */

  /*
   *  Built-in Comparison expression (like x==y, x!=y)
   */

  /*
   *  Built-in Address-Of expression (like &x)
   */

  /*
   *  Built-in Post Increment/Decrement expression (x--, x++)
   */

  /*
   *  Lambda expression
   */
 
  std::cout << Fraction(4, 8) << '\n';

  Fraction &&rref = Fraction(3, 5); // r-value reference to temporary Fraction
  std::cout << rref << '\n';
 
  // rref (and the temporary Fraction) goes out of scope here

  return (0);
}
