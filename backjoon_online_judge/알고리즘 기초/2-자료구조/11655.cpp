#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    // cout << str;
    
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] >= 'a' && str[i] <= 'm'){
            str[i] = str[i] + 13;
        }
        else if(str[i] >= 'n' && str[i] <= 'z'){
            str[i] = str[i] - 13;
        }
        else if(str[i] >= 'A' && str[i] <= 'M'){
            str[i] = str[i] + 13;
        }
        else if(str[i] >= 'N' && str[i] <= 'Z'){
            str[i] = str[i] - 13;
        }
    }

    cout << str << '\n';
    return 0;
}