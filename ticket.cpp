#include <stdio.h>
#include <unistd.h>
#include <time.h> // For simulating time-based prediction

int main() 
{
    int a,travel_class,n;
    float tp=0;
    int available_tickets=10;  // Set a limit for available tickets for each route
    int wl=0;  // Track the number of people waiting for tickets
    int bt=0;  // Track booked tickets

    // AI-like feature: Adjust ticket availability based on time of the day
    time_t t;
    struct tm *time_info;
    time(&t);
    time_info=localtime(&t);
    
    // Predictive availability: assume higher demand during specific times (e.g., 8 AM - 10 AM)
    int h=time_info->tm_hour;
    if (h>=8&&h<=10) 
	{
        available_tickets=5; // Simulating higher demand (less tickets available)
        printf("AI Prediction: Higher demand expected during this time (8 AM - 10 AM). Limited tickets are available.\n");
    } 
	else 
	{
        available_tickets=10; // Normal availability
    }

    printf("Welcome to the Train Booking System\n");
    printf("Select a route:\n");
    printf("1. Route A (City A to City B)\n");
    printf("2. Route B (City B to City C)\n");
    printf("3. Route C (City C to City A)\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &a);

    printf("....Please wait....\n");
    sleep(2);
    
    if (a<1||a>3) 
	{
        printf("Invalid route selected! Please choose a valid route (1, 2, or 3).\n");
        return 0;
    }

    printf("\nSelect travel class:\n");
    printf("1. First class\n");
    printf("2. Second class\n");
    printf("3. Sleeper class\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &travel_class);

    printf("....Please wait....\n");
    sleep(2);
    
    if (travel_class<1||travel_class>3) 
	{
        printf("Invalid class selected! Please choose a valid class (1, 2, or 3).\n");
        return 1;
    }

    printf("\nEnter the number of tickets: ");
    scanf("%d", &n);

    printf("....Please wait....\n");
    sleep(2);

    // Setting ticket prices based on route and class
    if(a==1) 
	{
        if (travel_class==1) 
		tp=1000.0;
        else if (travel_class==2) 
		tp=760.0;
        else if (travel_class==3) 
		tp=430.0;
    }
	 else if(a==2)
	 {
        if (travel_class==1) 
		tp=620.0;
        else if (travel_class==2) 
		tp=475.0;
        else if (travel_class==3) 
		tp=240.0;
    } 
	else if (a == 3) 
	{
        if (travel_class==1) 
		tp=550.0;
        else if (travel_class==2)
		tp=370.0;
        else if (travel_class==3)
		tp=135.0;
    }

    // Check ticket availability and handle waiting list
    if (n<=available_tickets) 
	{
        available_tickets=available_tickets-n; // Update available tickets
        bt=bt+n; // Update booked tickets
        tp*=n; // Calculate total cost

        printf("\nTicket booking details:\n");
        printf("Route: ");
        if (a==1) printf("City A to City B\n");
        else if (a ==2)printf("City B to City C\n");
        else if (a==3)printf("City C to City A\n");

        printf("Class: ");
        if (travel_class==1) printf("First class\n");
        else if (travel_class==2) printf("Second class\n");
        else if (travel_class==3) printf("Sleeper class\n");

        printf("Number of tickets: %d\n",n);
        printf("Total cost: %.2f\n",tp);
        printf("Remaining tickets: %d\n",available_tickets);
        
    } 
	else 
	{
        wl=wl+n;
        printf("Not enough tickets available. You have been added to the waiting list.\n");
        printf("Currently available tickets: %d\n",available_tickets);
        printf("You are on the waiting list with %d other passengers.\n",wl);
    }

    return 0;
}

