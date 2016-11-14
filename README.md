# K-Map
this is source code to a program in C that solve a four variable K-Map problem and return the optimal solution in sum of product(SOP) form
this is a highschool project so don't expect much

##Compilation
to compile this you need a gcc compiler
`gcc k-map.c -o k-map`

##Running
to execite this program after compilation type this in terminal/console/command promt (in the same folder where compiled)
`./k-map`

##Demo

                         K-Map Minimizer by- Zeeshan Khan
              
        Enter the number of min terms: 4


        Enter the number of don't care terms: 2

        Enter all the min terms with a single spaces between them..

        F( A,B,C,D ) = 1 5 9 14

        Enter all the don't care terms with a single spaces between them..

        d( A,B,C,D ) = 3 2


        K-map created...Successfully


                   C'D'    C'D     CD      CD'

        A'B'       0       1       x       x

        A'B        0       1       0       0

        AB         0       0       0       1

        AB'        0       1       0       0


                 Y = A'C'D + B'C'D + ABCD' +

        Program Ended

        To Restart Program press 1 and hit Enter

        To Exit press 0 and hit Enter
        0
        
##To-Dos
  * create executable.
  * translate in JS for webapps
  * create a webapp
