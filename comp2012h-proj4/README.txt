/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name: LIU Qinhan  SID: 20328953 Email: qliuan@connect.ust.hk         
Login:            
Hours to complete assignment (optional):
    
    25

/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
    To implement brute force, I used for loops with depth of 4 to examine every
possible 4 points as a group.
    In the Point class, I chose to store the location informations in a 
structure named "Point" and constructed a corresponding manipulating class called 
"Points" to realise operations on "Point"s.
    In "Point" structure, "x" and "y" record horizontal and vertical locations 
respectively.
    In "Points" class, addPoint() and returnPoints() methods are implemented which 
work exactly as what they were named.


/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
    I selected to sort by the slope, and in "Point" structure "<" & "==" operators 
were overloaded for comparing the angles that two "Point"s form with respect to the 
reference Point. A static Point pointer "ref" was added to "Point" to store the 
reference Point.
    In order to find the minimal representation, firstly I find all possibilities that 
several points lies on the same line segment and then delete those ones not with longest
length. All detailed steps are breifly commented in the source file.


/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N     brute(sec)   sorting(sec)
------------------------------------
     10         0             0            
     20         0             0            
     40         0             0            
     80        0.01           0        
    100        0.02           0          
    150        0.07           0          
    200        0.24         0.01          
    400        3.79         0.04           
   1000        148          0.15                           
   2000        N/A          0.58                  
   4000        N/A          2.60               
  10000        N/A                            


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute:  10^20 sec
Sorting: 2*10^6 sec

/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Brute:    O(N^4) 
        Because there is a for loop with depth of 4 which is critical for the 
      whole computing process.

Sorting:  O(N^3)
        There is an iteration through all points which takes O(N) time and an 
      inside sorting process for remaining points which takes O(N^2) for the 
      worst case. This is the overall critical process.

/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
  For Brute method, if there are a line segment with N (N>4) points on it,
then totally C(N,4) different representations would be printed out. 

/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
  Chen Lian helped me in coding up the UI designing. We discussed about which
kind of classes and functions should be implemented in PointPlotter and done 
a lot web searching.
  

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
  There was a segmentation fault when I attempted to test 10000 points, however,
this would not happen in all tests with input less than 4000. Firstly I thought
that there must be an mis-accessing inside the loop, so I printed out "Enter i" 
and "Exit" every time it loops for the outer most loop which iterate through all 
points. Something really odd happened, the error was reported after one "Exit" 
and before next "Enter i" with i varies hugely between 67 to 7572.
  When I did further investment, something even more strange happened. When I 
tried 5000 points, it reported error, then I tried one more time, it worked 
perfectly! After that, I moved on to 6000 points, error was reported multiple 
times, then I return to 5000, it would not work again!
  Right now what troubles me most is that how come inputing less than 4000 
points everything is good, even in the test of 6 or 8 points? 



/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/

