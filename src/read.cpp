#include "read.hpp"
vector<string> stopword;
unordered_map<string, int> wordCount;
priority_queue<Item> heap;

void stopwords() {
  ifstream stfile("dataset/input/stopwords.txt");
  string line, word;

  while (getline(stfile, line)) {
    istringstream iss(line);
    while (iss >> word) {
      stopword.push_back(word);
    }
  }
}

bool ehstopword(string word) {
  for (long unsigned int i = 0; i < stopword.size(); i++) {
    if (word == stopword[i])
      return true;
  }
  return false;
}

void mapeamento() {
  ifstream inputFile("dataset/input/DomCasmurro.txt");
  string line, word;

  while (getline(inputFile, line)) {
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    istringstream iss(line);
    while (iss >> word) {
      word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
      if (!word.empty() && !ehstopword(word)) {
        wordCount[word]++;
      }
    }
  }

  inputFile.close();
}

void topKitens() {
  int count = 0;

  for (const auto &pair : wordCount) {
    if (count == 20)
      break;
    heap.push(Item(pair.first, pair.second));
    count++;
  }

  for (const auto &pair : wordCount) {
    if (pair.second > heap.top().value) {
      heap.pop();
      heap.push(Item(pair.first, pair.second));
    }
  }
}

void heapfinal() {
  priority_queue<Item2> heap2;

  while (!heap.empty()) {
    heap2.push(Item2(heap.top().name, heap.top().value));
    heap.pop();
  }

  while (!heap2.empty()) {
    cout << heap2.top().name << " - Contagem: " << heap2.top().value << endl;
    heap2.pop();
  }
}
