#include "point.h"

bool turnLeft(Point a, Point b, Point c);
bool turnRight(Point a, Point b, Point c);
void insertionSort(Point list[], int n);
void findHull(Point P[], int k, Point Hull[], int &nHull);
bool isInsideHull(Point P, Point H[], int k);

int main()
{   

    int c, r, o;

    Point cops[100];

cin >> c >> r >> o;

    for ( int i = 0; i < c; i++)
    {
        cin >> cops[i];
    }

Point copsHull[100];
int nHull1;

    findHull(cops, c, copsHull, nHull1);

    Point robbers[100];

    for ( int i = 0; i < r; i++)
    {
        cin >> robbers[i];
    }

Point robbersHull[100];
int nHull2;

    findHull(robbers, r, robbersHull, nHull2);

    Point others;

    int
        s,
        t,
        d;

    for ( int i = 0; i < o; i++)
    {
        cin >> others;

        if (isInsideHull(others, copsHull, nHull1) == true)
        {
            s++;
        }

        else if (isInsideHull(others, robbersHull, nHull2) == true)
        {
            t++;
        }

        else
        {
            d++;
        }
    }

    cout << "Safe:      " << s << endl;
    cout << "Robbed:    " << t << endl;
    cout << "In Danger: " << d << endl;


    return 0;
}

bool turnRight(Point a, Point b, Point c)
{
    return ((b - a)*(c - a) < 0);
}

bool turnLeft(Point a, Point b, Point c)
{
    return ((b - a)*(c - a) > 0);
}

void insertionSort(Point list[], int n)
{
    int 
        i,
        s;
    
    Point
        tmp;

    for ( s = 1; s < n; s++)
    {
        tmp = list[s];
        for ( i = s - 1; i >= 0 && list[i].getx() > tmp.getx() 
        || (list[i].getx() == tmp.getx() 
        && list[i].gety() > tmp.gety()); i--)
        {
            list[ i + 1 ] = list[i];
        }
        list[ i + 1 ] = tmp;
    }


}

void findHull(Point P[], int k, Point Hull[], int &nHull)
// procedure FINDHULL(Point P[], int k)
{
    // Sort p by x-coordinate

    insertionSort(P, k);

    // lower[0] <- p(0)
    // t <- 0
    Point lower[100];
    lower[0] =  P[0];
    int t = 0;

    // for i <- 1 to k - 1 do
    //      while t > 0 and lower[ t - 1 ] -> lower[t] -> p(i) does not
    //      turn left do
    //          t <- t - 1
    //      end while
    
    //      t <- t + 1
    //      lower[t] <- p(i)
    // end for

    for (int i = 1; i < k; i++)
    {
        while ( t > 0 && turnLeft(lower[t-1], lower[t], P[i] ) == false )
        {
            t = t - 1;
        }

        t = t + 1;
        lower[t] = P[i];
    }

    // upper[0] <- p( k - 1 )
    // u <- 0
    Point upper[100];
    upper[0] = P[ k - 1 ];
    int u = 0;

    // for i <- k - 2 downto 0 do
    //      while u > 0 and upper[ u - 1 ] -> upper[u] -> p(i) does not
    //      turn left do
    //          u <- u - 1
    //      end while

    //      u <- u + 1
    //      upper[u] <- p(i)
    // end for

    for (int i = k - 2; i >= 0; i--)
    {
        while ( u > 0 && turnLeft(upper[u-1], upper[u], P[i]) == false )
        {
            u = u - 1;
        }

        u = u + 1;
        upper[u] = P[i];
    }

    // return lower[0], lower[1], ... , lower[t-1], upper[0], upper[1],
    // ... , upper[u-1]

    nHull = 0;

    for (int i = 0; i < t; i++)
    {
        Hull[nHull] = lower[i];
        nHull++;
    }

    for (int i = 0; i < u; i++)
    {
        Hull[nHull] = upper[i];
        nHull++;
    }

// end procedure
}

bool isInsideHull(Point P, Point H[], int k)
// procedure isInsideHull(Point P, Point H[], int k)
{
    // for i <- 0 to k - 1 do
    //      j <- (i + 1) mod k
    //      if P -> h(i) -> h(j) turns right then
    //          return false
    //      end if
    // end for

    for (int i = 0; i < k; i++)
    {
        int j = ( i + 1 ) % k;
        
        if ( turnRight(P, H[i], H[j]) )
        {
            return false;
        }
    }

    // return true

    return true;

// end procedure    
}