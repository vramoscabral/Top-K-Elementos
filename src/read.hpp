#ifndef READ_HPP
#define READ_HPP
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

extern vector<string> stopword;
extern unordered_map<string, int> wordCount;

struct Item {
  string name;
  int value;

  Item(const string &n, int v) : name(n), value(v) {}

  bool operator<(const Item &other) const {
    return value > other.value; }
};

extern priority_queue<Item> heap;

struct Item2 {
  string name;
  int value;

  Item2(const string &n, int v) : name(n), value(v) {}

  bool operator<(const Item2 &other) const {
    return value < other.value; }
};

void stopwords();
bool ehstopword(string word);
void mapeamento();
void topKitens();
void heapfinal();

#endif