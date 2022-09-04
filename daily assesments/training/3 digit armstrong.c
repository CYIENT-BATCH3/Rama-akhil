
#include<stdio.h>
int
main ()
{
  int n,r,s=0,dummy;                     //decleration of variable
  printf ("enter a 3 digit number =");
  scanf ("%d",&n);                      //reading input from user
  dummy= n;                             //storing original number into temp variable
  while (n > 0)
    {
      r = n % 10;                       //storing reminder
      s = s + (r * r * r );
      n = n / 10;
    }
  if (dummy == s)                        // comparing original and processed result 
  {
    printf ("%d is a armstrong  number ",dummy);
  }
  else
  {
    printf ("%d is not armstrong number",dummy);
  }
  return 0;
}
