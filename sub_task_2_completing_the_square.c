#include <stdio.h>
#include <math.h>

// ax^2 + bx + c = 0

int a, b, c;
double newa, newb, newc, d, e, f, right_side, root1, root2;

void print_output(int); // output function

int main() {

  printf("COMPLETING THE SQUARE\n");
  //get the values
  printf("\nEnter A !=0 :");
  scanf("%d", & a);

  if (a<=0)// check if a is invalid
  {
	printf("\nA must be more than 0!");
	return 0;
  }  

  printf("\nEnter B:");
  scanf("%d", & b);

  printf("\nEnter C:");
  scanf("%d", & c);

  if (a == 1) {
    // when c is moved to rhs its polarity changes, we do this by *-1 since +*+=+, +*-=- ,-*-=+
    d = c * -1;

    // half of b squared
    e = pow(b / 2, 2);
    right_side = d + e;

    //half b
    f = b / 2;

    // + and - roots
    root1 = sqrt(right_side) - f;
    root2 = -sqrt(right_side) - f;

    // JUST PRINTING DOWN BELOW
    print_output(a);

  } else if (a > 1) {
    // since a is more than 1 we divide everything by a
    newa = (double) a / (double) a;
    newb = (double) b / (double) a;
    newc = (double) c / (double) a;

    // when c is moved to rhs its polarity changes, we do this by *-1 since +*+=+, +*-=- ,-*-=+
    d = newc * -1;
    // half of b squared
    e = pow(newb / 2, 2);

    // calc rhs value 
    right_side = d + e;

    //half b
    f = newb / 2;

    // + and - roots
    root1 = sqrt(right_side) - f;
    root2 = -sqrt(right_side) - f;

    // JUST PRINTING DOWN BELOW
    print_output(a);

  } 

  return 0;
}

void print_output(int val_a) {

  // JUST PRINTING DOWN BELOW
  printf("\n(%d)x^2 + (%d)x + (%d) = 0\n\n", a, b, c);

  printf("Move constant to the RHS -->");
  printf("\n(%d)x^2 + (%d)x + __ = (%d)\n", a, b, c * -1);

  if (val_a > 1) {
    printf("\nA != 1, so divide by A, %d", a);
    printf("\n(%d/a)x^2 + (%d/a)x + __ = (%d/a)\n\n", a, b, c * -1);
  }

  printf("Take half of b, square it, then add to both sides\n");
  printf("(%d)x^2 + (%d)x +  __  = (%0.2f)\n", a, b, d);
  printf("(%d)x^2 + (%d)x + (%0.2f) = (%0.2f) + (%0.2f)\n\n", a, b, e, d, e);

  printf("Rewrite the LHS as a perfect square\n");
  printf("((%dx + (%0.2f))^2 = (%0.2f)\n\n", a, f, (right_side));

  printf("Take the square root of both sides\n");
  printf("sqrt (((%dx + (%0.2f))^2) = sqrt (%0.2f)\n\n", a, f, (right_side));

  printf("Isolate and solve for X\n");
  printf("(%d)x + (%0.2f) = +- (%0.2f)\n\n", a, f, sqrt(right_side));
  printf("(%d)x = + (%0.2f) - (%.2f)\n\n", a, sqrt(right_side), f);
  printf("(%d)x = - (%0.2f) - (%.2f)\n\n", a, sqrt(right_side), f);

  printf("First root is: %0.2f\n\n", root1);
  printf("Second root is: %0.2f\n\n", root2);

}
