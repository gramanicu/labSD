#ifndef __TRIE_H
#define __TRIE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

int ALPHABET_SIZE = 26;

template <typename T>
class Trie {
   private:
    int count;
    std::vector<Trie<T> *> children;
    T value;
    bool isEndOfWord;

   public:
    Trie() {}

    Trie(int capacity, T value)
        : count(0), children(capacity, NULL), value(value) {}

    Trie(int capacity) : count(0), children(capacity, NULL) {}

    ~Trie() {}

    void insert(std::string key, T value) {
        // TODO 1 implementati functia de inserare in Trie
        if (key.length() == 0) {
            this->value = value;
            isEndOfWord = true;
            return;
        }

        char letter = key.at(0);
        int index = std::tolower(int(letter)) - 96;

        if (children[index] == nullptr) {
            children[index] = new Trie<T>(children.size());
            count++;
        }

        children[index]->insert(key.erase(0, 1), value);
    }

    bool search(std::string key, T &val) {
        // TODO 1 implementati functia de cautare in Trie
        if (key == "") {
            val = value;
            return isEndOfWord;
        }

        char letter = key.at(0);
        int index = std::tolower(int(letter)) - 96;

        if (children[index] == nullptr) {
            return false;
        }

        return children[index]->search(key.erase(0, 1), val);
    }

    bool remove(std::string key) {
        if (key.length() == 0) {
            value = T();
            isEndOfWord = false;
            if(count==0) {
              return isEndOfWord;
            }
            return false;
        }

        char letter = key.at(0);
        int index = std::tolower(int(letter)) - 96;

        if(children[index] != nullptr) {
          if(children[index]->remove(key.erase(0, 1))) {
            children[index] = nullptr;
            count--;
            if(count==0  && isEndOfWord == false) {
              return true;
            }
          }
        }

        return false;
    }

    int numWordsWithPrefix(std::string prefix) {
        // TODO BONUS implementati gasirea numarului de cuvinte din Trie avand
        // prefixul dat
        return 0;
    }
};
#endif
