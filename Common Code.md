# Some common C++ code that I wish I knew at times :persevere:

-   Setting output field width to x 
    -   cout<<setw(x)<<str;
-   Limiting output to x decimal points
    -   cout<<fixed<<showpoint<<setprecision(x)<<real;
-   Rounding a double to the nearest integer
    -   real = double(int(real+0.5));
-   Rounding a double to the nearest x decimal place
    -   real = double(int(real*pow(10,x)+0.5));
