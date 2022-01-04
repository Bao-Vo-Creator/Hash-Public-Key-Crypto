#include <string>

#include <iostream>

using namespace std;



void hex_to_binary(string &hex){
    string converted_hex="";
    int hex_length=hex.length();

    for(int i=0; i<hex_length; i++){
        if(hex[i] == '0'){
        	converted_hex = converted_hex + "0000";
            continue;
        }

        else if(hex[i] == '1'){
            converted_hex = converted_hex + "0001";
            continue;
        }

        else if(hex[i] == '2'){
            converted_hex = converted_hex + "0010";
            continue;
        }

        else if(hex[i] == '3'){
            converted_hex = converted_hex + "0011";
            continue;
        }

        else if(hex[i] == '4'){
            converted_hex = converted_hex + "0100";
            continue;
        }

        else if(hex[i] == '5'){
            converted_hex = converted_hex + "0101";
            continue;
        }

        else if(hex[i] == '6'){
            converted_hex = converted_hex + "0110";
            continue;
        }

        else if(hex[i] == '7'){
            converted_hex = converted_hex + "0111";
            continue;
        }

        else if(hex[i] == '8'){
            converted_hex = converted_hex + "1000";
            continue;
        }

        else if(hex[i] == '9'){
            converted_hex = converted_hex + "1001";
            continue;
        }

        else if(hex[i] == 'a'){
            converted_hex = converted_hex + "1010";
            continue;
        }

        else if(hex[i] == 'b'){
            converted_hex = converted_hex + "1011";
            continue;
        }

        else if(hex[i] == 'c'){
            converted_hex = converted_hex + "1100";
            continue;
        }

        else if(hex[i] == 'd'){
            converted_hex = converted_hex + "1101";
            continue;
        }

        else if(hex[i] == 'e'){
            converted_hex = converted_hex + "1110";
            continue;
        }

        else if(hex[i] == 'f'){
            converted_hex = converted_hex + "1111";
            continue;
        }

        else{
            cout << "There is an invalid hex value at index " << i << endl << "the value is " << hex[i] << "endl";
            return;
        }

    }

    hex = converted_hex;
}


int amount_of_same_bits(string &hash1, string &hash2){
    int length = hash1.length();
    int amnt = 0;

    for(int i=0; i<length; i++){
        if(hash1[i] == hash2[i]){
            amnt++;
        }
    }

    return amnt;
}



int main(){
    string h1;
    string h2;
    cout << "Enter H1: ";
    cin >> h1;
    cout << "Enter H2: ";
    cin >> h2;

    cout << "The number of hex bits that are the same between H1 and H2 is: " << amount_of_same_bits(h1, h2) << endl;
    hex_to_binary(h1);
    hex_to_binary(h2);
    cout << "The number of binary bits that are the same between H1 and H2 is: " << amount_of_same_bits(h1, h2) << endl;
}