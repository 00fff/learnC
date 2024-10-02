/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) // do nothing if array contains fewer than two elements
        return;

    // Move the partition element to v[left]
    swap(v, left, (left + right) / 2);
    last = left;

    // Partition the array
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    // Restore partition element
    swap(v, left, last);

    // Recursively sort the two parts
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

// swap: interchange v[i] and v[j]
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Exercise 5-7: Rewrite readlines to store lines in an array supplied by main.
// How much faster is the program?

/*
 * Multi-dimensional Arrays in C:
 * C provides rectangular multi-dimensional arrays, though arrays of pointers are more commonly used.
 * Example: Date conversion from day of the month to day of the year and vice versa.
 */

// Two-dimensional array holding the number of days in each month
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Non-leap year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Leap year
};

/* day_of_year: Convert month and day to the day of the year */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    // Check for valid year and month
    if (year < 1) {
        return 0; // Invalid year
    } 
    if (month > 12 || month < 1) {
        return 0; // Invalid month
    }

    // Determine if it's a leap year
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // Pointer to the days in the selected year type
    char *dayptr = daytab[leap]; // Point to the correct row of daytab

    // Add days for previous months
    for (i = 1; i < month; i++) {
        day += *(dayptr + i); // Use pointer arithmetic to access days
    }

    return day; // Return the total day of the year
}


/* month_day: Convert day of the year to month and day */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    // Determine if it's a leap year
    if (year < 1) {
        return 0;
    } else if (*pmonth > 12 || *pmonth < 1)
    {
        return 0;
    }
    
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int *daytabptr = daytab[leap]; 
    // Determine the month and day by subtracting month days
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}
