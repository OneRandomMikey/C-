
#include <iostream>
using std::cout; using std::endl; using std::cin;
int main(){
	long days;
	cout<<"Insert number of days: ";
	cin>> days;
	double dist_per_day=1471132.8;
	double total_dist_km=days * dist_per_day+19481000000;
	double total_dist_mi=total_dist_km*0.621371;
	double total_dist_au=total_dist_km/1479597871;
	double round_trip=(total_dist_km*1000)/299792458/60/60*2;
	
	cout<<"Total distance:"<<endl<<total_dist_km<<" KM"<<endl<<total_dist_mi<<" MI"<<endl
	<<total_dist_au<<" AU"<<endl<<"Round trip for radio comm: "<<round_trip<<" HRS"<<endl;
	return 0;
	}


