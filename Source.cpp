#include"AVLTREE.h"

int  main(){

	AVLTREE obj;
	
	int choice, num;
	do{
		cout << "-------------------------------------" << endl;
		cout << "PRESS 1 FOR INSERTION ";
		cout << "\nPRESS 2 FOR IN-ORDER DISPLAY ";
		cout << "\nPRESS 3 FOR PRE-ORDER DISPLAY ";
		cout << "\nPRESS 4 FOR POST-ORDER DISPLAY ";
		cout << "\nPRESS 5 FOR SEARCHING ";
		cout << "\nPRESS 6 FOR EXIT ";
		cout << "\nENTER CHOICE : ";
		cin >> choice;


		switch (choice)
		{
		case 1:
			cout << "-----------------------------------" << endl;
			cout << "\nENTER NUMBER YOU WANT TO INSERT : ";
			cin >> num;
			obj.insertion(num);
			cout << "SUCCESSFULLY INSERTED" << endl;
			cout << "\n";
			break;
		case 2:
			cout << "\n";
			cout << "IN-ORDER DISPLAY : ";
			obj.inOrder();
			cout << "\n";
			break;
		case 3:
			cout << "\n";
			cout << "PRE-ORDER DISPLAY : ";
			obj.preOrder();
			cout << "\n";
			break;
		case 4:
			cout << "\n";
			cout << "POST-ORDER DISPLAY : ";
			obj.postOrder();
			cout << "\n";
			break;
		case 5:
			cout << "\n";
			cout << "ENTER NUMBER YOU WANT TO SEARCH : ";
			cin >> num;
			obj.searching(num);
			cout << "\n";
			break;
		case 6:
			cout << "\n";
			cout << "----------------------" << endl;
			cout << "        THANK YOU      "<< endl;
			cout << "----------------------" << endl;
			break;
		}

	} while (choice != 6);

	system("pause");
	return 0;
}