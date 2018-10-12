#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "LLAB.h"

using namespace std;

//Address book struction
struct Abooknode {
	string firstname;
	string lastname;
	string phone;
	string address;
	string city;
	string state;
	string zipcode;

	struct Abooknode*   next;
};



// Create the adress book linked list head
struct Abooknode* Abookhead() {
	struct Abooknode* head=NULL; //Assign a empty memory address to head
	head = new Abooknode; // Assign a new memory address to head
	 
	 // To set personal information empty for head initialized                  
	head->firstname = "";
	head->lastname = "";
	head->phone="";
	head->address="";
	head->city="";
	head->state="";
	head->zipcode="";

	head->next = nullptr; /// doesn't have the next memory address when head initialized
	return head; /// launch head's memory address
}


								void displaytitle() {
									cout << setw(4) << left << "SN" <<  '\t';
									cout << setw(10) << left << "First Name"<< '\t';
									cout << setw(8) << left << "Last Name"<< '\t';
									cout << setw(13) << left << "Phone"<< '\t';
									cout << setw(20) << left << "Address" << '\t';
									cout << setw(10) << left << "City" << '\t';
									cout << setw(10) << left << "State" << '\t';
									cout << setw(5) << left << "Zip Code" << setw(3) << left << " " << endl;
								}

							void displaycontact(struct Abooknode* indicator, int count) {
								cout << setw(4) << left << count << '\t';
								cout << setw(10) << left << indicator->firstname.c_str() << '\t';
								cout << setw(8) << left << indicator->lastname.c_str() << '\t';
								cout << setw(13) << left << indicator->phone.c_str() << '\t';
								cout << setw(20) << left << indicator->address.c_str() << '\t';
								cout << setw(10) << left << indicator->city.c_str() << '\t';
								cout << setw(10) << right << indicator->state.c_str() << '\t';
								cout << setw(5) << left << indicator->zipcode.c_str() << setw(3) << left << " " << endl;
							}

							int displaycontact(struct Abooknode* head) {
								int count = 0;
								struct Abooknode* indicator = head; // To read the linked list, we initialize indicator memory address with the head's
	      						/// To read the linked list address
								while (indicator != NULL) {
																	
									if (count > 0) { // doesn't display head
										displaycontact(indicator, count);// Display the contact one time 
									}

									count++;
									indicator = indicator->next; ///reads the next memory address then confirms if it is the last one in this loop.
								}

								if (count >= 1) { // doesn't count head
									return count - 1;
								}
								else {
									return count;
								}
							}


							//Update or Add function
							string contactAddUpdate(string enterprompt, char entrytype) {
								struct entryreturn* returnsetnodeinformation;
								char Updatedata[81];
								string returnstring="";
								string prompttype;//To prompt Add or Update model
								bool exitloop=false; // true means exit the loop
								///cout << "***" << entrytype << "***";
												if (entrytype == 'A') {
													prompttype = "Add model> ";
												}
												else  { //(entrytype == 'U')
													prompttype = "Update model> ";
												}
												 
								do { // At Add model, if entering nothing, user repeats to enter in the loop
										cout << prompttype.c_str() << enterprompt.c_str();
										cin.getline(Updatedata, 30);
										// cin.ignore();
										returnstring = Updatedata;

										exitloop = true;// before check if user enter nothing, set the flag to lease the loop
											
											if (returnstring.empty()) { //if user enters nothing, adding model lets user enter again, and update model return "EmPt N/a"
												if (entrytype == 'A') {
													exitloop = false;
												}
												else if (entrytype == 'U'){
													 returnstring = "EmPt N/a";
												}
											}

								} while (exitloop == false);

									return returnstring;
							}


							void setinformation(struct Abooknode* setdata, char operationmodel) {
								cin.ignore();
								
								string recievedentry=""; // To get entery information
																
								if (operationmodel == 'A') { // Add model

									 setdata->firstname = contactAddUpdate("First name: ", operationmodel);
									 setdata->lastname = contactAddUpdate( "Last name: ", operationmodel);
									 setdata->phone = contactAddUpdate( "Phone numnber: ", operationmodel);
									 setdata->address = contactAddUpdate( "House number and Street: ", operationmodel);
									 setdata->city = contactAddUpdate( "City: ", operationmodel);
									 setdata->state = contactAddUpdate( "State: ", operationmodel);
									  setdata->zipcode = contactAddUpdate( "zipcode: ", operationmodel);
								}
								else if (operationmodel == 'U')  // Update model
								{

									recievedentry = contactAddUpdate("First name: "+setdata->firstname + " update of :", operationmodel);
									setdata->firstname = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->firstname : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "Last name: " + setdata->firstname + " update of :", operationmodel);
									setdata->lastname = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->lastname : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "Phone numnber: " + setdata->firstname + " update of :", operationmodel);
									setdata->phone = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->phone : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "House number and Street: " + setdata->firstname + " update of :", operationmodel);
									setdata->address = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->address : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "City: " + setdata->firstname + " update of :", operationmodel);
									setdata->city = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->city : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "State: " + setdata->firstname + " update of :", operationmodel);
									setdata->state = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->state : recievedentry);// if enter nothing, keep old information
									recievedentry = contactAddUpdate( "zipcode: " + setdata->firstname + " update of :", operationmodel);
									setdata->zipcode = (strcmp(recievedentry.c_str(), "EmPt N/a") == 0 ? setdata->zipcode : recievedentry);// if enter nothing, keep old information
								}


								 
							}

void addnode(struct Abooknode* head) {
	
	struct Abooknode* indicator = head; // To read the linked list, we initialize indicator memory address with the head's

	struct Abooknode* addnode = new Abooknode; // a new memory address declared for the addition node and will assign data to it.
	

	addnode->next = NULL; // set up the adding contact as the last on in the liked list
	setinformation(addnode,'A');// get data for this addnode



	while (indicator->next != NULL) {
		indicator = indicator->next;///reads the next memory address then confirms if it is the last one in this loop.
	}
	
	// gets the last one of the linked list then assign the next memory address  
	indicator->next = addnode;

	
}



    // to count the linked list length
int length(struct Abooknode* head) {
	int count = 0; 
	struct Abooknode* indicator = head; // To read the linked list, we initialize indicator memory address with the head's

	/// To read the linked list address
	while (indicator != NULL) {
		count++;
		indicator = indicator->next; ///reads the next memory address then confirms if it is the last one in this loop.
	}
	return count;
}

// find a node have a same sequence number and return the node's memory address
struct Abooknode* findnode(struct Abooknode* head, int indexNum) {
	int count = 0;
	//struct Abooknode* foundnode = head;// To record the aim node's memory address
	struct Abooknode* indicator = head; // To read the linked list, we initialize indicator memory address with the head's

										/// To read the linked list address
	while (indicator != NULL) {
				
		if (indexNum == count) {return indicator;}
		count++;
		indicator = indicator->next; ///reads the next memory address then confirms if it is the last one in this loop.
	}
	return head; // find nothing


}

int search(struct Abooknode* head, char findinfo []) {
	int count=0;//count the match contacts
	struct Abooknode* indicator = head; // To read the linked list, we initialize indicator memory address with the head's
	while (indicator != NULL) {

		
			// if (indicator != NULL) {

							 if (strstr(indicator->lastname.c_str(), findinfo) != 0 ||
								 strstr(indicator->firstname.c_str(), findinfo) != 0 ||
								 strstr(indicator->phone.c_str(), findinfo) != 0 ||
								 strstr(indicator->address.c_str(), findinfo) != 0 ||
								 strstr(indicator->city.c_str(), findinfo) != 0 ||
								 strstr(indicator->state.c_str(), findinfo) != 0 ||
								 strstr(indicator->zipcode.c_str(), findinfo) != 0
								 )
							 {
								 //cout << "foud";
								 displaycontact(indicator, count);// Display the contact one time 
							 }///string matchs end if 
			//}
			 
			 indicator = indicator->next; ///reads the next memory address then confirms if it is the last one in this loop.
			 count++;

		 
	}// while loop
	//cout << "found " << count - 1 << " contact(s)!" << endl;
	return (count - 1);

}// function end


int main() {
	struct Abooknode* head = Abookhead(); ///Gets head's momery address
	struct Abooknode* editAbook = head; /// for edit Abook purpose
	cout << "Loading... " << endl;
	cout << "Total: " <<  displaycontact(head) << " contacts" << endl << endl << endl;

	do {
		int menuChoice;
		cout << "Please choose one of the options below: " << endl;
		cout << "******************************************************************" << endl;
		cout << "1. Add contact to address book." << endl;
		cout << "2. Update existing contact." << endl;
		//cout << "3. Delete contact from address book" << endl;
		cout << "4. Search for contact in address book." << endl;
		cout << "5. List all" << endl;
		cout << "6. Quit the program" << endl;
		cout << "******************************************************************" << endl;
		cout << "Menu number:";
		cin >> menuChoice;
		char findinfo[21];

					switch (menuChoice){

							case 1: //Function to add contact to address book.
								int contactNumber;
								addnode(head);
								cout << endl << endl;
								//contactNumber = length(head);
			
								break;
							case 2: //Function to update contact in address book.


								cin.ignore();
								cout << endl << "Update model: Any information (20 characters):";
								cin.getline(findinfo, 20);
								//cin.ignore();

								if (search(head, findinfo) > 0) {//found the aim contacts
									int aimNum = 0; // chose sequence number to locate the update contact

									do {
										cout << endl << "Choose a sequence number from above / list all (0) /Exit (-1): ";
										cin >> aimNum;
										if (aimNum == -1) {
											break;
										}
										else if (aimNum == 0) {///display all
											cout << "Loading... " << endl;
											displaytitle();
											cout << "Total: " << displaycontact(head) << " contacts" << endl << endl << endl;
										}
										else {
														struct Abooknode* foundnode = findnode(head, aimNum);
													if (foundnode != head) {
													 
														setinformation(foundnode,'U'); //Update the contact 

													}
										}//end of second menu choose if

									} while (1 == 1); //do loop end
								}

								break;
							case 3: //Function to delete contact from address book.
			
								break;
							case 4: //Function to search for contact in address book

								cin.ignore();
								cout << endl << "Search model: Any information (20 characters):";
								cin.getline(findinfo, 20);
								//cin.ignore();
								if (search(head, findinfo) > 0) {

									cout << "found  contact(s)!" << endl;
								}
								break;
			
								
							case 5:  //list all
								cout << "Loading... " << endl;
								displaytitle();
								cout << "Total: " << displaycontact(head) << " contacts" << endl << endl << endl;
								break;
							case 6:  //Functiont to quit the program.
								return 0;
							default:
								cin.ignore();
								break;

					  }//end of the switch case


		} while(1 == 1);

	return 0;
}