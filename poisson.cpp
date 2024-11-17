#include<iostream>
#include<cmath>
#include<vector>
#include<fstream>

 using namespace std;
int main(){
 // initialize vector

 vector<int> zaehler(11,0);

// open file 
  ifstream file("datensumme.txt");
 if (!file.is_open()){
   cerr << "Error: Unable to open file datensumme.txt\n";
   return 1;
 }
// read numbers from file and count occurrences
  int zahl,i;
  int N=234;
for ( i=0; i<N; ++i){
  if(file >> zahl){
    if(zahl>=0 && zahl<=10){
      ++zaehler[zahl];
    }else{
      cerr << "Error: Invalid number in file datensumme.txt\n";
    }
  } else{
    cerr << "Error: Unable to read number from file datensumme.txt\n";
    break;
  }
  
}
file.close();

// print all entries of zaehler

for(int k=0; k<zaehler.size(); ++k){
  cout << "Zahl " << k << " kommt " << zaehler[k] << " mal vor" << endl;
}

  ofstream outputfile("hist.txt");
  if(!outputfile.is_open()){
    cerr << "Error: Unable to open file hist.txt\n" <<endl;
    return 1;
  
  }

  // print in txt file

  for(int k=0; k<zaehler.size(); ++k){
    outputfile << k << " " << zaehler[k] << endl;
    
  }
  outputfile.close();

    return 0;
  
}
  
