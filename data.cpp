#include<iostream>
#include<fstream>
using namespace std;
class House_Owner{
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
	public:
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
};
class Tenant{
	 public:
	 char user_name[15];
	 char password[15];	
	 char house_no[10];
	 char total_persons[4];
	 char contact_no[20];
	 char car_number[10];
	 public:
	 char Resident_Name[20];	
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
};
class Secretary{
	public:
	 	protected:
		char contact[20];
		char user_name[20];
		char password[20];
	public:
			char name[20];
			char house_number[6];	
	void display_info()
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"General Secretary  Name:"<<name<<endl;
		cout<<"General Secretary Contact:"<<contact<<endl;
		cout<<"General Secretary User name:"<<user_name<<endl;
		cout<<"General Secretary Password:"<<password<<endl;
		cout<<"--------------------------------------"<<endl;
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
};
class Estate_Agent{
	public:
		protected:
		char contact[20];
		char user_name[20];
		char password[20];
	public:
			char name[20];
			char office_address[60];		
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
};
class Guard{
	public:
		char contact[20];
		char user_name[20];
		char password[20];
	public:
			char name[20];
			char salary[12];
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
};
class Visitor{
	public:
		
		char vname[50], cnum[50];
		long long int pnum;
		void viewvis(){
			cout<<"------------------------------"<<endl;
			cout<<"Visitor Name: "<<vname<<endl;
			cout<<"Car Number: "<<cnum<<endl;
			cout<<"Phone Number: "<<pnum<<endl;
			cout<<"------------------------------"<<endl;
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
class EmptyHouse{
	public:
		char houseno[50],streetno[50],housetype[50],sell[50];
		double rent;
		
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
};
class Bills{
	public:
	char billarrived[50], billtype[50];
		int d1,m1,y1,d2,m2,y2;
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
class Duties{
	public:
		char guardname[50], streetno[50], timing[50];
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
class Gsalary{
		public:	
		char gname[50], status[50];
		double salary;
	 
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
class Complains{
	public:
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
};
int main(){
	House_Owner H;
	Tenant T;
	Secretary S;
	Estate_Agent E;
	Guard G;
	Visitor V;
	EmptyHouse E1;
	Bills b;
	Duties D;
	Gsalary GS;
	Complains C;
	int press;
	a:
	system("cls");
	cout<<"=======DATA VIEWING==================="<<endl;
	cout<<"1-House Owner"<<endl;
	cout<<"2-Tenant"<<endl;
	cout<<"3-Secretary"<<endl;
	cout<<"4-Estate Agent"<<endl;
	cout<<"5-Guard"<<endl;
	cout<<"6-Visitor"<<endl;
	cout<<"7-Empty Houses"<<endl;
	cout<<"8-Guard Salary"<<endl;
	cout<<"9-Complains"<<endl;
	cout<<"Enter Your Choice:";
	cin>>press;
	switch(press){
		case 1:
			H.view_House_Owners();
			system("pause");
			goto a;
		break;
		case 2:
			T.view_Tenants();
			system("pause");
			goto a;
		break;
		case 3:
			S.view_secretaries();
			system("pause");
			goto a;
		break;
		case 4:
			E.view_Agent_list();
			system("pause");
			goto a;
		break;
		case 5:
			G.view_Guards_list();
			system("pause");
			goto a;
		break;
		case 6:
			V.getvis();
			system("pause");
			goto a;
		break;
		case 7:
			E1.checkhouse();
			system("pause");
			goto a;
		break;
		case 8:
			GS.getsal();
			system("pause");
			goto a;
		break;
		case 9:
		   C.viewcomplain();
		   system("pause");
		    goto a;
	}
	
}
