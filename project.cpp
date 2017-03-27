#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846
using namespace std;

/*		COLOR CODES
		FG_RED      = 31,
		FG_GREEN    = 32,
		FG_BLUE     = 34,
		FG_DEFAULT  = 39,
		BG_RED      = 41,
		BG_GREEN    = 42,
		BG_BLUE     = 44,
		BG_DEFAULT  = 49
 */
/* COLOR CODES 
   \033[0;44m0\033[0m . MY_VEHICLE
   \033[0;47m0\033[0m. No Vehicle
   \033[0;42m0\033[0m. Vehicle
   \033[0;41m0\033[0m. Vehicle [More Danger]
   \033[0;45m0\033[0m. Vehicle [Less Danger]
   \033[0;43m0\033[0m. Vehicle in Opposite Direction	
 */

/*********************************************************************************************************/
/******************DISTANCE BETWEEN TWO  POINTS (Given the latitude/longitude of those points)************/
/*********************************************************************************************************/
double deg2rad(double);
double rad2deg(double);
double distance(double lat1, double lon1, double lat2, double lon2) {
	double theta, dist;
	theta = lon1 - lon2;
	dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
	dist = acos(dist);
	dist = rad2deg(dist);
	dist = dist * 60 * 1.1515;
	dist = dist * 1.609344;
	return (dist);
}
double deg2rad(double deg) {
	return (deg * pi / 180);
}
double rad2deg(double rad) {
	return (rad * 180 / pi);
}

/*********************************************************************************************************/
/*********************************************************************************************************/
int count=1;

struct vehicle
{
	double lat,lon,speed,dis;
	char dir[10];
	int lane;
	int i,j;
	int count;
}MY_VEHICLE,Vehicle[25];
const char *Array[][3]=
{
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},
	{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"},{"\033[0;47m0\033[0m","\033[0;47m0\033[0m","\033[0;47m0\033[0m"}
};
char message1[200],message2[200],message3[200];
int print(char *not1,char *not2,char *not3)
{

	printf("********LANE-1************LANE-2************LANE-3********************************************************************\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[0][0],Array[0][1],Array[0][2]);
	printf(" |                 |                 |                 |                             _____________________________\n");
	printf(" |                 |                 |                 |                            |Scale: 1 unit      = 1   km  |\n");
	printf(" |        %s        |        %s        |        %s        |                            |       1 iteration = 120kmph |\n",Array[1][0],Array[1][1],Array[1][2]);
	printf(" |                 |                 |                 |                            |_____________________________|\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[2][0],Array[2][1],Array[2][2]);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |         Notifications:\n",Array[3][0],Array[3][1],Array[3][2]);
	printf(" |                 |                 |                 |         1.%s\n",not1);
	printf(" |                 |                 |                 |         2.%s\n",not2);
	printf(" |        %s        |        %s        |        %s        |         3.%s\n",Array[4][0],Array[4][1],Array[4][2],not3);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[5][0],Array[5][1],Array[5][2]);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[6][0],Array[6][1],Array[6][2]);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[7][0],Array[7][1],Array[7][2]);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[8][0],Array[8][1],Array[8][2]);
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |         Note:\n",Array[9][0],Array[9][1],Array[9][2]);
	printf(" |                 |                 |                 |         \033[0;44m0\033[0m. MY_VEHICLE\n");
	printf(" |                 |                 |                 |         \033[0;47m0\033[0m. No Vehicle\n");
	printf(" |        %s        |        %s        |        %s        |         \033[0;42m0\033[0m. Vehicle\n",Array[10][0],Array[10][1],Array[10][2]);
	printf(" |                 |                 |                 |         \033[0;41m0\033[0m. Vehicle [More Danger]\n");
	printf(" |                 |                 |                 |         \033[0;45m0\033[0m. Vehicle [Less Danger]\n");
	printf(" |        %s        |        %s        |        %s        |         \033[0;43m0\033[0m. Vehicle in Opposite Direction\n",Array[11][0],Array[11][1],Array[11][2]);	
	printf(" |                 |                 |                 |\n");
	printf(" |                 |                 |                 |\n");
	printf(" |        %s        |        %s        |        %s        |\n",Array[12][0],Array[12][1],Array[12][2]);	

}
int delay()
{
	long long int k=999999999;
	while(k--);

}
char *update_alerts()
{
	strcpy(message1,"\033[1;32mGo Slow\033[0m");
	strcpy(message2,"Maintain Constant Speed");
	strcpy(message3,"White Swift infront of you is going fast"); 
}

int update1(int i , int j)
{

	Array[i-1][j]="\033[0;44m0\033[0m";
	Array[i][j]="\033[0;47m0\033[0m";
}
int update(int i , int j)
{

	Array[i-1][j]="\033[0;42m0\033[0m";
	Array[i][j]="\033[0;47m0\033[0m";
}
int main()
{
	double lat,lon,speed,lat1,lon1,speed1;
	FILE * input;
	char dir[2],dir1[2],temp1[20],temp2[20],temp3[20],temp4[20],temp5[20];
	int lane,lane1;


	//while(1)
	{
		//	Array[1][0]="\033[0;43m0\033[0m";
		strcpy(dir,"hi");

		input = fopen ("vehicles_data","r");
		fscanf (input,"%s %s %s %s %s",temp1,temp2,temp3,temp4,temp5);
		fscanf (input,"%lf %lf %lf %s %d",&lat,&lon,&speed,dir,&lane);
		MY_VEHICLE.lat=lat;
		MY_VEHICLE.lon=lon;
		MY_VEHICLE.speed=speed;
		strcpy(MY_VEHICLE.dir,dir);
		MY_VEHICLE.lane=lane;
		MY_VEHICLE.j=lane-1;
		MY_VEHICLE.i=6;
		Array[MY_VEHICLE.i][MY_VEHICLE.j]= "\033[0;44m0\033[0m" ;

		printf("\n%s %s %s %s %s\n\n",temp1,temp2,temp3,temp4,temp5 );
		count=1;
		while(1)
		{
			lon1=lon;lat1=lat;speed1=speed;strcpy(dir1,dir);lane1=lane;
			fscanf (input,"%lf %lf %lf %s %d",&lat,&lon,&speed,dir,&lane);
			Vehicle[count].lat=lat;
			Vehicle[count].lon=lon;
			Vehicle[count].speed=speed;
			strcpy(Vehicle[count].dir,dir);
			Vehicle[count].lane=lane;
			Vehicle[count].j=lane-1;
			Vehicle[count].dis=distance(MY_VEHICLE.lat,MY_VEHICLE.lon,Vehicle[count].lat, Vehicle[count].lon);
			if(MY_VEHICLE.lon > Vehicle[count].lon)
			{
				if(Vehicle[count].dis < 2)
				{
					Vehicle[count].i=MY_VEHICLE.i+1;
				}
				else if(Vehicle[count].dis < 3)
				{
					Vehicle[count].i=MY_VEHICLE.i+2;
				}
				else if(Vehicle[count].dis < 4)
				{
					Vehicle[count].i=MY_VEHICLE.i+3;
				}
				else if(Vehicle[count].dis < 5)
				{
					Vehicle[count].i=MY_VEHICLE.i+4;
				}
				else if(Vehicle[count].dis < 6)
				{
					Vehicle[count].i=MY_VEHICLE.i+5;
				}
			}
			else
			{

				if(Vehicle[count].dis < 2)
				{
					Vehicle[count].i = MY_VEHICLE.i-1;
				}
				else if(Vehicle[count].dis < 3)
				{
					Vehicle[count].i = MY_VEHICLE.i-2;
				}
				else if(Vehicle[count].dis < 4)
				{
					Vehicle[count].i = MY_VEHICLE.i-3;
				}
				else if(Vehicle[count].dis < 5)
				{
					Vehicle[count].i = MY_VEHICLE.i-4;
				}
				else if(Vehicle[count].dis < 6)
				{
					Vehicle[count].i = MY_VEHICLE.i-5;
				}


			}
			Array[Vehicle[count].i][Vehicle[count].j]="\033[0;42m0\033[0m";
			count++;
			//	printf("%lf %lf %lf %s %d\n",lat,lon,speed,dir,lane);
			if(lon1==lon && lat1==lat && speed1==speed && !(strcmp(dir1,dir)) && lane1==lane)break;
		}
		fclose(input);
		int spd=180;
		//int i,j;
		printf("MY_VEHICLE->  %lf %lf %lf %s %d\n\n",MY_VEHICLE.lat,MY_VEHICLE.lon,MY_VEHICLE.speed,MY_VEHICLE.dir,MY_VEHICLE	.lane);

		for (int i = 1; i < count-1; i++)
		{
			/* code */

			printf("Vehicle[%d]->  %lf %lf %lf %s %d Distance=%0.2lfkm\n",i,Vehicle[i].lat,Vehicle[i].lon,Vehicle[i].speed,Vehicle[i].dir,Vehicle[i].lane, distance(MY_VEHICLE.lat,MY_VEHICLE.lon,Vehicle[i].lat, Vehicle[i].lon));
		}
		printf("\n");

		//Vehicle[i].count=0;

		for (int i = 1; i < count-1; i++)
		{
			if(Vehicle[i].speed>=160){
				Vehicle[i].count=1;
			}
			else if(Vehicle[i].speed>=120){
				Vehicle[i].count=2;
			}
			else if(Vehicle[i].speed>=80){
				Vehicle[i].count=3;
			}
			else if(Vehicle[i].speed>=60){
				Vehicle[i].count=4;
			}
			else if(Vehicle[i].speed>=30){
				Vehicle[i].count=5;
			}
		}

		if(MY_VEHICLE.speed>=160){
			MY_VEHICLE.count=1;
		}
		else if(MY_VEHICLE.speed>=120){
			MY_VEHICLE.count=2;
		}
		else if(MY_VEHICLE.speed>=80){
			MY_VEHICLE.count=3;
		}
		else if(MY_VEHICLE.speed>=60){
			MY_VEHICLE.count=4;
		}
		else if(MY_VEHICLE.speed>=30){
			MY_VEHICLE.count=5;
		}


		update_alerts();
		while(1)
		{
			print(message1,message2,message3);
			delay();
			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1||Vehicle[i].count==2||Vehicle[i].count==3||Vehicle[i].count==4||Vehicle[i].count==5)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}	
			if (MY_VEHICLE.count==1||MY_VEHICLE.count==2||MY_VEHICLE.count==3||MY_VEHICLE.count==4||MY_VEHICLE.count==5)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}

			print(message1,message2,message3);
			delay();

			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}	
			if (MY_VEHICLE.count==1)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}
			print(message1,message2,message3);
			delay();

			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1||Vehicle[i].count==2)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}
			if (MY_VEHICLE.count==1||MY_VEHICLE.count==2)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}	
			print(message1,message2,message3);
			delay();


			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1||Vehicle[i].count==3)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}	
			if (MY_VEHICLE.count==1||MY_VEHICLE.count==3)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}
			print(message1,message2,message3);
			delay();

			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1||Vehicle[i].count==2||Vehicle[i].count==4)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}	
			if (MY_VEHICLE.count==1||MY_VEHICLE.count==2||MY_VEHICLE.count==4)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}
			print(message1,message2,message3);
			delay();

			for (int i = 1; i < count-1; i++)
			{
				if (Vehicle[i].count==1||Vehicle[i].count==5)
				{
					update(Vehicle[i].i,Vehicle[i].j);
					if(Vehicle[i].i)
						Vehicle[i].i--;
					else Vehicle[i].i=12;
				}
			}	
			if (MY_VEHICLE.count==1||MY_VEHICLE.count==5)
			{
				update1(MY_VEHICLE.i,MY_VEHICLE.j);
				if(MY_VEHICLE.i)
					MY_VEHICLE.i--;
				else MY_VEHICLE.i=12;
			}

			print(message1,message2,message3);
			delay();

		}























	}

}
