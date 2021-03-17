#include "snowman.hpp"
#include <cassert>
#include <iostream>
#include <array>

int const arr_size = 4;
int const snowman_size = 10;


array<string,arr_size> hat = {"_===_", " ___ \n .....", "  _  \n  /_\\ ", " ___ \n (_*_)"};
array<string,arr_size> nose = {",", ".", "_", " "};   //the last=  "" or " "
array<string,arr_size> eye = {".", "o", "O", "-"};
array<string,arr_size> left_hand_up = {" ", "\\", " ", " "};  // dont forget \n....
array<string,arr_size> left_hand_down = {"<", " ", "/", " "};
array<string,arr_size> right_hand_up = {" ", "/", " ", " "};
array<string,arr_size> right_hand_down = {">", " ", "\\", " "};
array<string,arr_size> torso = {"( : )", "(] [)", "(> <)", "(   )"};
array<string,arr_size> base = {"( : )", "(\" \")", "(___)", "(   )"};
array< array<string,arr_size> , snowman_size> snowman_arr = {hat, left_hand_up, eye, nose, eye, right_hand_up, left_hand_down, torso, right_hand_down, base};



namespace ariel{
    const int max = 99999999;
    const int min = 11111111;
    const int input_length = 8;
    const int ten = 10;
    const int H = 0;    //had
    const int N = 1;    //nose
    const int L = 2;    //left eye
    const int R = 3;    //right eye
    const int X = 4;    //left hand
    const int Y = 5;    //right hand
    const int T = 6;    //torso
    const int B = 7;    //base

    string snowman(int input){
        string unveiled_input = inputCheck(input);
        if (!unveiled_input.empty()){
            throw invalid_argument(unveiled_input);
        }

        array<int,input_length> input_arr = {};
        for (int i=input_length-1; i>=0; --i){
            input_arr.at(i)= input%ten -1;
            input /= ten;
        }

        string output = " " + hat.at(input_arr.at(H)) + "\n"; 
        output += left_hand_up.at(input_arr.at(X)) + "(" + eye.at(input_arr.at(L))
                + nose.at(input_arr.at(N))+ eye.at(input_arr.at(R)) + ")"
                + right_hand_up.at(input_arr.at(Y)) + "\n";
        output += left_hand_down.at(input_arr.at(X))  + torso.at(input_arr.at(T))
                + right_hand_down.at(input_arr.at(Y)) + "\n";
        output += + " " + base.at(input_arr.at(B));

        return output;
        
    }

    string inputCheck(int input){
        if (input<0){
            return "unveiled number";
        }
        if (input<min){
            return "input too short";
        }
        if (input>max){
            return "input too long";
        }
        int temp = input;
        for (int i=0; i<input_length; ++i){
            int digit = temp%ten;
            if (digit==0 ||digit>4){
                return "unveiled digits";
            }
            temp /= ten;
        }
        return "";
    }

}

