#include <stdio.h>

class Rectangle
{
   private:
      int length;
      int breadth;

   public:
      // constructor
      Rectangle () { length = breadth = 0; }
      // constructor overload
      Rectangle (int, int);

      // facilitators
      int area();
      int peri();

      // setter (mutators)
      void setLength(int l) { length = l; }
      void setBreadth(int d) { breadth = d; }

      // getter (accessor)
      int getLength() { return length; }
      int getBreadth() { return breadth; }

      // destructor
      ~Rectangle() { printf("Destructed!"); }
};

// :: is scope resolution operator
// <scope>::<func>
Rectangle::Rectangle(int l, int d)
{
   length = l;
   breadth = d;
}

int Rectangle::area()
{
   return length * breadth;
}

int Rectangle::peri()
{
   return 2*(length + breadth);
}

int main()
{
   // struct Rectangle r = { 0, 0 };
   int l, d;

   printf("Enter Length and Breadth: ");
   scanf("%d %d", &l, &d);

   Rectangle r(l, d);

   int a = r.area();

   int p = r.peri();

   printf("area: %d\n", a);
   printf("peri: %d\n", p);

   return 0;
}
