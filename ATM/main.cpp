/*
Project Name: PiATM v 0.1
Objective: Create a low cost secured ATM machine using Raspberry Pi

Created By:
    Mariful Islam Maruf
    Id: 161071036
    11th Batch, 6th (tri)
    E-mail: maruf.cs@outlook.com
    Github: github.com/Maaaaruf
    Shanto-Mariam University of Creative Technology
*/



#include <iostream>
#include<stdlib.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#include <sstream>


using namespace std;

    int opcode, amt, dep, bank;
    string pass, fpass, fBal;
	int bill;
	int transfer, actype, samt;
	int mybal;


    void ff(); //final function, all method are called in this function
class ATM{
public:
    void RFBalance();
    void welcomeScreen();
    void inputPassword();
    void instraction();
    void balanceInquary();
    void payBill();
    void balanceTransfer();
    void withdraw();
    void depositBalance();
    void changepass();
};


int main()
{
    ff();
	return 0;
}


void ff(){
ATM atm;
    atm.RFBalance();
    atm.welcomeScreen();
    atm.inputPassword();

    if (pass==fpass){
        while(1){
            cout<<endl<<endl;
            atm.instraction();
            cin >> opcode;
            if (opcode==7){

            //Write Balance to Database
            fstream pFile("Balance.txt",ios::out | ios::in);     //Open Balance file
            if(pFile.is_open()){
               pFile<<mybal; //write balance data to Balance.txt
            }
            pFile.close();
                break;
            }
            switch (opcode)
            {
                case 1:
                    atm.balanceInquary();
                    break;
                case 2:
                    atm.payBill();
                    break;

                case 3:
                    atm.balanceTransfer();
                    break;

                case 4:

                    atm.withdraw();
                    break;
                case 5:

                    atm.depositBalance();
                    break;
                case 6:

                    atm.changepass();
                    break;
            }
}
    }
    else
		{
				cout << "\tInvalid Pin";
		}



}

void ATM::RFBalance(){

    fstream pFile("Balance.txt",ios::out | ios::in);     //Open Balance file
    if(pFile.is_open()){
       getline(pFile,fBal); //get balance data from Balance.txt
    }
    else
        cout<<"Create a password first";
    pFile.close(); //close file

//To covert String fBal to integer mybal.
    stringstream geek(fBal);
    mybal = 0;
    geek >> mybal;
    pFile.close();
}


void ATM::welcomeScreen(){
    cout << "\t WELCOME TO Pi ATM MACHINE\n";
	cout << "\t Please insert your atm card\n";
    cout << "\t Enter your password: ";
}

void ATM::inputPassword(){
    fstream pFile("Password.txt",ios::out | ios::in); // open password file
    if(pFile.is_open()){
       getline(pFile,fpass); //get password to fpass variable
    }
    else
        cout<<"Create a password first";

    cin >> pass;
    pFile.close(); //close password file
}

void ATM::instraction(){

    cout<< " \tPlease input\n";
	cout<<" \t 1 - inquiry\n";
	cout <<"\t 2 - Bill pay \n";
	cout << "\t 3 - Transfer \n";
	cout<< " \t 4 - Withdraw \n";
	cout<< " \t 5 - deposit \n";
	cout << "\t 6 - Change Password\n";
	cout << "\t 7 - Pull out the card\n";
}

void ATM::balanceInquary(){
    cout << "\t Your balance is = " << mybal;

}

void ATM::payBill(){
        cout << "\tIndicate Bill type"<<endl;
        cout << "\tPlease input"<<endl;
        cout<< "\t1 - Current Bill"<<endl;
        cout << "\t2 - Hospital Bill"<<endl;
        cout << "\t3 - Gas Bill"<<endl;
        cin >> bill;
        fstream hFile("History.txt",ios::out | ios::in | ios::app);
            if(hFile.is_open()){
                switch (bill)
                {
                    case 1:
                        hFile<< "Current Bill Payment Succesful"<<endl;
                        cout <<"\tYour Current BILL Payment was succesful";
                        break;

                    case 2:
                        hFile<< "Hospital Bill payment was successful"<<endl;
                        cout <<"\tYou Hospital Bill payment was successful";
                        break;

                    case 3:
                        hFile<< "Gas Bill payment was successful"<<endl;
                        cout<< "\tYour Gas Bill payment was successful";
                        break;
                }
            }
}

void ATM::balanceTransfer(){
            fstream hFile("History.txt",ios::out | ios::in | ios::app);
            if(hFile.is_open()){
            cout <<"\t Specify destination bank\n";
            cout <<"\t Please Input \n";
            cout <<"\t 1 - One Bank\n";
            cout <<"\t 2 - Rupali Bank\n";
            cout <<"\t 3 - Sonali Bank \n";
            cout <<"\t 5 - DBBL \n";
            cout <<"\t 6 - Meghna Bank \n";
            cout <<"\t 7 - Union Bank\n";
            cout <<"\t 8 - Other\n";
            cin >> bank;

                    cout <<"\t\n Specify Access Bank Account type\n";
                    cout << "\t \n Please input\n";
                    cout << "\t\n 1 - Saving\n";
                    cout << "\t\n 2 -  Current \n";
                    cout << "\t\n 3 - Fixed \n";
//                    break;
                    cin >> actype;
                    switch (actype)
                    {
                    case 1:
                        cout << "\n\t Specify Amount\n";
                        cin>> samt;
                        mybal=mybal-samt; //calculate current balance
                        hFile<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout <<"\t"<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout << "\tNow, your current balance is "<<mybal<<" taka.";
                        break;

                    case 2:
                        cout << "\n\t Specify Amount\n";
                        cin>> samt;
                        mybal=mybal-samt; //calculate current  balance
                        hFile<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout <<"\t"<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout << "Now, your current balance is "<<mybal<<" taka.";
                        break;

                    case 3: cout << "\n\t Specify Amount\n";
                        cin>> samt;
                        mybal=mybal-samt;
                        hFile<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout <<"\t"<< samt << "tk was transfered to Mr. Maruf Successfully"<<endl;
                        cout << "\tNow, your current balance is "<<mybal<<" taka.";
                        break;
            }

		}

}

void ATM::withdraw(){
    fstream hFile("History.txt",ios::out | ios::in | ios::app);
    if(hFile.is_open()){ //check, file opened or not
            cout << "\t Input amt to withdraw: ";
            cin >> amt;
            mybal = mybal - amt;
            hFile<<"Withdrawn Ammount: "<<amt<<" Balance: "<<mybal<<endl; //write transection history
            cout << "\t \n your remaining balance: "<< mybal;
    }
    hFile.close();
}

void ATM::depositBalance(){
        fstream hFile("History.txt",ios::out | ios::in | ios::app);
        if(hFile.is_open()){
            cout << "\t Input amount deposited: ";
            cin >> dep;
            hFile<< dep <<"tk deposited succesfully";
            mybal = mybal + dep;
            cout<< "\tYour current balance is "<<mybal;
    }
}

void ATM::changepass(){
            string tpass;
            fstream pFile("Password.txt",ios::out | ios::in | ios::trunc);
            if(pFile.is_open()){
                cout<< "Please input your new password"<<endl;
                cin>> pass;
                pFile<<pass;
                pFile.close();
                cout<<"Password has been changed successfully"<<endl;
            }
            else
                cout<<"Create a password first";
}

