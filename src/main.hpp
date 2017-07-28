#include <iostream>
#include <cstring>
using namespace std; //мне очень лень писать std::<что-то>
bool named=false; //менять на true для своего имени.
bool started=false;
string name="Tuubie";
string stat="Жив";
string necrologue;
int print();
int blackhole=-100;//просто
int randomCap=10;
int day=0;
int hunger=100;
int mood=100;
int health=100;
int money=500;
string choice; //вначале это было int, потом всё поменялось, а потом опять. но string осталось.
int next() {
  system("clear");//. . .
  if(choice=="1") {
    if(money-100>0) {
      money=money-100;
      mood=mood-10;
      hunger=hunger+15;
    } else {
      cout<<"STD::ПРЕДУПРЕЖДЕНИЕ: Денег не хватает, действие было не совершено!\n";
    }
  } else if(choice=="2") {
    if(money-200>0) {
      money=money-200;
      mood=mood-10;
      hunger=hunger+35;
    } else {
      cout<<"STD::ПРЕДУПРЕЖДЕНИЕ: Денег не хватает, действие было не совершено!\n";
    }
  } else if(choice=="3") {
    if(money-100>0) {
      money=money-150;
      mood=mood-50; //суп не для всех
      hunger=hunger+30;
    } else {
      cout<<"STD::ПРЕДУПРЕЖДЕНИЕ: Денег не хватает, действие было не совершено!\n";
    }
  } else if(choice=="4") {
    if(1+(rand()%static_cast<int>(randomCap-1+1))==4){
      cout<<"Питон поранился, но не умер.\n";
      health=health-40;
    }
    mood=mood+10;
    hunger=hunger-15;
    if(mood>100){mood=100;}
  } else if(choice=="5") {
      if(money-50>0){
      mood=mood+25;
      hunger=hunger+2;
    cout<<"Ваш питон съел мячик\n";
    } else {
      cout<<"STD::ПРЕДУПРЕЖДЕНИЕ: Денег не хватает, действие было не совершено!\n";
    }
  } else if(choice=="6") {
    mood=mood+15;
    hunger=hunger-10;
  } else if(choice=="7") {
    mood=mood-10;
    hunger=hunger-20;
    money=money+70;
  } else if(choice=="8") {
    mood=mood-30;
    hunger=hunger-35;
    money=money+300;
  } else if(choice=="9") {
    mood=mood-50;
    hunger=hunger-60;
    money=money+900;
  } else if(choice=="10") {
    mood=mood-60;
    hunger=hunger-75;
    money=money+1500;
  } else {
    cout<<"STD::ПРЕДУПРЕЖДЕНИЕ: Действие "<<choice<<" не было распознано, действие не совершено!\n";
  }
  day++;
  health=health+10;
  if(hunger>100){hunger=100;}
  if(mood>100){mood=100;}
  if(health>100){health=100;}
  if(hunger<0){hunger=0;}
  if(mood<0){mood=0;}
  if(health<0){health=0;}
  print();
}
int print() {
  if(health==0||hunger==0||mood==0){stat="Мёртв";}else{
    cout<<"Питон "<<name<<"\n";
    cout<<"Здоровье: "<<health<<"%,"<<"\n";
    cout<<"Сытость: "<<hunger<<"%,"<<"\n";
    cout<<"Настроение: "<<mood<<"%,"<<"\n";
    cout<<"Деньги: "<<money<<"₴,"<<"\n";
  }
  cout<<"Состояние: "<<stat<<"\n";
  if(stat=="Мёртв"){cout<<"[Мёртв]\n";cout<<"Введите некролог: "; cin>>necrologue; cout<<"Вы прошли "<<day<<" дней.\n"<<necrologue;return 1;}else{
    cout<<"==================================\n";
    cout<<"=====Еда=====\n";
    cout<<"1) Дать съесть печеньку (100₴)\n";
    cout<<"2) Дать съесть пирог (200₴)\n";
    cout<<"3) Дать съесть суп (150₴)\n";
    cout<<"=====Развлечения=====\n";
    cout<<"4) Выгулять (0₴)\n";
    cout<<"5) Купить мячик (50₴)\n";
    cout<<"6) Поиграть (0₴)\n";
    cout<<"=====Деньги=====\n";
    cout<<"7) Показывать людям 1 час (+70₴)\n";
    cout<<"8) Показывать людям 4 часа (+300₴)\n";
    cout<<"9) Показывать людям 10 часов (+900₴)\n";
    cout<<"10) Показывать людям весь день (+1500₴)\n";
    cout<<"_________________________________________\n";
    cout<<"|День: "<<day<<"|Имя питона: "<<name<<"|Пока что "<<stat<<"|\n";
    cin>>choice;
    next();
  }
}
int main() {
  if(name==""&&!named) {
    cout<<"Введите имя своего питона: ";
    cin>>name;
  }
  if(!started) {
    cout<<"Добро пожаловать в симулятор питона!\n";
    cout<<"==Как играть?\n";
    cout<<"Ваша задача прожить как можно больше дней. Для этого ухаживайте за своим питоном. Для этого выбирайте вариант действия (номер действия). Каждое действие поднимает один параметр и опускает другие и деньги (если надо). Во время прогулки питон может пораниться, здоровье восстонавливается по 10 единиц в день. Если хоть какой-то параметр упадёт до 0 то питон умрёт. Удачи\n";
  }
  print();
  return 0;
}
