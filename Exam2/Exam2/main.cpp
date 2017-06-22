//
//  main.cpp
//  Exam2
//
//  Created by Josiah on 6/22/17.
//  Copyright © 2017 Josiah. All rights reserved.
//

#include <fstream>
#include <vector>
#include "Runner.hpp"

void orderRunners(){
    
    string file = "/Users/Josiah/Desktop/CS/CS172-Online-ALL/CS172-Online-Exam2/Exam2/registrants.txt";
    ifstream fin(file);
    if (fin.fail()){
        cout<<"open failed."<<endl;
        return;
    }
    
    Runner runner, nextFastest, prevFastest, slowest;
    vector<Runner> w, y, g, o, b, l, r;
    int runnerCount = 0;
    
    //finding runner count
    while (!fin.eof()){
        fin >> runner;
        runnerCount++;
    }
    fin.close();
    
    fin.open(file);
    fin >> runner;
    slowest = runner;
    //Finding the slowest runner
    while (!fin.eof()){
        fin >> runner;
        if (runner>slowest){
            slowest = runner;
        }
    }
    nextFastest = slowest;
    fin.close();
    
    fin.open(file);
    fin >> runner;
    //Goes through the file multiple times until every runner is added to a vector
    for (int i=0; i<runnerCount; i++){
        //Finding the next fastest runner
        while (!fin.eof()){
            if (runner<nextFastest && runner>prevFastest){
                nextFastest = runner;
            }
            fin >> runner;
        }
        //adding the next fastest runner into their corresponding vector based on pace
        if (nextFastest.get_pace()>=0 && nextFastest.get_pace()<=360){
            w.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=361 && nextFastest.get_pace()<=420){
            y.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=421 && nextFastest.get_pace()<=480){
            g.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=481 && nextFastest.get_pace()<=540){
            o.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=541 && nextFastest.get_pace()<=600){
            b.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=601 && nextFastest.get_pace()<=720){
            l.push_back(nextFastest);
        }
        if (nextFastest.get_pace()>=720 && nextFastest.get_pace()<=1200){
            r.push_back(nextFastest);
        }
        prevFastest = nextFastest;
        nextFastest = slowest;
        fin.close();
        fin.open(file);
        fin >> runner;
    }
    fin.close();
    
    //The vectors' data is transfered to files
    fstream f;
    
    //transfer to white.txt--------------------------------------
    f.open("white.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("white.txt", ios::out);
    }
    else{
        f.close();
        f.open("white.txt", ios::out | ios::app);
    }
    for (int i=0; i<w.size(); i++){
        f << w.at(i) << endl;
    }
    f.close();
    
    //transfer to yellow.txt--------------------------------------
    f.open("yellow.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("yellow.txt", ios::out);
    }
    else{
        f.close();
        f.open("yellow.txt", ios::out | ios::app);
    }
    for (int i=0; i<y.size(); i++){
        f << y.at(i) << endl;
    }
    f.close();
    
    //transfer to green.txt--------------------------------------
    f.open("green.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("green.txt", ios::out);
    }
    else{
        f.close();
        f.open("green.txt", ios::out | ios::app);
    }
    for (int i=0; i<g.size(); i++){
        f << g.at(i) << endl;
    }
    f.close();
    
    //transfer to orange.txt--------------------------------------
    f.open("orange.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("orange.txt", ios::out);
    }
    else{
        f.close();
        f.open("orange.txt", ios::out | ios::app);
    }
    for (int i=0; i<o.size(); i++){
        f << o.at(i) << endl;
    }
    f.close();
    
    //transfer to blue.txt--------------------------------------
    f.open("blue.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("blue.txt", ios::out);
    }
    else{
        f.close();
        f.open("blue.txt", ios::out | ios::app);
    }
    for (int i=0; i<b.size(); i++){
        f << b.at(i) << endl;
    }
    f.close();
    
    //transfer to lilac.txt--------------------------------------
    f.open("lilac.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("lilac.txt", ios::out);
    }
    else{
        f.close();
        f.open("lilac.txt", ios::out | ios::app);
    }
    for (int i=0; i<l.size(); i++){
        f << l.at(i) << endl;
    }
    f.close();
    
    //transfer to red.txt--------------------------------------
    f.open("red.txt", ios::in);
    if (f.fail()){
        f.close();
        f.open("red.txt", ios::out);
    }
    else{
        f.close();
        f.open("red.txt", ios::out | ios::app);
    }
    for (int i=0; i<r.size(); i++){
        f << r.at(i) << endl;
    }
    f.close();
}

int main(){
    orderRunners();
    
    //Test (I assumed if one worked they all worked because they all relativiely have the same code in terms of file creation/opening and transfering data)
    fstream f;
    Runner r;
    f.open("green.txt", ios::in);
    if (f.fail()){
        cout<<"Failed to open green.txt"<<endl;
        return 0;
    }
    else{
        while(!f.eof()){
            f >> r;
            cout << r << endl;
        }
    }
}
