//composition relationship between vehicle route and vehicle
#include<iostream>
using namespace std;
class vehicleroute
{
	private:
		int routeID;
	public:
		vehicleroute(int no);
		void display();
		~vehicleroute();
};
class vehicle
{
	private:
		vehicleroute*route;
	public:
		vehicle(int no1);
		void displayroutes();
		~vehicle();	
};
vehicleroute::vehicleroute(int no){
	routeID=no;
}
void vehicleroute::display(){
	cout<<"route ID"<<routeID<<endl;
}
vehicleroute::~vehicleroute(){
	cout<<"delete"<<routeID<<endl;
}
vehicle::vehicle(int no1)
{
	route=new vehicleroute(no1);
}
void vehicle::displayroutes()
{
	route->display();
}
vehicle::~vehicle()
{
	cout<<"delete vehicle"<<endl;
	delete route;
}
int main()
{
	vehicle*myvehicle;
	myvehicle=new vehicle(400);
	myvehicle->displayroutes();
	delete myvehicle;
	return 0;
}

//composition relationship between renter and vehicle
//extracted renter class from inheritance relationship of user(IT21487484)
#include<iostream>
using namespace std;
#include<cstring>
class Renter
{
	private:
		int RID;
		int vehicleNo;
		char VehicleDetails[];
	public:
		Renter();
		Renter(char pName[], char pEmail[], char pNIC[], int pBankAccountNo, int pContactNo, char pAddress[]);
		void setDetails(int pRID,  char pdes[]);
		void setVehicleNo(int pVehNo);
		int getVehicleNo();
		void display();
};
class vehicle
{
	private:
		Renter*rental;
	public:
		vehicle(int no1);
		void displayVehicleNo();
		~vehicle();	
};
Renter::Renter()
{
	RID = 0;
	vehicleNo = 0;
	strcpy(VehicleDetails,"");
}

Renter::Renter(char pName[], char pEmail[], char pNIC[], int pBankAccountNo, int pContactNo, char pAddress[])
{
	
}
 void Renter::setVehicleNo(int pVehNo)
{
	vehicleNo = pVehNo;
}
int Renter::getVehicleNo()
{
	return vehicleNo;
}
void Renter::display()
{
	cout<<"display vehicle"<<vehicleNo<<endl;
}
vehicle::vehicle(int no1)
{
	rental=new Renter();
	
}
void vehicle::displayVehicleNo()
{
	rental->display();
}
vehicle::~vehicle()
{
	cout<<"delete vehicle"<<endl;
	delete rental;
}
int main()
{
	vehicle*myrent;
	myrent=new vehicle(0);
	myrent->displayVehicleNo();
	delete myrent;
	return 0;
}





