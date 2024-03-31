/* cpp supports generic function and generic class
 * generic function are template function
 * generic class are template class
 * */

#include <stdio.h>

template <class T>
class Arithmetic
{
   private:
      T a;
      T b;

   public:
      Arithmetic(T a, T b);
      T add();
      T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
   this->a = a;
   this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
   T c;
   c = a + b;
   return c;
}

template <class T>
T Arithmetic<T>::sub()
{
   T c;
   c = a - b;
   return c;
}

int main()
{
   Arithmetic<int> ar(10, 5);
   Arithmetic<float> ar1(10.5, 20.3);
   printf("Add = %d\n", ar.add());
   printf("Sub = %d\n", ar.sub());
   printf("Add = %.1f\n", ar1.add());
   printf("Sub = %.1f\n", ar1.sub());
   return 0;
}
