// LamqtaStanka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

class LamyataSpaska
{
public:
	int life;
	int damage;
	int armor;
	LamyataSpaska(int life, int damage, int armor)
	{
		this->life = life;
		this->damage = damage;
		this->armor = armor;
	}
	int get_life_points()
	{
		return life;
	}
	int get_damage()
	{
		return damage;
	}
	int get_armor_points()
	{
		return armor;
	}
};
class Item
{
public:
	int life;
	int damage;
	int armor;
	int sell_cost;
	string type;
	Item(int life, int damage, int armor, int sell_cost, string type)
	{
		this->life = life;
		this->damage = damage;
		this->armor = armor;
		this->sell_cost = sell_cost;
		this->type = type;
	}
	void print_Item()
	{
		cout <<"life:"<<life <<" damage:"<< damage << " armor:" << armor << " sell_cost:" << sell_cost << " type:" << type << endl;
	}
	int get_life_points()
	{
		return life;
	}
	int get_damage()
	{
		return damage;
	}
	int get_armor_points()
	{
		return armor;
	}
	int get_item_sell_cost()
	{
		return sell_cost;
    }
	string get_item_type()
	{
		return type;
	}
};
class Monster
{
public:
	int life;
	int damage;
	int armor;
	int item_drop_chance;
	int chance_to_dodge_attacks;
	Monster(int life, int damage, int armor,int item_drop_chance,int chance_to_dodge_attacks)
	{
		this->life = life;
		this->damage = damage;
		this->armor = armor;
		this->item_drop_chance = item_drop_chance;
		this->chance_to_dodge_attacks = chance_to_dodge_attacks;
	}
	int get_life_points()
	{
		return life;
	}
	int get_damage()
	{
		return damage;
	}
	int get_armor_points()
	{
		return armor;
	}
	int get_chance_to_drop_item()
	{
		return item_drop_chance;
	}
	int get_chance_to_dodge_attack()
	{
		return chance_to_dodge_attacks;
	}
};
class Player
{
   public:
	   int life;
	   int damage;
	   int armor;
	   int gold_owned;
	   int damageTakenDuringLastBattle = 0;
	   int daysPassed = 0;
	   vector<Item> Inventory;
	   vector<Item> Equipment;
	   Player(int life, int damage, int armor,int gold_owned,vector<Item> Inventory, vector<Item> Equipment)
	   {
		   this->life = life;
		   this->damage = damage;
		   this->armor = armor;
		   this->gold_owned = gold_owned;
		   this->Inventory = Inventory;
		   this->Equipment = Equipment;
	   }
	   int get_character_life_points()
	   {
		   return life;
	   }
	   int get_character_damage()
	   {
		   return damage;
	   }
	   int get_character_armor_points()
	   {
		   return armor;
	   }
	   int get_character_gold_owned()
	   {
		   cout <<"Your characters has " << gold_owned << " gold coins" <<endl;
		   return gold_owned;
	   }
	   int get_days_passed()
	   {
		   cout << daysPassed << " days have passed since you started your adventure" << endl;
		   return daysPassed;
	   }
	   vector<Item> get_Player_Inventory()
	   {
		   return Inventory;
	   }
	   void calculate_stats()
	   {
		   int calculate_life = get_character_life_points();
		   int calculate_damage = get_character_damage();
		   int calculate_armor = get_character_armor_points();
		   for (auto elem : Equipment) {
			   calculate_armor = elem.get_armor_points()+calculate_armor;
			   calculate_life = elem.get_life_points() + calculate_life;
			   calculate_damage = elem.get_damage() + calculate_damage;
		   }
		   cout << "Your hero has " << calculate_life-damageTakenDuringLastBattle << " life, " << calculate_damage << " damage, " << calculate_armor << " armor, "<< gold_owned << " gold coins."<<endl;
	   }
	   int calculate_max_health()
	   {
		   int calculate_life = get_character_life_points();
		   for (auto elem : Equipment) {
			   calculate_life = elem.get_life_points() + calculate_life;
		   }
		   return calculate_life;
	   }
	   int calculate_max_damage()
	   {
		   int calculate_damage = get_character_damage();
		   for (auto elem : Equipment) {
			   calculate_damage = elem.get_damage() + calculate_damage;
		   }
		   return calculate_damage;
	   }
	   int calculate_max_armor()
	   {
		   int calculate_armor = get_character_armor_points();
		   for (auto elem : Equipment) {
			   calculate_armor = elem.get_armor_points() + calculate_armor;
		   }
		   return calculate_armor;
	   }
	   void print_My_Inventory()
	   {
		   cout << "You have these items in your inventory:" << endl;
		   int index = 1;
		   for (auto elem : Inventory) {
			   cout << index << ":";
			   elem.print_Item();
			   index++;
		   }
		   cout << endl;
	   }
	   void print_My_Equipment()
	   {
		   cout << "You have these items equipped:" << endl;
		   int index = 1;
		   for (auto elem : Equipment) {
			   cout << index << ":";
			   elem.print_Item();
			   index++;
		   }
		   cout << endl;
	   }
	   void sell_items()
	   {
		   if (Inventory.empty())
		   {
			   cout << "You can't sell any items because your inventory is empty" << endl;
		   }
		   else
		   {
			   int index = 0;
			   print_My_Inventory();
			   cout << "Which item index would you like to sell" << endl;
			   cin >> index;
			   index = index - 1;
			   gold_owned = Inventory[index].get_item_sell_cost() + gold_owned;
			   Inventory.erase(Inventory.begin() + index);
		   }
	   }
	   void equip_items()
	   {
		   if (Inventory.empty())
		   {
			   cout << "You can't equip any items because your inventory is empty" << endl;
		   }
		   else
		   {
			   int index_Inventory = 0;
			   int index_Equipment = 0;
			   print_My_Inventory();
			   print_My_Equipment();
			   cout << "Which item index would you like to equip:" << endl;
			   cin >> index_Inventory;
			   if (index_Inventory>Inventory.size())
			   {
				   cout << "Please enter an index of an item that exists" << endl;
			   }
			   else
			   {
                   index_Inventory = index_Inventory - 1;
				   if (Equipment.size() <= 6)
				   {
					   int ArmorsEquiped = 0;
					   int WeaponsEquiped = 0;
					   for (size_t i = 0; i < Equipment.size(); i++)
					   {
						   if (Equipment[i].get_item_type() == "Armor")
						   {
							   ArmorsEquiped++;
						   }
						   if (Equipment[i].get_item_type() == "Weapon")
						   {
							   WeaponsEquiped++;
						   }
					   }
					   if (ArmorsEquiped == 5 && Inventory[index_Inventory].get_item_type() == "Armor")
					   {
						   cout << "You can't equip more armor" << endl;
					   }
					   if (WeaponsEquiped == 2 && Inventory[index_Inventory].get_item_type() == "Weapon")
					   {
						   cout << "You can't equip more Weapons" << endl;
					   }
					   else
					   {
						   Inventory[index_Inventory].print_Item();
						   cout << "has been equiped" << endl;
						   Equipment.push_back(Inventory[index_Inventory]);
						   Inventory.erase(Inventory.begin() + index_Inventory);
					   }
				   }
				   else
				   {
					   cout << "Which equipment would you like to unequip:" << endl;
					   cin >> index_Equipment;
					   index_Equipment = index_Equipment - 1;
					   if (index_Equipment > Equipment.size())
					   {
						   cout << "Please enter an index of an item that exists" << endl;
					   }
					   if (Inventory[index_Inventory].get_item_type() != Equipment[index_Equipment].get_item_type())
					   {
						   cout << "The types of the items must be the same in order to swap them." << endl;
					   }
					   else
					   {
						   Inventory[index_Inventory].print_Item();
						   cout << "has been swaped with:" << endl;
						   Equipment[index_Equipment].print_Item();
						   swap(Inventory[index_Inventory], Equipment[index_Equipment]);
					   }
				   }
			   }
		   }

	   }
	   void rest_at_the_inn()
	   {
		   if (gold_owned<10)
		   {
			   cout << "You didn't have enough gold to sleep at the inn so you mined gold instead" << endl;
			   mine_gold_behind_inn();
		   }
		   else
		   {
		       cout << "You rested at the inn and your HP has been replenished" << endl;
			   gold_owned = gold_owned - 10;
			   cout << "You have: "<<gold_owned << " gold coins left."<< endl;
			   daysPassed = daysPassed + 1;
			   life = calculate_max_health();
			   damageTakenDuringLastBattle = 0;
		   }
	   
	   }
	   void mine_gold_behind_inn()
	   {
		   gold_owned = gold_owned + 10;
		   daysPassed = daysPassed + 1;
	   }
	   void go_to_the_forest()
	   {
		   string index_of_Monster;
		   Monster weak_Monster = Monster(20, 2, 0, 20, 0);
		   Monster normal_Monster = Monster(80, 4, 2, 40, 0);
		   Monster hard_Monster = Monster(120, 6, 3, 60, 30);
		   cout << "Which monster would you like to fight:" << endl;
		   cout << "1:Weak Monster" << " Life Points:" << weak_Monster.get_life_points() << " Damage:" << weak_Monster.get_damage() << " Armor:" << weak_Monster.get_armor_points() << " Chance to drop an item:" << weak_Monster.get_chance_to_drop_item() << "% chance to dodge attacks:" << weak_Monster.get_chance_to_dodge_attack() << "%." << endl;
		   cout << "2:Normal Monster" << " Life Points:" << normal_Monster.get_life_points() << " Damage:" << normal_Monster.get_damage() << " Armor:" << normal_Monster.get_armor_points() << " Chance to drop an item:" << normal_Monster.get_chance_to_drop_item() << "% chance to dodge attacks:" << normal_Monster.get_chance_to_dodge_attack() << "%." << endl;
		   cout << "3:Hard Monster" << " Life Points:" << hard_Monster.get_life_points() << " Damage:" << hard_Monster.get_damage() << " Armor:" << hard_Monster.get_armor_points() << " Chance to drop an item:" << hard_Monster.get_chance_to_drop_item() << "% chance to dodge attacks:" << hard_Monster.get_chance_to_dodge_attack() <<"%."<< endl;
		   cout << "Choose an index 1,2 or 3:";
		   int player_life = calculate_max_health() - damageTakenDuringLastBattle;
		   int player_damage = calculate_max_damage();
		   int player_armor = calculate_max_armor();
		   cin >> index_of_Monster;
		   if (index_of_Monster == "1")
		   {
			   int monster_life = weak_Monster.get_life_points();
			   int monster_damage = weak_Monster.get_damage();
			   int monster_armor = weak_Monster.get_armor_points();
			   player_damage = player_damage - weak_Monster.get_armor_points();
			   monster_damage = monster_damage - calculate_max_armor();
			   if (monster_damage <= 0)
			   {
				   monster_damage = 0;
			   }
			   while (player_life > 0 && monster_life > 0)
			   {
				   player_life = player_life - monster_damage;
				   cout << "Player takes " << monster_damage << " damage and has " << player_life << " life left" << endl;
				   monster_life = monster_life - player_damage;
				   cout << "Weak Monster takes " << player_damage << " damage and has " << monster_life << " life left" << endl;
				   damageTakenDuringLastBattle = calculate_max_health() - player_life;
				   if (monster_life <= 0)
				   {
					   cout << "Weak Monster has been defeated!" << endl;
					   int goldRecievedFromMonster = 1 + (rand() % 3);
					   cout << "You recieved " << goldRecievedFromMonster << " gold coins" << endl;
					   gold_owned = gold_owned + goldRecievedFromMonster;
				   }
				   if (player_life <= 0)
				   {
					   cout << "You have been defeated by weak monster and lost: " << gold_owned << " gold coins" << endl;
					   gold_owned = 0;
					   daysPassed = daysPassed + 2;
					   cout << "You respawned at a nearby inn" << endl;
				   }
			   }
			   srand(time(0));
			   int itemDropChance = 1 + (rand() % 100);
			   //cout << itemDropChance << endl; Roller for the drop chance
			   if (monster_life <= 0 && itemDropChance <= 20)
			   {
				   string item_type;
				   cout << "choose item type 1 for weapon 2 for armor:";
				   cin >> item_type;
				   if (item_type == "1")
				   {
					   cout << "you have choosen weapon" << endl;
					   int weapon_damage = 1 + (rand() % 10);
					   int item_sell_cost = 1 + (rand() % 5);
					   Item Dropped_Item = Item(0, weapon_damage, 0, item_sell_cost, "Weapon");
					   cout << "You have received the following item: ";
					   Dropped_Item.print_Item();
					   Inventory.push_back(Dropped_Item);
				   }
				   if (item_type == "2")
				   {
					   cout << "you have choosen armor" << endl;
					   int armor_life = 1 + (rand() % 10);
					   int armor_points = 1 + (rand() % 3);
					   int item_sell_cost = 1 + (rand() % 5);
					   Item Dropped_Item = Item(armor_life, 0, armor_points, item_sell_cost, "Armor");
					   cout << "You have received the following item: ";
					   Dropped_Item.print_Item();
					   Inventory.push_back(Dropped_Item);
				   }
			   }
		   }
			   if (index_of_Monster == "2")
			   {
				   int monster_life = normal_Monster.get_life_points();
				   int monster_damage = normal_Monster.get_damage();
				   int monster_armor = normal_Monster.get_armor_points();
				   player_damage = player_damage - normal_Monster.get_armor_points();
				   monster_damage = monster_damage - calculate_max_armor();
				   if (monster_damage <= 0)
				   {
					   monster_damage = 0;
				   }
				   while (player_life > 0 && monster_life > 0)
				   {
					   player_life = player_life - monster_damage;
					   cout << "Player takes " << monster_damage << " damage and has " << player_life << " life left" << endl;
					   monster_life = monster_life - player_damage;
					   cout << "Normal Monster takes " << player_damage << " damage and has " << monster_life << " life left" << endl;
					   damageTakenDuringLastBattle = calculate_max_health() - player_life;
					   if (monster_life <= 0)
					   {
						   cout << "Normal Monster has been defeated!" << endl;
						   int goldRecievedFromMonster = 2 + (rand() % 10);
						   cout << "You recieved " << goldRecievedFromMonster << " gold coins" << endl;
						   gold_owned = gold_owned + goldRecievedFromMonster;
					   }
					   if (player_life <= 0)
					   {
						   cout << "You have been defeated by normal monster and lost: " << gold_owned << " gold coins" << endl;
						   gold_owned = 0;
						   daysPassed = daysPassed + 2;
						   cout << "You respawned at a nearby inn" << endl;
					   }
				   }
				   srand(time(0));
				   int itemDropChance = 1 + (rand() % 100);
				   //cout << itemDropChance << endl; Roller for the drop chance
				   if (monster_life <= 0 && itemDropChance <= 40)
				   {
					   string item_type;
					   cout << "choose item type 1 for weapon 2 for armor:";
					   cin >> item_type;
					   if (item_type == "1")
					   {
						   cout << "you have choosen weapon" << endl;
						   int weapon_damage = 1 + (rand() % 15);
						   int item_sell_cost = 1 + (rand() % 10);
						   Item Dropped_Item = Item(0, weapon_damage, 0, item_sell_cost, "Weapon");
						   cout << "You have received the following item: ";
						   Dropped_Item.print_Item();
						   Inventory.push_back(Dropped_Item);
					   }
					   if (item_type == "2")
					   {
						   cout << "you have choosen armor" << endl;
						   int armor_life = 1 + (rand() % 20);
						   int armor_points = 1 + (rand() % 5);
						   int item_sell_cost = 1 + (rand() % 10);
						   Item Dropped_Item = Item(armor_life, 0, armor_points, item_sell_cost, "Armor");
						   cout << "You have received the following item: ";
						   Dropped_Item.print_Item();
						   Inventory.push_back(Dropped_Item);
					   }
				   }
			   }
			   if (index_of_Monster == "3")
			   {
				   int monster_life = hard_Monster.get_life_points();
				   int monster_damage = hard_Monster.get_damage();
				   int monster_armor = hard_Monster.get_armor_points();
				   player_damage = player_damage - hard_Monster.get_armor_points();
				   monster_damage = monster_damage - calculate_max_armor();
				   if (monster_damage <= 0)
				   {
					   monster_damage = 0;
				   }
				   srand(time(0));
				   while (player_life > 0 && monster_life > 0)
				   {
					   int ChanceToDodgeAttack = 1 + (rand() % 100);
					   player_life = player_life - monster_damage;
					   cout << "Player takes " << monster_damage << " damage and has " << player_life << " life left" << endl;
					   monster_life = monster_life - player_damage;
					   if (ChanceToDodgeAttack <= 30)
					   {
						   monster_life = monster_life + player_damage;
						   cout << "Hard Monster dodges player attack and doesn't take any damage" << endl;
					   }
					   else
					   {
						   cout << "Hard Monster takes " << player_damage << " damage and has " << monster_life << " life left" << endl;
					   }
					   if (monster_life <= 0)
					   {
						   cout << "Hard Monster has been defeated!" << endl;
						   int goldRecievedFromMonster = 5 + (rand() % 10);
						   cout << "You recieved " << goldRecievedFromMonster << " gold coins" << endl;
						   gold_owned = gold_owned + goldRecievedFromMonster;
					   }
					   if (player_life <= 0)
					   {
						   cout << "You have been defeated by hard monster and lost: " << gold_owned << " gold coins" << endl;
						   gold_owned = 0;
						   daysPassed = daysPassed + 2;
						   cout << "You respawned at a nearby inn" << endl;
					   }
					   damageTakenDuringLastBattle = calculate_max_health() - player_life;
				   }
				   int itemDropChance = 1 + (rand() % 100);
				   //cout << itemDropChance << endl; Roller for the drop chance
				   if (monster_life <= 0 && itemDropChance <= 60)
				   {
					   string item_type;
					   cout << "choose item type 1 for weapon 2 for armor:";
					   cin >> item_type;
					   if (item_type == "1")
					   {
						   cout << "you have choosen weapon" << endl;
						   int weapon_damage = 1 + (rand() % 30);
						   int item_sell_cost = 1 + (rand() % 25);
						   Item Dropped_Item = Item(0, weapon_damage, 0, item_sell_cost, "Weapon");
						   cout << "You have received the following item: ";
						   Dropped_Item.print_Item();
						   Inventory.push_back(Dropped_Item);
					   }
					   if (item_type == "2")
					   {
						   cout << "you have choosen armor" << endl;
						   int armor_life = 1 + (rand() % 50);
						   int armor_points = 1 + (rand() % 10);
						   int item_sell_cost = 1 + (rand() % 20);
						   Item Dropped_Item = Item(armor_life, 0, armor_points, item_sell_cost, "Armor");
						   cout << "You have received the following item: ";
						   Dropped_Item.print_Item();
						   Inventory.push_back(Dropped_Item);
					   }

				   }
			   }
	   }
	   string fight_LamyataSpaska(string &writeline)
	   {
		   LamyataSpaska EndBoss = LamyataSpaska(10000, 45, 10);
		   int player_life = calculate_max_health()-damageTakenDuringLastBattle;
		   int player_damage = calculate_max_damage();
		   int player_armor = calculate_max_armor();
		   int monster_life = EndBoss.get_life_points();
		   int monster_damage = EndBoss.get_damage();
		   int monster_armor = EndBoss.get_armor_points();
		   player_damage = player_damage - EndBoss.get_armor_points();
		   monster_damage = monster_damage - calculate_max_armor();
		   if (monster_damage <= 0)
		   {
		     monster_damage = 0;
		   }
		   while (player_life > 0 && monster_life > 0)
		   {
				   player_life = player_life - monster_damage;
				   cout << "Player takes " << monster_damage << " damage and has " << player_life << " life left" << endl;
				   monster_life = monster_life - player_damage;
				   cout << "Lamyata Spaska takes " << player_damage << " damage and has " << monster_life << " life left" << endl;
				   if (player_life <= 0)
				   {
					   cout << "You have lost the battle with the Dragon Spaska and lost "<<gold_owned<<" gold coins." << endl;
					   gold_owned = 0;
					   cout << "You Have been resurrected at the inn." << endl;
					   daysPassed = daysPassed + 2;
					   cout << "You can try again after acquire better gear." << endl;
				   }
				   if (monster_life <= 0)
				   {
					   cout << "Congratulations!" << endl;
					   cout << "You have defeated Dragon Spaska and restored balance to the force" << endl;
					   cout << "You completed the journey in "<< daysPassed << " days" << endl;
					   cout << "Now you can go outside and touch some grass." << endl;
					   writeline = "Exit";
					   return writeline;
				   }
		   }
		   return writeline;
		   
	   }
	   void save_game(string fname)
	   {
		   std::ofstream file;
		   file.open(fname);
		   if (file.is_open())
		   {
			   file << "Days_passed:" << endl;
			   file << daysPassed << endl;
			   file << endl;
			   file << "Gold_owned:" <<endl;
			   file << gold_owned << endl;
			   file << endl;
			   file << "Inventory_Items:" <<endl;
			   file << Inventory.size() << endl;
			   for (size_t i = 0; i < Inventory.size(); i++)
			   {
				   file << Inventory[i].get_life_points()<<" "<< Inventory[i].get_armor_points()<< " " << Inventory[i].get_damage() << " " << Inventory[i].get_item_sell_cost() << " " <<Inventory[i].get_item_type() << endl;
			   }
			   file << endl;
			   file << "Equiped_Items:"<<endl;
			   file << Equipment.size() << endl;
			   for (size_t i = 0; i < Equipment.size(); i++)
			   {
				   file << Equipment[i].get_life_points()<<" "<< Equipment[i].get_armor_points() << " " << Equipment[i].get_damage() << " " << Equipment[i].get_item_sell_cost() << " " <<Equipment[i].get_item_type() << endl;
			   }
		   }
		   file.close();
	   }
	   void load_saved_game(string filename)
	   {
		   string line;
		   ifstream file(filename);
		   if (file.is_open()) {
			   while (getline(file, line)) 
			   {
				   if (line == "Days_passed:")
				   {
					   getline(file, line);
					   string days = line;
					   int passingDays = stoi(days);
					   daysPassed = passingDays;
				   }
				   if (line == "Gold_owned:")
				   {
					   getline(file, line);
					   string text_gold_owned = line;
					   int int_gold_owned = stoi(text_gold_owned);
					   gold_owned = int_gold_owned;
				   }
				   if (line == "Inventory_Items:")
				   {
					   getline(file, line);
					   int InventorySize = stoi(line);
					   for (int i = 0; i < InventorySize; i++)
					   {
						   getline(file, line);
						   stringstream ss(line);
						   string word;
						   int LifePoints;
						   int ArmorPoints;
						   int DamagePoints;
						   int SellValue;
						   string ItemType;
						   ss >> word;
						   LifePoints = stoi(word);
						   ss >> word;
						   ArmorPoints = stoi(word);
						   ss >> word;
						   DamagePoints = stoi(word);
						   ss >> word;
						   SellValue = stoi(word);
						   ss >> word;
						   ItemType = word;
						   Item saved_Item = Item(LifePoints, DamagePoints, ArmorPoints, SellValue, ItemType);
						   Inventory.push_back(saved_Item);
                       }
                   }
				   if (line == "Equiped_Items:")
				   {
					   getline(file, line);
					   int EquipmentSize = stoi(line);
					   for (int i = 0; i < EquipmentSize; i++)
					   {
						   getline(file, line);
						   stringstream ss(line);
						   string word;
						   int LifePoints;
						   int ArmorPoints;
						   int DamagePoints;
						   int SellValue;
						   string ItemType;
						   ss >> word;
						   LifePoints = stoi(word);
						   ss >> word;
						   ArmorPoints = stoi(word);
						   ss >> word;
						   DamagePoints = stoi(word);
						   ss >> word;
						   SellValue = stoi(word);
						   ss >> word;
						   ItemType = word;
						   Item saved_Item = Item(LifePoints, DamagePoints, ArmorPoints, SellValue, ItemType);
						   Equipment.push_back(saved_Item);
					   }

				   }
			   }
			   cout << "Load Successful!" << endl;
			   file.close();
		   }
		   else
		   {
			   cout << "The file you entered doesn't exist." << endl;
			   cout << "Please try again." << endl;
		   }
	   }

};
void main_Game()
{
	cout << "Welcome to the Game: Kill the dragon Spaska" << endl;
	cout << "Your mission is to kill the dragon while eradicating monsters in the forest and looting diffrent kind of weapons and armors" << endl;
	cout << "Here are the following command that you can execute with your character:" << endl;
	cout << "Exit --you can exit the game with this command" << endl;
	cout << "Save -- saves your progress like gold earned , inventory and equipment" << endl;
	cout << "Load -- loads your progress like gold earned , inventory and equipment from a file that you save to." << endl;
	cout << "Fight --you can decide which type of 3 monster you can fight" << endl;
	cout << "Mine -- with this command you can mine gold" << endl;
	cout << "Rest --with this command you rest in the inn and restore your health" << endl;
	cout << "Days --shows how many days have passed since you started your adventure" << endl;
	cout << "Equip --with this command you can equip weapons and armors" << endl;
	cout << "Sell -- with this command you can sell weapons and armors from your inventory" << endl;
	cout << "FightEndBoss -- with this command you can fight the last boss the dragon Spaska" << endl;
	cout << "InfoEndBoss -- with this command you can see the last boss Health , Damage and Armor" << endl;
	cout << "ShowInventory -- you can see the items in your inventory" << endl;
	cout << "ShowEquipment -- you can see the items you have equiped" << endl;
	cout << "Info -- you can see the stats of your hero" << endl;
	cout << "Gold -- shows how much gold you own" << endl;
	cout << "Help -- you can see all the commands again" << endl;
	std::string writeLine;
	vector<Item> Inventory;
	vector<Item> Equipment;
	Player character = Player(100, 5, 0, 0, Inventory, Equipment);
	int exitgame = 0;
	while (writeLine != "Exit")
	{
		std::cin >> writeLine;
		if (writeLine == "Help")
		{
			cout << "Here are the following command that you can execute with your character:" << endl;
			cout << "Exit --you can exit the game with this command" << endl;
			cout << "Save -- saves your progress like gold earned , inventory and equipment" << endl;
			cout << "Load -- loads your progress like gold earned , inventory and equipment from a file that you save to." << endl;
			cout << "Fight --you can decide which type of 3 monster you can fight" << endl;
			cout << "Mine -- with this command you can mine gold" << endl;
			cout << "Rest --with this command you rest in the inn and restore your health" << endl;
			cout << "Days --shows how many days have passed since you started your adventure" << endl;
			cout << "Equip --with this command you can equip weapons and armors" << endl;
			cout << "Sell -- with this command you can sell weapons and armors from your inventory" << endl;
			cout << "FightEndBoss -- with this command you can fight the last boss the dragon Spaska" << endl;
			cout << "InfoEndBoss -- with this command you can see the last boss Health , Damage and Armor" << endl;
			cout << "ShowInventory -- you can see the items in your inventory" << endl;
			cout << "ShowEquipment -- you can see the items you have equiped" << endl;
			cout << "Info -- you can see the stats of your hero" << endl;
			cout << "Gold -- shows how much gold you own" << endl;
		}
		if (writeLine == "Save")
		{
			string filename;
			cout << "Write the name of the file you want to save to:";
			cin >> filename;
			character.save_game(filename);
		}
		if (writeLine == "Load")
		{
			string filename;
			cout << "Write the name of the file you want to load from:";
			cin >> filename;
			character.load_saved_game(filename);
		}
		if (writeLine == "Fight")
		{
			character.go_to_the_forest();
		}
		if (writeLine == "Mine")
		{
			character.mine_gold_behind_inn();
			character.get_character_gold_owned();
		}
		if (writeLine == "Rest")
		{
			character.rest_at_the_inn();
		}
		if (writeLine == "Days")
		{
			character.get_days_passed();
		}
		if (writeLine == "Equip")
		{
			character.equip_items();
		}
		if (writeLine == "Sell")
		{
			character.sell_items();
		}
		if (writeLine == "InfoEndBoss")
		{
			cout << "Lamyata Spaska has 10000 Life 100 damage and 50 Armor." << endl;
		}
		if (writeLine == "FightEndBoss")
		{
			character.fight_LamyataSpaska(writeLine);
		}
		if (writeLine == "ShowInventory")
		{
			character.print_My_Inventory();
		}
		if (writeLine == "ShowEquipment")
		{
			character.print_My_Equipment();
		}
		if (writeLine == "Info")
		{
			character.calculate_stats();
		}
		if (writeLine == "Gold")
		{
			character.get_character_gold_owned();
		}
	}
}

int main()
{
	main_Game();
}

