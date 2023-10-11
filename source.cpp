#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;



string convertToASCII(string letter){ //returns ascii code of entered string. in the format of a string.
    string final;
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        final = final + to_string(x);
    }
    return final;
}

string disp_in_binary(int displacement) { //turns displacement into binary.
    string disp;
    string disp_binary;
    disp = to_string(displacement);
    if(displacement < 10){
        disp = "00" + disp;
        std::bitset<12> xl = {(std::stoull(disp, nullptr, 16))};
        disp_binary= xl.to_string();
    }
    else if(displacement < 100 && displacement > 10) {
        disp = "0" + disp;
        std::bitset<12> xl = {(std::stoull(disp, nullptr, 16))};
        disp_binary= xl.to_string();
    }
    else{
        std::bitset<12> xl = {(std::stoull(disp, nullptr, 16))};
        disp_binary= xl.to_string();
    }
    return disp_binary;
}

string Reg_in_binary(string reg){ //register to binary for format 2 opcode generation
    std::bitset<4> exo = {(std::stoull(reg, nullptr, 16))};
    string reg_in_binary = exo.to_string();
    return reg_in_binary;
}



string Addr_in_binary(int location) { //turns addresses into their binary counterparts
    string address;
    string address_binary;
    address = to_string(location);
    if(location < 10){
        address = "00" + address;
        std::bitset<20> xl = {(std::stoull(address, nullptr, 16))};
        address_binary= xl.to_string();
    }
    else if(location < 100 && location > 10) {
        address = "0" + address;
        std::bitset<12> xl = {(std::stoull(address, nullptr, 16))};
        address_binary= xl.to_string();
    }
    else{
        std::bitset<12> xl = {(std::stoull(address, nullptr, 16))};
        address_binary= xl.to_string();
    }
    return address_binary;
}


int count_spaces(string s) { //this function is used to count the spaces in input and seperate the file accordingly
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && s[i + 1] != '\n') {
            count++;
        }
    }
    return count;
}





int main() {

    unordered_map<string, string> hexii; //for turning binary opcodes to hex
    hexii.insert({"1111", "F"});
    hexii.insert({"1110", "E"});
    hexii.insert({"1101", "D"});
    hexii.insert({"1100", "C"});
    hexii.insert({"1011", "B"});
    hexii.insert({"1010", "A"});
    hexii.insert({"1001", "9"});
    hexii.insert({"1000", "8"});
    hexii.insert({"0111", "7"});
    hexii.insert({"0110", "6"});
    hexii.insert({"0101", "5"});
    hexii.insert({"0100", "4"});
    hexii.insert({"0011", "3"});
    hexii.insert({"0010", "2"});
    hexii.insert({"0001", "1"});
    hexii.insert({"0000", "0"});



    unordered_map<string, int> format; //hashmap for the instruction and it's format
    format.insert({"FIX", 1});
    format.insert({"FLOAT", 1});
    format.insert({"HIO", 1});
    format.insert({"NORM", 1});
    format.insert({"SIO", 1});
    format.insert({"TIO", 1});
    format.insert({"ADDR", 2});
    format.insert({"CLEAR", 2});
    format.insert({"COMPR", 2});
    format.insert({"DIVR", 2});
    format.insert({"MULR", 2});
    format.insert({"RMO", 2});
    format.insert({"SHIFTL", 2});
    format.insert({"SHIFTR", 2});
    format.insert({"SUBR", 2});
    format.insert({"SVC", 2});
    format.insert({"TIXR", 2});
    format.insert({"ADD", 3});
    format.insert({"ADDF", 3});
    format.insert({"AND", 3});
    format.insert({"COMP", 3});
    format.insert({"COMPF", 3});
    format.insert({"DIV", 3});
    format.insert({"DIVF", 3});
    format.insert({"J", 3});
    format.insert({"JEQ", 3});
    format.insert({"JGT", 3});
    format.insert({"JLT", 3});
    format.insert({"JSUB", 3});
    format.insert({"LDA", 3});
    format.insert({"LDB", 3});
    format.insert({"LDCH", 3});
    format.insert({"LDF", 3});
    format.insert({"LDL", 3});
    format.insert({"LDS", 3});
    format.insert({"LDT", 3});
    format.insert({"LDX", 3});
    format.insert({"LPS", 3});
    format.insert({"MUL", 3});
    format.insert({"MULF", 3});
    format.insert({"OR", 3});
    format.insert({"RD", 3});
    format.insert({"RSUB", 3});
    format.insert({"SSK", 3});
    format.insert({"STA", 3});
    format.insert({"STB", 3});
    format.insert({"STCH", 3});
    format.insert({"STF", 3});
    format.insert({"STI", 3});
    format.insert({"STL", 3});
    format.insert({"STS", 3});
    format.insert({"STSW", 3});
    format.insert({"STT", 3});
    format.insert({"STX", 3});
    format.insert({"SUB", 3});
    format.insert({"SUBF", 3});
    format.insert({"TD", 3});
    format.insert({"TIX", 3});
    format.insert({"WD", 3});

    unordered_map<string, string> opcode; //hashmap for the opcode and instruction
    opcode.insert({"FIX", "C4"});
    opcode.insert({"FLOAT", "C0"});
    opcode.insert({"HIO", "F4"});
    opcode.insert({"NORM", "C8"});
    opcode.insert({"SIO", "F0"});
    opcode.insert({"TIO", "F8"});
    opcode.insert({"ADDR", "90"});
    opcode.insert({"CLEAR", "B4"});
    opcode.insert({"COMPR", "A0"});
    opcode.insert({"DIVR", "9C"});
    opcode.insert({"MULR", "98"});
    opcode.insert({"RMO", "AC"});
    opcode.insert({"SHIFTL", "A4"});
    opcode.insert({"SHIFTR", "A8"});
    opcode.insert({"SUBR", "94"});
    opcode.insert({"SVC", "B0"});
    opcode.insert({"TIXR", "B8"});
    opcode.insert({"ADD", "18"});
    opcode.insert({"ADDF", "58"});
    opcode.insert({"AND", "40"});
    opcode.insert({"COMP", "28"});
    opcode.insert({"COMPF", "88"});
    opcode.insert({"DIV", "24"});
    opcode.insert({"DIVF", "64"});
    opcode.insert({"J", "3C"});
    opcode.insert({"JEQ", "30"});
    opcode.insert({"JGT", "34"});
    opcode.insert({"JLT", "38"});
    opcode.insert({"JSUB", "48"});
    opcode.insert({"LDA", "00"});
    opcode.insert({"LDB", "68"});
    opcode.insert({"LDCH", "50"});
    opcode.insert({"LDF", "70"});
    opcode.insert({"LDL", "08"});
    opcode.insert({"LDS", "6C"});
    opcode.insert({"LDT", "74"});
    opcode.insert({"LDX", "04"});
    opcode.insert({"LPS", "D0"});
    opcode.insert({"MUL", "20"});
    opcode.insert({"MULF", "60"});
    opcode.insert({"OR", "44"});
    opcode.insert({"RD", "D8"});
    opcode.insert({"RSUB", "4C"});
    opcode.insert({"SSK", "EC"});
    opcode.insert({"STA", "0C"});
    opcode.insert({"STB", "78"});
    opcode.insert({"STCH", "54"});
    opcode.insert({"STF", "80"});
    opcode.insert({"STI", "D4"});
    opcode.insert({"STL", "14"});
    opcode.insert({"STS", "7C"});
    opcode.insert({"STSW", "E8"});
    opcode.insert({"STT", "84"});
    opcode.insert({"STX", "10"});
    opcode.insert({"SUB", "1C"});
    opcode.insert({"SUBF", "5C"});
    opcode.insert({"TD", "E0"});
    opcode.insert({"TIX", "2C"});
    opcode.insert({"WD", "DC"});

    unordered_map<string,string> symbols;
    vector<string> inputWords;//used to store the input file.
    string finalOP[150]; //opcode in hex
    string label[150]; //labels
    string ix[150]; //instructions
    string ref[150];//references
    string opcodee[150]; //opcode in binary
    int locctr[150];//Addresses/location counter.
    string line, word;
    ifstream filein;
    int BASE_ADDRESS;//storing Base.
    string FLAG_N, FLAG_I, FLAG_X, FLAG_B, FLAG_P, FLAG_E;//6 bit flags for generating opcode.
    int displacement;
    string p1, p2, p3, p4, p5, p6, p7, p8;
    string part1;

    filein.open("E:\\college\\systems\\passone\\input.txt");
    int i = 0;
    int counter = 0;
    while (getline(filein, line, '\n')) {
        stringstream s(line);
        while (getline(s, word, ' ')) {
            inputWords.push_back(word);
        }


        switch (count_spaces(line) + 1) {
            case 3:
                label[counter] = inputWords[i];
                ix[counter] = inputWords[i + 1];
                ref[counter] = inputWords[i + 2];
                symbols.insert({ref[counter], label[counter]});
                //cout << inputWords[i] << inputWords[i+1] << inputWords[i+2] << endl;
                i = i + 3;
                break;
            case 2:
                label[counter] = "-";
                ix[counter] = inputWords[i];
                ref[counter] = inputWords[i + 1];
                symbols.insert({ref[counter], label[counter]});
                //cout << inputWords[i] << inputWords[i+1] << endl;
                i = i + 2;
                break;
            case 1:
                label[counter] = "-";
                ix[counter] = inputWords[i];
                ref[counter] = "-";
                i = i + 1;
                break;

        }
        counter++;
    }

//pass one

    locctr[0] = stoi(ref[0]);
    locctr[1] = locctr[0];
    for (int s = 1; s < counter; s++) {
        if (ix[s] == "BTYE") {

                if (ref[s].front() == 'x') {
                    locctr[s + 1] = locctr[s] + ((ref[s].size() - 3) / 2);
                }
                else {
                    locctr[s + 1] = locctr[s] + (ref[s].size() - 3);
                }

        }
        else if (ix[s] == "RESW") {
                locctr[s + 1] = locctr[s] + stoi(ref[s]) * 3;
        }
        else if (ix[s] == "RESB") {
                locctr[s + 1] = locctr[s] + stoi(ref[s]);
        }
        else if (format.find(ix[s]) !=format.end()) { //if the instruction is found as a key in the format hashmap, the corresponding value is added to the location counter(locctr)
                locctr[s + 1] = locctr[s] + format[ix[s]];
        }
        else if (ix[s].front() == '+') {
                locctr[s + 1] = locctr[s] + 4;
        }
        else if(ix[s] == "BASE"){
                BASE_ADDRESS = locctr[s];
                locctr[s + 1] = locctr[s] + 3;
        }
        else {
                locctr[s + 1] = locctr[s] + 3;
        }

    }


    //                            p1 = opcodee[xi].substr(0,4);
    //                            p2 = opcodee[xi].substr(4,4);
    //                            p3 = opcodee[xi].substr(8, 4);
    //                            p4 = opcodee[xi].substr(12,4);
    //                            p5 = opcodee[xi].substr(16,4);
    //                            p6 = opcodee[xi].substr(20,4);
    //                            cout << hexii[p1]<<hexii[p2]<<hexii[p3]<<hexii[p4]<<hexii[p5]<<hexii[p6]<<endl;
    //
    //
    //Printing pass one tables:
    unordered_map<string,int> TA;

    cout << "------------------------------------------------------" << endl;
    cout << "|" << std::setw(10) << "Symbol" << "|" << setw(8) << "Location" << "|" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int l = 0; l < 46; l++) {

        if (label[l] == "-") continue; //we check for this in order to only print the rows where there is a symbol.
        else {
            cout << "|" << std::left << setw(10) << label[l];
            cout << "|" << std::hex << std::internal << setw(8) << locctr[l] << "|" << endl;
            TA.insert({label[i], locctr[i]});
        }
    }
    int len = locctr[counter] - locctr[0];
    cout << endl;
    cout << "length of the program:" << std::hex << len << endl;


    //Pass two:
    string neww;
    string og;
    int switcheroo;
    string R1,R2;
    string og1;
    for (int xi = 0; xi < counter; xi++) {
        og = ix[xi];
        if(ix[xi].front() == '+')  {
            //cout << "GOT ONE" << endl;
            neww = og.erase(0,1); //removes the + sign so i can look the label up in the TA map.
            //cout << format[neww] << endl;
        }
        else {
            //cout << "it's the same" << endl;
            neww = og;
        }
        //cout << "original:" << ix[xi] << "|" <<  neww  << endl;
        if (opcode.find(neww) != opcode.end()) {
            std::bitset<8> bitt = {(std::stoull(opcode[neww], nullptr, 16))};
            string binary_representation = bitt.to_string();
            part1 = binary_representation.substr(0, binary_representation.length() - 2);
            switcheroo = format[neww];
            switch (switcheroo) {
                case 1:
                    part1 = binary_representation;
                    opcodee[xi] == part1;
                    break;
                case 2:
                    part1 = binary_representation;
                    if(ref[xi] == "X" or ref[xi] == "X,A"){
                        R1= "1";
                        R2= "0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] == "S" or ref[xi] =="S,A"){
                        R1="5";
                        R2="0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] == "B" or ref[xi] == "B,A"){
                        R1="4";
                        R2="0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] == "T" or ref[xi] == "T,A"){
                        R1="6";
                        R2="0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] == "F" or ref[xi] == "F,A"){
                        R1="7";
                        R2="0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] == "A"){
                        R1="0";
                        R2="0";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] =="X,B"){
                        R1="1";
                        R2="4";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi]=="B,X"){
                        R1="4";
                        R2="1";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi]=="X,S"){
                        R1="1";
                        R2="5";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi] =="S,X"){
                        R1="5";
                        R2="1";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi]=="X,F"){
                        R1="1";
                        R2="7";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }

                    else if(ref[xi]=="F,X"){
                        R1="7";
                        R2="1";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    else if(ref[xi]=="A,S"){
                        R1="0";
                        R2="5";
                        R1 = Reg_in_binary(R1);
                        R2 = Reg_in_binary(R2);
                        opcodee[xi] = part1+R1+R2;
                    }
                    break;
                case 3:
                    // part1 = binary_representation.substr(0, ix[xi].length()-2);
                    //cout << ix[xi] << ix[xi].front() << endl;
                    //cout << "Entered case 3" << endl;
                    if (ix[xi].front() == '+') {
                        //cout << "GOT ONE" << endl;
                        FLAG_E = "1";
                        FLAG_P = "0";
                        FLAG_B = "0";
                        FLAG_I = "0";
                        FLAG_N = "0";

                        opcodee[xi] = part1 + FLAG_E + FLAG_P + FLAG_B + FLAG_I + FLAG_N + Addr_in_binary(TA[neww]);
                        //cout <<opcodee[xi] << endl;
                    }
                    else {
                        FLAG_E = "0";
                        if (ref[xi].front() == '#') {
                            FLAG_I = "1";
                            FLAG_N = "0";
                        }
                        else if (ref[xi].front() == '@') {
                            FLAG_I = "0";
                            FLAG_N = "1";
                        }
                        else if (ref[xi].find(",x") != string::npos) {
                            FLAG_X = "1";
                        }
                        else {
                            FLAG_I = "1";
                            FLAG_N = "1";
                        }
                        string jkl = symbols[ref[xi]];
                        displacement = TA[jkl] - locctr[xi + 1];
                        if (displacement < 2048 && displacement > -2084) {
                            FLAG_P = "1";
                            FLAG_B = "0";

                        }
                        else{
                            displacement = TA[jkl] - BASE_ADDRESS;
                            FLAG_P = "0";
                            FLAG_B = "1";
                        }

                        opcodee[xi] = part1 + FLAG_N + FLAG_I + FLAG_X + FLAG_B + FLAG_P + FLAG_E + disp_in_binary(displacement);
                        /*cout << "part1:" << part1 << endl;
                        cout <<  FLAG_N << FLAG_I << FLAG_X << FLAG_B << FLAG_P << FLAG_E << endl;
                        cout << "displacement:" << disp_in_binary(displacement) << endl;
                        cout <<ix[xi] <<  opcodee[xi] << endl;
                        p1 = opcodee[xi].substr(0,4);
                        p2 = opcodee[xi].substr(4,4);
                        p3 = opcodee[xi].substr(8, 4);
                        p4 = opcodee[xi].substr(12,4);
                        p5 = opcodee[xi].substr(16,4);
                        p6 = opcodee[xi].substr(20,4);
                        cout << hexii[p1]<<hexii[p2]<<hexii[p3]<<hexii[p4]<<hexii[p5]<<hexii[p6]<<endl;
                         */
                        break;
                    }
            }

        }
        else if(ix[xi] == "START"){
            opcodee[xi] = "NO OPCODE";
            finalOP[xi] = "";
        }
        else if(ix[xi] == "RESW"){
            opcodee[xi] = "NO OPCODE";
            finalOP[xi] = "";
        }
        else if(ix[xi] == "RESB"){
            opcodee[xi] = "NO OPCODE";
            finalOP[xi] = "";
        }
        else if(ix[xi] == "BYTE"){
            if(ref[xi].front() == 'X'){
                og1 = ref[xi];
                og1 = og1.erase(0,1);
                og1.erase(remove(og1.begin(), og1.end(), '\''), og1.end());
                opcodee[xi] = og1;
                finalOP[xi] = og1;
            }
            else if(ref[xi].front() == 'C'){
                og1 = ref[xi];
                og1 = og1.erase(0,1);
                og1.erase(remove(og1.begin(), og1.end(), '\''), og1.end());
                opcodee[xi] = convertToASCII(og1);
                finalOP[xi] = og1;
            }
        }
        else if(ix[xi] == "BASE"){
            opcodee[xi] = "NO OPCODE";
            finalOP[xi] = "";
        }
        else if(ix[xi] == "END"){
            opcodee[xi] = "NO OPCODE";
            finalOP[xi] = "";
        }
    }

    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << std::left << std::setw(10) << "location";
    cout << "|" << std::internal << std::setw(8) << "Label";
    cout << "|" << std::setw(13) << std::left << "Instruction";
    cout << "|" << std::setw(13) << std::left << "Reference";
    cout << "|" << std::setw(13) << std::left << "OPCODE" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int z = 0; z < counter; z++) {

        cout << "|" << std::left << "Ox" << std::hex << std::left << std::setw(8) << locctr[z];
        cout << "|" << std::right << std::setw(8) << label[z] << "|";
        cout << setw(13) << std::left << ix[z];
        cout << "|" << setw(13) << std::left << ref[z];
        if(ix[z] == "START"){
            cout << "|" << setw(13) << opcodee[z] << "|" << endl;
        }
        else if(ix[z] == "RESB"){
            cout << "|" << setw(13) << opcodee[z] << "|" << endl;
        }
        else if(ix[z] == "RESW"){
            cout << "|" << setw(13) << opcodee[z] << "|" << endl;
        }
        else if(ix[z] == "BYTE"){
            cout << "|" << setw(13) << opcodee[z] << "|" << endl;
        }
        else if(ix[z] == "BASE"){
            cout << '|' << setw(13) << opcodee[z] << "|" << endl;
        }
        else if(ix[z] == "END"){
            cout << '|' << setw(13) << opcodee[z] << "|" << endl;
        }
        else{

            if(ix[z].front() == '+'){
                //cout << endl;
                //cout << "this is format 4";
                p1 = opcodee[z].substr(0,4);
                p2 = opcodee[z].substr(4,4);
                p3 = opcodee[z].substr(8, 4);
                p4 = opcodee[z].substr(12,4);
                p5 = opcodee[z].substr(16,4);
                p6 = opcodee[z].substr(20,4);
                p7 = opcodee[z].substr(24,4);
                p8 = opcodee[z].substr(28,4);
                cout << "|" << hexii[p1] << hexii[p2] << hexii[p3] <<hexii[p4] << hexii[p5] << hexii[p6] << hexii[p7] << hexii[p8] << "|" << endl;
                finalOP[z] = hexii[p1] +hexii[p2] + hexii[p3] +hexii[p4] + hexii[p5] +hexii[p6]+ hexii[p7] + hexii[p8];
            }
            else if(format[ix[z]] == 1){
                //cout << endl;
                //cout << "this is format 1";
                p1 = opcodee[z].substr(0,4);
                p2 = opcodee[z].substr(4,4);
                cout << "|" << hexii[p1] << hexii[p2]<< "0000"<<"|"<< endl;
                finalOP[z] = hexii[p1] +hexii[p2] ;
            }
            else if(format[ix[z]] == 2){
                //cout << endl;
                //cout << "this is format 2";
                p1 = opcodee[z].substr(0,4);
                p2 = opcodee[z].substr(4,4);
                p3 = opcodee[z].substr(8,4);
                p4 = opcodee[z].substr(12,4);
                cout << "|" << hexii[p1] << hexii[p2] << hexii[p3] << hexii[p4] << "|" << endl;
                finalOP[z] = hexii[p1] +hexii[p2] + hexii[p3] +hexii[p4];
            }
            else{
                //cout << endl;
                //cout <<"this is format 3";
                p1 = opcodee[z].substr(0,4);
                p2 = opcodee[z].substr(4,4);
                p3 = opcodee[z].substr(8, 4);
                p4 = opcodee[z].substr(12,4);
                p5 = opcodee[z].substr(16,4);
                p6 = opcodee[z].substr(20,4);
                cout << "|" << hexii[p1] << hexii[p2] << hexii[p3] <<hexii[p4] << hexii[p5] << hexii[p6] << "|" << endl;
                finalOP[z] = hexii[p1] +hexii[p2] + hexii[p3] +hexii[p4] + hexii[p5] +hexii[p6];
            }
        }

    }


    //HTE RECORD

    cout << "H:" << label[0] << "/0x" << locctr[0] << "/" << len << endl;

    int Tc = 0;
    int CC;

    while(Tc < counter){
        CC = 0;
        cout << "T:";
        while(CC < 10){
            cout << locctr[Tc] << "/";
            if(ref[Tc] == "RESW" or ref[Tc] == "RESB"){
                Tc++;
                break;
            }
            else{
                cout << finalOP[Tc] << "^";
                CC++;
                Tc++;
            }
        }
        cout << CC << "/" << endl;
    }
    cout << "E:" << "/0x" <<locctr[0] << endl;





    return 0;
}
