#define _CRT_SECURE_NO_WARNINGS // Windows doesn't like localtime deems unsafe, but in this usecase the user has no interaction with anything that would incur this warning
#include<string>
#include <iostream>
#include<vector>
#include<time.h>
using namespace std;
class Handler;

//Validation functions
bool stringValidation(string a) // Validates a string input
{
	bool isString = true;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z' || a[i] == ' ') {}
		else { isString = false; }
	}
	return isString;
}
bool floatValidation(string a) //Valdiates a float input
{
	bool isFloat = true;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9' || a[i] == '.') {}
		else { isFloat = false; }
	}
	return isFloat;
}
bool intValidation(string a) //Validates an input as being an int
{
	bool isInt = true;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9') {}
		else { isInt = false; }
	}
	return isInt;
}

//Classes
//Functions for the MOT
class MOT
{
public:
	bool getIsPassed() { return isPassed; }
	bool getSteering() { return steering; }
	bool getSuspension() { return suspension; }
	bool getBreaks() { return breaks; }
	bool getWheels() { return wheels; }
	bool getLights() { return lights; }
	bool getEmissions() { return emissions; }
	bool getBooked() { return booked; }
	bool getPreformed() { return motPreformed; }
	MOT getMOTDetails() //Returns all details of the MOT
	{
		MOT m;
		m.breaks = breaks;
		m.wheels = wheels;
		m.emissions = emissions;
		m.suspension = suspension;
		m.lights = lights;
		m.steering = steering;
		m.isPassed = isPassed;
		m.timeinfo = timeinfo;
		m.motHeld = motHeld;
		m.booked = booked;
		m.motPreformed = motPreformed;
		return m;
	}
	void setMOT() //Sets MOT regarding several boolean questions and then displays a pass or fail
	{
		string thisInput;

		do
		{
			cout << "Pass steering? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		steering = (thisInput == "Y") ? true : false;

		do
		{
			cout << "Pass wheels? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		wheels = (thisInput == "Y") ? true : false;

		do
		{
			cout << "Pass breaks? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		breaks = (thisInput == "Y") ? true : false;

		do
		{
			cout << "Pass suspension? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		suspension = (thisInput == "Y") ? true : false;

		do
		{
			cout << "Pass lights? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		lights = (thisInput == "Y") ? true : false;

		do
		{
			cout << "Pass emissions? Y/N" << endl;
			cin >> thisInput;
		} while (thisInput != "Y" && thisInput != "N");
		emissions = (thisInput == "Y") ? true : false;

		isPassed = (steering && suspension && breaks && wheels && lights && emissions) ? true : false;
		if (isPassed)
		{
			cout << "MOT passed" << endl;
		}
		else
		{
			cout << "MOT failed" << endl;
		}
		motPreformed = true;
		time_t rawtime;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
	}

private:
	bool isPassed, steering, suspension, breaks, wheels, lights, emissions;
	bool booked = false;
	bool motHeld = false;
	bool motPreformed = false;
	struct tm* timeinfo;

};

//Function for the dateAvailability
class dateAvailability
{
public:

	//Gets all variables 
	string getDay() { return day; }
	string getMonth() { return month; }
	string getYear() { return year; }
	string getTime() { return time; }
	string getDate() { return date; }
	string getHour() { return hour; }
	string getMin() { return min; }


	//Functions to set varibles 
	void setDay(string d) { day = d; }
	void setMonth(string m) { month = m; }
	void setYear(string y) { year = y; }
	void setHour(string h) { hour = h; }
	void setMin(string m) { min = m; }


	void setDate(string d, string m, string y)
	{
		date = d + "/" + m + "/" + y;
	}
	void setTime(string h, string m)
	{
		time = h + ":" + m;
	}


private:
	string date;
	string day;
	string month;
	string year;
	string time;
	string hour;
	string min;


};

//Class for the customer
class Customer
{
public:
	//Creates new customer
	Customer newCustomer()
	{
		Customer c;
		string thisInput;
		customerNo += 1;
		do
		{
			cout << "Enter name:\n "; //Gets users first and last name
			cin.ignore();
			getline(cin, thisInput);
		} while (!stringValidation(thisInput));
		c.name = thisInput;

		do
		{
			cout << "Enter phone number: " << endl;
			cin >> thisInput;
		} while (!intValidation(thisInput));
		c.phoneNumber = thisInput;

		do
		{
			cout << "Enter house number: " << endl;
			cin >> thisInput;
		} while (!intValidation(thisInput));
		c.fistLine = thisInput;

		do
		{
			cout << "Enter post code: " << endl;
			cin >> thisInput;
		} while (thisInput.size() != 7);
		c.postCode = thisInput;
		return c;
	}
	
	//Gets all variables
	string getName() { return name; }
	string getPhoneNumber() { return phoneNumber; }
	string getFirstLine() { return fistLine; }
	string getPostCode() { return postCode; }
	int getCustomrNumber() { return customerNo; }

private:
	int customerNo;
	string name;
	string phoneNumber;
	string fistLine;
	string postCode;
};	//Customer class end

//Class for the vehicles
class Vehicle
{
public:
	//Creates a new vehcile with type, fuel, make, model, and wheel count
	void createVehicle(vector<Vehicle>& vehicles)
	{
		string thisInput;
		bool isVehicleSelected = false;
		do
		{
			cout << "Please enter the registration plate: " << endl; //Gets reg for the car
			cin >> thisInput;
		} while (thisInput.size() != 7);
		reg = thisInput;

		if (vehicles.size() > 0)
		{
			do
			{
				for (size_t i = 0; i < vehicles.size(); i++)	
				{
					Vehicle v = vehicles[i];
					cout << "[ " << i + 1 << " ]" << endl
						<< "Make: " << v.getMake() << endl
						<< "Model : " << v.getModel() << endl
						<< "Fuel Type: " << v.getFuelType() << endl
						<< "Wheel count: " << v.getWheels() << endl;
				}
				cout << "IF vehicle not found please enter NO" << endl;
				cin >> thisInput;
			} while (!intValidation(thisInput) && thisInput != "NO");
			if (thisInput != "NO")
			{
				isVehicleSelected = true;
				Vehicle v = vehicles[stoi(thisInput) - 1];
				make = v.getMake();
				model = v.getModel();
				fuelType = v.getFuelType();
				vehicleType = v.getVehicleType();
				wheels = v.getWheels();
			}
			else {}
		}
		if (!isVehicleSelected)
		{
			int input;
			do
			{
				//Determines the vehicle type
				cout << "Select vehicle type: " << endl;
				cout << "[1] Car\n[2] Van\n[3] MoterBike\n[4] HGV" << endl;
				cin >> input;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					input = -1;
				}
			} while (input > 5 || input < 0);
			int intThisInput = input;
			switch (intThisInput)
			{
			case 1:
				vehicleType = "Car";
				break;
			case 2:
				vehicleType = "Van";
				break;
			case 3:
				vehicleType = "MoterBike";
				break;
			case 4:
				vehicleType = "HGV";
				break;
			default:
				break;
			}
			//determines the fuel type
			do
			{
				cout << "Select fuel type: " << endl;
				cout << "[1] Petrol\n[2] Diseal\n[3] Hybrid\n[4] Electric" << endl;
				cin >> input;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
					input = -1;
				}
			} while (input > 5 || input < 0);
			intThisInput = input;
			switch (intThisInput)
			{
			case 1:
				fuelType = "Petrol";
				break;
			case 2:
				fuelType = "Diseal";
				break;
			case 3:
				fuelType = "Hybrid";
				break;
			case 4:
				fuelType = "Electric";
				break;
			default:
				break;
			}

			do
			{
				cout << "Enter make: " << endl;
				cin >> thisInput;

			} while (!stringValidation(thisInput));
			make = thisInput;

			do
			{
				cout << "Enter Model: " << endl;
				cin >> thisInput;

			} while (!stringValidation(thisInput));
			model = thisInput;

			do
			{
				cout << "Enter amount of wheels: " << endl;
				cin >> input;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (input < 0);
			wheels = input;

			//saves to the vehicle object and then adds to the vehicles vector
			Vehicle v;
			v.make = make;
			v.model = model;
			v.fuelType = fuelType;
			v.vehicleType = vehicleType;
			v.wheels = wheels;
			vehicles.push_back(v);

		}
	}

	//Creates new vehicle without straight away adding the vechicle array
	//Otherwise same process to the previous function
	Vehicle createVehicle()
	{
		Vehicle v;
		string thisInput;
		int input;
		do
		{

			//Determines the vehicle type
			cout << "Select vehicle type: " << endl;
			cout << "[1] Car\n[2] Van\n[3] MoterBike\n[4] HGV" << endl;
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				input = -1;
			}
		} while (input > 5 || input < 0);
		int intThisInput = input;
		switch (intThisInput)
		{
		case 1:
			vehicleType = "Car";
			break;
		case 2:
			vehicleType = "Van";
			break;
		case 3:
			vehicleType = "MoterBike";
			break;
		case 4:
			vehicleType = "HGV";
			break;
		default:
			break;
		}
		//determines the fuel type
		do
		{
			cout << "Select fuel type: " << endl;
			cout << "[1] Petrol\n[2] Diseal\n[3] Hybrid\n[4] Electric" << endl;
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				input = -1;
			}
		} while (input > 5 || input < 0);
		intThisInput = input;
		switch (intThisInput)
		{
		case 1:
			fuelType = "Petrol";
			break;
		case 2:
			fuelType = "Diseal";
			break;
		case 3:
			fuelType = "Hybrid";
			break;
		case 4:
			fuelType = "Electric";
			break;
		default:
			break;
		}
		do
		{
			cout << "Enter make: " << endl;
			cin >> thisInput;

		} while (!stringValidation(thisInput));
		v.make = thisInput;

		do
		{
			cout << "Enter Model: " << endl;
			cin >> thisInput;

		} while (!stringValidation(thisInput));
		v.model = thisInput;

		do
		{
			cout << "Enter amount of wheels: " << endl;
			cin >> thisInput;
		} while (!intValidation(thisInput));
		v.wheels = stoi(thisInput);
		return v;
	}

	//Returns all entities of vehicle
	Vehicle getVehcile()
	{
		Vehicle v;
		v.make;
		v.model;
		v.wheels;
		v.fuelType;
		v.vehicleType;
		v.reg;
		v.mot;
		return v;
	}

	//Sets the MOT
	void setMOT()
	{
		mot.setMOT();
		mot = mot.getMOTDetails();
	}

	//Main Getters
	string getReg() { return reg; }
	string getMake() { return model; }
	string getModel() { return make; }
	int getWheels() { return wheels; }
	string getVehicleType() { return vehicleType; }
	string getFuelType() { return fuelType; }
	MOT getMOT() { return mot; }
private:
	string reg;
	string make;
	string model;
	int wheels = 0;
	string vehicleType;
	string fuelType;
	MOT mot;

}; //Vehicle class end

//Class for part
class Part
{
public:
	string getPartName() { return partName; }
	string getMake() { return make; }
	string getModel() { return model; }
	float getPrice() { return price; }
	int getStock() { return stock; }

	//Returns information saved in the part
	Part getPart(Part p)
	{

		p.partName = p.getPartName();
		p.make = p.getMake();
		p.model = p.getModel();
		p.price = p.getPrice();
		p.stock = p.getStock();
		return p;
	}

	//Creates a new part
	//Sets name, make, model, price, and stock
	Part createNewPart(Part p)
	{
		cout << "Enter part name" << endl;
		cin >> p.partName;
		cout << "Enter make" << endl;
		cin >> p.make;
		cout << "Enter model" << endl;
		cin >> p.model;
		cout << "Enter price" << endl;
		cin >> p.price;
		cout << "Enter stock" << endl;
		cin >> p.stock;
		return p;
	}

	//Makes new part but using info from vehicle to set make and model
	Part createNewPart(Part p, Vehicle v)
	{
		
		cout << "Enter part name" << endl;
		cin >> p.partName;
		p.make = v.getMake();
		p.model = v.getModel();
		cout << "Enter price" << endl;
		cin >> p.price;
		cout << "Enter stock" << endl;
		cin >> p.stock;
		return p;
	}

	//Removes one item from the stock
	void updateStock() { stock = stock - 1; }

	//Sets a new stock count
	void setStock()
	{
		string thisInput;
		do
		{
			cout << "Enter new stock count: " << endl;
			cin >> thisInput;
		} while (!intValidation(thisInput));
		stock = stoi(thisInput);
	}

	//Sets a new stock price
	void setPrice()
	{
		string thisInput;
		do
		{
			cout << "Enter Price: " << endl;
			cin >> thisInput;
		} while (intValidation(thisInput));
		price = stoi(thisInput);
	}

private:
	string partName;
	string make;
	string model;
	float price = 0;
	int stock = 0;

};	//Parts class end

//Class to manage booking
class Booking
{
public:
	//Gets all variables
	Vehicle getVehicle() { return vehicle; }
	string getService() { return serviceRequired; }
	dateAvailability getBookedInfo() { return bookedInfo; }
	float getPrice() { return quotedPrice; }
	Part getPart() { return part; }
	struct tm* getTimestamp() { return timeinfo; }
	bool getCompleted() { return bookingCompleted; }
	bool getisMOT() { return isMOT; }

	//Returns all info stored with a booking
	Booking getBooking(Booking b)
	{
		b.part = part;
		b.serviceRequired = serviceRequired;
		b.vehicle = vehicle;
		b.quotedPrice = quotedPrice;
		b.timeinfo = timeinfo;
		b.bookedInfo = bookedInfo;
		b.bookingCompleted = bookingCompleted;
		return b;
	}

	//Creates a new booking 
	Booking createNewBooking(vector<Part>& parts, vector<Vehicle>& vehicles, Booking b, vector<Handler>& handlers, vector<dateAvailability>& availability)
	{
		bookingCompleted = false;
		b.setBookedTimeDate(handlers, availability);
		b.setVehicle(vehicles);
		b.setServie(parts, b.getVehicle());

		b.setQuotedPrice();
		b.setTimestamp();

		b = b.getBooking(b);
		return b;
	}
	//Creates a new timestamp
	void setTimestamp()
	{
		time_t rawtime;
		time(&rawtime);
		timeinfo = localtime(&rawtime);

	}
	//Assigns a vehicle to the booking
	void setVehicle(vector<Vehicle>& vehicles) { vehicle.createVehicle(vehicles); }
	
	//Assigns the service required for the car
	void setServie(vector<Part>& parts, Vehicle v)
	{

		string thisInput;
		int input;
		do
		{
			//Determines if the user wants a mot or other service
			cout << "[1] MOT" << endl << "[2] Other" << endl;
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (input != 1 && input != 2);

		switch (input)
		{
		case 1:
			//Assigns a MOT
			quotedPrice = quotedPrice + 100;
			isMOT = true;
			serviceRequired = "MOT";
			break;
		case 2:
			cout << "Please enter service required: " << endl;
			cin >> serviceRequired;
			cout << "Please select part required: " << endl;
			string choice;
			parts = parts;
			Part p; //Creates object part
			int input;
			int count = 0;
			do //Selects name of the part
			{
				for (size_t i = 0; i < parts.size(); i++)
				{
					cout << "[" << i + 1 << "] " << endl << "Name: " << parts[i].getPartName() << endl
						<< "Make: " << parts[i].getMake() << endl
						<< "Model: " << parts[i].getModel() << endl;
					count = count + 1;
				}
				do
				{
					cout << "If part not found please enter 0" << endl;
					cin >> input;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
					}
				} while (input > count || input < -1);

				if (input == 0)
				{
					cout << "Please now follow the instructions to create a new part. " << endl;
					p = p.createNewPart(p, v);
					p = p.getPart(p);
					part = p;
					parts.push_back(p);
				}
			} while (input < 0 || input  > count); ////DEBUG FROM HERE
			int thisChoice = input; //thisChoice is the position in  parts that the desired part lays
			if (thisChoice != 0)
			{
				if (parts[thisChoice - 1].getStock() <= 0)
				{
					cout << "This part is out of stock" << endl;
					cout << "This part has been ordered. This may result in a delay of service" << endl;
				}
				else
				{
					part = parts[thisChoice - 1];

					parts[thisChoice - 1].updateStock();

				}
			}

			break;
		}


	}

	//Assigns a day to the booking
	void setBookedTimeDate(vector<Handler>& handlers, vector<dateAvailability>& availability)
	{
		bool isFree = false;
		do {

			string day;
			string month;
			string year;
			string hour;
			string min;
			int temp;
			do
			{
				cout << "Please enter day: " << endl;
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}

			} while (temp <= 0 || temp > 31 || to_string(temp).length() > 2);
			day = to_string(temp);

			do
			{
				cout << "Please enter month: " << endl;
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (temp <= 0 || temp > 12 || to_string(temp).length() > 2);
			month = to_string(temp);

			do
			{
				cout << "Please enter year: " << endl;
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (to_string(temp).length() != 4);
			year = to_string(temp);

			do
			{
				cout << "Please enter hour: " << endl;
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (temp < 0 || temp > 24 || to_string(temp).length() > 2);
			hour = to_string(temp);

			do
			{
				cout << "Please enter min: " << endl;
				cin >> temp;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			} while (temp < 0 || temp > 60 || to_string(temp).length() > 2);
			min = to_string(temp);

			//If that date isnt taken then its assigned to the booking else a new date is required
			if (availability.size() > 0)
			{
				for (size_t i = 0; i < availability.size(); i++) //Date
				{
					if (availability[i].getHour() == hour && availability[i].getDay() == day && availability[i].getMonth() == month && availability[i].getYear() == year)
					{
						isFree = false;
						cout << "This slot has already been booked." << endl;
					}
					else
					{
						isFree = true;
					}
				}
			}
			else {
				isFree = true;
			}
			if (isFree)
			{
				isFree = true;
				cout << "Slot free and now booked" << endl;
				dateAvailability a;
				a.setDay(day);
				a.setDate(day, month, year);
				a.setTime(hour, min);
				a.setMonth(month);
				a.setYear(year);
				a.setHour(hour);
				a.setMin(min);
				availability.push_back(a);
				bookedInfo = a;
			}


		} while (!isFree);

	}
	void setCompleted()
	{
		bookingCompleted = true;
	}

	//Sets price for booking
	void setQuotedPrice()
	{
		int labourCosts;
		bool accepted = false;
		do
		{
			cout << "Enter labour costs: " << endl;
			cin >> labourCosts;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				accepted = true;
			}

		} while (!accepted);
		quotedPrice = quotedPrice + labourCosts + part.getPrice();

	}

private:
	Part part;
	Vehicle vehicle;
	dateAvailability bookedInfo;
	string serviceRequired;
	struct tm* timeinfo;
	float quotedPrice = 0;
	bool bookingCompleted;
	bool isMOT = false;


};	//Booking class end

//Class that combines customer and a vector of bookings
class Handler
{
public:
	Customer getCustomer() { return customer; } //Returns all customer details for a function to break down the necessary components
	vector<Booking> getBookings() { return bookings; } //Returns all bookings for this user for a function to decide which is relevant 

	void createNewCustomer()
	{
		customer = customer.newCustomer(); //creates customer
	}

	//creates a new booking object to be saved to the booking vector
	Booking newBooking(vector<Part>& parts, vector<Vehicle>& vehicles, Booking b, vector<Handler>& handlers, vector<dateAvailability>& availability)
	{
		b = b.createNewBooking(parts, vehicles, b, handlers, availability);
		b = b.getBooking(b);
		return b;
	}
	//Overrides the booking vector with a new vector
	void setBookingArray(vector<Booking> newBookings)
	{
		bookings = newBookings;
	}

	//Adds a single predefined booking to the booking vector
	void setBooking(Booking b)
	{
		bookings.push_back(b);
	}


private:
	Customer customer; //Holds one customer for each iteration of handlers
	vector<Booking> bookings; //Holds all the booking infomration for this customer 


};	//Handler class end;

//this function handles adding a new user
void newCustomer(vector<Handler>& handlers)
{
	Handler h;
	h.createNewCustomer();

	handlers.push_back(h);
}

//this function handles displaying user details
void showCustomer(vector<Handler> handlers)
{
	if (handlers.size() > 0)
	{
		for (size_t i = 0; i < handlers.size(); i++)
		{

			cout << "Name: " << handlers[i].getCustomer().getName() << endl;
			cout << "Phone Nummber: " << handlers[i].getCustomer().getPhoneNumber() << endl;
			cout << "Address: " << handlers[i].getCustomer().getFirstLine() << " " << handlers[i].getCustomer().getPhoneNumber() << endl;
		}
	}
}

//this function handles adding a new booking
void newBooking(vector<Part>& parts, vector<Vehicle>& vehicles, vector<Handler>& handlers, vector<dateAvailability>& availability)
{
	string thisInput;
	if (handlers.size() > 0)
	{

		int input;
		do
		{
			for (size_t i = 0; i < handlers.size(); i++)
			{
				//Displays all the users
				cout << "[" << i + 1 << "] " << handlers[i].getCustomer().getName() << endl;
			}
			cout << "If user not found, please enter 0: " << endl;
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				input = -1;
			}
		} while (input > handlers.size() || input <= -1);

		if (input != 0)	//Sets up a booking for that user
		{
			int intInput = input - 1;
			Booking b;
			b = handlers[intInput].newBooking(parts, vehicles, b, handlers, availability);
			handlers[intInput].setBooking(b);
		}
		else //If 0 is entered the this message will show
		{
			cout << "Please select to create a new user on the menu system" << endl;
		}
	}
}

//this function handles displaying booking asking for a registration
void viewBooking(vector<Handler>& handlers)
{
	bool isVehicleFound = false;
	string thisInput;
	do
	{
		cout << "Please enter registration number: " << endl;
		cin >> thisInput;
	} while (thisInput.size() != 7);
	if (handlers.size() > 0)
	{
		for (size_t i = 0; i < handlers.size(); i++) // i is the customers handlers
		{
			vector<Booking> searchBooking = handlers[i].getBookings();
			for (size_t j = 0; j < searchBooking.size(); j++)	//j is the specific for a customer
			{
				if (searchBooking[j].getVehicle().getReg() == thisInput)
				{

					//Displays all information held for that booking and customer
					Vehicle v = searchBooking[j].getVehicle();
					Customer c = handlers[i].getCustomer();

					cout << "Cutomer: " << endl;
					cout << "Name: " << c.getName() << endl
						<< "Address: " << c.getFirstLine() << " " << c.getPostCode() << endl
						<< "Phone number: " << c.getPhoneNumber() << endl << endl;


					cout << "Booking Details: " << endl;
					cout << "Time booking made: " << asctime(searchBooking[j].getTimestamp()) << endl;
					cout << "Date and time of booking: " << searchBooking[j].getBookedInfo().getDate() << " " << searchBooking[j].getBookedInfo().getTime() << endl << endl;


					cout << "Vehicle: " << endl
						<< "Make: " << v.getMake() << endl
						<< "Model: " << v.getModel() << endl
						<< "Fuel: " << v.getFuelType() << endl
						<< "Vehicle: " << v.getVehicleType() << endl
						<< "Wheels: " << v.getWheels() << endl
						<< "Registration: " << v.getReg() << endl;

					cout << "Reason: " << searchBooking[j].getService() << endl
						<< "Part required: " << searchBooking[j].getPart().getPartName() << endl // if part required is empty this is because the service was MOT
						<< "Price: " << searchBooking[j].getPrice() << endl;

					isVehicleFound = true;
				}
			}
		}
	}
	if (!isVehicleFound)
	{
		cout << "Vehicle not found." << endl;
	}
}

//function used to display reminders depending on showReminders results
void displayReminders(Booking b)
{
	cout << "Registration Number: " << b.getVehicle().getReg() << endl;
	cout << "Booking reason: " << b.getService() << endl;
	cout << "Booked date and time: " << b.getBookedInfo().getDate() << " " << b.getBookedInfo().getTime() << endl;
	cout << "-------------------------------" << endl;
}

//Shows results depending on the if they happen in the next month, quater, year or if the booking is a mot
void showReminders(vector<Handler> handlers)//Still needs work
{
	//Gets the current date time for comparrision 
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int month = 1 + newtime.tm_mon;
	int day = newtime.tm_mday;
	int year = 1900 + newtime.tm_year;

	int thisInput;
	do
	{
		cout << "1. Month" << endl
			<< "2. Quater " << endl
			<< "3. Year" << endl
			<< "4. MOTs" << endl;
		cin >> thisInput;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (thisInput < 0 || thisInput > 4);
	switch (thisInput)
	{
	case 1: //This month
		for (size_t i = 0; i < handlers.size(); i++)
		{
			vector<Booking> bookings = handlers[i].getBookings();
			for (size_t j = 0; j < bookings.size(); j++)
			{
				//Displays all booking for the next month
				if (stoi(bookings[j].getBookedInfo().getMonth()) == month && stoi(bookings[j].getBookedInfo().getYear()) == year && bookings[j].getCompleted() == false)
				{
					displayReminders(bookings[j]);
				}
			}
		}
		break;
	case 2:
		for (size_t i = 0; i < handlers.size(); i++)
		{
			vector<Booking> bookings = handlers[i].getBookings();
			for (size_t j = 0; j < bookings.size(); j++)
			{
				// Displays all bookings for the next 3 months
				if (stoi(bookings[j].getBookedInfo().getYear()) == year && stoi(bookings[j].getBookedInfo().getMonth()) <= month + 3 && bookings[j].getCompleted() == false)
				{
					displayReminders(bookings[j]);
				}
			}
		}
		break;
	case 3:
		for (size_t i = 0; i < handlers.size(); i++)
		{
			vector<Booking> bookings = handlers[i].getBookings();
			for (size_t j = 0; j < bookings.size(); j++)
			{
				//Displays all bookings for the next year
				if (stoi(bookings[j].getBookedInfo().getYear()) <= year + 1 && bookings[j].getCompleted() == false)
				{
					displayReminders(bookings[j]);
				}
			}
		}
		break;
	case 4:
		for (size_t i = 0; i < handlers.size(); i++)
		{
			vector<Booking> bookings = handlers[i].getBookings();
			for (size_t j = 0; j < bookings.size(); j++)
			{
				//Displays all MOT bookings
				if (bookings[j].getisMOT() == true)
				{
					cout << "Registration Number: " << bookings[j].getVehicle().getReg() << endl;
					cout << "Booked date and time: " << bookings[j].getBookedInfo().getDate() << " " << bookings[j].getBookedInfo().getTime() << endl;
					cout << "-------------------------------" << endl;
				}
			}
		}
		break;
	case 5:

		break;

	default:
		cout << "Input not available" << endl;
		showReminders(handlers);
		break;
	}
}

//Adds new part to the parts array
void newPart(vector<Part>& parts) //Function which adds a new part to parts - passed by reference
{
	Part p;
	p = p.createNewPart(p);
	parts.push_back(p);
}

//adds new vehicle to the vehicle array
void newVehicle(vector<Vehicle>& vehicles)
{
	Vehicle v;
	v = v.createVehicle();
	vehicles.push_back(v);
}

//Allows for a part stock or a part price to be changed
void updatePart(vector<Part>& parts)
{
	if (parts.size() > 0)
	{

		int input;
		int partLocation;
		do
		{
			//Displays all stored parts
			cout << "Please select part you wish to update" << endl;
			for (size_t i = 0; i < parts.size(); i++)
			{
				cout << "[" << i + 1 << "]" << endl
					<< "Make: " << parts[i].getMake() << endl
					<< "Model: " << parts[i].getModel() << endl
					<< "Stock: " << parts[i].getStock() << endl
					<< "Price: " << parts[i].getPrice() << endl;
			}
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				input = -1;
			}
		} while (input > parts.size() || input < 0);
		partLocation = input - 1;

		//Gives choice what option to select

		do
		{
			cout << "[1] Update stock" << endl << "[2] Update price" << endl;
			cin >> input;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				input = -1;
			}
		} while (input > 2 || input < 1);

		if (input == 1)
		{
			//Update stock
			parts[partLocation].setStock();
		}
		else
		{
			//Update price
			parts[partLocation].setPrice();
		}


	}

	else
	{
		cout << "No parts to update. Please select another option" << endl;
	}

}

//Function to remove user from vector
void removeCustomer(vector<Handler>& handlers, vector<dateAvailability>& availability)
{
	int thisInput;
	if (handlers.size() == 0)
	{
		cout << "No entities to remove" << endl;
	}
	else
	{


		do
		{
			//Displays all customers to determine who to be removed
			cout << "Please select user to be removed" << endl;
			for (size_t i = 0; i < handlers.size(); i++)
			{
				cout << "--------[" << i + 1 << "]--------" << endl;
				cout << "Name: " << handlers[i].getCustomer().getName() << endl;
				cout << "Address: " << handlers[i].getCustomer().getFirstLine() << handlers[i].getCustomer().getPostCode() << endl;
				cout << "Phone number: " << handlers[i].getCustomer().getPhoneNumber() << endl;
				cout << "----------------------------------" << endl;
			}
			cin >> thisInput;
		} while (thisInput > handlers.size() && thisInput <= -1);

		for (size_t i = 0; i < availability.size(); i++)
		{
			if (availability.size() > 0)
			{
				for (size_t j = 0; j < handlers[thisInput - 1].getBookings().size(); j++)
				{
					//Removes all the date and times assicated with that client
					if (availability[i].getDate() == handlers[thisInput - 1].getBookings()[j].getBookedInfo().getDate())
					{
						availability.erase(availability.begin() + i);
					}
				}
			}
			else
			{
				//If one one booking clears the entired vector
				availability.clear();
				break;
			}
		}

		//If only one client clears vector
		if (handlers.size() == 1)
		{
			handlers.clear();
		}
		else
		{
			//Removes needed user from the handler vector
			handlers.erase(handlers.begin() + thisInput - 1);

		}
	}

}

//This function allows for a booking to be removed from a users booking vector
void removeBooking(vector<Handler>& handlers, vector<dateAvailability>& avaliabilty)//Need help here
{
	bool isFound = false;
	string thisInput;
	int handlerInput;
	int input;

	//Displays all users to determine the correct person to be removed
	for (size_t i = 0; i < handlers.size(); i++)
	{
		cout << "[" << i + 1 << "] " << endl;
		cout << "Name: " << handlers[i].getCustomer().getName() << endl;
		cout << "Address: " << handlers[i].getCustomer().getFirstLine() << " " << handlers[i].getCustomer().getPostCode() << endl;
		cout << "----------------------------" << endl;

	}
	cin >> thisInput;
	handlerInput = stoi(thisInput) - 1;

	//Displays all booking held for that user
	for (size_t j = 0; j < handlers[handlerInput].getBookings().size(); j++)
	{
		cout << "Registration: " << handlers[handlerInput].getBookings()[j].getVehicle().getReg() << endl;
		cout << "Date booked for: " << handlers[handlerInput].getBookings()[j].getBookedInfo().getDate() << endl;
	}
	cout << "If booking not found enter 0" << endl;	//If that user has no bookings then this is used to allow for an escape
	cin >> input;
	if (input != 0)	
	{
		input = input - 1;
		avaliabilty.erase(avaliabilty.begin() + input);	//removed booked date and time to allow that date time to be rebooked
		vector<Booking> b = handlers[handlerInput].getBookings();	//Copies booking vector 
		b.erase(b.begin() + input);	//Erases the needed booking from the copied vector 
		handlers[handlerInput].setBookingArray(b);	//Replaces the held booking vector with the copied
	}
}

//Allows for a booking to be updated
void updateBooking(vector<Handler>& handlers)
{
	bool isFound = false;
	string thisInput;
	do
	{
		cout << "Enter Registration number: " << endl;
		cin >> thisInput;
	} while (thisInput.length() != 7);
	for (size_t i = 0; i < handlers.size(); i++)	//Loops through handler
	{
		vector<Booking> bookings = handlers[i].getBookings();
		for (size_t j = 0; j < bookings.size(); j++)	//loops through bookings to that handler
		{
			if (bookings[j].getVehicle().getReg() == thisInput && bookings[j].getisMOT() == false && bookings[j].getCompleted() == false) //determines if this is the vehicel, and that the booking hasnt been compeleted yet
			{
				isFound = true;
				cout << "Bookings reason: " << bookings[j].getService() << endl;	//Shows the service booked
				cout << "Booking made: " << asctime(bookings[j].getTimestamp()) << endl;	//Displays when the booking was made
				do
				{
					cout << "Has this bookings been fulfilled? Y/N" << endl;
					cin >> thisInput;
				} while (thisInput != "Y" && thisInput != "N");

				if (thisInput == "Y")	//If the booking has been completed the completed flag will be set to true
				{
					cout << "Accepted. Booking marked as complete" << endl;
					handlers[i].getBookings()[j].setCompleted();
				}
				else
				{
					cout << "Accepted" << endl;
				}

			}
		}
	}
	if (!isFound)
	{
		cout << "No active booking found" << endl;
	}
}

//Allows for a MOT to be preformed
void preformMOT(vector<Handler>& handlers)
{
	bool isFound = false;
	string thisInput;
	do
	{
		cout << "Enter Registration number: " << endl;
		cin >> thisInput;
	} while (thisInput.length() != 7);
	for (size_t i = 0; i < handlers.size(); i++)	//Loops through all entities in handler
	{
		vector<Booking> bookings = handlers[i].getBookings();
		for (size_t j = 0; j < bookings.size(); j++)	//Loops through all entities in bookings
		{
			//deterimes if the reg entered has an MOT booked
			if (bookings[j].getisMOT() == true)
			{
				cout << "Booking made: " << asctime(bookings[j].getTimestamp()) << endl; //Displays when the booking was made
				do
				{
					cout << "Update MOT Results? Y/N" << endl;
					cin >> thisInput;
				} while (thisInput != "Y" && thisInput != "N");
				if (thisInput == "Y")
				{
					isFound = true;
					handlers[i].getBookings()[j].setCompleted();
					handlers[i].getBookings()[j].getVehicle().setMOT();	//Preforms MOT 
				}
			}
		}
	}
	if (!isFound)
	{
		cout << "No MOT booking found" << endl;
	}
}



//Menus
void menu(vector<Part>& parts, vector<Vehicle>& vehicles, vector<Handler>& handlers, vector<dateAvailability>& availability) //Menu handlers
{
	int choice;
	do
	{
		cout << "[1] View upcoming bookings" << endl
			<< "[2] View customer" << endl
			<< "[3] View booking" << endl
			<< "[4] Add booking" << endl
			<< "[5] Add customer" << endl
			<< "[6] Add part" << endl
			<< "[7] Add vehicle" << endl
			<< "[8] Update part" << endl
			<< "[9] Remove customer" << endl
			<< "[10] Remove booking" << endl
			<< "[11] Preform MOT" << endl
			<< "[12] Completed booking" << endl
			<< "[13] End Program" << endl;
		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (choice > 13 || choice < 1);
	
	//Menu switch case
	switch (choice)
	{
	case 1:
		showReminders(handlers);
		break;
	case 2:
		showCustomer(handlers);
		break;
	case 3:
		viewBooking(handlers);
		break;
	case 4:
		newBooking(parts, vehicles, handlers, availability);
		break;
	case 5:
		newCustomer(handlers);
		break;
	case 6:
		newPart(parts);
		break;
	case 7:
		newVehicle(vehicles);
		break;
	case 8:
		updatePart(parts);
		break;
	case 9:
		removeCustomer(handlers, availability);
		break;
	case 10:
		removeBooking(handlers, availability);
		break;
	case 11:
		preformMOT(handlers);
		break;
	case 12:
		updateBooking(handlers);
		break;
	case 13: //ends program
		system("CLS");
		cout << "--------------------------" << endl;
		cout << "PROGRAM ENDED SUCESSFULLY" << endl;
		cout << "--------------------------" << endl;
		exit(0);
		break;

	default:
		break;
	}
}

int main()
{
	//All vectors are held in memory. No reading or writing to a file
	//All vectors are held here outside of the menu loop and passed by reference to ensure data continues through every menu loop
	vector<Part> parts;
	vector<Handler> handlers;
	vector<Vehicle> vehicles;
	vector<dateAvailability> availability;

	while (true) { menu(parts, vehicles, handlers, availability); }
}