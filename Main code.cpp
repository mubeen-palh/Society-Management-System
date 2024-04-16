#include<iostream>
#include<fstream>
#include<string.h>
#include<dos.h>
#include<Windows.h>
#include <unistd.h>
using namespace std;
class House{
	
	protected:
		char houseno[50],streetno[50],housetype[50],sell[50];
		double rent;
		
	public:
		
		void inphouse(){
			
			cout<<"Enter House Number"<<endl;
			fflush(stdin);
			cin.getline(houseno,50);
			fflush(stdin);
			cout<<"Enter Street Number"<<endl;
			fflush(stdin);
			cin.getline(streetno,50);
			fflush(stdin);
			cout<<"Enter House Type (Single Story / Double Story)"<<endl;
			fflush(stdin);
			cin.getline(housetype,50);
			fflush(stdin);
			cout<<"Enter is the house available for (purchase/rent)"<<endl;
			fflush(stdin);
			cin.getline(sell,50);
			fflush(stdin);
			cout<<"Enter House Rent"<<endl;
			fflush(stdin);
			cin>>rent;
			fflush(stdin);
			
		}
		
		void addhou(){
			ofstream fout;
			fout.open("House.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
	  		fout.close();
		}
		
		void viewhouse(){
			cout<<"House Number: "<<houseno<<endl;
			cout<<"Street Number: "<<streetno<<endl;
			cout<<"House Type: "<<housetype<<endl;
			cout<<"House Available for: "<<sell<<endl;
			cout<<"House Rent: "<<rent<<endl;
		}
		void checkhouse(){
			ifstream hout;
			hout.open("House.dat",ios::app|ios::binary);
			hout.read((char*)this,sizeof(*this));
			while(!hout.eof()){
				viewhouse();
				hout.read((char*)this,sizeof(*this));
			}
	  		hout.close();
		}
		void managehou(string hn){
			int flag=0;
			int i;
			string current;
			double r;
			
			fstream file;
			file.open("House.dat", ios::in|ios::out|ios::ate|ios::binary);
			file.seekg(0);
			file.read((char*)this,sizeof(*this));
			while(!file.eof()){
				if(hn==houseno){
					cout<<"House Number: "<<houseno<<endl;
					cout<<"Street Number: "<<streetno<<endl;
					cout<<"House Type: "<<housetype<<endl;
					cout<<"House Available for: "<<sell<<endl;
					cout<<"House Rent: "<<rent<<endl;
					cout<<endl;
					cout<<"Press 1 to change House number\nPress 2 to change Street Number\nPress 3 to change House type\nPress 4 to change House Available for\nPress 5 to change Rent"<<endl;
					cout<<"Enter your choice: ";
					cin>>i;
					cout<<endl;
					if(i==1){
						cout<<"Enter the new house number:";
						fflush(stdin);
						cin.getline(houseno,50);
						fflush(stdin);
						int n1,n2;
						n1=file.tellp();
						n2=sizeof(*this);
						file.seekp(n1-n2);
						file.write((char*)this,sizeof(*this));
						flag=1;
						cout<<"Changed Successfully"<<endl;
					}
					else if(i==2){
						cout<<"Enter new street number"<<endl;
						fflush(stdin);
						cin.getline(streetno,50);
						fflush(stdin);
						int n1,n2;
						n1=file.tellp();
						n2=sizeof(*this);
						file.seekp(n1-n2);
						file.write((char*)this,sizeof(*this));
						flag=1;
						cout<<"Changed Successfully"<<endl;
					}
					else if(i==3){
						cout<<"Enter new house type"<<endl;
						fflush(stdin);
						cin.getline(housetype,50);
						fflush(stdin);
						int n1,n2;
						n1=file.tellp();
						n2=sizeof(*this);
						file.seekp(n1-n2);
						file.write((char*)this,sizeof(*this));
						flag=1;
						cout<<"Changed Successfully"<<endl;
					}
					else if(i==4){
						cout<<"Enter new current state of house"<<endl;
						fflush(stdin);
						cin.getline(sell,50);
						fflush(stdin);
						int n1,n2;
						n1=file.tellp();
						n2=sizeof(*this);
						file.seekp(n1-n2);
						file.write((char*)this,sizeof(*this));
						flag=1;
						cout<<"Changed Successfully"<<endl;
					}
					else if(i==5){
						cout<<"Enter new rent of house"<<endl;
						cin>>rent;
						int n1,n2;
						n1=file.tellp();
						n2=sizeof(*this);
						file.seekp(n1-n2);
						file.write((char*)this,sizeof(*this));
						flag=1;
						cout<<"Changed Successfully"<<endl;
					}
				}
			 file.read((char*)this,sizeof(*this));	
			}
			if(flag==0){
				cout<<"Data not found"<<endl;
			}
		}
};
class Duties{
	
	protected:
		char guardname[50], streetno[50], timing[50];
		
	public:
		
		void inpdut(){
			cout<<"Enter Guard Name"<<endl;
			fflush(stdin);
			cin.getline(guardname,50);
			fflush(stdin);
			cout<<"Enter Street Number where guard will perform duty"<<endl;
			fflush(stdin);
			cin.getline(streetno,50);
			fflush(stdin);
			cout<<"Enter Timings Format(8-9)AM/PM"<<endl;
			fflush(stdin);
			cin.getline(timing,50);
			fflush(stdin);
		}
		void adddut(){
			ofstream fout;
			fout.open("Duty.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
	  		fout.close();
		}
		void viewdut(){
			cout<<"Guard Name: "<<guardname<<endl;
			cout<<"Street Number: "<<streetno<<endl;
			cout<<"Timings: "<<timing<<endl;
		}
		void checkduty(){
			ifstream hout;
			hout.open("Duty.dat",ios::app|ios::binary);
			hout.read((char*)this,sizeof(*this));
			while(!hout.eof()){
				viewdut();
				hout.read((char*)this,sizeof(*this));
			}
	  		hout.close();
		}
};
class GuardSalary{
	
	protected:
		
		char gname[50], status[50];
		double salary;
		
	public:
		string getgname(){
			return gname;
		}
		string getstatus(){
			return status;
		}
		void inpguard(){
			cout<<"Enter Guard's Name"<<endl;
			fflush(stdin);
			cin.getline(gname,50);
			fflush(stdin);
			cout<<"Enter Guard's Salary"<<endl;
			fflush(stdin);
			cin>>salary;
			fflush(stdin);
			cout<<"Enter Salary Status (Transferred / Not Transferred)"<<endl;
			fflush(stdin);
			cin.getline(status,50);
			fflush(stdin);
		}
		
		void addsal(){
			ofstream fout;
			fout.open("Salary.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
	  		fout.close();
		}
		
		void getsal(){
			ifstream hout;
			hout.open("Salary.dat",ios::app|ios::binary);
			hout.read((char*)this,sizeof(*this));
			while(!hout.eof()){
				viewsal();
				hout.read((char*)this,sizeof(*this));
			}
	  		hout.close();
		}
		
		void viewsal(){
			cout<<"Guard Name: "<<gname<<endl;
			cout<<"Salary: $"<<salary<<endl;
			cout<<"Status: "<<status<<endl;
		}	
};
class Bill{
	
	protected:
		char billarrived[50], billtype[50];
		int d1,m1,y1,d2,m2,y2;
		
	public:
		
		void inpbill(){
				cout<<"Has bill arrived? \\ Not Arrived"<<endl;
				fflush(stdin);
				cin.getline(billarrived,50);
				fflush(stdin);
				cout<<"Enter Bill type\nWater \\ Electricity \\ Gas"<<endl;
				fflush(stdin);
				cin.getline(billtype,50);
				fflush(stdin);
				cout<<endl;
				cout<<"Enter Arrival date Day"<<endl;
				fflush(stdin);
				cin>>d1;
				fflush(stdin);
				cout<<"Enter Arrival date Month"<<endl;
				fflush(stdin);
				cin>>m1;
				fflush(stdin);
				cout<<"Enter Arrival date Year"<<endl;
				fflush(stdin);
				cin>>y1;
				fflush(stdin);
				cout<<endl;
				cout<<endl;
				cout<<"Enter Due date Day"<<endl;
				fflush(stdin);
				cin>>d2;
				fflush(stdin);
				cout<<"Enter Due date Month"<<endl;
				fflush(stdin);
				cin>>m2;
				fflush(stdin);
				cout<<"Enter Due date Year"<<endl;
				fflush(stdin);
				cin>>y2;
				fflush(stdin);
			}
		
		void addbill(){
			ofstream fout;
			fout.open("Bill.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
	  		fout.close();
		}
		
		void getbills(){
			ifstream hout;
			hout.open("Bill.dat",ios::app|ios::binary);
			hout.read((char*)this,sizeof(*this));
			while(!hout.eof()){
				viewbills();
				hout.read((char*)this,sizeof(*this));
			}
	  		hout.close();
		}
		
		void viewbills(){
			cout<<"Bill Arrived: "<<billarrived<<endl;
			cout<<"Type of Bill: "<<billtype<<endl;
			cout<<"Arrive Date: "<<d1<<"/"<<m1<<"/"<<y1<<endl;
			cout<<"Due Date: "<<d2<<"/"<<m2<<"/"<<y2<<endl;
		}	
};
class Visitor{
	
	protected:
		
		char vname[50], cnum[50];
		long long int pnum;
		
	public:
		
		void inpvis(){
			cout<<"Enter Visitor's Name"<<endl;
			fflush(stdin);
			cin.getline(vname,50);
			fflush(stdin);
			cout<<"Enter Visitor's Car Number"<<endl;
			fflush(stdin);
			cin.getline(cnum,50);
			fflush(stdin);
			cout<<"Enter Phone number"<<endl;
			fflush(stdin);
			cin>>pnum;
			fflush(stdin);
		}
		
		void addvis(){
			ofstream fout;
			fout.open("Visitor.dat",ios::app|ios::binary);
			fout.write((char*)this,sizeof(*this));
	  		fout.close();
		}
		
		void viewvis(){
			cout<<"Visitor Name: "<<vname<<endl;
			cout<<"Car Number: "<<cnum<<endl;
			cout<<"Phone Number: "<<pnum<<endl;
		}
		
		void getvis(){
			ifstream hout;
			hout.open("Visitor.dat",ios::app|ios::binary);
			hout.read((char*)this,sizeof(*this));
			while(!hout.eof()){
				viewvis();
				hout.read((char*)this,sizeof(*this));
			}
	  		hout.close();
		}
};
class Residents{
	protected:
	 char user_name[15];
	 char password[15];	
	 char house_no[10];
	 char total_persons[4];
	 char contact_no[20];
	 char car_number[10];
	 public:
	 char Resident_Name[20];	
	 friend class Estate_Agent;
};
class House_Owner:public Residents{
	public:
		
	void inphouse(){
			cout<<"Enter the Name of the Resident:";
			cin.getline(Resident_Name,20);
			cout<<"Enter the House No. of the Resident:";
			cin.getline(house_no,10);
			cout<<"Enter the total number of Persons in House:";
			cin.getline(total_persons,4);
			cout<<"Enter the Contact Number of Resident:";
			cin.getline(contact_no,20);
			cout<<"Enter the Car Number of the Resident:";
			cin.getline(car_number,10);
			cout<<"Enter Username Of Resident:";
			cin.getline(user_name,15);
		    cout<<"Enter Password of Resident:";	
			cin.getline(password,15);
	}	
		
	void store_resident()
	{
		ofstream fout;
		fout.open("HouseOwnerfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
	  	fout.close();
	}
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"Resident  Name:"<<Resident_Name<<endl;
		cout<<"Resident  House No:"<<house_no<<endl;
		cout<<"Total Number of Persons in house:"<<total_persons<<endl;
		cout<<"Contact Number:"<<contact_no<<endl;
		cout<<"Car Number:"<<car_number<<endl;
		cout<<"User Name:"<<user_name<<endl;
		cout<<"Password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	void view_House_Owners(){
		ifstream hout;
		hout.open("HouseOwnerfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			display_info();
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	void view_House_Owners(string na){
		ifstream hout;
		hout.open("HouseOwnerfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			if(na==Resident_Name){
			   display_info();
		    }
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	 char display_menu(){
		char press;
		cout<<"1-Show Personal Information"<<endl;
		cout<<"2-Change Password"<<endl;
		cout<<"3-View Bills"<<endl;
		cout<<"4-Add Visitor"<<endl;
		cout<<"5-Raise Complain"<<endl;
		cout<<"6-Logout"<<endl;
		cin>>press;
		return press;
	}
	 void viewbill(){
			Bill b;
			b.getbills();
	 }
	 
	void addvisitor(){
			Visitor v;		
			v.inpvis();
			v.addvis();
	}
	void Addcomplain(){
			
			string name,complaint;
			string mainn;
			
			cout<<"Enter your Name: "<<endl;
			getline(cin,name);
			cout<<"Enter your complain: "<<endl;
			getline(cin,complaint);
			
			cout<<endl;
			cout<<name<<endl;
			cout<<complaint<<endl;
			
			mainn = "Complaint By: " + name + "\n" + "Complain: " + complaint + "\n";
			
			ofstream file;
			
			file.open("Complain.dat",ios::app|ios::binary);
			file<<mainn;
			file.close();	
	 }
	bool check_login(string, string);
	void change_password(string name);
};
bool House_Owner::check_login(string user, string pass){
	ifstream fin;
	fin.open("HouseOwnerfile.dat", ios::in|ios::binary);
	if(!fin){
	 cout<<"\nFile Not Found";
    }
	else{
	 fin.read((char*)this, sizeof(*this));
	 while(!fin.eof()){
	 	if(user==user_name){
	 		cout<<"UserName Matched"<<endl;
	 		cout<<user_name<<endl;
	 		if(pass==password){
	 			cout<<"Password Matched"<<endl;
	 			cout<<password<<endl;
	 			return true;
			 }
		 }
	   fin.read((char*)this, sizeof(*this));	 
	 }
	 return false;
	 fin.close();	
	}
}
void House_Owner::change_password(string name){
	fstream file;
		file.open("HouseOwnerfile.dat", ios::in|ios::out|ios::ate|ios::binary);
		file.seekg(0);
		file.read((char*)this,sizeof(*this));
		while(!file.eof()){
			if(name==Resident_Name){
				cout<<"Enter the new password:";
				cin.getline(password,15);
				int n1,n2;
				n1=file.tellp();
				n2=sizeof(*this);
				file.seekp(n1-n2);
				file.write((char*)this,sizeof(*this));
			}
		 file.read((char*)this,sizeof(*this));	
		}
}
class Tenant:public Residents{
	
	public:
	
	void inpten(){
			cout<<"Enter the Name of the Tenant:";
			cin.getline(Resident_Name,20);
			cout<<"Enter the House No. of the Tenant:";
			cin.getline(house_no,10);
			cout<<"Enter the total number of Persons in House:";
			cin.getline(total_persons,10);
			cout<<"Enter the Contact Number of Tenant:";
			cin.getline(contact_no,20);
			cout<<"Enter the Car Number of the Tenant:";
			cin.getline(car_number,10);
			cout<<"Enter Username for Tenant:";
			cin.getline(user_name,15);
		    cout<<"Enter Password for Tenant:";	
			cin.getline(password,15);
	}
		
	void store_resident()
	{
		ofstream fout;
		fout.open("Tenantfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
	  	fout.close();
	}
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"Tenant  Name:"<<Resident_Name<<endl;
		cout<<"Tenant  House No:"<<house_no<<endl;
		cout<<"Total Number of Persons in house:"<<total_persons<<endl;
		cout<<"Contact Number:"<<contact_no<<endl;
		cout<<"Car Number:"<<car_number<<endl;
		cout<<"User Name:"<<user_name<<endl;
		cout<<"Password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	void view_Tenants(){
		ifstream hout;
		hout.open("Tenantfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			display_info();
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	
	void view_Tenants(string na){
		ifstream hout;
		hout.open("Tenantfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			if(Resident_Name==na){
			 display_info();
		     }
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	
	 void viewbill(){
			Bill b;
			b.getbills();
	 }
	char display_menu(){
		char press;
		cout<<"1-Show Personal Information"<<endl;
		cout<<"2-Change Password"<<endl;
		cout<<"3-View Bills"<<endl;
		cout<<"4-Add Visitor"<<endl;
		cout<<"5-Raise Complain"<<endl;
		cout<<"6-Check Empty House"<<endl;
		cout<<"7-Logout"<<endl;
		cin>>press;
		return press;
	}
	 void addvisitor(){
			Visitor v;	
			v.inpvis();
			v.addvis();
	 }
	 void Addcomplain(){
			
			string name,complaint;
			string mainn;
			
			cout<<"Enter your Name: "<<endl;
			getline(cin,name);
			cout<<"Enter your complain: "<<endl;
			getline(cin,complaint);
			
			cout<<endl;
			cout<<name<<endl;
			cout<<complaint<<endl;
			
			mainn = "Complaint By: " + name + "\n" + "Complain: " + complaint + "\n";
			
			ofstream file;
			
			file.open("Complain.dat",ios::app|ios::binary);
			file<<mainn;
			file.close();
			
	 }
	 void checkempty(){
		 House h;
		 h.checkhouse();
	 } 
	bool check_login(string, string);
	void change_password(string);	
};
bool Tenant::check_login(string user, string pass){
	ifstream fin;
	fin.open("Tenantfile.dat", ios::in|ios::binary);
	if(!fin){
	 cout<<"\nFile Not Found";
    }
	else{
	 fin.read((char*)this, sizeof(*this));
	 while(!fin.eof()){
	 	if(user==user_name){
	 		cout<<"UserName Matched"<<endl;
	 		cout<<user_name<<endl;
	 		if(pass==password){
	 			cout<<"Password Matched"<<endl;
	 			cout<<password<<endl;
	 			return true;
			 }
		 }
	   fin.read((char*)this, sizeof(*this));	 
	 }
	 return false;
	 fin.close();	
	}
}
void Tenant::change_password(string name){
	fstream file;
		file.open("Tenantfile.dat", ios::in|ios::out|ios::ate|ios::binary);
		file.seekg(0);
		file.read((char*)this,sizeof(*this));
		while(!file.eof()){
			if(name==Resident_Name){
				cout<<"Enter the new password:";
				cin.getline(password,15);
				int n1,n2;
				n1=file.tellp();
				n2=sizeof(*this);
				file.seekp(n1-n2);
				file.write((char*)this,sizeof(*this));
			}
		 file.read((char*)this,sizeof(*this));	
		}
}
class Member{
	protected:
		char contact[20];
		char user_name[20];
		char password[20];
	public:
			char name[20];	
//	 virtual bool check_login(string,string)=0;
//	 virtual void display_info()=0;		
};
class Estate_Agent:public Member{
	public:
		char office_address[60];
		friend class GeneralSecretary;
	void Add_HomeOwner_Account(){
			House_Owner H;
			H.inphouse();
			H.store_resident();
		}
		
	void viewhouse(){
		House_Owner h;
		h.view_House_Owners();
	}
	//for tenant info storing
	void Add_Rental_Account(){
			Tenant t;
			t.inpten();
			t.store_resident();
		}
	//
	
	void viewtenants(){
		Tenant t;
		t.view_Tenants();
	}
	
	void store_Agent()
	{
		ofstream fout;
		fout.open("Agentfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
	  	fout.close();
	}
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"Estate Agent  Name:"<<name<<endl;
		cout<<"Estate Agent Contact:"<<contact<<endl;
		cout<<"Estate Agent address:"<<office_address<<endl;
		cout<<"Estate Agent user name:"<<user_name<<endl;
		cout<<"Estate Agent password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	void view_Agent_list(){
		ifstream hout;
		hout.open("Agentfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			display_info();
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	void view_Agent_list(string na){
		ifstream hout;
		hout.open("Agentfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			if(name==na){
			 display_info();
		    }
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	char show_menu(){
		char press;
		cout<<"1-Display Information"<<endl;
		cout<<"2-Change Password"<<endl;
		cout<<"3-Add HomeOwner Account"<<endl;
		cout<<"4-Add Rental Account"<<endl;
		cout<<"5-View All HomeOwners"<<endl;
		cout<<"6-View All Tenants"<<endl;
		cout<<"7-Add House"<<endl;
		cout<<"8-Manage House"<<endl;
		cout<<"9-Logout"<<endl;
		cin>>press;
		return press;
	}
	void addhouse(){
			House h;
			h.inphouse();
			h.addhou();
		}
		
	 void managehouse(string hn){
			House h;
			h.managehou(hn);
	 }
	bool check_login(string, string);
	void change_password(string);	
};
bool Estate_Agent::check_login(string user, string pass){
	ifstream fin;
	fin.open("Agentfile.dat", ios::in|ios::binary);
	if(!fin){
	 cout<<"\nFile Not Found";
    }
	else{
	 fin.read((char*)this, sizeof(*this));
	 while(!fin.eof()){
	 	if(user==user_name){
	 		cout<<"UserName Matched"<<endl;
	 		cout<<user_name<<endl;
	 		if(pass==password){
	 			cout<<"Password Matched"<<endl;
	 			cout<<password<<endl;
	 			return true;
			 }
		 }
	   fin.read((char*)this, sizeof(*this));	 
	 }
	 return false;
	 fin.close();	
	}
}
void Estate_Agent::change_password(string name2){
		cout<<name2<<endl;	
		fstream file;
		file.open("Agentfile.dat", ios::in|ios::out|ios::ate|ios::binary);
		file.seekg(0);
		file.read((char*)this,sizeof(*this));
		while(!file.eof()){
			if(name==name2){
				cout<<"Enter the new password:";
				cin.getline(password,15);
				int n1,n2;
				n1=file.tellp();
				n2=sizeof(*this);
				file.seekp(n1-n2);
				file.write((char*)this,sizeof(*this));
			}
		 file.read((char*)this,sizeof(*this));	
		}
}

class Security_Guard:public Member{
	public:
	char salary[12];
	
	void store_Guard()
	{
		ofstream fout;
		fout.open("Guardsfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
	  	fout.close();
	}
	
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"Security Guard  Name:"<<name<<endl;
		cout<<"Security Guard Contact:"<<contact<<endl;
		cout<<"Salary:"<<salary<<endl;
		cout<<"Security Guard user name:"<<user_name<<endl;
		cout<<"Security Guard password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	void view_Guards_list(){
		ifstream hout;
		hout.open("Guardsfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			display_info();
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	void view_Guards_list(string na){
		ifstream hout;
		hout.open("Guardsfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			if(name==na){
		     display_info();
		    }
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	
	char display_menu(){
		char press;
		cout<<"1-Show Personal Information"<<endl;
		cout<<"2-Check Salary Status"<<endl;
		cout<<"3-View Visitor list"<<endl;
		cout<<"4-Check Duties"<<endl;
		cout<<"5-Logout"<<endl;
		cin>>press;
		return press;
	}
	void checksal(string n){
			
			GuardSalary g;
			int flag=0;
			
			fstream file;
			file.open("Salary.dat", ios::in|ios::out|ios::ate|ios::binary);
			file.seekg(0);
			file.read((char*)&g,sizeof(g));
			while(!file.eof()){
				if(n==g.getgname()){
					if(g.getstatus()=="Transferred"){
						cout<<"Your Salary has been transferred"<<endl;
						flag=1;
					}
					else{
						cout<<"Your Salary has not been transferred"<<endl;
						flag=1;
					}
				}
			 file.read((char*)&g,sizeof(g));	
			}
			if(flag==0){
				cout<<"Data not found"<<endl;
			}
	 		
	  }
	  
	  void checkduties(){
			Duties d;
			d.checkduty();
	   }
	  void viewvisitor(){
			
			Visitor v;
			
			v.getvis();
	   }
	friend class GeneralSecretary;
	bool check_login(string, string);
	void change_password(string name);	
};
bool Security_Guard::check_login(string user, string pass){
	ifstream fin;
	fin.open("Guardsfile.dat", ios::in|ios::binary);
	if(!fin){
	 cout<<"\nFile Not Found";
    }
	else{
	 fin.read((char*)this, sizeof(*this));
	 while(!fin.eof()){
	 	if(user==user_name){
	 		cout<<"UserName Matched"<<endl;
	 		cout<<user_name<<endl;
	 		if(pass==password){
	 			cout<<"Password Matched"<<endl;
	 			cout<<password<<endl;
	 			return true;
			 }
		 }
	   fin.read((char*)this, sizeof(*this));	 
	 }
	 return false;
	 fin.close();	
	}
}
class GeneralSecretary:public Member{
      public:
      	char house_number[6];
      Estate_Agent Add_Agent_Account(){
			Estate_Agent E;
			cout<<"Enter Name Of Estate Agent:";
			cin.getline(E.name,20);
			cout<<"Enter the Contact of Estate Agent:";
			cin.getline(E.contact,20);
			cout<<"Enter the shop address of Estate Agent:";
			cin.getline(E.office_address,60);
			cout<<"Enter the username for Estate Agent:";
			cin.getline(E.user_name,20);
		    cout<<"Enter Password For Estate Agent:";	
			cin.getline(E.password,15);
			return E;
		}
		Security_Guard Add_Guard_Account(){
			Security_Guard G;
			cout<<"Enter Name Of Security Guard:";
			cin.getline(G.name,20);
			cout<<"Enter the Contact of Security Guard:";
			cin.getline(G.contact,20);
			cout<<"Enter the salary of Security Guard:";
			cin.getline(G.salary,10);
			cout<<"Enter the username for Security Guard:";
			cin.getline(G.user_name,20);
		    cout<<"Enter Password For Security Guard:";	
			cin.getline(G.password,15);
			return G;
		}
	void Add_Secretary_Account(){
			cout<<"Enter Name Of General Secretary:";
			cin.getline(name,20);
			cout<<"Enter the Contact of General Secretary:";
			cin.getline(contact,20);
			cout<<"Enter the House no. of General Secretary:";
			cin.getline(house_number,10);	
			cout<<"Enter the username for General Secretary:";
			cin.getline(user_name,20);
		    cout<<"Enter Password For General Secretary:";	
			cin.getline(password,15);
		}
	void store_secretary()
	{
		ofstream fout;
		fout.open("Secretaryfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
	  	fout.close();
	}		
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"General Secretary  Name:"<<name<<endl;
		cout<<"General Secretary Contact:"<<contact<<endl;
		cout<<"General Secretary User name:"<<user_name<<endl;
		cout<<"General Secretary Password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	void view_secretaries(string name2){
		ifstream hout;
		hout.open("Secretaryfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			if(name==name2){
		     	display_info();
		      }
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	void view_secretaries(){
		ifstream hout;
		hout.open("Secretaryfile.dat",ios::app|ios::binary);
		hout.read((char*)this,sizeof(*this));
		while(!hout.eof()){
			display_info();
			hout.read((char*)this,sizeof(*this));
		}
	  	hout.close();
	}
	int show_menu(){
		int press;
		cout<<"1-Display Information"<<endl;
		cout<<"2-Change Password"<<endl;
		cout<<"3-Add Agent Account"<<endl;
		cout<<"4-Add Guard Account"<<endl;
		cout<<"5-Add Secretary Account"<<endl;
		cout<<"6-View All Guards"<<endl;
		cout<<"7-View All Agents"<<endl;
		cout<<"8-View All Secretaries"<<endl;
		cout<<"9-Add Bills"<<endl;
		cout<<"10-View All Bills"<<endl;
		cout<<"11-Give Guard Salary"<<endl;
		cout<<"12-View Complains"<<endl;
		cout<<"13-Add Duties"<<endl;
		cout<<"14-Logout"<<endl;
		cin>>press;
		return press;
	 }
		void addbills(){
			Bill b;
			b.inpbill();
			b.addbill();
		}
		
		void viewbill(){
			Bill b;
			b.getbills();
		}
		
	    void givesalary(){
			GuardSalary gs;
			
			gs.inpguard();
	    	gs.addsal();
		}	
		void viewcomplain(){
			
			string mainn;
			
			ifstream file;
			file.open("Complain.dat");
			while(!file.eof()){
				while (getline (file, mainn)) {
  					cout << mainn<<endl;
				}
			}
			
			
			file.close();		
		}
	  void addduty(){
			Duties d;
			d.inpdut();
			d.adddut();
		}	
	bool check_login(string,string);
	void change_password(string);							
};
bool GeneralSecretary::check_login(string user, string pass){
	ifstream fin;
	fin.open("Secretaryfile.dat", ios::in|ios::binary);
	if(!fin){
	 cout<<"\nFile Not Found";
    }
	else{
	 fin.read((char*)this, sizeof(*this));
	 while(!fin.eof()){
	 	if(user==user_name){
	 		cout<<"UserName Matched"<<endl;
	 		cout<<user_name<<endl;
	 		if(pass==password){
	 			cout<<"Password Matched"<<endl;
	 			cout<<password<<endl;
	 			return true;
			 }
		 }
	   fin.read((char*)this, sizeof(*this));	 
	 }
	 return false;
	 fin.close();	
	}
}
void GeneralSecretary::change_password(string name2){
	fstream file;
		file.open("Secretaryfile.dat", ios::in|ios::out|ios::ate|ios::binary);
		file.seekg(0);
		file.read((char*)this,sizeof(*this));
		while(!file.eof()){
			if(name==name2){
				cout<<"Enter the new password:";
				cin.getline(password,15);
				int n1,n2;
				n1=file.tellp();
				n2=sizeof(*this);
				file.seekp(n1-n2);
				file.write((char*)this,sizeof(*this));
			}
		 file.read((char*)this,sizeof(*this));	
		}
}

int main(){
	char press;
	string user_name, password;
	bool check;
	int flag=0;
	House_Owner h1;
	Tenant t1;
    GeneralSecretary s1;
    Estate_Agent e1;
    Security_Guard g1;
    a:
	cout<<"\t\tWelcome to Askari Society Portal"<<endl;
	cout<<"Resident---------(Press 1)"<<endl;
	cout<<"Union Member-----(Press 2)"<<endl;
	cin>>press;
	sleep(1);
	switch(press)
	{
		case '1':
			b:
			system("cls");
			cout<<"Welcome to Askari Society Resident Portal!"<<endl;
			cout<<"House Owner------(Press 1)"<<endl;
			cout<<"Tenant-----------(Press 2)"<<endl;
			cin>>press;
			if(press=='1'){
				re_enter:	
				cout<<"Please enter your user name:";
				cin>>user_name;
				cout<<"Please enter your password:";
				cin>>password;
				check=h1.check_login(user_name, password);
					if(check==true)
					{
						cout<<"Login Successfully"<<endl;
						string na;
						na=h1.Resident_Name;
						system("pause");
						start1:
						 system("cls");
						switch(h1.display_menu()){
							case '1':
							h1.view_House_Owners(na);
							system("pause");
							goto start1;
							case '2':
							cin.ignore();	
							h1.change_password(h1.Resident_Name);
							system("pause");
							goto start1;
							case '3':
							h1.viewbill();
							system("pause");
							goto start1;
							case '4':
							cin.ignore();	
							h1.addvisitor();
							system("pause");
							goto start1;
							case '5':
							cin.ignore();	
							h1.Addcomplain();
							system("pause");
							goto start1;
							case '6':
							system("cls");
							cout<<"Logout Succesfully"<<endl;
							goto a;
							default:
							cout<<"Enter a valid choice"<<endl;
							goto start1;	
						}	
					}
					else
					{
						cout<<"Incorrect Password or Username"<<endl;
						cout<<"Please Re-enter"<<endl;
						system("pause");
						goto re_enter;
					}		
        	}
        	else if(press=='2'){
				re_enter2:
				cout<<"Please enter your user name:";
				cin>>user_name;
				cout<<"Please enter your password:";
				cin>>password;
				check=t1.check_login(user_name, password);

					if(check==true)
					{
						cout<<"Login Successfully"<<endl;
						string na;
						na=t1.Resident_Name;
						system("pause");
						start2:
						 system("cls");
						switch(t1.display_menu()){
							case '1':
							t1.view_Tenants(na);
							system("pause");
							goto start2;
							case '2':
							cin.ignore();		
							t1.change_password(t1.Resident_Name);
							goto start2;
							case '3':
							t1.viewbill();
							system("pause");
							goto start2;
							case '4':
							cin.ignore();	
							t1.addvisitor();
							system("pause");
							goto start2;
							case '5':
							cin.ignore();	
							t1.Addcomplain();
							system("pause");
							goto start2;
							case '6':
							t1.checkempty();
							system("pause");
							goto start2;
							case '7':
							system("cls");
							cout<<"Logout Succesfully"<<endl;
							goto a;
							default:
							cout<<"Enter a valid choice"<<endl;
							goto start2;				
						}	
					}
					else
					{
						cout<<"Incorrect Password or Username"<<endl;
						cout<<"Please Re-enter"<<endl;
						system("pause");
						goto re_enter2;
					}				
   		}
   		else if(press!=1|| press!=0 || press!=2){
   			cout<<"Enter a valid choice"<<endl;
   			system("pause");
   			goto b;
		   }
   	break;		
    case '2':
    	c:
   		system("cls");
   		cout<<"Welcome to Askari Society Union Member Portal"<<endl;
   		cout<<"General Secretary-----(Press 1)"<<endl;
   		cout<<"Estate Agent----------(Press 2)"<<endl;
   		cout<<"Security Guard--------(Press 3)"<<endl;
   		cin>>press;
   		if(press=='1'){
				re_enter3:
				cout<<"Please enter your user name:";
				cin>>user_name;
				cout<<"Please enter your password:";
				cin>>password;
				check=s1.check_login(user_name, password);
					if(check==true)
					{
						cout<<"Login Successfully"<<endl;
						string na;
						na=s1.name;
						system("pause");
						start3:
						 system("cls");
						switch(s1.show_menu()){
							case 1:
							s1.view_secretaries(na);
							system("pause");
							goto start3;
							case 2:
							cin.ignore();		
							s1.change_password(na);
							system("pause");
							//s1.view_secretaries();
							goto start3;
							case 3:
							cin.ignore();	
							e1=s1.Add_Agent_Account();
							e1.store_Agent();
							cout<<"Account Succesfully stored"<<endl;
							system("pause");
							goto start3;
							case 4:
							cin.ignore();	
							g1=s1.Add_Guard_Account();
							g1.store_Guard();
							cout<<"Account Succesfully stored"<<endl;
							system("pause");
							goto start3;
							case 5:
							cin.ignore();	
							s1.Add_Secretary_Account();
							s1.store_secretary();
							cout<<"Account Succesfully stored"<<endl;
							system("pause");
							goto start3;
							case 6:
							g1.view_Guards_list();
							system("pause");
							goto start3;
							case 7:
							e1.view_Agent_list();
							system("pause");
							goto start3;	
							case 8:
							s1.view_secretaries();
							system("pause");
							goto start3;
							case 9:
							cin.ignore();
							s1.addbills();
							system("pause");
							goto start3;
							case 10:
							s1.viewbill();
							system("pause");
							goto start3;
							case 11:
						    cin.ignore();
							s1.givesalary();
							system("pause");
							goto start3;
							case 12:
							s1.viewcomplain();	
							system("pause");
							goto start3;
							case 13:
							cin.ignore();	
							s1.addduty();
							system("Pause");
							goto start3;
					        case 14:
							system("cls");
							cout<<"Logout Succesfully"<<endl;
							goto a;
							default:
							cout<<"Enter a valid choice"<<endl;
							goto start3;		
						}		
					}
					else
					{
						cout<<"Incorrect Password or Username"<<endl;
						cout<<"Please Re-enter"<<endl;
						system("pause");
						goto re_enter3;
					}		
        }
        else if(press=='2'){
				re_enter4:
				cout<<"Please enter your user name:";
				cin>>user_name;
				cout<<"Please enter your password:";
				cin>>password;	
				check=e1.check_login(user_name, password);
					if(check==true)
					{
						cout<<"Login Successfully"<<endl;
						string na;
						na=e1.name;
						system("pause");
						start4:
						char house_no[20];	
						system("cls");
						switch(e1.show_menu()){
							case '1':
							e1.view_Agent_list(na);
							system("pause");
							goto start4;
							case '2':
							cin.ignore();	
							e1.change_password(e1.name);
							system("pause");
							goto start4;
							case '3':
							cin.ignore();	
							e1.Add_HomeOwner_Account();
							cout<<"Account Succesfully Stored"<<endl;
							system("pause");
							goto start4;
							case '4':
							cin.ignore();	
							e1.Add_Rental_Account();
							cout<<"Account Succesfully Stored"<<endl;
							system("pause");
							goto start4;
							case '5':
							h1.view_House_Owners();
							system("pause");
							goto start4;
							case '6':
							t1.view_Tenants();
							system("pause");
							goto start4;
							case '7':
							cin.ignore();	
							e1.addhouse();
							system("pause");
							goto start4;	
							case '8':
							cin.ignore();	
							cout<<"Enter House Number to edit"<<endl;
							cin.getline(house_no,20);
							e1.managehouse(house_no);
							system("pause");
							goto start4;
							case '9':
							system("cls");
							cout<<"Logout Succesfully"<<endl;
							goto a;
							default:
							cout<<"Enter a valid choice"<<endl;
							goto start4;				
						}	
					}
					else
					{
						cout<<"Incorrect Password or Username"<<endl;
						cout<<"Please Re-enter"<<endl;
						system("pause");
						goto re_enter4;
					}		
        }
        else if(press=='3'){
				re_enter5:
				cout<<"Please enter your user name:";
				cin>>user_name;
				cout<<"Please enter your password:";
				cin>>password;
				check=g1.check_login(user_name, password);
					if(check==true)
					{
						cout<<"Login Successfully"<<endl;
						string na;
						na=g1.name;
						system("pause");
						start5:
						system("cls");
						char name[20];
						switch(g1.display_menu()){
							case '1':
						    g1.view_Guards_list(na);
							system("pause");
							goto start5;
							case '2':
							cin.ignore();
							cout<<"Enter the guard name to check salary:";
							cin.getline(name,20);
							g1.checksal(name);
							system("pause");
							goto start5;
							case '3':
							g1.viewvisitor();
							system("pause");
							goto start5;
							case '4':
							g1.checkduties();
							system("pause");
							goto start5;
							case '5':
							system("cls");
							cout<<"Logout Succesfully"<<endl;
							goto a;
							default:
							cout<<"Enter a valid choice"<<endl;
							goto start5;		
						}		
					}
					else
					{
						cout<<"Incorrect Password or Username"<<endl;
						cout<<"Please Re-enter"<<endl;
						system("pause");
						goto re_enter5;
					}		
         }
         else if(press!=1|| press!=2 || press!=3 || press!=0){
   			cout<<"\n\nEnter a valid choice"<<endl;
   			system("pause");
   			goto c;
	      }
         break;
         default:
         cout<<"Please Enter Valid Choice"<<endl;
		 goto a;	
    }
}

//*/
//
//int main(){
//	
//   House_Owner H;
//   H.view_House_Owners();
//}


/*
//int main()
//{
//	Security_Guard G;
//	G.checkduties();
//}
//*/
