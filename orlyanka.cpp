#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Base{
int coordinates, maxcoordinates;
int width = 3;
public:
  Base(){
    maxcoordinates = 50; 
    coordinates = rand()%maxcoordinates+1;
        }
  int get_coordinates()
  { 
    return coordinates;
  }
  int get_width()
  { 
    return width;
  }
};

class Player{
  string name;
  int money;
public:
  Player(){
      name = "";
      money = 0;
  }
  int victory(int win){
    money = money+win;
    return money;
  }
  int rate(int rate){
    money = money-rate;
    return rate;
  }
  string get_name(){ 
    return name;
  }
  int get_money(){
    return money;
  }
  void set_name(string input_name){
    name = input_name;
  }
  void set_money(int input_money){
    money = input_money;
  }
  int shoot(int v, int ang){ 
    return (int)(pow(v, 2)*sin((ang*M_PI)/180))/9.8;
  }
};

class Bank{
  int money;
public:
  Bank(){
    money = 0;
  }
  void put_money(int added_money){
    money = money + added_money;
  }
  int get_money_of_bank(){
    return money;
  }
};

class Game{
  int count_of_players;
  bool game_run;
  vector <Player> list_of_players;
  int number_of_player;
  Bank bank;
  Base base;
public:

  void registration()
  {

    cout<<"Yoo-hoo!"<<endl;
    cout<<"Enter the number of players"<<endl;
    cin>>count_of_players;
    cout<<endl;
    list_of_players.reserve(count_of_players);
    for (int num = 0; num <count_of_players; num++){
      Player new_player;
      string name;
      cout<<"Enter your name"<<endl;
      cin>>name;
      new_player.set_name(name);
      new_player.set_money(10);
      cout<<"Weclome to  "<<name<<" "<<"Your balance is "<<new_player.get_money()<<" "<<"gold"<<endl;
      cout<<"▁ ▂ ▃ ▄ ▅ ▆ ▇ █ ▉ █ ▇ ▆ ▅ ▄ ▃ ▂ ▁"<<endl;
      cout<<endl;
      list_of_players.push_back(new_player);
    }

  }

  void new_game()
  {
    if(count_of_players>0)
    {
      game_run = true;
      cout<<"Start game"<<endl;
      for (int i=0; i<count_of_players; i++)
      {
        bank.put_money(list_of_players[i].rate(5));
        cout<<"Player "<<list_of_players[i].get_name()<<" "<<"makes a bet 5 gold"<<endl;
      }
      cout<<endl<<"Base installation"<<endl;
      cout<<"▁ ▂ ▃ ▄ ▅ ▆ ▇ █ ▉ █ ▇ ▆ ▅ ▄ ▃ ▂ ▁"<<endl;
      cout<<"The base is set. Coordinates: "<<base.get_coordinates()<< ". "<<"Width of base: "<<base.get_width()<< endl;
      click();
    }
    else
    {
        cout<<"At least one player is required to play"<<endl;
    }
  }

  void click()
  {
    while(game_run)
    {
      for (int i = 0; i<count_of_players; i++)
      {
        cout<<"Goes player "<<list_of_players[i].get_name()<<endl;
        int speed, angle;
        cout<<"Enter the speed: "<<endl;
        cin>> speed;
        cout<<"Enter the angle:"<<endl;
        cin>> angle;
        int shot = list_of_players[i].shoot(speed, angle);
        cout<< "Your ball landed in the coordinate: "<<shot<<" "<<endl;
        if (check_win(shot))
        {
          cout<<"Сongratulate "<<list_of_players[i].get_name()<<"!"<<endl;
          int jackpot = bank.get_money_of_bank();
          list_of_players[i].victory(jackpot);
          game_run = false;
          continuation_of_the_game();
        }
      }
    }
   }

  bool check_win(int shot)
  {
    if((base.get_coordinates()-base.get_width())<=shot && shot<=(base.get_coordinates()+base.get_width()))
    {
      cout<<"Hit!"<<endl;
      return true;
    }
    else{ cout<<"Loser!"<<endl; return false;}
  }

  void continuation_of_the_game()
  {
    for (int i = 0; i<count_of_players; i++){
      cout<<list_of_players[i].get_name()<<" "<<"If you want to continue type yes"<<endl;
      string question;
      cin>>question;
      if(question=="yes"){
        cout<<"You're back in the game "<<list_of_players[i].get_name()<<endl;
        continue;
      }
      else{
        cout<<"Goodbye "<<list_of_players[i].get_name()<<endl;
        list_of_players.erase(list_of_players.begin() + i);
        count_of_players--;
      }
    }
    new_game();
   }
};


int main(){
  Game game;
  game.registration();
  game.new_game();
}
