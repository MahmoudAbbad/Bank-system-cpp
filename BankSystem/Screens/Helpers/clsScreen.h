#pragma once
#include <iostream>
#include "Global.h"; 
#include "clsDate.h";

using namespace std;

class clsScreen
{
protected: 

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t     " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t\t     " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << "\n\n";
    }
    
        static bool CheckAccessRights(clsUser::enPermissions Permissions)
        {
            if (!CurrentUser.CheckAccessRight(Permissions))
            {
                cout << "\t\t\t\t\t------------------------------------------";
                cout << "\n\n\t\t\t\t\tAccess Denied! Contact your Admin.";
                cout << "\n\n\t\t\t\t\t------------------------------------------";

                return false;
            }
            else
                return true;
        }

};

