#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class Animals{
public:
    string color[6]={"brown","black","grey","white","orange","green"};
    int age;
    string sex[2]={"male","female"};
    string ndeath[2]={"illness","old age"};
    void Reproduce(){
        cout<<"Animal gave birth\n";
    }
    void Die(){
        cout<<"Animal die\n";
    }
};
class Herbivorous:public Animals{
public:
    int nrh=0;
    void Eat(){
        cout<<"Herbivorous animal eat grass\n";
    }
    void Run(){
        cout<<"Herbivorous animal run from predator\n";
    }
};
class Carnivore:public Animals{
public:
    int nrc=0;
    void Hunt(){
        cout<<"Carnivore animal hunt\n";
    }
    void Protect(){
        cout<<"Carnivore animal protects its territory\n";
    }
};
class Butterfly{
public:
  string color;
  Butterfly( ){
   color="orange";
   cout<<"The butterfly is "<<color<<endl;
  }
  void Pollinate(){
   cout<<"Butterfly pollinate"<<endl;
  }
};
class Bacteries{
public:
  string animals[8]={"squirrel","deer","marten","lizard","rabbit","wolf","fox","bear"};
  float size;
  string type;

  Bacteries(){
      size=0.4;
      type="heterotroph";
      cout<<"Bacteries have "<<size<<" nano meters "<<"Type: "<<type<<endl;
  }
  void Decompose(){
      int r=rand()%8;
      cout<<"Bacteries decompose "<<animals[r]<<endl;
  }
};
class Squirrel:public Herbivorous{
public:
  Herbivorous nr;
  Squirrel(){
      int s=rand()%2,a=rand()%10,c=rand()%4;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Squirrel is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Reproduce(){
      cout<<"The squirrel gave birth\n";
  }
  void Eat(){
      cout<<"Squirrel eat  nuts"<<endl;
  }
  void Run(){
      cout<<"Squirrel run from predator\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Squirrel die because of "<<ndeath[d]<<endl;
  }
};
class Deer:public Herbivorous{
public:
  Deer(){
      int s=rand()%2,a=rand()%10,c=rand()%2;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Deer is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Eat(){
        cout<<"Deer eat grass\n";
  }
  void Reproduce(){
      cout<<"The deer gave birth\n";
  }
  void Run(){
      cout<<"Deer run from predator\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Deer die because of "<<ndeath[d]<<endl;
  }
};
class Marten:public Carnivore{
public:
  Marten(){
      int s=rand()%2,a=rand()%10,c=rand()%3;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Marten is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Hunt(){
      cout<<"The marten hunt the squirrel"<<endl;
  }
  void Reproduce(){
      cout<<"The marten gave birth\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Marten die because of "<<ndeath[d]<<endl;
  }
  void Protect(){
      cout<<"Marten protects its territory\n";
  }
};
class Lizard:public Carnivore{
 public:
  Lizard(){
      int s=rand()%2,c=5;
      string color_c=color[c];
      string sex_s=sex[s];
      cout<<"The lizard is "<<color_c<<" Sex:"<<sex_s<<endl;
  }
  void Hunt(){
   cout<<"The lizard hunts the butterfly"<<endl;
  }
  void Reproduce(){
      cout<<"The lizard laid eggs\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Lizard die because of "<<ndeath[d]<<endl;
  }
};
class Rabbit:public Herbivorous{
public:
  Rabbit(){ 
      int s=rand()%2,a=rand()%10,c=rand()%4;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Rabbit is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Home(){
      cout<<"Rabbit make the burrow"<<endl;
  }
  void Reproduce(){
      cout<<"The rabbit gave birth\n";
  }
  void Eat(){
      cout<<"Rabbit eat grass\n";
  }
  void Run(){
      cout<<"Rabbit run from predator\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Rabbit die because of "<<ndeath[d]<<endl;
  }
};
class Wolf:public Carnivore{
 public:
  Wolf(){
      int s=rand()%2,a=rand()%10,c=rand()%4;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Wolf is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Hunt(){
      cout<<"The wolf hunt the deer"<<endl;
  }
  void Protect(){
      cout<<"Wolf defend the tribe"<<endl;
  }
  void Reproduce(){
      cout<<"The wolf gave birth\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Wolf die because of "<<ndeath[d]<<endl;
  }
};
class Fox:public Carnivore{
public:
  Fox(){
      int s=rand()%2,a=rand()%10,c=rand()%5;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Fox is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Hunt(){
      cout<<"The fox hunt the rabbit"<<endl;
  }
  void Reproduce(){
      cout<<"The fox gave birth\n";
  }
  void Die(){
      int d=rand()%2;
      cout<<"Fox die because of "<<ndeath[d]<<endl;
  }
  void Protect(){
      cout<<"Fox protects its territory\n";
  }
};
class Bear:public Carnivore{
 public:
  Bear(){
      int s=rand()%2,a=rand()%10,c=rand()%2;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Bear is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Eat(){
      cout<<"Bear eat honey"<<endl;
  }
  void Reproduce(){
      cout<<"The bear gave birth\n";
  }
    void Hunt(){
      cout<<"The bear hunt the deer"<<endl;
  }
  void Die(){
      int d=rand()%2;
      cout<<"Bear die because of "<<ndeath[d]<<endl;
  }
  void Protect(){
      cout<<"Bear protects its territory\n";
  }
};
int main(){
srand(time(0));
Herbivorous numberh;
Carnivore numberc;
Bacteries bact;
Squirrel squir;
Deer deer;
Marten mar;
Lizard  liza;
Butterfly bfly;
Rabbit rabb;
Wolf auf;
Fox fire;
Bear griz;
numberh.nrh=50;
numberc.nrc=50;
cout<<"\n Play!\n";
while(1){
    int nr=rand()%8+1;
    if(nr==1){
        nr=rand()%8+1;
        if(nr==1){
            squir.Reproduce();
            numberh.nrh++;
        }
        else if(nr==2){
            deer.Reproduce();
            numberh.nrh++;

        }
        else if(nr==3){
            mar.Reproduce();
            numberc.nrc++;

        }
        else if(nr==4){
            liza.Reproduce();
            numberc.nrc++;
        }
        else if(nr==5){
            rabb.Reproduce();
            numberh.nrh++;
        }
        else if(nr==6){
            auf.Reproduce();
            numberc.nrc++;
        }
        else if(nr==7){
            fire.Reproduce();
            numberc.nrc++;
        }
        else{
            griz.Reproduce();
            numberc.nrc++;
        }
    }
    else if(nr==2){
        nr=rand()%8+1;
        if(nr==1){
            squir.Die();
            numberh.nrh--;
        }
        else if(nr==2){
            deer.Die();
            numberh.nrh--;
        }
        else if(nr==3){
            mar.Die();
            numberc.nrc--;
        }
        else if(nr==4){
            liza.Die();
            numberc.nrc--;
        }
        else if(nr==5){
            rabb.Die();
            numberh.nrh--;
        }
        else if(nr==6){
            auf.Die();
            numberc.nrc--;
        }
        else if(nr==7){
            fire.Die();
            numberc.nrc--;
        }
        else{
            griz.Die();
            numberc.nrc--;
        }
    }
    else if(nr==3){
        nr=rand()%3+1;
        if(nr==1){
            squir.Eat();
        }
        else if(nr==2){
            deer.Eat();
        }
        else{
            rabb.Eat();
        }
    }
    else if(nr==4){
        nr=rand()%5+1;
        if(nr==1){
            mar.Hunt();
            sleep(1);
            squir.Run();
            sleep(1);
            nr=rand()%2+1;
            if(nr==1){
                cout<<"The squirrel escaped\n";
            }
            else{
                cout<<"The marten caught the squirrel\n";
                numberh.nrh--;

            }
        }
        else if(nr==2){
            liza.Hunt();
        }
        else if(nr==3){
            auf.Hunt();
            sleep(1);
            deer.Run();
            sleep(1);
            nr=rand()%2+1;
            if(nr==1){
                cout<<"The deer escaped\n";
            }
            else{
                cout<<"The wolf caught the deer\n";
                numberh.nrh--;

            }
        }
        else if(nr==4){
            fire.Hunt();
            sleep(1);
            rabb.Run();
            sleep(1);
            nr=rand()%2+1;
            if(nr==1){
                cout<<"The rabbit escaped\n";
            }
            else{
                cout<<"The fox caught the rabbit\n";
                numberh.nrh--;

            }
        }
        else{
            griz.Hunt();
            sleep(1);
            deer.Run();
            sleep(1);
            nr=rand()%2+1;
            if(nr==1){
                cout<<"The deer escaped\n";
            }
            else{
                cout<<"The bear caught the deer\n";
                numberh.nrh--;

            }
        }
    }
    else if(nr==5){
        nr=rand()%4+1;
        if(nr==1){
            mar.Protect();
        }
        else if(nr==2){
            auf.Protect();
        }
        else if(nr==3){
            fire.Protect();
        }
        else {
            griz.Protect();
        }
    }
    else if(nr==6){
        bact.Decompose();
    }
    else if(nr==7){
        bfly.Pollinate();
    }
    else if(nr==8){
        griz.Eat();  
    }
    else{
        rabb.Home();
    }
    sleep(1);
    if(numberh.nrh==60 or numberc.nrc==60 or numberh.nrh==40 or numberc.nrc==40 ){
        break;
    }
}
return 0;
}

