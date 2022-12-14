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
    virtual void Reproduce() = 0;
    virtual void Die() = 0;
};
class Herbivorous:public Animals{
public:
    virtual void Eat() = 0;
    virtual void Run() = 0;
};
class Carnivore:public Animals{
public:
    virtual void Hunt() = 0;
    virtual void Protect() = 0;
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
  Squirrel(){
      int s=rand()%2,a=rand()%10,c=rand()%4;
      string color_c=color[c];
      age=a;
      string sex_s=sex[s];
      cout<<"Squirrel is "<<color_c<<" "<<age<<" year "<<"Sex:"<<sex_s<<endl;
  }
  void Reproduce() override{
      cout<<"The squirrel gave birth\n";
  }
  void Eat() override{
      cout<<"Squirrel eat  nuts"<<endl;
  }
  void Run() override{
      cout<<"Squirrel run from predator\n";
  }
  void Die() override{
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
  void Eat() override{
        cout<<"Deer eat grass\n";
  }
  void Reproduce() override{
      cout<<"The deer gave birth\n";
  }
  void Run() override{
      cout<<"Deer run from predator\n";
  }
  void Die() override{
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
  void Hunt() override{
      cout<<"The marten hunt the squirrel"<<endl;
  }
  void Reproduce() override{
      cout<<"The marten gave birth\n";
  }
  void Die() override{
      int d=rand()%2;
      cout<<"Marten die because of "<<ndeath[d]<<endl;
  }
  void Protect() override{
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
  void Hunt() override{
   cout<<"The lizard hunts the butterfly"<<endl;
  }
  void Reproduce() override{
      cout<<"The lizard laid eggs\n";
  }
  void Protect() override{
      cout<<"Lizard protects its territory\n";
  }
  void Die() override{
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
  void Reproduce() override{
      cout<<"The rabbit gave birth\n";
  }
  void Eat() override{
      cout<<"Rabbit eat grass\n";
  }
  void Run() override{
      cout<<"Rabbit run from predator\n";
  }
  void Die() override{
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
  void Hunt() override{
      cout<<"The wolf hunt the deer"<<endl;
  }
  void Protect() override{
      cout<<"Wolf defend the tribe"<<endl;
  }
  void Reproduce() override{
      cout<<"The wolf gave birth\n";
  }
  void Die() override{
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
  void Hunt() override{
      cout<<"The fox hunt the rabbit"<<endl;
  }
  void Reproduce() override{
      cout<<"The fox gave birth\n";
  }
  void Die() override{
      int d=rand()%2;
      cout<<"Fox die because of "<<ndeath[d]<<endl;
  }
  void Protect() override{
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
  void Eat() {
      cout<<"Bear eat honey"<<endl;
  }
  void Reproduce() override{
      cout<<"The bear gave birth\n";
  }
    void Hunt() override{
      cout<<"The bear hunt the deer"<<endl;
  }
  void Die() override{
      int d=rand()%2;
      cout<<"Bear die because of "<<ndeath[d]<<endl;
  }
  void Protect() override{ 
      cout<<"Bear protects its territory\n";
  }
};
int main(){
srand(time(0));
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
int numberh = 50;
int numberc = 50;
cout<<"\n Play!\n";
while(1){
    int nr=rand()%8+1;
    if(nr==1){
        nr=rand()%8+1;
        if(nr==1){
            squir.Reproduce();
            numberh++;
        }
        else if(nr==2){
            deer.Reproduce();
            numberh++;

        }
        else if(nr==3){
            mar.Reproduce();
            numberc++;

        }
        else if(nr==4){
            liza.Reproduce();
            numberc++;
        }
        else if(nr==5){
            rabb.Reproduce();
            numberh++;
        }
        else if(nr==6){
            auf.Reproduce();
            numberc++;
        }
        else if(nr==7){
            fire.Reproduce();
            numberc++;
        }
        else{
            griz.Reproduce();
            numberc++;
        }
    }
    else if(nr==2){
        nr=rand()%8+1;
        if(nr==1){
            squir.Die();
            numberh--;
        }
        else if(nr==2){
            deer.Die();
            numberh--;
        }
        else if(nr==3){
            mar.Die();
            numberc--;
        }
        else if(nr==4){
            liza.Die();
            numberc--;
        }
        else if(nr==5){
            rabb.Die();
            numberh--;
        }
        else if(nr==6){
            auf.Die();
            numberc--;
        }
        else if(nr==7){
            fire.Die();
            numberc--;
        }
        else{
            griz.Die();
            numberc--;
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
                numberh--;

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
                numberh--;

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
                numberh--;

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
                numberh--;

            }
        }
    }
    else if(nr==5){
        nr=rand()%5+1;
        if(nr==1){
            mar.Protect();
        }
        else if(nr==2){
            auf.Protect();
        }
        else if(nr==3){
            fire.Protect();
        }
        else if(nr==4){
            griz.Protect();
        }
        else{
            liza.Protect();
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
    if(numberh==60 or numberc==60 or numberh==40 or numberc==40 ){
        break;
    }
}
return 0;
}

