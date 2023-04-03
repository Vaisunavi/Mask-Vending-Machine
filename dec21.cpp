//mask vending machine management
#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>
using namespace std;
class vending_machine
{
	protected:
		int w,cost,totdisp,totcloth,totnh,y,bill;
		string gain;
		int numc,numn,j,pricec,pricen,total;
		char name[20][20];
		int p,pinNumber;
		int InputPinNumber;
	    bool isPinInvalid;
	    int RetryCount;
	    char str[200];
	     fstream vmout;
	    fstream vmin;
   time_t now = time(0);
   char* dt = ctime(&now);
};

class user : public vending_machine
{
	public:
		void disp();
		void cloth();
		void nh();
        
};	
void user :: disp()
{
			vmout.open("sales_report.txt",ios::out|ios::app);
			cout<<"how many masks would you like to buy?"<<endl;
			cin>>w;
			totdisp=200;
			totdisp=totdisp-w;
			cost=5*w;
			vmout<<"\npurchased items: "<<w<<" disposable masks"<<endl;
			vmout<<"the cost of your purchase is: Rs."<<cost<<"/-"<<endl;
			vmout << dt;
			vmout<<"------------------------------------------------------------------"<<endl;
			cout<<"purchased items: "<<w<<" disposable masks"<<endl;
			cout<<"the cost of your purchase is: Rs."<<cost<<"/-"<<endl;
			cout<<"kindly insert the coins and collect your commodity at the drop box"<<endl;
			cout<<"\t~~thank you for using our services~~"<<endl;
			cout<<"\t~wear masks and stay safe~";
		}
void user :: cloth()
		{
			cout<<"how many cloth masks and customized cloth masks would you like to buy?"<<endl;
			cout<<"no.of cloth masks: "<<endl;
			cin>>numc;
			totcloth=200;
			totcloth=200-numc;
			cout<<"no.of customized masks: "<<endl;
			cin>>numn;
			totcloth-=numn;
			for(j=1;j<=numn;j++)
			{	
			cout<<"enter the text to be printed in your customized mask "<<j<<":"<<endl;
			cin>>name[j];
			}
			pricec=10*numc;
			pricen=15*numn;
            total=pricec+pricen;
			vmout<<"\npurchased items:\n"<<numn<<" cloth masks\n"<<numc<<"customized cloth masks"<<endl;
			vmout<<"the total cost of your purchase is: Rs."<<total<<"/-"<<endl;	
			vmout << dt;
			vmout<<"------------------------------------------------------------------"<<endl;
			cout<<"purchased items:\n"<<numn<<" cloth masks\n"<<numc<<"customized cloth masks"<<endl;
			cout<<"the total cost of your purchase is: Rs."<<total<<"/-"<<endl;
			cout<<"kindly insert the coins and collect your commodity at the drop box"<<endl;
			cout<<"\t~~thank you for using our services~~"<<endl;
			cout<<"\t~wear masks and stay safe~";
		}
void user:: nh()
{
			cout<<"how many masks would you like to buy?"<<endl;
			cin>>y;
			totnh=200;
			totnh=totnh-y;
			bill=20*y;
			vmout<<"\npurchased items: "<<y<<" N95 masks"<<endl;
			vmout<<"the cost of your purchase is: Rs."<<bill<<"/-"<<endl;
			vmout <<dt;
			vmout<<"------------------------------------------------------------------"<<endl;
			cout<<"purchased items: "<<y<<" N95 masks"<<endl;
			cout<<"the cost of your purchase is: Rs."<<bill<<"/-"<<endl;
			cout<<"kindly insert the coins and collect your commodity at the drop box"<<endl;
			cout<<"\t~~thank you for using our services~~"<<endl;
			cout<<"\t~wear masks and stay safe~";
			vmout.close();
		}

class admin : public vending_machine
{
	public:
		bool security();
		void sales();
		void change();
		void count();
		void exit();
};
bool admin :: security() 
{	
pinNumber = 12345;
RetryCount = 3;
InputPinNumber = -1;
isPinInvalid =true;
	while (isPinInvalid && RetryCount) {

		cout << "Enter the pin code: ";
		cin >> InputPinNumber;

		if (InputPinNumber == pinNumber) {
			isPinInvalid = false;
		}
		else {
			RetryCount--;
			if(RetryCount)
				cout << "Invalid pin code ! Try again." << endl;
			else
			{
				cout << "Your Account is Locked! 3 retry Reached! Try After some time." << endl;
				return false;
			}

		}

	}

	return true;
}
void admin::sales()
{
	cout<<"The sales report";
	vmin.open("sales_report.txt",ios::in);
	while(!vmin.eof())
	{
		vmin.getline(str,200);
		cout<<str<<endl;
	}
	vmin.close();
}
void admin::count()
{
	cout<<"No.of disposable masks available: "<<totdisp<<endl;
	cout<<"No.of cloth masks available: "<<totcloth<<endl;
	cout<<"No.of N95 masks available: "<<totnh<<endl;
}
int main (void)
{
char str1[20] = "y";
  char str2[20] = "Y";
  char choice[20];
   string again = "y";
   string repeat = "y";
   int k1,k2,k;
	int n,x;
	user u;
	admin a;
	cout<<"\t\t\t\t~WELCOME~"<<endl;
	cout<<"\tWhich one of the following are you?\n1.user\t2.administrator"<<endl;
	cout<<"Your option is: "<<endl;
	cin>>n; 
	switch(n)
		{
			case 1:
			    	cout<<"Do you like to know about the type of masks and their benefits(y/n)?"<<endl;
			    	cin>>choice;
			    	k1 = strcmp(str1, choice);
                    k2 = strcmp(str2, choice);
                    if (k1 == 0 || k2==0)
                    {
				cout<<"\t~TYPES OF MASKS~"<<endl;
				cout<<"1.Disposable masks\n2.Cloth masks\n3.N95 masks"<<endl;
				cout<<"DISPOSABLE MASKS:\n\t*disposable masks are for one time use only.\n";
				cout<<"\t*cost of a disposable mask is Rs.5/-"<<endl;
				cout<<"CLOTH MASKS:\n\t*cloth masks can be reused."<<endl;
				cout<<"\t*cloth masks can be customized with printed names"<<endl;
				cout<<"\t*cost of a cloth mask is Rs.10/-"<<endl;
				cout<<"\t*cost of a customized cloth mask is Rs.15/-"<<endl;
				cout<<"N95 MASKS:\n\t*N95 masks are for one time use only.\n";
				cout<<"\t*these masks are the most safest and are clinically suggested type."<<endl;
				cout<<"\t*cost of a N95 mask is Rs.20/-"<<endl;
				goto option;
			        }
			else{
				goto option;
			}
			option:
                while( again == "y" || again == "Y")
                {
				cout<<"select any one of the following options:"<<endl;
				cout<<"1.Disposable masks\n2.Cloth masks\n3.N95 masks\n4.Exit"<<endl;
				cout<<"your selection is: "<<endl;
				cin>>x;
				switch(x)
				{
					case 1:
						u.disp();
						break;
					case 2:
						u.cloth();
						break;
					case 3:
						u.nh();
						break;
					case 4:
						cout<<"*thank you for using our services*";
						exit(0);
					default:
						cout<<"invalid data";
						break;
			    }
			    cout << "\nWould you like to go again? (Y/N)" << endl;
                cin >> again;
			}
			case 2:
				while( again == "y" || again == "Y")
				{
					a.security();
				cout<<"select any one of the following options:"<<endl;
				cout<<"1.View sales report\n2.View mask count\n3.Exit"<<endl;
				cout<<"Your selection is: "<<endl;
				cin>>k;
				switch(k)
				{
					case 1:
						a.sales();
						break;
					case 2:
						a.count();
						break;
						case 3:
							cout<<"*thank you for using our services*";
							exit(0);
					default:
						cout<<"invalid data";
						break;
			    }
			    cout << "Would you like to go again? (Y/N)" << endl;
                cin >> repeat;
			}
			cout<<"thank you!! visit again";
				break;
			default:
				cout<<"\ninvalid option";
				break;
		}
	}
