#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>



using namespace std;



struct covidMK

{
string Gradovi;
int novi19;
int ozdraveni19;

    covidMK(const string& Gradovi, int novi19, int ozdraveni19)

    : Gradovi(Gradovi), novi19(novi19), ozdraveni19(ozdraveni19){}

bool operator>(const covidMK& c) const
    {
        return novi19 > c.novi19; //tuka ima sporedba za sortiranje po novi19
    }

};

struct SortPointers
{
    bool operator()(const covidMK* a, const covidMK* b) const
    {
        return *a > *b;
    }
};





int main()
{

vector<covidMK*> vcmk;      //ovde se definira vektorot
    //8 zapisi za gradoj i za novi i zaboleni
    vcmk.push_back(new covidMK( "Bitola", 15, 29));

    vcmk.push_back(new covidMK( "Kumanovo", 10, 4));

    vcmk.push_back(new covidMK( "Tetovo", 2, 3));

    vcmk.push_back(new covidMK( "Shtip", 3, 2));

    vcmk.push_back(new covidMK( "Skopje", 84, 135 ));

    vcmk.push_back(new covidMK( "Gostivar", 1, 5));

    vcmk.push_back(new covidMK( "Veles" , 6, 12));

    vcmk.push_back(new covidMK( "Kicevo" , 1, 1));

cout<<"NESORTIRANI"<<endl;
cout<<" "<<endl;


for(const auto* c: vcmk)

cout <<c->Gradovi <<"  novi --- "<< c->novi19 << "  ozdraveni --- " << c->ozdraveni19<< '\n';

cout<<" "<<endl;
cout<<"SORTIRANI"<<endl;
cout<<" "<<endl;

sort(vcmk.begin(), vcmk.end(), SortPointers());

for(const auto* c: vcmk)

cout <<c->Gradovi<<"  novi --- "<< c->novi19 << "  ozdraveni --- " << c->ozdraveni19<< '\n';

//vector vo nadvoreshen fajl
vector<string>v{"Devet","EDinaeset","Trinaeset"};
ofstream outFile ("INKI851CovidMK2204.txt");
for (const auto& e: vcmk) outFile<<e<<endl;

for(auto* c: vcmk)
delete c;



}

